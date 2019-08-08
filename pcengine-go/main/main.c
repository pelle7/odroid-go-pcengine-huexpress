#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_partition.h"
#include "driver/i2s.h"
#include "esp_spiffs.h"
#include "nvs_flash.h"
#include "esp_sleep.h"
#include "driver/rtc_io.h"
#include "esp_ota_ops.h"

#include "pce.h"

extern char *rom_file_name;
extern uchar *SPM_raw;
extern uchar *SPM;
extern char *syscard_filename;

/////////

#include "../components/odroid/odroid_settings.h"
#include "../components/odroid/odroid_audio.h"
#include "../components/odroid/odroid_input.h"
#include "../components/odroid/odroid_system.h"
#include "../components/odroid/odroid_display.h"
#include "../components/odroid/odroid_sdcard.h"
#include "../components/odroid/odroid_ui.h"

#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOINLINE  __attribute__ ((noinline))

const char* SD_BASE_PATH = "/sd";
#define PATH_MAX_MY 128

#define TASK_BREAK (void*)1
uchar* osd_gfx_buffer = NULL;
uchar* XBuf;
#ifdef MY_GFX_AS_TASK
QueueHandle_t vidQueue;
TaskHandle_t videoTaskHandle;
volatile bool videoTaskIsRunning = false;
#endif
uint8_t* framebuffer[2];
uint16_t* my_palette;

#define AUDIO_SAMPLE_RATE (22050)

void dump_heap_info_short() {
    printf("LARGEST: 8BIT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT ));
    printf("LARGEST: 32BIT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL | MALLOC_CAP_32BIT ));
    printf("LARGEST: MALLOC_CAP_INTERNAL: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL ));
    printf("LARGEST: MALLOC_CAP_DEFAULT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_DEFAULT ));
}

void *my_special_alloc(unsigned char speed, unsigned char bytes, unsigned long size) {
    uint32_t caps = (speed?MALLOC_CAP_INTERNAL:MALLOC_CAP_SPIRAM) | 
      ( bytes==1?MALLOC_CAP_8BIT:MALLOC_CAP_32BIT);
      /*
    if (speed) {
        uint32_t max = heap_caps_get_largest_free_block(caps);
        if (max < size) {
            printf("ALLOC: Size: %u; Max FREE for internal is '%u'. Allocating in SPI RAM\n", (unsigned int)size, max);
            caps = MALLOC_CAP_SPIRAM | ( size==1?MALLOC_CAP_8BIT:MALLOC_CAP_32BIT);
        }
    } else {
      caps = MALLOC_CAP_SPIRAM | MALLOC_CAP_32BIT;
    }
    */
    if (!speed) caps = MALLOC_CAP_SPIRAM | MALLOC_CAP_32BIT;
    //if (!speed || size!=65536) caps = MALLOC_CAP_SPIRAM | MALLOC_CAP_32BIT; // only RAM
    void *rc = heap_caps_malloc(size, caps);
    printf("ALLOC: Size: %-10u; SPI: %u; 32BIT: %u; RC: %p\n", (unsigned int)size, (caps&MALLOC_CAP_SPIRAM)!=0, (caps&MALLOC_CAP_32BIT)!=0, rc);
    if (!rc) { dump_heap_info_short(); abort(); }
    return rc;
}

#ifdef MY_GFX_AS_TASK

#define VID_TASK(func) \
    uint8_t* param; \
    videoTaskIsRunning = true; \
    printf("%s: STARTED\n", __func__); \
     \
    while(1) \
    { \
        xQueuePeek(vidQueue, &param, portMAX_DELAY); \
 \
        if (param == TASK_BREAK) \
            break; \
 \
        odroid_display_lock(); \
        func(param, my_palette); \
        odroid_display_unlock(); \
        /* odroid_input_battery_level_read(&battery);*/ \
        xQueueReceive(vidQueue, &param, portMAX_DELAY); \
    } \
    xQueueReceive(vidQueue, &param, portMAX_DELAY); \
    /*odroid_display_lock();*/ \
    /*odroid_display_show_hourglass();*/ \
    /*odroid_display_unlock();*/ \
    videoTaskIsRunning = false; \
    printf("%s: FINISHED\n", __func__); \
    vTaskDelete(NULL); \
    while (1) {}

void videoTask_mode0(void *arg) { VID_TASK(ili9341_write_frame_pcengine_mode0) }

NOINLINE void update_display_task()
{
    printf("VIDEO: Task: Start\n");
    TaskFunction_t taskFunc = &videoTask_mode0;
    xTaskCreatePinnedToCore(taskFunc, "videoTask", 1024 * 4, NULL, 5, &videoTaskHandle, 1);
    while (!videoTaskIsRunning) { vTaskDelay(1); }
    printf("VIDEO: Task: Start done\n");
}

#endif

void DoMenuHome(bool save)
{
    uint8_t* param = TASK_BREAK;
    //void *exitAudioTask = NULL;

    // Clear audio to prevent studdering
    printf("PowerDown: stopping audio.\n");
    odroid_audio_terminate();
    //xQueueSend(audioQueue, &exitAudioTask, portMAX_DELAY);
    //while (AudioTaskIsRunning) {}

    // Stop tasks
    printf("PowerDown: stopping tasks.\n");
#ifdef MY_GFX_AS_TASK
    xQueueSend(vidQueue, &param, portMAX_DELAY);
    while (videoTaskIsRunning) { vTaskDelay(1); }
#endif
    //DoReboot(save);
    DoReboot(false);
}


NOINLINE void app_init(void)
{
    printf("pcengine (%s-%s).\n", COMPILEDATE, GITREV);
    
    nvs_flash_init();

    odroid_system_init();

    ili9341_init();
    ili9341_clear(0);

    // Joystick.
    odroid_input_gamepad_init();
    odroid_input_battery_level_init();

    //printf("osd_init: ili9341_prepare\n");
    ili9341_prepare();

    /////
    check_boot_cause();
    
    esp_err_t r = odroid_sdcard_open(SD_BASE_PATH);
    if (r != ESP_OK)
    {
        odroid_display_show_sderr(ODROID_SD_ERR_NOCARD);
        abort();
    }
    
    char *rom_file = odroid_ui_choose_file("/sd/roms/pce", "pce");
    if (!rom_file)
    {
        printf("No file selected!\n");
        abort();
    }
    
    cart_name = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    short_cart_name = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    short_iso_name = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    rom_file_name = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    config_basepath = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    sav_path = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    sav_basepath = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    tmp_basepath = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    video_path = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    ISO_filename = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    syscard_filename = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    cdsystem_path = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    
    spr_init_pos = (uint32 *)my_special_alloc(false, 4, 1024 * 4);
    SPM_raw = (uchar*)my_special_alloc(false, 1, XBUF_WIDTH * XBUF_HEIGHT);
    SPM = SPM_raw + XBUF_WIDTH * 64 + 32;
    log_filename = (char *)my_special_alloc(false, 1, PATH_MAX_MY);
    strcpy(cart_name, "");
    strcpy(short_cart_name, "");
    strcpy(rom_file_name, "");
    strcpy(config_basepath, "/sd/odroid/data/pce");
    strcpy(tmp_basepath, "");
    strcpy(video_path, "");
    strcpy(ISO_filename, "");
    strcpy(sav_basepath,"/sd/odroid/data");
    strcpy(sav_path,"pce");
    
    framebuffer[0] = my_special_alloc(false, 1, XBUF_WIDTH * XBUF_HEIGHT);
    // framebuffer[0] = heap_caps_malloc(XBUF_WIDTH * XBUF_HEIGHT, MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
    if (!framebuffer[0]) abort();
    printf("app_main: framebuffer[0]=%p\n", framebuffer[0]);

     framebuffer[1] = my_special_alloc(false, 1, XBUF_WIDTH * XBUF_HEIGHT);
    //framebuffer[1] = heap_caps_malloc(XBUF_WIDTH * XBUF_HEIGHT, MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
    if (!framebuffer[1]) abort();
    printf("app_main: framebuffer[1]=%p\n", framebuffer[1]);
    
    my_palette = my_special_alloc(false, 1, 256 * sizeof(uint16_t));
    if (!my_palette) abort();
    
    XBuf = framebuffer[0];
    osd_gfx_buffer = XBuf + 32 + 64 * XBUF_WIDTH;
#ifdef MY_GFX_AS_TASK
    vidQueue = xQueueCreate(1, sizeof(uint16_t*));
#endif
    // void QuickSaveSetBuffer(void* data);
    
    odroid_audio_init(odroid_settings_AudioSink_get(), AUDIO_SAMPLE_RATE);
    
    InitPCE(rom_file);
    osd_init_machine();
#ifdef MY_GFX_AS_TASK
    update_display_task();
#endif
}

NOINLINE void app_loop(void)
{
   printf("up and running\n");
   //if (!(*osd_gfx_driver_list[video_driver].init) ())
   odroid_ui_debug_enter_loop();
   RunPCE();
   abort();
}

void app_main(void)
{
    app_init();
    app_loop();
}


bool QuickLoadState(FILE *f)
{
    return false;
}

bool QuickSaveState(FILE *f)
{
    return false;
}
