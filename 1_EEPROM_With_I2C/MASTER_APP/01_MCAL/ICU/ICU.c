/*
 * ICU.c
 *
 *  Created on: Mar 22, 2024
 *      Author: KimoStore
 */


#include "ICU.h"


#define GET_2BITS_MASK  0x03
#define CLR_MASK_REG    0x00
#define CLER_FLAG         1

#define PRESCALER_8     2

#define F_CPU 8000000UL


void Icu_vidInit(void){
/*1- Configure Timer1 in Overflow mode */
	TCCR1A = 0;
/*2- Clear ICF (Input Capture flag)  */
	TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */



/*3-Activate Noise Canceler Mode*/
	 TCCR1B |=(ENABLE<<ICNC1);

/*4-Initial Capture Edge Select*/
	 /*Trigger at Rising Edge*/
	 TCCR1B |=(0<<ICES1);

/*5- Select Prescaler of Timer1*/
	 TCCR1B |=(PRESCALER_8<<CS10);

}

void Icu_vidEnableInterrupt(void){

	 TIMSK |=(ENABLE<<TICIE1);

}

void Icu_vidDisableInterrupt(void){
	 TIMSK |=(DISABLE<<TICIE1);
}

void Icu_vidChangeTrigger(u8 Copy_u8TriggerSource){

	switch(Copy_u8TriggerSource){

		case FALLING_EDGE:
			TCCR1B &=(FALLING_EDGE);
			break;
		case RISING_EDGE:
			TCCR1B |=(RISING_EDGE);
			break;
	}
}

void Icu_vidReadValue(u16* Add_pu16Value){
	if(Add_pu16Value){
		*Add_pu16Value=ICR1;
	}
}

void Icu_vidCalculations(u16* DutyCycle,u16* Frequency){

		u16 firstRisingValue  = 0;
		u16 firstFallingValue = 0;
		u16 secondRisingValue = 0;
		u16 ON_Time = 0;
		u16 TotalPeriod =0;

			TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag)  */

			Icu_vidChangeTrigger(RISING_EDGE);
			while ((TIFR&(1<<ICF1)) == 0);
			Icu_vidReadValue(&firstRisingValue);
			TIFR |= (CLER_FLAG<<ICF1);

			Icu_vidChangeTrigger(FALLING_EDGE);
			while ((TIFR&(1<<ICF1)) == 0);
			Icu_vidReadValue(&firstFallingValue);
			TIFR |= (CLER_FLAG<<ICF1);

			Icu_vidChangeTrigger(RISING_EDGE);
			while ((TIFR&(1<<ICF1)) == 0);
			Icu_vidReadValue(&secondRisingValue);
			TIFR |= (CLER_FLAG<<ICF1);


			if(firstRisingValue<firstFallingValue && firstFallingValue<secondRisingValue)  	/* Check for valid condition,
							          to avoid timer overflow reading */
			{
			ON_Time     =  firstFallingValue - firstRisingValue;
			TotalPeriod =  secondRisingValue - firstRisingValue;
			*DutyCycle  =  ((float)ON_Time/TotalPeriod)*100;
			*Frequency=     F_CPU/(TotalPeriod*8ul);

			}

}

