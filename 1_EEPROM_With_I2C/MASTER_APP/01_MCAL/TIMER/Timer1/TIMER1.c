/*
 * TIMER1.c
 *
 *  Created on: Mar 21, 2024
 *      Author: KimoStore
 */


#include"TIMER1.h"

#define GET_2BITS_MASK  0x03
#define CLR_MASK_REG    0x00

u16 two_power (u8 num)
{
    u16 result=1;
    for (u8 i=0;i<num;i++)
    {
        result*=2;
    }
    return result;
}
/**
 * @brief Initialize the Timer 0 (TMR0) driver with pre-compiled settings.
 *
 * This function performs the initialization of the TMR0 module with a predefined configuration.
 * It should be called before any other TMR0-related functions to ensure the timer is set up correctly.
 */
void TMR1_voidInitPreCompile(void){

	u8 TCCR1A_Temp = TCCR1A;
	u8 TCCR1B_Temp = TCCR1B;

	/*Select Timer Mode*/
	/*Set the first 2 bits in TCCR1A*/
	TCCR1A_Temp &= CLR_MASK_REG;
	TCCR1A_Temp |= ((TIMER1_MODE & GET_2BITS_MASK )<<WGM10);

	/*Set the Second 2 bits in TCCR1A*/
	TCCR1B_Temp &= CLR_MASK_REG;
	TCCR1B_Temp |= ((TIMER1_MODE>>2)<<WGM12);

	TCCR1A =TCCR1A_Temp;
	TCCR1B =TCCR1B_Temp;

	/*Enable Interrupts */

	/*Enable Timer1, Output Compare A Match Interrupt*/
	TIMSK |=(ENABLE << OCIE1A);
	/*Enable Timer1, Output Compare B Match Interrupt*/
	TIMSK |=(ENABLE << OCIE1B);
	/*Enable Timer1,Overflow Interrupt*/
	TIMSK |=(ENABLE << TOIE1);

	/*4- Select input capture noise canceler mode-*/
	//TCCR1B |= (NOISE_CANCLER_MODE<<ICNC1);

}
/**
 * @brief Start Timer 0 to begin counting.
 *
 * @return TMR1_enuErrorStatus_t Error status of the start process.
 *
 * This function activates TMR0 to start counting based on the previously configured settings.
 * It returns an error status to indicate the success or nature of any failure in starting the timer.
 */
void TMR1_enuStart(void){
	/*Select clock source of Timer1*/
		u8 TCCR1B_Temp = TCCR1B;
		TCCR1B_Temp &= CLR_MASK_REG;
		TCCR1B_Temp |= TIMER1_PRESCALER ;
		TCCR1B =TCCR1B_Temp;
}

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
void TMR1_enuSetDutyCycleFastPWM(u8 Copy_u8SelectTimerOption ,u8 Copy_u8FastPwmType,u8 Copy_u8DutyCycle, u8 Copy_OC1PinMode){

     /*Configure OC1A/B pin as an output*/
	 DIO_enumSetPinConfig(DIO_enumPortD,Copy_u8SelectTimerOption,DIO_enumOutputLOW);
	 u16 overflowValue = 0;

	 /*Handle only three cases*/
if((Copy_u8FastPwmType == TIMER1_MODE5_FAST_PWM_8BIT)||
   (Copy_u8FastPwmType == TIMER1_MODE6_FAST_PWM_9BIT)||
   (Copy_u8FastPwmType == TIMER1_MODE7_FAST_PWM_10BIT)){

	/*Get Over flow value according to Timer Resolution*/
	/*Subtract 1 bec It starts counting form 0*/
	 switch(Copy_u8FastPwmType){

	 case TIMER1_MODE5_FAST_PWM_8BIT:
		 overflowValue =two_power(8)-1;
		 break;

	 case TIMER1_MODE6_FAST_PWM_9BIT:
		 overflowValue =two_power(9)-1;
	 		 break;

	 case TIMER1_MODE7_FAST_PWM_10BIT:
		 overflowValue =two_power(10)-1;
	 		 break;
	 }

	switch(Copy_u8SelectTimerOption){

		case TIMER1A :
			 /*1-Activate Mode*/
			TCCR1A |= (Copy_OC1PinMode <<COM1A0);

			 /*2-Assign OCR value*/
			 switch(Copy_OC1PinMode){
			  	  case SET_OC1AB_ON_COMPARE_MATCH_AND_CLR_OC1AB_AT_TOP:

			  		  OCR1A = ((100-Copy_u8DutyCycle)*overflowValue)/100;
			  		  break;
			  	  case CLR_OC1AB_ON_COMPARE_MATCH_AND_SET_OC1AB_AT_TOP:
			  		  OCR1A = (Copy_u8DutyCycle*overflowValue)/100;
			  		  break;
				 }
		    break;
		case TIMER1B:
			 /*1-Activate Mode*/
			TCCR1A |= (Copy_OC1PinMode <<COM1B0);

			/*2-Assign OCR value*/
			 switch(Copy_OC1PinMode){
			 	 case SET_OC1AB_ON_COMPARE_MATCH_AND_CLR_OC1AB_AT_TOP:

					 OCR1B = ((100-Copy_u8DutyCycle)*overflowValue)/100;
					 break;
				case CLR_OC1AB_ON_COMPARE_MATCH_AND_SET_OC1AB_AT_TOP:
					 OCR1B = (Copy_u8DutyCycle*overflowValue)/100;
			 		 break;
			 }
			break;
	}
 }

}
void TMR1_enuSetDutyCyclePhasePWM(u8 Copy_u8SelectTimerOption ,u8 Copy_u8PhasePwmType,u8 Copy_u8DutyCycle, u8 Copy_OC1PinMode){

     /*Configure OC1A/B pin as an output*/
	 DIO_enumSetPinConfig(DIO_enumPortD,Copy_u8SelectTimerOption,DIO_enumOutputLOW);
	 u16 overflowValue = 0;

	 /*Handle only three cases*/
  if((Copy_u8PhasePwmType == TIMER1_MODE1_PWM_PHASE_CORRECT_8BIT)||
	 (Copy_u8PhasePwmType == TIMER1_MODE2_PWM_PHASE_CORRECT_9BIT)||
	 (Copy_u8PhasePwmType == TIMER1_MODE3_PWM_PHASE_CORRECT_10BIT)){

	 /*Get Over flow value according to Timer Resolution*/
	 /*Subtract 1 bec It starts counting form 0*/
	 switch(Copy_u8PhasePwmType){

	 case TIMER1_MODE1_PWM_PHASE_CORRECT_8BIT:
		 overflowValue =two_power(8)-1;
		 break;

	 case TIMER1_MODE2_PWM_PHASE_CORRECT_9BIT:
		 overflowValue =two_power(9)-1;
	 		 break;

	 case TIMER1_MODE3_PWM_PHASE_CORRECT_10BIT:
		 overflowValue =two_power(10)-1;
	 		 break;
	 }

	switch(Copy_u8SelectTimerOption){

		case TIMER1A :
			 /*1-Activate Mode*/
			TCCR1A |= (Copy_OC1PinMode <<COM1A0);

			 /*2-Assign OCR value*/
			 switch(Copy_OC1PinMode){
			  	  case SET_OC1AB_ON_COMPARE_MATCH_UP_AND__CLR_OC1AB_ON_COMPARE_MATCH_DOWN:

			  		  OCR1A = ((100-Copy_u8DutyCycle)*overflowValue)/100;
			  		  break;
			  	  case CLR_OC1AB_ON_COMPARE_MATCH_UP_AND__SET_OC1AB_ON_COMPARE_MATCH_DOWN:
			  		  OCR1A = (Copy_u8DutyCycle*overflowValue)/100;
			  		  break;
				 }
		    break;

		case TIMER1B:
			 /*1-Activate Mode*/
			TCCR1A |= (Copy_OC1PinMode <<COM1B0);

			/*2-Assign OCR value*/
			 switch(Copy_OC1PinMode){
			 	 case SET_OC1AB_ON_COMPARE_MATCH_UP_AND__CLR_OC1AB_ON_COMPARE_MATCH_DOWN:

					 OCR1B = ((100-Copy_u8DutyCycle)*overflowValue)/100;
					 break;
				case CLR_OC1AB_ON_COMPARE_MATCH_UP_AND__SET_OC1AB_ON_COMPARE_MATCH_DOWN:
					 OCR1B = (Copy_u8DutyCycle*overflowValue)/100;
			 		 break;
			 }
			break;
	}
  }

}

