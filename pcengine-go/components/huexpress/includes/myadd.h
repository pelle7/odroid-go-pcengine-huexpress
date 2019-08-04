#pragma once

#include "esp_system.h"
#include "../../odroid/odroid_debug.h"

extern void *my_special_alloc(unsigned char speed, unsigned char bytes, unsigned long size);

#define USE_INSTR_SWITCH

extern bool skipNextFrame;
