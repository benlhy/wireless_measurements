/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Render.h
/////////////////////////////////////////////////////////////////////////////

#ifndef RENDER_H_
#define RENDER_H_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "render_config.h"

/**************************************************************************//**
 * @addtogroup mem_lcd
 * @{
 *****************************************************************************/

/**************************************************************************//**
 * @addtogroup render Render Driver
 * @{
 *
 * @brief Board support driver for rendering for the Sharp LS013B7DH03 LCD
 *
 * # Introduction #
 *
 * This module contains all the driver content for rendering line buffers
 * for the Sharp LS013B7DH03 LCD.
 *
 *****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Default Build Options
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**
 *  @addtogroup render_options Build Options
 *  @{
 *
 *  @brief Build options constants read from **memory_lcd_config.h**
 *
 *  This board support library will look for configuration constants in
 *  **memory_lcd_config.h**. This file is provided/written by the user and should be
 *  located in a directory that is part of the include path.
 *
 ******************************************************************************/

/// @name Build Options
///
/// Build options control inclusion of a specific module function.
///
/// When @c 1, the module function is included.
///
/// Each default setting is defined below and may be overridden by defining in
/// **memory_lcd_config.h**.
/// @{

#if !defined(RENDER_STR_LINE_BUILD) || defined(IS_DOXYGEN)
#define RENDER_STR_LINE_BUILD                   1
#endif

#if !defined(RENDER_LARGE_STR_LINE_BUILD) || defined(IS_DOXYGEN)
#define RENDER_LARGE_STR_LINE_BUILD             1
#endif

#if !defined(RENDER_NUMERIC_BUILD) || defined(IS_DOXYGEN)
#define RENDER_NUMERIC_BUILD                    1
#endif

#if !defined(RENDER_VERTICAL_STR_LINE_BUILD) || defined(IS_DOXYGEN)
#define RENDER_VERTICAL_STR_LINE_BUILD          1
#endif

/// @}

/** @} render_options */

/////////////////////////////////////////////////////////////////////////////
// Default Configuration Options
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**
 *  @addtogroup render_config Driver Configuration
 *  @{
 *
 *  @brief Driver configuration constants read from **memory_lcd_config.h**
 *
 *  This board support library will look for configuration constants in
 *  **memory_lcd_config.h**. This file is provided/written by the user and should be
 *  located in a directory that is part of the include path.
 *
 ******************************************************************************/

#if !defined(RENDER_LINE_SEG) || defined(IS_DOXYGEN)
/***************************************************************************//**
 * @brief Controls variable segment pointer target memory space for parameters
 *
 * Specifies the memory space for a user defined line buffer array.
 *
 * Default setting is @c SI_SEG_IDATA and may be overridden by defining in
 * **memory_lcd_config.h**.
 *
 ******************************************************************************/
#define RENDER_LINE_SEG                         SI_SEG_IDATA
#endif

#if !defined(RENDER_STR_SEG) || defined(IS_DOXYGEN)
/***************************************************************************//**
 * @brief Controls variable segment pointer target memory space for parameters
 *
 * Specifies the memory space for a user defined string.
 *
 * Default setting is @c SI_SEG_GENERIC and may be overridden by defining in
 * **memory_lcd_config.h**.
 *
 ******************************************************************************/
#define RENDER_STR_SEG                          SI_SEG_GENERIC
#endif

#if !defined(RENDER_SPRITE_SEG) || defined(IS_DOXYGEN)
/***************************************************************************//**
 * @brief Controls variable segment pointer target memory space for parameters
 *
 * Specifies the memory space for a user defined sprite array.
 *
 * Default setting is @c SI_SEG_CODE and may be overridden by defining in
 * **memory_lcd_config.h**.
 *
 ******************************************************************************/
#define RENDER_SPRITE_SEG                       SI_SEG_CODE
#endif

/** @} render_config */

/**************************************************************************//**
 * @addtogroup render_runtime Runtime API
 * @{
 *****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////

#define FONT_WIDTH          6               ///< Character width in px
#define FONT_HEIGHT         8               ///< Character height in px
#define FONT_MAP_SPACING    8               ///< Character spacing in font map

#define TO_BYTE_MASK 		0x000000FF

/////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**
 * @brief Return the size of the string in pixels
 *
 * @param str a null-terminated string
 *
 * @return The width of a string in pixels as rendered by ::RENDER_StrLine()
 *
 *****************************************************************************/
uint8_t RENDER_GetStrSize(
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG));

/***************************************************************************//**
 * @brief Clear the contents of a line buffer, setting its contents to the
 * background color
 *
 * @param line a line buffer to clear
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 *
 *****************************************************************************/
void RENDER_ClrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG));

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
        uint8_t posx);

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
        uint8_t xstop);

/***************************************************************************//**
 * @brief Write a string to a line buffer horizontally
 * (text reads from left to right, up facing up)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-HEIGHT)
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
void RENDER_StrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG));

/***************************************************************************//**
 * @brief Write a string to a line buffer horizontally
 * (text reads from left to right, up facing up)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-HEIGHT)
 * @param str a null-terminated string to write
 * @param fontScale can be enlarged from 2x to 4x. However, if larger than 5x, this
 *        function only renders 4x.
 ******************************************************************************/
void RENDER_Large_StrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG),
        uint8_t fontScale);

/***************************************************************************//**
 * @brief Write numeric string to line buffer ('0'-'9' and ':')
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-WIDTH)
 * @param posy the y position for the text row relative to the top side of the
 * text block y = [0, ::DISP_HEIGHT-HEIGHT)
 * @param str a null-terminated string to write
 * @param fontScale can be enlarged from 2x to 4x. However, if larger than 5x, this
 *        function only renders 4x
 *
 ******************************************************************************/
void RENDER_Numeric(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG),
        uint8_t fontScale);

/***************************************************************************//**
 * @brief Write a string to a line buffer vertically (CCW 90 degrees)
 * (text reads from bottom to top, up facing left)
 *
 * @param line a line buffer to write to
 *        (length = ::DISP_BUF_SIZE; segment = ::RENDER_LINE_SEG)
 * @param posx the LCD x position for the left side of the text block
 * x = [0, ::DISP_WIDTH-WIDTH)
 * @param posy the y position for the text row relative to the left side of the
 * first character y = [0, ::DISP_HEIGHT-HEIGHT)
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
void RENDER_VerticalStrLine(
        SI_VARIABLE_SEGMENT_POINTER(line, uint8_t, RENDER_LINE_SEG),
        uint8_t posx,
        uint8_t posy,
        SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG));

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
        uint8_t spriteWidth);

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
        uint8_t spriteWidth);

/** @} render_runtime */

/** @} render */

/** @} mem_lcd */

#endif /* RENDER_H_ */
