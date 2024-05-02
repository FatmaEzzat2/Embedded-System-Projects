/*
 * _7_SEG_Confg.h
 *
 * Created: 12/18/2023 5:42:32 PM
 *  Author: FatmaEzzat
 */ 


#ifndef _7_SEG_CONFG_H_
#define _7_SEG_CONFG_H_
#include "../../01_MCAL/DIO/DIO.h"

#define NUM_OF_7SEG   1
#define NUM_OF_PINS_IN_ONE_SEG   8 

/*Names of Seven Segment*/
#define _7_SEG1       0
#define _7_SEG2       1
#define _7_SEG3       2
#define _7_SEG4       3
#define _7_SEG5       4

/*Names of LEDS for every Seven Segment*/
#define _7_SEG_LED1   0 
#define _7_SEG_LED2   1
#define _7_SEG_LED3   2 
#define _7_SEG_LED4   3 
#define _7_SEG_LED5   4 
#define _7_SEG_LED6   5 
#define _7_SEG_LED7   6
#define _7_SEG_DOT    7  

/*
*@brief: The 7 Segment configuration type
*/
typedef enum{
	COMMON_Cathode,
	COMMON_Anode
}_7_SEG_enumCfg;

/*
*@brief: The Configuration for every LED in the 7 Segment
*/
typedef struct{
    DIO_enumPorts_t Port ;
    DIO_enumPins_t Pin ;	
}_7_SEG_StrLEDConfg;

/*
*@brief: The Configuration for the 7 Segment
1- The Configuration for every LED in the 7 Segment
2- The Type of Seven Segment
*/
typedef struct{
	_7_SEG_StrLEDConfg PINs[NUM_OF_PINS_IN_ONE_SEG];
	_7_SEG_enumCfg confgType;
}_7_SEG_strCfg;

#endif /* _7_SEG_CONFG_H_ */