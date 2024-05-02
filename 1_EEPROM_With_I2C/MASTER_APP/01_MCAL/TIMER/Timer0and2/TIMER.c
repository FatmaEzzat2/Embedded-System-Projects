/*
 * TIMER.c
 *
 *  Created on: Mar 21, 2024
 *      Author: KimoStore
 */

#include"TIMER.h"

#define CLEAR_TYPE_MASK     0xcf
#define SHIFT_COM_BITS       4


//static u32 TickCounter =0;

#if (TIMER_CONFIGURATION == PRECOMPILE)
/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 *
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */

void TMR0_voidInitPreCompile(void){
	/*Timer Mode*/
	TCCR0 |= TIMER_MODE;

	/*Enable Interrupt */
	TIMSK |=(INT_MODE<<OCIE0);     /*Enable Overflow Interrupt*/
	TIMSK |=(INT_MODE<<TOIE0);		/*Enable Compare match Interrupt*/
}

#elif (TIMER_CONFIGURATION == POSTCOMPILE)
/**
 * @brief Initialize the Timer 0 (TMR0) driver with user-provided configuration.
 *
 * @param Copy_strTimerConfig Pointer to a TMR0Config_t structure that contains the desired timer configuration.
 * @return TMR0_enuErrorStatus_t Error status of the initialization process.
 *
 * This function allows for post-compilation initialization of the TMR0 module, enabling the user to
 * specify a configuration at run-time.
 */
TMR0_enuErrorStatus_t TMR0_voidInitPostCompile(TMR0Config_t *Copy_strTimerConfig){

	/*-----------------------------Validation----------------------------------*/
	TMR0_enuErrorStatus_t returnError  = TIMER0_enumNOk;

	if(Copy_strTimerConfig ==NULL){
		returnError = TIMER0_enumNullPOinter;
	}
	else if((Copy_strTimerConfig->timerMode < Timer_OverFlow_Mode)||(Copy_strTimerConfig->timerMode > Timer_FastPWM_Mode)){
		returnError =TIMER0_enuWrongMode;

	}else if((Copy_strTimerConfig->interruptMode.OverFlow_Interrupt != INT_Enable)&&
	         (Copy_strTimerConfig->interruptMode.OverFlow_Interrupt != INT_Disable)&&
			 (Copy_strTimerConfig->interruptMode.CTC_Interrupt      != INT_Enable) &&
			 (Copy_strTimerConfig->interruptMode.CTC_Interrupt      != INT_Disable)){

			returnError = TIMER0_enuWrongMode;

	}else{

		returnError =TIMER0_enumOk;
		/*-----------------------------Implementation--------------------------------*/
		/*1- Activate Timer Mode*/
		TCCR0 |= Copy_strTimerConfig->timerMode;

		/*2- Activate Interrupt*/
		TIMSK |=(Copy_strTimerConfig->interruptMode.OverFlow_Interrupt<<TOIE0);
		TIMSK |=(Copy_strTimerConfig->interruptMode.CTC_Interrupt<<OCIE0);
	}
	return returnError;
}
#endif
/**
 * @brief Start Timer 0 to begin counting.
 *
 * @return TMR0_enuErrorStatus_t Error status of the start process.
 *
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
void TMR0_enuStart(void){
	TCCR0 |= TIMER0_PRESCALER;
}

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
//TMR0_enuErrorStatus_t TMR0_enuSetTickTimeMS(u8 Copy_u8DesiredTime, u8 Copy_u8InterruptSource){
//
//
//
//
//}

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
TMR0_enuErrorStatus_t TMR0_enuSetDutyCycleFastPWM(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType){

	/*-----------------------------Validation----------------------------------*/
	TMR0_enuErrorStatus_t returnError =TIMER0_enumNOk;

	if ((Copy_u8DutyCycle<0)||(Copy_u8DutyCycle>100))
	{
		returnError=TIMER0_enuWrongDutyCycle;

	}
	else if((Copy_u8PWMType!=INVERTING_MODE)&&(Copy_u8PWMType!=NON_INVERTING_MODE)){
		returnError =TIMER0_enuWrongPWMType;
	}else{
		returnError =TIMER0_enumOk;
	/*-----------------------------Implementation----------------------------------*/
	/*OC0 as an output*/
	DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin3,DIO_enumOutputLOW);

	OCR0 =0;

	u8 TCCR0_temp = TCCR0;
	TCCR0_temp &=CLEAR_TYPE_MASK;

	switch (Copy_u8PWMType)
	{
		case INVERTING_MODE:
		TCCR0_temp |= (INVERTING_MODE<<SHIFT_COM_BITS);
		OCR0 = (Copy_u8DutyCycle *256)/100;
		break;
		case NON_INVERTING_MODE:
		TCCR0_temp |= (NON_INVERTING_MODE<<SHIFT_COM_BITS);
		OCR0 = ((1-Copy_u8DutyCycle)*256)/100;
		break;
	}
	TCCR0 =TCCR0_temp;

	}
	return returnError;
}

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
TMR0_enuErrorStatus_t TMR0_enuSetDutyCyclePhaseCorrection(u8 Copy_u8DutyCycle, u8 Copy_u8PWMType){

		/*-----------------------------Validation----------------------------------*/
		TMR0_enuErrorStatus_t returnError =TIMER0_enumNOk;

		if ((Copy_u8DutyCycle<0)||(Copy_u8DutyCycle>100))
		{
			returnError=TIMER0_enuWrongDutyCycle;
		}
		else if((Copy_u8PWMType!=INVERTING_MODE)&&(Copy_u8PWMType!=NON_INVERTING_MODE)){

			returnError =TIMER0_enuWrongPWMType;
		}else{
			returnError =TIMER0_enumOk;
		/*-----------------------------Implementation--------------------------------*/
			/*OC0 as an output*/
			DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin3,DIO_enumOutputLOW);

			OCR0 =0;

			u8 TCCR0_temp = TCCR0;
			TCCR0_temp &=CLEAR_TYPE_MASK;

			switch (Copy_u8PWMType)
			{
				case INVERTING_MODE:
				TCCR0_temp |= (INVERTING_MODE<<SHIFT_COM_BITS);
				OCR0 = (Copy_u8DutyCycle *256)/100;;
				break;
				case NON_INVERTING_MODE:
				TCCR0_temp |= (NON_INVERTING_MODE<<SHIFT_COM_BITS);
				OCR0 = ((100-Copy_u8DutyCycle)*256)/100;
				break;
			}
			TCCR0 =TCCR0_temp;

		}
		return returnError;
}



