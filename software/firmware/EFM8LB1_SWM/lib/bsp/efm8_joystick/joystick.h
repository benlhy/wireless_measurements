/******************************************************************************
 * Copyright (c) 2014 by Silicon Laboratories Inc. All rights reserved.
 *
 * http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
 *****************************************************************************/
 
/////////////////////////////////////////////////////////////////////////////
// joystick.h
/////////////////////////////////////////////////////////////////////////////

#ifndef JOYSTICK_H_
#define JOYSTICK_H_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "joystick_config.h"

/**************************************************************************//**
 * @addtogroup joystick Joystick Driver
 * @{
 *
 * @brief Board support driver for 8-direction joystick pad with center button
 *
 * # Introduction #
 *
 * This module contains all the driver content for decoding joystick
 * analog voltages into directions and center button press.
 *
 *****************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Default Configuration Options
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**
 * @addtogroup joystick_config Driver Configuration
 * @{
 *
 * @brief Driver configuration constants read from joystick_config.h
 *
 * This board support library will look for configuration constants in
 * **joystick_config.h**. This file is provided/written by the user and should be
 * located in a directory that is part of the include path.
 *
 ******************************************************************************/

/// @name Configuration Enums
/// @{
 
/// Return the four cardinal directions only (N, S, E, W)
#define CARDINAL_ONLY          0

/// Return the four cardinal or four secondary directions (N, S, E, W, NW, NE, SW, SE)
#define CARDINAL_AND_SECONDARY 1

/// @}

/// @name Configuration Options
/// @{

#if !defined(JOYSTICK_DIRECTIONS) || defined(IS_DOXYGEN)
/***************************************************************************//**
 * @brief Controls joystick thresholds for cardinal and secondary positions
 *
 * Specifies the joystick thresholds for cardinal and secondary positions
 * (::CARDINAL_ONLY or ::CARDINAL_AND_SECONDARY).
 *
 * Default setting is ::CARDINAL_ONLY and may be overridden by defining in
 * **joystick_config.h**.
 *
 ******************************************************************************/
#define JOYSTICK_DIRECTIONS      CARDINAL_ONLY
#endif

/// @}

/** @} joystick_config */

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////

/**************************************************************************//**
 * @addtogroup joystick_runtime Runtime API
 * @{
 *****************************************************************************/

/// @name Direction Enums
/// @anchor dir_enums
/// @{

#define JOYSTICK_NONE          0       ///< not pressed
#define JOYSTICK_C             1       ///< center
#define JOYSTICK_N             2       ///< north
#define JOYSTICK_E             3       ///< east
#define JOYSTICK_S             4       ///< south
#define JOYSTICK_W             5       ///< west

#if (JOYSTICK_DIRECTIONS == CARDINAL_AND_SECONDARY) || defined(IS_DOXYGEN)

#define JOYSTICK_NE            6       ///< northeast
#define JOYSTICK_NW            7       ///< northwest
#define JOYSTICK_SE            8       ///< southeast
#define JOYSTICK_SW            9       ///< southwest

#endif

/// @}

/// @name Voltage Enums
/// @{

#define JOYSTICK_MV_C          3       ///< center position in mV
#define JOYSTICK_MV_N          2831    ///< north position in mV
#define JOYSTICK_MV_E          2533    ///< east position in mV
#define JOYSTICK_MV_S          1650    ///< south position in mV
#define JOYSTICK_MV_W          1980    ///< west position in mV

#if (JOYSTICK_DIRECTIONS == CARDINAL_AND_SECONDARY) || defined(IS_DOXYGEN)

#define JOYSTICK_MV_NE         2247    ///< northeast position in mV
#define JOYSTICK_MV_NW         1801    ///< northwest position in mV
#define JOYSTICK_MV_SE         1433    ///< southeast position in mV
#define JOYSTICK_MV_SW         1238    ///< southwest position in mV

#endif

#if (JOYSTICK_DIRECTIONS == CARDINAL_ONLY) || defined(IS_DOXYGEN)
#define JOYSTICK_MV_ERROR      150     ///< tolerance in mV for cardinal
#endif

#if (JOYSTICK_DIRECTIONS == CARDINAL_AND_SECONDARY) || defined(IS_DOXYGEN)
#define JOYSTICK_MV_ERROR      75      ///< tolerance in mV for cardinal and secondary
#endif

/// @}

/////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**
 * @brief Convert the joystick analog voltage from mV to a joystick direction
 *
 * @param mV The joystick analog voltage at one of its positions
 *
 * @return The joystick direction corresponding to the specified analog voltage
 * @returns @ref dir_enums "Direction Enums"
 *
 *****************************************************************************/
uint8_t JOYSTICK_convert_mv_to_direction(uint32_t mV);

/** @} joystick_runtime */
/** @} joystick */

#endif /* JOYSTICK_H_ */
