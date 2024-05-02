/*
 * TIMER1.h
 *
 *  Created on: Mar 21, 2024
 *      Author: KimoStore
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../../00_Lib/Bit_Math.h"
#include "../../../00_Lib/Registers.h"
#include "../../../00_Lib/STD_TYPES.h"
#include "../../../00_Lib/Delay.h"
#include "../../../01_MCAL/DIO/DIO.h"
#include "TIMER1_Confg.h"


#define ENABLE   1
#define DISABLE  0

/*Timer1 Options*/
#define TIMER1A   5
#define TIMER1B   4

typedef enum{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	TIMER_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	TIMER_enumNOk,
	 /**
	 *@brief : Send Null Pointer
	 */
	 TIMER_enumNullPOinter,
	 /**
	 *@brief : Select Wrong DutyCycle
	 */
	 TIMER_enuWrongDutyCycle,
	 /**
	 *@brief : Select wrong Timer Mode
	 */
	 TIMER_enuWrongMode,
	  /**
	 *@brief : Select wrong PWM Type
	 */
	 TIMER_enuWrongPWMType,

}TMR1_enuErrorStatus_t;


/* Function Prototypes */
/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 *
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */
void TMR1_voidInitPreCompile(void);

/**
 * @brief Set the desired tick time and interrupt source for Timer 0.
 *
 * @param Copy_u8DesiredTime The desired tick time, which can be one of the predefined constants:
 *        100MS_TICK_TIME, 500MS_TICK_TIME, 1S_TICK_TIME, 2S_TICK_TIME, 5S_TICK_TIME.
 * @param Copy_u8InterruptSource The interrupt source, which can be either OVERFLOW or COMPARE_MATCH.
 * @return TMR0_enuErrorStatus_t Error status of the tick time setting process.
 *
 * This function configures the tick time for the TMR0 module and specifies whether an interrupt should
 * be generated on an overflow or a compare match event. It returns an error status to indicate the success
 * or nature of any failure in setting the tick time.
 */
//TMR0_enuErrorStatus_t TMR1_enuSetTickTimeMS(u8 Copy_u8DesiredTime, u8 Copy_u8InterruptSource);

/**
 * @brief Start Timer 0 to begin counting.
 *
 * @return TMR1_enuErrorStatus_t Error status of the start process.
 *
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
void TMR1_enuStart(void);

/**
 * @brief Set the duty cycle for Timer 0 in Fast PWM mode.
 *
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 *
 * This function configures the duty cycle for TMR0 when operating in Fast PWM mode. The duty cycle and PWM type
 * are specified by the user. It returns an error status to indicate success or the nature of any failure in setting
 * the duty cycle.
 */
void  TMR1_enuSetDutyCycleFastPWM(u8 Copy_u8SelectTimerOption ,u8 Copy_u8FastPwmType,u8 Copy_u8DutyCycle, u8 Copy_OC1PinMode);

/**
 * @brief Set the duty cycle for Timer 0 in Phase Correct PWM mode.
 *
 * @param Copy_u8DutyCycle The desired duty cycle value.
 * @param Copy_u8PWMType The PWM type, which can be either INVERTED or NON_INVERTED.
 * @return TMR0_enuErrorStatus_t Error status of the duty cycle setting process.
 *
 * This function configures the duty cycle for TMR0 when operating in Phase Correct PWM mode. It allows
 * for finer control of the PWM waveform compared to Fast PWM mode. It returns an error status to indicate
 * the success or nature of any failure in setting the duty cycle.
 */
void TMR1_enuSetDutyCyclePhasePWM(u8 Copy_u8SelectTimerOption ,u8 Copy_u8PhasePwmType,u8 Copy_u8DutyCycle, u8 Copy_OC1PinMode);





#endif /*TIMER1_H_ */
