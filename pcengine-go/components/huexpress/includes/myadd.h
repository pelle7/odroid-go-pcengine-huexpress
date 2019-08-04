#pragma once

#include "esp_system.h"
#include "../../odroid/odroid_debug.h"

extern void *my_special_alloc(unsigned char speed, unsigned char bytes, unsigned long size);

#define USE_INSTR_SWITCH
#define MY_HCD_ENABLED
#define ODROID_DEBUG_PERF_CPU_ALL_INSTR
#define MY_PCENGINE_LOGGING

#define MY_INLINE
#define MY_INLINE_bank_set
#define MY_INLINE_GFX
#define MY_INLINE_GFX_Loop6502
#define MY_INLINE_SPRITE
#define MY_INLINE_SPRITE_sp2pixel
#define MY_INLINE_SPRITE_PutSpriteHflipMakeMask
#define MY_INLINE_SPRITE_PutSpriteHflipM
#define MY_INLINE_SPRITE_PutSpriteHflip
#define MY_INLINE_SPRITE_plane2pixel
#define MY_INLINE_SPRITE_CheckSprites
#define MY_INLINE_SPRITE_RefreshScreen

extern bool skipNextFrame;
