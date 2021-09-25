/*
 * vars.h
 *
 *  Created on: Aug 10, 2021
 *      Author: lilda
 */

#ifndef INC_VARS_H_
#define INC_VARS_H_


#define MINI // Board version 2
//#define GUM // Board version 1
//#define NANO

#define JDY08
//#define JDY23

#define W_VER // MAX44834 version
#define V_REF 2400 // reference voltage
#define SCALE 0.75 // scale that we will use for input voltages
#define LED_DELAY 100

// ============= Current sense multipliers =======//

#ifdef W_VER
#define MULTIPLIER 200
#endif

#ifdef H_VER
#define MULTIPLIER 100
#endif

#ifdef F_VER
#define MULTIPLIER 50
#endif

// =========== RESISTOR Values ============== //

#ifdef MINI
#define RESISTOR1 10 // R actual * 10 to avoid any dp
#endif

#ifdef GUM
#define RESISTOR1 30
#define RESISTOR2 56
#endif

// =========== Scaling values ============== //

// when are the values set, before or after init?

/*
#if (ADC0CN0 & ADC0CN0_ADGN__FMASK) == ADC0CN0_ADGN__GAIN_0P75
#define SCALE 75
#endif

#if (ADC0CN0 & ADC0CN0_ADGN__FMASK) == ADC0CN0_ADGN__GAIN_0P5
#define SCALE 50
#endif

#if (ADC0CN0 & ADC0CN0_ADGN__FMASK) == ADC0CN0_ADGN__GAIN_0P25
#define SCALE 25
#endif

#if (ADC0CN0 & ADC0CN0_ADGN__FMASK) == ADC0CN0_ADGN__GAIN_1
#define SCALE 100
#endif
*/

// ========== Extern vars -------------------//

extern volatile int send_msg;
extern volatile int adc1;
extern volatile int adc2;
extern volatile int adc3;
extern volatile int adc4;

//extern float scale;

#endif /* INC_VARS_H_ */
