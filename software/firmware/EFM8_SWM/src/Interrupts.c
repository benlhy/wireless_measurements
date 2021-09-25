//=========================================================
// src/Interupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES			
#include <SI_EFM8LB1_Register_Enums.h>
#include "vars.h"

volatile int send_msg;
volatile uint32_t adc1;
volatile uint32_t adc2;
volatile uint32_t adc3;
volatile uint32_t adc4;


SI_SBIT(PWRC, SFR_P1, 2);                  // P1.2 PWRC
SI_SBIT(LED, SFR_P1, 0);// P1.0 LED

//SI_SBIT(IDLE,PCON0,0);// set IDLE mode
//SI_SBIT(SNOOZE,PCON1,7);// set SNOOZE mode

SI_SBIT (HALL, SFR_P0, 6);// port match pin

//-----------------------------------------------------------------------------
// ADC0EOC_ISR
//-----------------------------------------------------------------------------
//
// ADC0EOC ISR Content goes here. Remember to clear flag bits:
// ADC0CN0::ADINT (Conversion Complete Interrupt Flag)
//
// This ISR averages 2048 samples then prints the result to the terminal.  The
// ISR is called after each ADC conversion which is triggered by Timer2.
//
//-----------------------------------------------------------------------------
SI_INTERRUPT(ADC0EOC_ISR, ADC0EOC_IRQn)
  {
    static uint32_t accumulator = 0;     // Accumulator for averaging
    static uint16_t measurements = 2048;// Measurement counter
    uint32_t result = 0;
    uint32_t mV;// Measured voltage in mV
    uint32_t uA;

    //uint8_t SFRPAGE_save;

    //LED=1; // turn on the LED

    // Select a pin

    switch(send_msg)
      {
        case 0:
        ADC0MX = ADC0MX_ADC0MX__ADC0P13; // select ADC13- P1.7
        break;
        case 1:
        ADC0MX = ADC0MX_ADC0MX__ADC0P12;// select ADC12- P1.6
        break;
        case 2:
        ADC0MX = ADC0MX_ADC0MX__ADC0P11;// select ADC11- P1.5
        break;
        case 3:
        ADC0MX = ADC0MX_ADC0MX__ADC0P10;// select ADC10- P1.4
        break;
        default:
        break;
      }

    accumulator += ADC0;
    measurements--;

    if(measurements == 0)
      {
        measurements = 2048;
        result = accumulator / 2048;
        accumulator = 0;

        // The 14-bit ADC value is averaged across 2048 measurements.
        // The measured voltage applied to P1.7 is then:
        //
        //                           Vref (mV)
        //   measurement (mV) =   --------------- * result (bits)
        //                       (2^14)-1 (bits)

        mV = (result * 3300) / 16383;


        switch(send_msg)
          {
            case 0:
              uA = (uint32_t)((result * 2400) / (16383*scale/100) * 1000 / (MULTIPLIER*RESISTOR1/10));
              adc1 = uA;
              break;
            case 1:
#ifdef GUM
              uA = (result * 3277) / 16383 * 1000 / (200*RESISTOR1/10);
              adc2 = uA;
#endif
#ifdef MINI
              adc2= (uint32_t)((result * 2400) / (16383*scale/100));// convert to mV so no decimals
#endif
              break;
            case 2:
              adc3 = mV;
#ifdef MINI
              adc3= (uint32_t)((result * 2400) / (16383*scale/100)); // convert to mV so no decimals
#endif
            break;
            case 3:
            adc4 = mV;
#ifdef MINI
	         // high voltage element 110k/10k
           // V_high * 10 / (110 + 10 ) = V_measured
            adc4 = (uint32_t)(result*2400/(16383*scale/100) * 120/10 ); // measured in mV
#endif

            break;
            default:
            break;
          }
        send_msg++; // increment count

        //SFRPAGE_save = SFRPAGE;
        //SFRPAGE = LEGACY_PAGE;
        //RETARGET_PRINTF ("\nP1.7 voltage: %ld mV\n", mV);
        //SFRPAGE = SFRPAGE_save;
        //LED = 0; // turn off the LED
      }

    ADC0CN0_ADINT = 0;              // Clear ADC0 conv. complete flag
  }

//-----------------------------------------------------------------------------
// PMATCH_ISR
//-----------------------------------------------------------------------------
//
// PMATCH ISR Content goes here. Remember to clear flag bits:

//
//-----------------------------------------------------------------------------

SI_INTERRUPT (PMATCH_ISR, PMATCH_IRQn)
  {
    //RETARGET_PRINTF ("\nPort Match Interrupt fired");
    // TODO: check if it is the pin we care about
    if (false)
      {
        PWRC = 0; // wake BLE module
        SFRPAGE = LEGACY_PAGE;
        //EIE1 &= ~0x02; // disable Port Match interrupt
      }
    EIE1 &= ~0x02; // disable Port Match interrupt
  }

//-----------------------------------------------------------------------------
// TIMER4_ISR
//-----------------------------------------------------------------------------
//
// TIMER4 ISR Content goes here. Remember to clear flag bits:
// TMR4CN0::TF4H (Timer # High Byte Overflow Flag)
// TMR4CN0::TF4L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER4_ISR, TIMER4_IRQn)
  {

  }

