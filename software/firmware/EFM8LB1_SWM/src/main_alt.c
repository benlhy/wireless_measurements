//-----------------------------------------------------------------------------
// EFM8UB1_ADC_Lib_Polled.c
//-----------------------------------------------------------------------------
// Copyright 2016 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// This example demonstrates using the EFM8 ADC peripheral driver library to
// sample a voltage in polled mode.
//
// The analog multiplexer selects P1.7 as the positive ADC0 input. This pin is
// configured as an analog input in the port initialization routine. The
// negative ADC0 input is connected via mux to ground, which provides for a
// single-ended ADC input.
//
// An analog joystick is connected to P1.7. Each joystick position corresponds
// to a unique voltage.
//
// Inside the main loop, the ADC is triggered to start a conversion. The
// device then waits in the main loop until the ADC conversion is complete.
// The sampled voltage is then converted into a joystick direction, which,
// in turn, is used to turn on LEDs to make a particular color.
//
// Resources:
//   SYSCLK - 24.5 MHz HFOSC0 / 1
//   ADC    - 10-bit, VREF = Internal 1.65 VREF / 0.5  (3.3V)
//   P1.4   - Green LED
//   P1.5   - Blue LED
//   P1.6   - Red LED
//   P1.7   - Joystick
//   P2.0   - Board Controller enable
//   P2.3   - Display enable
//
//-----------------------------------------------------------------------------
// How To Test: EFM8UB1 STK
//-----------------------------------------------------------------------------
// 1) Place the switch in "AEM" mode.
// 2) Connect the EFM8UB1 STK board to a PC using a mini USB cable.
// 3) Compile and download code to the EFM8UB1 STK board.
//    In Simplicity Studio IDE, select Run -> Debug from the menu bar,
//    click the Debug button in the quick menu, or press F11.
// 4) Run the code.
//    In Simplicity Studio IDE, select Run -> Resume from the menu bar,
//    click the Resume button in the quick menu, or press F8.
// 5) Move the joystick. LED0 will change color based on the joystick's position:
//      UP    - White
//      LEFT  - Blue
//      DOWN  - Green
//      RIGHT - Red
//
// Target:         EFM8UB1
// Tool chain:     Generic
//
// Release 0.1 (BL;AT)
//    - Initial Revision
//    - 08 JAN 2016
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8UB1_Register_Enums.h>
#include "InitDevice.h"
#include "adc_0.h"
#include "joystick.h"
#include "retargetserial.h"
#include <stdint.h>

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P2, 3);         // Display Enable
#define DISP_BC_DRIVEN   0            // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1            // 1 = EFM8 drives display

SI_SBIT (BC_EN, SFR_P2, 0);           // Board Controller Enable
#define BC_DISCONNECTED 0             // 0 = Board Controller disconnected
                                      //     to EFM8 UART pins
#define BC_CONNECTED    1             // 1 = Board Controller connected
                                      //     to EFM8 UART pins

SI_SBIT(GREEN_LED, SFR_P1, 4);        // Green LED
SI_SBIT(BLUE_LED, SFR_P1, 5);         // Blue LED
SI_SBIT(RED_LED, SFR_P1, 6);          // Red LED

#define LED_ON  (0)
#define LED_OFF (1)

//-----------------------------------------------------------------------------
// ADC Defines
//-----------------------------------------------------------------------------
#define VREF_MV         (3300UL)
#define ADC_MAX_RESULT  ((1 << 10)-1) // 10 bit ADC

//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
uint16_t ADC0_convertSampleToMillivolts(uint16_t sample);
void ConvertDirectionToColor(uint8_t dir);
void ChangeADCPin(uint8_t pin);

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // Disable the watchdog here
}

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{
  uint16_t mV;
  uint8_t joystickDir;
  uint8_t SFRPAGE_save;
  static uint32_t accumulator = 0;
  static uint16_t measurements = 2048; // Measurement counter
  uint32_t result = 0; // need to define before anything else otherwise error : https://stackoverflow.com/questions/34071199/keil-for-c51-and-have-some-problems-with-error-like-syntax-error-near-unsigned
  enter_DefaultMode_from_RESET();
  DISP_EN = DISP_BC_DRIVEN;           // Display not driven by EFM8
  BC_EN = BC_CONNECTED;
  SCON0_TI = 1;
  IE_EA = 1;


  while (1)
  {
    //Start conversion
    int i = 0;
    for ( i=0;i<4;i++) {
    //ADC0MX_ADC0MX__ADC0P11      0x0B ///< Select ADC0.11. --
    //ADC0MX_ADC0MX__ADC0P12      0x0C ///< Select ADC0.12. -- Reference, P1.4 (5)
    //ADC0MX_ADC0MX__ADC0P13      0x0D ///< Select ADC0.13.    P1.5 (7)
    //ADC0MX_ADC0MX__ADC0P14      0x0E ///< Select ADC0.14.    P1.6 (9)
    //ADC0MX_ADC0MX__ADC0P15      0x0F ///< Select ADC0.15.    P1.7 (NC)

        switch(i){
          case 0:
            ADC0MX = ADC0MX_ADC0MX__ADC0P15;
            break;
          case 1:
            ADC0MX = ADC0MX_ADC0MX__ADC0P14;
            break;
          case 2:
            ADC0MX = ADC0MX_ADC0MX__ADC0P13;
            break;
          case 3:
            ADC0MX = ADC0MX_ADC0MX__ADC0P12;
            break;
          default:
            break;
        }
        measurements = 2048;
        accumulator = 0;




        while (measurements>0) {
            ADC0_startConversion();

            // Wait for conversion to complete
            while (!ADC0_isConversionComplete());
            accumulator += ADC0_getResult();
            measurements--;


        }
        result = accumulator / 2048;


      // Convert sample to mV
      mV = ADC0_convertSampleToMillivolts(result);

      // Get joystick direction from ADC sample
      joystickDir = JOYSTICK_convert_mv_to_direction(mV);
      SFRPAGE_save = SFRPAGE; // save the content of the SFR Page
      SFRPAGE = LEGACY_PAGE; // go to the first page
      RETARGET_PRINTF ("\n voltage: %ld mV\n", mV); // writing to some SFR?
      SFRPAGE = SFRPAGE_save; // restore the content of the SFR Page

      // Convert joystick direction to LED color
      //ConvertDirectionToColor(joystickDir);
    }

  }
}

///////////////////////////////////////////////////////////////////////////////
// Supporting Functions
///////////////////////////////////////////////////////////////////////////////

/*
 * Select the adc pin
 */
void ChangeADCPin(uint8_t pin) {
  ADC0MX = ADC0MX_ADC0MX__ADC0P15;
}




//-----------------------------------------------------------------------------
// ADC0_convertSampleToMillivolts
//-----------------------------------------------------------------------------
//
// Converts a raw ADC sample to millivolts.
// sample - the raw sample from the ADC
//
// returns - a two byte number representing the adc sample in millivolts
//  e.g. 1.65V would equal 1650.
//
uint16_t ADC0_convertSampleToMillivolts(uint16_t sample)
{
  // The measured voltage applied to P1.7 is given by:
  //
  //                           Vref (mV)
  //   measurement (mV) =   --------------- * result (bits)
  //                       (2^10)-1 (bits)
  return ((uint32_t)sample * VREF_MV) / ADC_MAX_RESULT;
}





//-----------------------------------------------------------------------------
// ConvertDirectionToColor
//-----------------------------------------------------------------------------
//
// Turns on LEDs depending on the joystick direction given
//
// dir -  JOYSTICK_N = White
//        JOYSTICK_E = Red
//        JOYSTICK_S = Green
//        JOYSTICK_W = Blue
//        Any other direction = Off
//
void ConvertDirectionToColor(uint8_t dir)
{
  GREEN_LED = LED_OFF;
  BLUE_LED  = LED_OFF;
  RED_LED   = LED_OFF;

  switch (dir)
  {
  case JOYSTICK_N:
    GREEN_LED = LED_ON;
    BLUE_LED  = LED_ON;
    RED_LED   = LED_ON;
    break;

  case JOYSTICK_E:
    RED_LED   = LED_ON;
    break;

  case JOYSTICK_S:
    GREEN_LED = LED_ON;
    break;

  case JOYSTICK_W:
    BLUE_LED  = LED_ON;
    break;

  default:
    break;
  }
}
