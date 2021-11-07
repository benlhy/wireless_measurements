/////////////////////////////////////////////////////////////////////////////
// joystick.c
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "bsp.h"
#include "joystick.h"

/////////////////////////////////////////////////////////////////////////////
// Global Functions
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
// JOYSTICK_convert_mv_to_direction
//-----------------------------------------------------------------------------
//
// Converts ADC voltage (in mV) to cardinal/secondary direction. Direction is
// saved to joystickDirection global.
//
// This function should be called after a new ADC sample is ready.
//
// This function calls Voltmeter_direction_isr(), a 2nd level interrupt defined
// in the demo.
//
// mV - joystick voltage in millivolts (0 - 3300)
//
//-----------------------------------------------------------------------------
uint8_t JOYSTICK_convert_mv_to_direction(uint32_t mV)
{
    uint8_t joystickDirection;

    // determine which direction pad was pressed
    if ((mV <= JOYSTICK_MV_C + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_C;
    }
    else if ((mV >= JOYSTICK_MV_N - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_N + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_N;
    }
    else if ((mV >= JOYSTICK_MV_E - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_E + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_E;
    }
    else if ((mV >= JOYSTICK_MV_S - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_S + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_S;
    }
    else if ((mV >= JOYSTICK_MV_W - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_W + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_W;
    }
#if JOYSTICK_DIRECTIONS == CARDINAL_AND_SECONDARY
    else if ((mV >= JOYSTICK_MV_NE - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_NE + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_NE;
    }
    else if ((mV >= JOYSTICK_MV_NW - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_NW + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_NW;
    }
    else if ((mV >= JOYSTICK_MV_SE - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_SE + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_SE;
    }
    else if ((mV >= JOYSTICK_MV_SW - JOYSTICK_MV_ERROR) && \
             (mV <= JOYSTICK_MV_SW + JOYSTICK_MV_ERROR))
    {
      joystickDirection = JOYSTICK_SW;
    }
#endif
    else
    {
      joystickDirection = JOYSTICK_NONE;
    }

    return joystickDirection;
}
