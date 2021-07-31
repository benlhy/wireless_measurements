/////////////////////////////////////////////////////////////////////////////
// Render.c
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "bsp.h"
#include "disp.h"
#include "render.h"
#include <string.h>

#if RENDER_STR_LINE_BUILD || RENDER_LARGE_STR_LINE_BUILD
#include "thinfont.h"
#endif

#if RENDER_NUMERIC_BUILD
#include "thinfont_numeric.h"
#endif

#if RENDER_VERTICAL_STR_LINE_BUILD
#include "verticalthinfont.h"
#endif

/////////////////////////////////////////////////////////////////////////////
// Functions
/////////////////////////////////////////////////////////////////////////////

#if LSB == 0

uint16_t switchEndian(uint16_t value)
{
  uint16_t switched = (value & 0xFF) << 8;
  
  switched += (value & 0xFF00) >> 8;
  return switched;
}

#endif

/***************************************************************************//**
 * @brief Return the size of the string in pixels
 *
 * @param str a null-terminated string
 *
 * @return The width of a string in pixels as rendered by ::RENDER_StrLine()
 *
 *****************************************************************************/
uint8_t RENDER_GetStrSize(
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG))
{
    uint8_t len = 0;
    
    while (str[len++] != 0);
    len--;

    return (len * FONT_WIDTH + 2);
}

/***************************************************************************//**
 * @brief Clear the contents of a line buffer, setting its contents to the
 * background color
 *
 * @param line a line buffer to clear
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 *
 *****************************************************************************/
void RENDER_ClrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG))
{
  uint8_t i;
  
  for (i = 0; i < DISP_BUF_SIZE; i++)
  {
    line[i] = DISP_BACKGROUND_COLOR;
  }
}

/***************************************************************************//**
 * @brief Set a pixel in the line buffer to the foreground color
 *
 * @param line a line buffer to clear
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the x-position of the pixel to turn on [0, ::DISP_WIDTH)
 *
 *****************************************************************************/
void RENDER_PixelLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx)
{
#if DISP_FOREGROUND_COLOR == COLOR_BLACK
    line[posx / 8] &= ~(0x80 >> (posx % 8));
#else
    line[posx / 8] |= (0x80 >> (posx % 8));
#endif
}

/***************************************************************************//**
 * @brief Set the pixels of a line segment of the range
 * [xstart, xstop] in the line buffer to the foreground color
 *
 * @param line a line buffer to clear
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param xstart the starting x-position of the line segment [0, ::DISP_WIDTH)
 * @param xstop the stopping x-position of the line segment [0, ::DISP_WIDTH)
 *
 *****************************************************************************/
void RENDER_LineSegmentLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t xstart,
        uint8_t xstop)
{
    uint8_t x;
    uint8_t swap;

    // Swap the start/stop values
    if (xstart > xstop)
    {
        swap = xstop;
        xstop = xstart;
        xstart = swap;
    }

    for (x = xstart; x <= xstop; x++)
    {
        RENDER_PixelLine(line, x);
    }
}

/***************************************************************************//**
 * @brief Write a string to a line buffer horizontally
 * (text reads from left to right, up facing up)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-STR_WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-STR_HEIGHT)
 * @param str a null-terminated string to write
 *
 * Example
 * -------
 *
 * ~~~
 *                   LCD TOP
 * RR _____________________________________
 * 00|                                     |
 * 01|                                     |
 * 02|                                     |
 * 03|   ____________________              |
 * 04|  | ___  ___  ___  ___ |< y=0        |
 * 05|  |  |  |    |      |  |             |
 * 06|  |  |  |---  ---   |  |< y=HEIGHT/2 |
 * 07|  |  |  |___  ___|  |  |             |
 * 08|  |____________________|< y=HEIGHT   |
 * 09|  ^                    ^             |
 * 10|  x                    x+WIDTH       |
 * 11|_____________________________________|
 *   C0000000000111111111122222222223333333
 *   C0123456789012345678901234567890123456
 * ~~~
 *
 * To display the text, "TEST" horizontally on the LCD with the
 * top-left corner of the text block located on the LCD at
 * row = 4, col = 3, call:
 *
 * ~~~{.c}
 * for (y = 0; y < FONT_HEIGHT; y++)
 * {
 *    RENDER_StrLine(line, 3, y, "TEST");
 *    DISP_WriteLine(4+y, line);
 * }
 * ~~~
 *
 *****************************************************************************/
#if RENDER_STR_LINE_BUILD
void RENDER_StrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG))
{
    char c;
    uint8_t font_byte;

    SI_VARIABLE_SEGMENT_POINTER(line16, uint16_t, RENDER_LINE_SEG);
#if LSB == 0
    uint16_t tmp = 0;
#endif

    // String is null-terminated
    while (*str != '\0')
    {
        c = *str;

        // Check for non-printable characters
        if (c < ' ' || c > '~')
        {
          c = ' ';
        }

        // Don't write past the end of the line
        if (posx > (DISP_WIDTH - FONT_MAP_SPACING))
        {
            str++;
            posx += FONT_WIDTH;
            continue;
        }

        font_byte = thinfont_bits[(c - ' ') + thinfont_width / 8 * posy];

        // Calculate position in line buffer
        line16 = (SI_VARIABLE_SEGMENT_POINTER(, uint16_t, RENDER_LINE_SEG))(&line[posx / 8]);

        // WARNING: This could be very dangerous without proper
        // bounds checking as this technically touches the
        // 17th byte of the 16 byte line buffer.
        //
        // However, we only allow posx to be 120 at max, which
        // leaves div = 15, rem = 0, which means we effectively don't
        // change the value of the 17th byte

#if LSB == 0
        tmp = switchEndian(*line16);
        tmp &= ~(0xFF00 >> posx % 8);
        tmp |= (((uint16_t)font_byte << 8) >> (posx % 8));
        *line16 = switchEndian(tmp);
#else
        *line16 &= ~(0xFF00 >> posx % 8);
        *line16 |= (((uint16_t)font_byte << 8) >> (posx % 8));
#endif

        str++;
        posx += FONT_WIDTH;
    }
}
#endif

/***************************************************************************//**
 * @brief Write a string to a line buffer
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the pixel x position to start writing [0 - ::DISP_WIDTH)
 * @param enlarged_font_byte enlarged font byte that is inserted into line buffer
 *
 *****************************************************************************/
static void RENDER_byte(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t enlarged_font_byte)
{
#if LSB == 0
	uint16_t tmp = 0;
#endif
  
  SI_VARIABLE_SEGMENT_POINTER(line16, uint16_t, RENDER_LINE_SEG);
  
	// Calculate position in line buffer
	line16 = (SI_VARIABLE_SEGMENT_POINTER(, uint16_t, RENDER_LINE_SEG))&line[posx / 8];

	// WARNING: This could be very dangerous without proper
	// bounds checking as this technically touches the
	// 17th byte of the 16 byte line buffer.
	//
	// However, we only allow posx to be 120 at max, which
	// leaves div = 15, rem = 0, which means we effectively don't
	// change the value of the 17th byte

#if LSB == 0
	tmp = switchEndian(*line16);
	tmp &= ~(0xFF00 >> posx % 8);
	tmp |= (((uint16_t)enlarged_font_byte << 8) >> (posx % 8));
	*line16 = switchEndian(tmp);
#else
	*line16 &= ~(0xFF00 >> posx % 8);
	*line16 |= (((uint16_t)enlarged_font_byte << 8) >> (posx % 8));
#endif
}

/***************************************************************************//**
 * @brief Write a string to a line buffer horizontally
 * (text reads from left to right, up facing up)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-STR_WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-STR_HEIGHT)
 * @param str a null-terminated string to write
 * @param fontScale can be enlarged from 2x to 4x. However, if larger than 5x, this
 *        function only renders 4x
 *
 ******************************************************************************/
#if RENDER_LARGE_STR_LINE_BUILD
void RENDER_Large_StrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG),
        uint8_t fontScale)
{
    char c;
    uint8_t font_byte;
    uint8_t i;
    uint8_t shiftOffset;
    uint32_t enlarged_font_byte;

    // String is null-terminated
    while (*str != '\0')
    {
        c = *str;

        // Check for non-printable characters
        if (c < ' ' || c > '~' + 1)
        {
          c = ' ';
        }

        // Don't write past the end of the line
        if (posx > (DISP_WIDTH - (FONT_MAP_SPACING * fontScale)))
        {
            str++;
            posx += FONT_WIDTH * fontScale;
            continue;
        }

        font_byte = thinfont_bits[(c - ' ') + thinfont_width / 8 * posy];

        enlarged_font_byte = 0;
        for( i = 0; i < 8; i++)	//for every bit in font_byte
        {
        	if(font_byte & 0x01)
        	{
        		if(fontScale == 1)
        		{
        			enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0x80000000);
        		}
        		else if(fontScale == 2)
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xC0000000);
				}
				else if(fontScale == 3)
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xE0000000);
				}
				else
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xF0000000);
				}
        	}
        	else
        	{
        		enlarged_font_byte = (enlarged_font_byte >> fontScale);
        	}
        	font_byte = font_byte >> 1;
        }

        for(i = 0; i < fontScale; i++)	//Number of bytes of a 32 bit variable
        {
        	shiftOffset = 32 - (8 * (i + 1));	//start with top byte move down to last byte
        	RENDER_byte(line, posx + (8 * i), (uint8_t)((enlarged_font_byte >> shiftOffset) & TO_BYTE_MASK));
        }

        str++;
        posx += FONT_WIDTH * fontScale;
    }
}
#endif

/***************************************************************************//**
 * @brief Write numeric string to line buffer ('0'-'9' and ':')
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-STR_WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-STR_HEIGHT)
 * @param str a null-terminated string to write
 * @param fontScale can be enlarged from 2x to 4x. However, if larger than 5x, this
 *        function only renders 4x
 *
 ******************************************************************************/
#if RENDER_NUMERIC_BUILD
void RENDER_Numeric(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG),
        uint8_t fontScale)
{
    char c;
    uint8_t font_byte;
    uint8_t i;
    uint8_t shiftOffset;
    uint32_t enlarged_font_byte;

    // String is null-terminated
    while (*str != '\0')
    {
        c = *str;

        // Check for non-printable characters
        if (c < ' ' || c > '~' + 1)
        {
          c = ' ';
        }

        // Don't write past the end of the line
        if (posx > (DISP_WIDTH - (FONT_MAP_SPACING * fontScale)))
        {
            str++;
            posx += FONT_WIDTH * fontScale;
            continue;
        }

        font_byte = thinfont_numeric_bits[(c - '/') + thinfont_numeric_width / 8 * posy];

        enlarged_font_byte = 0;
        for( i = 0; i < 8; i++)	//for every bit in font_byte
        {
        	if(font_byte & 0x01)
        	{
        		if(fontScale == 1)
        		{
        			enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0x80000000);
        		}
        		else if(fontScale == 2)
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xC0000000);
				}
				else if(fontScale == 3)
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xE0000000);
				}
				else
				{
					enlarged_font_byte = ((enlarged_font_byte >> fontScale) | 0xF0000000);
				}
        	}
        	else
        	{
        		enlarged_font_byte = (enlarged_font_byte >> fontScale);
        	}
        	font_byte = font_byte >> 1;
        }

        for(i = 0; i < fontScale; i++)	//Number of bytes of a 32 bit variable
        {
        	shiftOffset = 32 - (8 * (i + 1));	//start with top byte move down to last byte
        	RENDER_byte(line, posx + (8 * i), (uint8_t)((enlarged_font_byte >> shiftOffset) & TO_BYTE_MASK));
        }

        str++;
        posx += FONT_WIDTH * fontScale;
    }
}
#endif

/***************************************************************************//**
 * @brief Write a string to a line buffer vertically (CCW 90 degrees)
 * (text reads from bottom to top, up facing left)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-STR_WIDTH)
 * @param posy the y position for the text row relative to the left side of the
 * first character y = [0, ::DISP_HEIGHT-STR_HEIGHT)
 * @param str a null-terminated string to write
 *
 * Example
 * -------
 *
 * ~~~
 *            LCD TOP
 * RR ________________________
 * 00|                        |
 * 01|                        |
 * 02|      _____             |
 * 03|     |     |< y=WIDTH   |
 * 04|     ||--- |            |
 * 05|     |   _ |            |
 * 06|     ||_| ||            |
 * 07|     |     |< y=WIDTH/2 |
 * 08|     ||_|_||            |
 * 09|     |     |            |
 * 10|     ||--- |            |
 * 11|     |_____|< y=0       |
 * 12|     ^     ^            |
 * 13|     x     x+HEIGHT     |
 * 14|________________________|
 *   C000000000011111111112222
 *   C012345678901234567890123
 * ~~~
 *
 * To display the text, "TEST" vertically on the LCD with the
 * top-left corner of the text block located on the LCD at
 * row = 11, col = 5, call:
 *
 * ~~~{.c}
 * for (y = 0; y < RENDER_GetStrSize("TEST"); y++)
 * {
 *    RENDER_VerticalStrLine(line, 5, y, "TEST");
 *    DISP_WriteLine(11 - y, line);
 * }
 * ~~~
 *
 * Note: This is an example; actual fonts may be larger/smaller.
 * In this example, ::RENDER_GetStrSize("TEST") would return the text block
 * width of 9.
 *
 ******************************************************************************/
#if RENDER_VERTICAL_STR_LINE_BUILD
void RENDER_VerticalStrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG))
{
    char c;
    uint8_t font_byte;
    uint8_t width;
    uint8_t charIndex;
    uint8_t charRow;
    uint16_t index;
    uint8_t len = 0;

    SI_VARIABLE_SEGMENT_POINTER(line16, uint16_t, RENDER_LINE_SEG);
#if LSB == 0
    uint16_t tmp = 0;
#endif

    width = RENDER_GetStrSize(str);

    // Invalid y-value
    if (posy >= width || posy >= DISP_HEIGHT)
        return;

    // Figure out which character in the string is on the line at the
    // specified y-value
    charIndex = posy / FONT_WIDTH;
    charRow = posy % FONT_WIDTH;

    while (str[len++] != 0);
    len--;
    
    if (charIndex >= len)
    {
        charIndex--;
        charRow += FONT_WIDTH;
    }

    c = str[charIndex];

    // Check for non-printable characters
    if (c < ' ' || c > '~')
    {
      c = ' ';
    }

    index = ((((verticalthinfont_height/FONT_MAP_SPACING)-1) - (c - ' ')) * FONT_MAP_SPACING) + (7 - charRow);
    font_byte = verticalthinfont_bits[index];

    // Calculate position in line buffer
    line16 = (uint16_t*)(&line[posx / 8]);

    // WARNING: This could be very dangerous without proper
    // bounds checking as this technically touches the
    // 17th byte of the 16 byte line buffer.
    //
    // However, we only allow posx to be 120 at max, which
    // leaves div = 15, rem = 0, which means we effectively don't
    // change the value of the 17th byte

#if LSB == 0
    tmp = switchEndian(*line16);
    tmp &= ~(0xFF00 >> posx % 8);
    tmp |= (((uint16_t)font_byte << 8) >> (posx % 8));
    *line16 = switchEndian(tmp);
#else
    *line16 &= ~(0xFF00 >> posx % 8);
    *line16 |= (((uint16_t)font_byte << 8) >> (posx % 8));
#endif
}
#endif

/***************************************************************************//**
 * @brief Write a sprite to a line buffer
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the pixel x position to start writing [0, ::DISP_WIDTH)
 * @param posy the pixel y position in the sprite currently being
 * written [0, SPRITE_HEIGHT)
 * @param sprite a pointer to a sprite array (segment = ::RENDER_SPRITE_SEG)
 * @param spriteWidth sprite width in pixels (must be divisible by 8)
 *
 ******************************************************************************/
void RENDER_SpriteLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(sprite, uint8_t, RENDER_SPRITE_SEG),
        uint8_t spriteWidth)
{
    uint8_t i;
    uint8_t sprite_byte;

    SI_VARIABLE_SEGMENT_POINTER(line16, uint16_t, RENDER_LINE_SEG);
#if LSB == 0
    uint16_t tmp = 0;
#endif

    // Don't write past the end of the line
    if (posx > (DISP_WIDTH - spriteWidth))
    {
        return;
    }

    for (i = 0; i < spriteWidth / 8; i++)
    {
        sprite_byte = sprite[i + spriteWidth / 8 * posy];

        // Calculate position in line buffer
        line16 = (SI_VARIABLE_SEGMENT_POINTER(, uint16_t, RENDER_LINE_SEG))(&line[posx / 8]);

        // WARNING: This could be very dangerous without proper
        // bounds checking as this technically touches the
        // 17th byte of the 16 byte line buffer.
        //
        // However, we only allow posx to be 120 at max, which
        // leaves div = 15, rem = 0, which means we effectively don't
        // change the value of the 17th byte

#if LSB == 0
        tmp = switchEndian(*line16);
        tmp &= ~(0xFF00 >> posx % 8);
        tmp |= (((uint16_t)sprite_byte << 8) >> (posx % 8));
        *line16 = switchEndian(tmp);
#else
        *line16 &= ~(0xFF00 >> posx % 8);
        *line16 |= (((uint16_t)sprite_byte << 8) >> (posx % 8));
#endif

        posx += 8;
    }
}

/***************************************************************************//**
 * @brief Write a sprite to a line buffer, only overwriting the
 * foreground pixels
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the pixel x position to start writing [0, ::DISP_WIDTH)
 * @param posy the pixel y position in the sprite currently being
 * written [0, SPRITE_HEIGHT)
 * @param sprite a pointer to a sprite array (segment = ::RENDER_SPRITE_SEG)
 * @param spriteWidth sprite width in pixels (must be divisible by 8)
 *
 ******************************************************************************/
void RENDER_SpriteLineForeground(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(sprite, uint8_t, RENDER_SPRITE_SEG),
        uint8_t spriteWidth)
{
    uint8_t i;
    uint8_t sprite_byte;

    SI_VARIABLE_SEGMENT_POINTER(line16, uint16_t, RENDER_LINE_SEG);
#if LSB == 0
    uint16_t tmp = 0;
#endif

    // Don't write past the end of the line
    if (posx > (DISP_WIDTH - spriteWidth))
    {
        return;
    }

    for (i = 0; i < spriteWidth / 8; i++)
    {
        sprite_byte = sprite[i + spriteWidth / 8 * posy];

        // Calculate position in line buffer
        line16 = (SI_VARIABLE_SEGMENT_POINTER(, uint16_t, RENDER_LINE_SEG))(&line[posx / 8]);

        // WARNING: This could be very dangerous without proper
        // bounds checking as this technically touches the
        // 17th byte of the 16 byte line buffer.
        //
        // However, we only allow posx to be 120 at max, which
        // leaves div = 15, rem = 0, which means we effectively don't
        // change the value of the 17th byte

#if LSB == 0

        tmp = switchEndian(*line16);
#if DISP_FOREGROUND_COLOR == COLOR_BLACK
        sprite_byte = ~sprite_byte;
        tmp &= ~(((uint16_t)sprite_byte << 8) >> (posx % 8));
#else
        tmp |= (((uint16_t)sprite_byte << 8) >> (posx % 8));
#endif
        *line16 = switchEndian(tmp);
#else

#if DISP_FOREGROUND_COLOR == COLOR_BLACK
        sprite_byte = ~sprite_byte;
        *line16 &= ~(((uint16_t)sprite_byte << 8) >> (posx % 8));
#else
        *line16 |= (((uint16_t)sprite_byte << 8) >> (posx % 8));
#endif

#endif
        posx += 8;
    }
}
