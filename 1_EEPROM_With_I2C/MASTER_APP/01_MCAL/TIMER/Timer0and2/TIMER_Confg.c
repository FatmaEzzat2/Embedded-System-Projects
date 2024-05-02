/*
 * TIMER_Confg.c
 *
 * Created: 3/14/2024 10:21:20 AM
 *  Author: KimoStore
 */ 
#include "../Timer0and2/TIMER.h"
#if (TIMER_CONFIGURATION == POSTCOMPILE)

TMR0Config_t Timer_0 ={
	/*Timer Mode*/
	.timerMode = Timer_CTC_Mode,
	/*Timer Clock*/
	.clockSrc  = _8_Prescaler,
	/*Timer Interrupt*/
	/*Overflow interrupt*/
	.interruptMode.OverFlow_Interrupt = INT_Enable,
	/*CTC interrupt*/
	.interruptMode.CTC_Interrupt = INT_Enable,
};

#endif