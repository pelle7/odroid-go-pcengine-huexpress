#ifndef ODROID_DISPLAY_EMU_IMPL
void ili9341_write_frame_pcengine_mode0(uint8_t* buffer, uint16_t* pal);
#else

#include "../huexpress/includes/cleantypes.h"

#define PCENGINE_GAME_WIDTH  352
#define PCENGINE_GAME_HEIGHT 240
#define PCENGINE_REMOVE_X 16
#define XBUF_WIDTH  (536 + 32 + 32)

extern uchar *Pal;
extern uchar *SPM;

void ili9341_write_frame_pcengine_mode0(uint8_t* buffer, uint16_t* pal)
{
    // ili9341_write_frame_rectangleLE(0,0,300,240, buffer -32);
#if 0    
    uint8_t* framePtr = buffer + PCENGINE_REMOVE_X;
    uint8_t *sPtr = SPM;
    short x, y;
    uchar pal0 = Pal[0];
    send_reset_drawing(0, 0, 320, 240);
    for (y = 0; y < PCENGINE_GAME_HEIGHT; y += 4)
    {
      uint16_t* line_buffer = line_buffer_get();
      uint16_t* line_buffer_ptr = line_buffer; 
      for (short i = 0; i < 4; ++i) // LINE_COUNT
      {
          //int index = i * displayWidth;
          for (x = 0; x < 320; ++x)
          {
            uint8_t source=*framePtr;
            *framePtr = pal0;
            framePtr++;
            uint16_t value1 = pal[source];
            //line_buffer[index++] = value1;
            *line_buffer_ptr = value1;
            line_buffer_ptr++;
            *sPtr = 0;
            sPtr++;
          }
          framePtr+=280;
      }
      send_continue_line(line_buffer, 320, 4);
    }
    //memset(buffer, Pal[0], 240 * XBUF_WIDTH);
    //memset(SPM, 0, 240 * XBUF_WIDTH);
#endif

    uint8_t* framePtr = buffer + PCENGINE_REMOVE_X;
    uint8_t *sPtr = SPM + (XBUF_WIDTH) * 64;
    short x, y;
    uchar pal0 = Pal[0];
    send_reset_drawing(0, 0, 320, 240);
    for (y = 0; y < PCENGINE_GAME_HEIGHT; y += 4)
    {
      uint16_t* line_buffer = line_buffer_get();
      uint16_t* line_buffer_ptr = line_buffer; 
      for (short i = 0; i < 4; ++i) // LINE_COUNT
      {
          for (x = 0; x < 320; ++x)
          {
            uint8_t source=*framePtr;
            *framePtr = pal0;
            framePtr++;
            uint16_t value1 = pal[source];
            *line_buffer_ptr = value1;
            line_buffer_ptr++;
            *sPtr = 0;
            sPtr++;
          }
          framePtr+=280;
          sPtr+=280;
      }
      send_continue_line(line_buffer, 320, 4);
    }
    //memset(buffer, Pal[0], 240 * XBUF_WIDTH);
    //memset(SPM, 0, 240 * XBUF_WIDTH);
    
    //#define MISSING ( 240 * XBUF_WIDTH - PCENGINE_GAME_HEIGHT*320)
    //memset(sPtr, 0, MISSING);
}

#endif
