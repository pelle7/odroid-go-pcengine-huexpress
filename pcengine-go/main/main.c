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

void dump_heap_info_short() {
    printf("LARGEST: 8BIT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL | MALLOC_CAP_8BIT ));
    printf("LARGEST: 32BIT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL | MALLOC_CAP_32BIT ));
    printf("LARGEST: MALLOC_CAP_INTERNAL: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_INTERNAL ));
    printf("LARGEST: MALLOC_CAP_DEFAULT: %u\n", heap_caps_get_largest_free_block( MALLOC_CAP_DEFAULT ));
}

void *my_special_alloc(unsigned char speed, unsigned char bytes, unsigned long size) {
    // if (size==16384) speed = 1;
    
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







NOINLINE void app_init(void)
{
    printf("pcengine (%s-%s).\n", COMPILEDATE, GITREV);
    
    nvs_flash_init();

    odroid_system_init();

    ili9341_init();
    ili9341_write_frame_lynx(NULL, NULL, false);

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
    
    InitPCE(rom_file);
    osd_init_machine();
}

NOINLINE void app_loop(void)
{
   printf("up and running\n");
   odroid_ui_debug_enter_loop();
   //if (!(*osd_gfx_driver_list[video_driver].init) ())
   RunPCE();
   abort();
}

void app_main(void)
{
    app_init();
    app_loop();
}
