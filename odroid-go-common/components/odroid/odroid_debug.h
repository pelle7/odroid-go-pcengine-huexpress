#pragma once

//#define ODROID_DEBUG_PERF_USE
//#define ODROID_DEBUG_PERF_LOG_ALL

#ifndef ODROID_DEBUG_PERF_USE
#define ODROID_DEBUG_PERF_INIT()
#define ODROID_DEBUG_PERF_START() 
#define ODROID_DEBUG_PERF_START2(var_name)
#define ODROID_DEBUG_PERF_INCR(call)
#define ODROID_DEBUG_PERF_INCR2(var_name, call) 
#define ODROID_DEBUG_PERF_LOG()
#else

#include "esp_system.h"

#define ODROID_DEBUG_PERF_INIT() odroid_debug_perf_init();

#define ODROID_DEBUG_PERF_START() \
    int odroid_debug_perf_start_time = xthal_get_ccount();
    
#define ODROID_DEBUG_PERF_START2(var_name) \
    int var_name = xthal_get_ccount();
    
#define ODROID_DEBUG_PERF_INCR(call) \
    odroid_debug_perf_data_calls[call]++; \
    odroid_debug_perf_data_time[call]+=(xthal_get_ccount() - odroid_debug_perf_start_time);

#define ODROID_DEBUG_PERF_INCR2(var_name, call) \
    odroid_debug_perf_data_calls[call]++; \
    odroid_debug_perf_data_time[call]+=(xthal_get_ccount() - var_name);

#define ODROID_DEBUG_PERF_LOG() odroid_debug_perf_log();

#ifdef __cplusplus
extern "C" {
#endif

extern int odroid_debug_perf_data_calls[512];
extern int odroid_debug_perf_data_time[512];

typedef enum
{
    ODROID_DEBUG_PERF_TOTAL = 0,
    ODROID_DEBUG_PERF_MIKIE_UPDATE,
    ODROID_DEBUG_PERF_CPU,
    ODROID_DEBUG_PERF_AUDIO,
    ODROID_DEBUG_PERF_SUSIE_PAINTSPRITES,
    ODROID_DEBUG_PERF_SUSIE_PAINTSPRITES_LOOP4,
    ODROID_DEBUG_PERF_SUSIE_PAINTSPRITES_VLOOP,
    ODROID_DEBUG_PERF_SUSIE_PAINTSPRITES_HLOOP,
    ODROID_DEBUG_PERF_SUSIE_PROCESSPIXEL,
    ODROID_DEBUG_PERF_SUSIE_LINEGETPIXEL,
    ODROID_DEBUG_PERF_SUSIE_LINEGETBITS,
    ODROID_DEBUG_PERF_CPU_INSTR = 0x100,
    ODROID_DEBUG_PERF_MAX,
} odroid_debug_perf_calls;

void odroid_debug_perf_init();
void odroid_debug_perf_log();
void odroid_debug_perf_log_specific(int call, int base);

#ifdef __cplusplus
}
#endif

#endif
