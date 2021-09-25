//-----------------------------------------------------------------------------
// EFM8LB1_ADC_ExternalInput.c
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// This example code takes and averages 2048 analog measurements from input
// P1.7 using ADC0, then prints the results to a terminal window via the UART.
//
// The system is clocked by the internal 24.5 MHz oscillator divided by 1.
// Timer 2 triggers a conversion on ADC0 on each overflow.  The completion of
// this conversion in turn triggers an interrupt service routine (ISR).  The ISR
// averages 2048 measurements, then prints the value to the terminal via printf
// before starting another average cycle.
//
// The analog multiplexer selects P1.7 as the positive ADC0 input. This pin is
// configured as an analog input in the port initialization routine. The
// negative ADC0 input is connected via mux to ground, which provides for a
// single-ended ADC input.
//
// An analog joystick is connected to P1.7. Each joystick position corresponds
// to a unique voltage.
//
// Terminal output is done via printf, which directs the characters to
// UART0.  A UART initialization routine is therefore necessary.
//
// ADC Settling Time Requirements, Sampling Rate:
// ----------------------------------------------
//
// The total sample time per input is comprised of an input setting time
// (Tsettle), followed by a conversion time (Tconvert):
//
// Tsample  = Tsettle + Tconvert
//
// |--------Settling-------|==Conversion==|----Settling--- . . .
// Timer 2 overflow        ^
// ADC0 ISR                               ^
//
// The ADC input voltage must be allowed adequate time to settle before the
// conversion is made.  This settling depends on the external source
// impedance, internal mux impedance, and internal capacitance.
// Settling time is given by:
//
//                   | 2^n |
//    Tsettle =   ln | --- | * Rtotal * Csample
//                   | SA  |
//
// For example, assume Rtotal = 100 kohm. The expression evaluates to:
//
//                   | 2^14 |
//    Tsettle =   ln | ---- | * 105e3 * 5e-12 = 5.82 us
//                   | 0.25 |
//
// In addition, one must allow at least 1.5uS after changing analog mux
// inputs or PGA settings.  The settling time in this example, then, is
// dictated by the large external source resistance.
//
// The conversion time is given in the datasheet (14-bit mode, SAR clock 18 MHz)
// as 0.81 us.
//
// Tsample, minimum  = Tsettle + Tconvert
//                   = 5.82 us + 0.81 us
//                   = 6.63 us
//
// Timer2 is set to start a conversion every 100 us, which is far longer
// than the minimum required.
//
// Resources:
//   SYSCLK - 24.5 MHz HFOSC0 / 1
//   ADC    - 14-bit, VREF = VDD (3.3V)
//   UART0  - 115200 baud, 8-N-1
//   Timer1 - UART0 clock source
//   Timer2 - ADC start of conversion source
//   P0.4   - UART0 TX
//   P0.5   - UART0 RX
//   P2.2   - Board Controller enable
//   P3.4   - Display enable
//
//-----------------------------------------------------------------------------
// How To Test: EFM8LB1 STK
//-----------------------------------------------------------------------------
// 1) Place the switch in "AEM" mode.
// 2) Connect the EFM8LB1 STK board to a PC using a mini USB cable.
// 3) Compile and download code to the EFM8LB1 STK board.
//    In Simplicity Studio IDE, select Run -> Debug from the menu bar,
//    click the Debug button in the quick menu, or press F11.
// 4) On the PC, open HyperTerminal (or any other terminal program) and connect
//    to the JLink CDC UART Port at 115200 baud rate and 8-N-1.
// 5) Run the code.
//    In Simplicity Studio IDE, select Run -> Resume from the menu bar,
//    click the Resume button in the quick menu, or press F8.
// 6) Move the joystick. The terminal program will print the voltage for
//    each joystick position.
//
// Target:         EFM8LB1
// Tool chain:     Generic
//
// Release 0.1 (ST)
//    - Initial Revision
//    - 06 MAR 2015
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>
//#include <stdint.h>
#include <stdio.h>
#include "InitDevice.h"
//#include "retargetserial.h"
#include "vars.h"
#include "uart_0.h"

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P3, 4);          // Display Enable
#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display

SI_SBIT (BC_EN, SFR_P2, 2);            // Board Controller Enable
#define BC_DISCONNECTED 0              // 0 = Board Controller disconnected
                                       //     to EFM8 UART pins
#define BC_CONNECTED    1              // 1 = Board Controller connected
                                       //     to EFM8 UART pins


SI_SBIT(PWRC, SFR_P1, 2);                  // P1.2 PWRC
SI_SBIT(LED, SFR_P1, 0);                  // P1.0 LED
SI_SBIT(HALL, SFR_P0,6);


//SI_SEGMENT_VARIABLE(scale, float, SI_SEG_XDATA);
//float scale;

const uint32_t xdata UUID _at_ 0xFFC3;
//uint8_t id;

void _delay_ms(uint32_t ms);
void _flash_LED();
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
  //id = UUID;
  //id=id&0xFF;
  //id = UUID & 0xFF;


}
#define F_CPU 24500000
#define CPU_DIV 1
#define SYSCLK_MS  ((F_CPU / CPU_DIV) / 1000.0) / 60.0 // Convert to oscillations per ms
#define SYSCLK_US  ((F_CPU / CPU_DIV) / 1000000.0) // Convert to oscillations per us
#define SUBTRACT_MS 7500.0 / 60.0 / CPU_DIV

void _delay_ms(uint32_t ms){
 // Subtract n clock cycles for every ms to account for the time that the loop takes
 uint32_t clockCycles = SYSCLK_MS * ms;
 uint32_t substract = (SUBTRACT_MS * ms) + 34;

 if(clockCycles > substract) clockCycles -= substract;

 while(clockCycles-- > 0){
  _nop_();
 }
}


/*
 * This function sets up the Bluetooth module
 * App Mode
 */

void init_device(void) {

  //uint32_t someval;
  //uint8_t your_id;
  LED = 1;
  PWRC = 0; // set AT mode
  //someval = UUID; // get the UUID

  //your_id = (uint8_t)(UUID & 0xFF); // take only 128 bits of the ID

  _delay_ms(50); // wait for module to respond

  //RETARGET_PRINTF("AT+NAMESWM-%d",(int)your_id); // set the name of the device

  printf("AT+NAMESWM-%d",(int)(uint8_t)(UUID & 0xFF));
#ifdef JDY23
  printf("AT+NAMESWM-%d\r\n",(int)(uint8_t)(UUID & 0xFF));
#endif

  _delay_ms(30); // wait for module to respond
  LED = 0;
  PWRC = 1; // unset AT mode

  // determine the scale and set accordingly
/*
  switch(ADC0CN0 & ADC0CN0_ADGN__FMASK) {
    case ADC0CN0_ADGN__GAIN_0P75:
      scale = 75;
      break;
    case ADC0CN0_ADGN__GAIN_0P5:
      scale = 50;
      break;
    case ADC0CN0_ADGN__GAIN_0P25:
      scale = 25;
      break;
    default:
      scale = 100;

  }
  */
}

void sleep_device(bool BLE_sleep) {
  LED = 1;
  if (BLE_sleep) {
      PWRC = 0; // set AT mode
      //RETARGET_PRINTF("AT+SLEEP2"); // send the BLE module into deep sleep
      printf("AT+SLEEP2");
      _delay_ms(30); // wait for command to be received and for the device to respond
      PWRC = 1; // unset AT mode
  }
  LED = 0;
  PCON1 |= 0x80; // set to SNOOZE - will only be woke by Timer 4
}

void _flash_LED(){
  LED=1;
  _delay_ms(LED_DELAY);
  LED=0;
  _delay_ms(LED_DELAY);
  LED=1;
  _delay_ms(LED_DELAY);
  LED=0;
  _delay_ms(LED_DELAY);
  LED=1;
  _delay_ms(LED_DELAY);
  LED=0;

}


//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{

  uint8_t read_msg;
  bool sleep_flag = false;

   enter_DefaultMode_from_RESET();
   UART0_initStdio();

   DISP_EN = DISP_BC_DRIVEN;           // Display not driven by EFM8

   BC_EN = BC_CONNECTED;               // Board controller connected to EFM8
                                       // UART pins

   SCON0_TI = 1;                       // This STDIO library requires TI to
                                       // be set for prints to occur

   IE_EA = 1;                          // Enable global interrupts
   init_device(); // init device before we start ADC sampling
   //set_device_chars();

   while (1) {
       //if (HALL==1) {
       //    EIE1 |= 0x02; // Enable Portmatch interrupt if HALL is high (released)
                         // And do a bitwise OR operation to set a bit
       //}
       //_delay_ms(2000);
       //PCON0 |= 0x01; // set to IDLE
       //PCON1 |= 0x80; // set to SNOOZE

       read_msg = UART0_read_if_available(); // read UART0 message, non blocking
       if (read_msg != 0) {
           // process it
           printf(&read_msg); // okay
           switch (read_msg) {

             case '1':
               //printf("1 rx");
               // set the high byte and low byte 66534
               //
               _flash_LED(); //indicate message received
               // set to 2 sec wake
               TMR4RLH = (0xFF << TMR4RLH_TMR4RLH__SHIFT);
               TMR4RLL = (0xFE << TMR4RLL_TMR4RLL__SHIFT);
               sleep_flag = true;

               break;
             case '2':
               //printf("2 rx");
               sleep_flag = false;
               break;
             default:
               //printf("other rx");
               //sleep_flag = false;
               break;
           }
       } else {
           // do whatever we have been doing
           if (sleep_flag) {
               _delay_ms(500);

               sleep_device(false);
               PWRC = 0; // turn on the BLE module
               _delay_ms(50); // wait for power on
           }
       }
       while(send_msg!=4); // blocking

       if (send_msg==4) {
           LED = ~LED; // flip the bit

           send_msg = 0;

           // need to typecast:https://www.keil.com/support/man/docs/c51/c51_xf_usingprintf.htm

           printf("%u,%u,%u,%u",(int)adc1,(int)adc2,(int)adc3,(int)adc4);


       }

   }
}
