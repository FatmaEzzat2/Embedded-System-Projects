/*
 * TIMER1_Confg.h
 *
 *  Created on: Mar 21, 2024
 *      Author: KimoStore
 */

#ifndef TIMER1_CONFG_H_
#define TIMER1_CONFG_H_

/*Timer_1 Modes*/

/***************************************/
/*------------TIMER 1 MODES------------*/
/***************************************/
#define TIMER1_MODE0_NORMAL										(0U)
#define TIMER1_MODE1_PWM_PHASE_CORRECT_8BIT						(1U)
#define TIMER1_MODE2_PWM_PHASE_CORRECT_9BIT						(2U)
#define TIMER1_MODE3_PWM_PHASE_CORRECT_10BIT					(3U)
#define TIMER1_MODE4_CTC_TOP_OCR1A								(4U)
#define TIMER1_MODE5_FAST_PWM_8BIT								(5U)
#define TIMER1_MODE6_FAST_PWM_9BIT								(6U)
#define TIMER1_MODE7_FAST_PWM_10BIT								(7U)
#define TIMER1_MODE8_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_ICR1	(8U)
#define TIMER1_MODE9_PWM_PHASE_AND_FREQUENCY_CORRECT_TOP_OCR1A	(9U)
#define TIMER1_MODE10_PWM_PHASE_CORRECT_TOP_ICR1				(10U)
#define TIMER1_MODE11_PWM_PHASE_CORRECT_TOP_OCR1A				(11U)
#define TIMER1_MODE12_CTC_TOP_ICR1								(12U)
#define TIMER1_MODE14_PWM_FAST_PWM_TOP_ICR1						(14U)
#define TIMER1_MODE15_PWM_FAST_PWM_TOP_OCR1A					(15U)

#define TIMER1_MODE    TIMER1_MODE5_FAST_PWM_8BIT

/***************************************/
/*-------PRE SCALER OF TIMER1 CLK------*/
/***************************************/
#define No_CLOCK            0
#define No_PRESCALAER       1
#define _8_PRESCALAER       2
#define _64_PRESCALAER      3
#define _256_PRESCALAER     4
#define _1024_PRESCALAER    5
#define EXT_FALLING         6
#define EXT_RISING          7

#define TIMER1_PRESCALER  _8_PRESCALAER

/***************************************/
/*----COMPARE OUTPUT MODE ->NON-PWM----*/
/***************************************/
#define NORMAL_PORT_OPERATION   		0
#define TOG_OC1AB_ON_COMPARE_MATCH   	1
#define CLR_OC1AB_ON_COMPARE_MATCH   	2
#define SET_OC1AB_ON_COMPARE_MATCH   	3


/***************************************/
/*---COMPARE OUTPUT MODE ->FAST_PWM----*/
/***************************************/
#define NORMAL_PORT_OPERATION   							    	0
#define TOG_OC1A_ON_COMPARE_MATCH_AND_OC1B_NORMAL_PORT_OPERATION	1
#define CLR_OC1AB_ON_COMPARE_MATCH_AND_SET_OC1AB_AT_TOP             2
#define SET_OC1AB_ON_COMPARE_MATCH_AND_CLR_OC1AB_AT_TOP             3

/***************************************/
/*---COMPARE OUTPUT MODE ->PHASE CORRECT & PHASE AND FRQ CORRECT PWM----*/
/***************************************/
#define NORMAL_PORT_OPERATION   							    				0
#define TOG_OC1A_ON_COMPARE_MATCH_AND_OC1B_NORMAL_PORT_OPERATION				1
#define CLR_OC1AB_ON_COMPARE_MATCH_UP_AND__SET_OC1AB_ON_COMPARE_MATCH_DOWN      2
#define SET_OC1AB_ON_COMPARE_MATCH_UP_AND__CLR_OC1AB_ON_COMPARE_MATCH_DOWN	    3


/***************************************/
/*---: INPUT CAPTURE NOISE CANCLER----*/
/***************************************/
#define ACTIVATE_NOISE_CANCLER       1
#define DEACTIVATE_NOISE_CANCLER     0

#define NOISE_CANCLER_MODE   ACTIVATE_NOISE_CANCLER

/***************************************/
/*------INPUT CAPTURE EDGE SELECT------*/
/***************************************/
#define CAPTURE_AT_FALLING_EDGE     0
#define CAPTURE_AT_RISING_EDGE      1

#define CAPTURE_EDGE_SELECT    CAPTURE_AT_RISING_EDGE




#endif /* TIMER1_CONFG_H_ */
