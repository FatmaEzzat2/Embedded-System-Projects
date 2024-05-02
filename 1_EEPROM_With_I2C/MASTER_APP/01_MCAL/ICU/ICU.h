/*
 * ICU.h
 *
 *  Created on: Mar 22, 2024
 *      Author: KimoStore
 */

#ifndef ICU_H_
#define ICU_H_

#include "../../00_Lib/STD_TYPES.h"
#include "../../00_Lib/Registers.h"
#include "avr/interrupt.h"
#include "../../02_HAL/LED/LED.h"

#define TIMER_MODE_MASK    0b0000

#define ENABLE      1
#define DISABLE 	0

/*Input Capture Edge Select*/
#define FALLING_EDGE 	0b10111111
#define RISING_EDGE 	0b01000000



void Icu_vidInit(void);

void Icu_vidCalculations(u16* DutyCycle,u16* Frequency);

void Icu_vidEnableInterrupt(void);

void Icu_vidDisableInterrupt(void);

void Icu_vidChangeTrigger(u8 Copy_u8TriggerSource);

void Icu_vidReadValue(u16* Add_pu16Value);



#endif /* 01_MCAL_ICU_ICU_H_ */
