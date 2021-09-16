/*
 * vars.h
 *
 *  Created on: Aug 10, 2021
 *      Author: lilda
 */

#ifndef INC_VARS_H_
#define INC_VARS_H_


#define MINI
#define W_VER
#define V_REF 2400 // reference voltage
#define SCALE 0.75 // scale that we will use for input voltages



extern volatile int send_msg;
extern volatile int adc1;
extern volatile int adc2;
extern volatile int adc3;
extern volatile int adc4;
extern volatile int multiplier;
extern float R1;
extern float R2;
extern float scale;

#endif /* INC_VARS_H_ */
