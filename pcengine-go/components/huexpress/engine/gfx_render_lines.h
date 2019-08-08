    save_gfx_context(1);
    load_gfx_context(0);
    if (!UCount) { /* Either we're in frameskip = 0 or we're in the frame to draw */
        if (SpriteON && SPONSwitch)
        {
#ifdef MY_INLINE_SPRITE
            int Y1 = last_display_counter;
            int Y2 = display_counter;
            uchar bg = 0;
            if (!skipNextFrame)
            {
            #include "sprite_RefreshSpriteExact.h"
            }
#else
            RefreshSpriteExact(last_display_counter, display_counter - 1, 0);
#endif
        }
#ifdef MY_INLINE_SPRITE
if (!skipNextFrame)
        {
        int Y1 = last_display_counter;
        int Y2 = display_counter - 1;
        #include "sprite_RefreshLine.h"
        }
#else
        RefreshLine(last_display_counter, display_counter - 1);
#endif
        if (SpriteON && SPONSwitch)
        {
#ifdef MY_INLINE_SPRITE
            int Y1 = last_display_counter;
            int Y2 = display_counter;
            uchar bg = 1;
            if (!skipNextFrame)
            {
            #include "sprite_RefreshSpriteExact.h"
            }
#else
            RefreshSpriteExact(last_display_counter, display_counter - 1, 1);
#endif
        }
    }
    load_gfx_context(1);
    gfx_need_redraw = 0;
