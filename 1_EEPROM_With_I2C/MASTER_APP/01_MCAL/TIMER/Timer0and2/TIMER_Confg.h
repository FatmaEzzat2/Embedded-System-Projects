/*
 * TIMER_Confg.h
 *
 * Created: 3/14/2024 10:22:01 AM
 *  Author: KimoStore
 */ 


#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_


/*Choose Timer Configuration*/
#define PRECOMPILE  0
#define POSTCOMPILE 1

#define TIMER_CONFIGURATION  PRECOMPILE



/*Choose Timer Mode*/
#define NORMAL_MODE            0x00
#define PHASE_CORRESCT_MODE    0x40
#define CTC_MODE               0x08
#define FAST_PWM_MODE          0x48

#define TIMER_MODE    PHASE_CORRESCT_MODE

/*Choose The Pre_Scalar of the clock*/
#define No_CLOCK            0
#define No_PRESCALAER       1
#define _8_PRESCALAER       2
#define _64_PRESCALAER      3
#define _256_PRESCALAER     4
#define _1024_PRESCALAER    5
#define EXT_FALLING         6
#define EXT_RISING          7

#define TIMER0_PRESCALER  _8_PRESCALAER

/*Choose PWM MODE*/
#define INVERTING_MODE       3
#define NON_INVERTING_MODE   2

/*Choose Interrupt mode*/
#define INTTRUPT_DISABLE  0
#define INTTRUPT_ENABLE   1

#define INT_MODE    INTTRUPT_ENABLE

#if(TIMER_CONFIGURATION == POSTCOMPILE) 


/*Timer Modes*/
typedef enum{
	/*Over Flow Mode*/
	Timer_OverFlow_Mode=0x00,
	
	/*Phase Correct Mode*/
	Timer_PhasePWM_Mode=0x40,
	
	/*Compare Match Clear on Mode*/
	Timer_CTC_Mode=0x08,
	
	/*Fast PWM Mode*/
	Timer_FastPWM_Mode=0x48

}Timer_Mode_t;


/*Timer Prescalers*/

typedef enum{
		/*Timer Mode*/
		/*Timer stops*/
		 No_Clock=0, 
		    
		 /*There is no prescaler*/    
		 No_Prescaler, 
		 
		 /*Divide System Clock by 8*/   
		 _8_Prescaler,  
		 
		 /*Divide System Clock by 64*/   
		 _64_Prescaler, 
		 
		 /*Divide System Clock by 128*/     
		 _256_Prescaler,  
		 
		 /*Divide System Clock by 1024*/   
		 _1024_Prescaler,
		 
		 /*Counter Mode*/ 
		 /*Counter detects a count at falling edge*/
		 EXT_FALLING, 
		 
		 /*Counter detects a count at rising edge*/    
		 EXT_RISING,     
}Timer_ClockSrc_t;

/*Interrupt mode*/
typedef enum {
	INT_Disable=0,
	INT_Enable
}Timer_INT_Mode_t;

typedef struct{
	Timer_INT_Mode_t OverFlow_Interrupt;
	Timer_INT_Mode_t CTC_Interrupt;
}Interrupt_Mode_t;

typedef struct{
	Timer_Mode_t timerMode;
	Timer_ClockSrc_t clockSrc;
	Interrupt_Mode_t  interruptMode;
	
}TMR0Config_t;

#endif
#define _100MS_TICK_TIME  100  
#define _500MS_TICK_TIME  500
#define _1S_TICK_TIME     1000
#define _2S_TICK_TIME     2000
#define _5S_TICK_TIME     5000

 


#endif /* TIMER_CONFG_H_ */