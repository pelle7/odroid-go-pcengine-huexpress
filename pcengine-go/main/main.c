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


NOINLINE void app_init(void)
{
    printf("pcengine (%s-%s).\n", COMPILEDATE, GITREV);
    
    nvs_flash_init();

    odroid_system_init();

    ili9341_init();

    // Joystick.
    odroid_input_gamepad_init();
    odroid_input_battery_level_init();

    //printf("osd_init: ili9341_prepare\n");
    ili9341_prepare();

    

    /////
    check_boot_cause();
    
    char *rom_file = odroid_ui_choose_file("/sd/roms/pce", "pce");
    
    InitPCE(rom_file);
}

NOINLINE void app_loop(void)
{
   printf("up and running\n");
   abort();
}

void app_main(void)
{
    app_init();
    app_loop();
}
