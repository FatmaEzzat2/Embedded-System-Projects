/*
 * LED.h
 *
 * Created: 12/11/2023 7:05:15 PM
 *  Author: FatmaEzzat
 */ 
#ifndef LED_H_
#define LED_H_

#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/Registers.h"
#include "../../00_Lib/STD_TYPES.h"
#include "LED_Confg.h"

/**
 *@brief : The Error List Type                                           
 */
typedef enum {
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	LED_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	LED_enumNOk,             
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	LED_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	LED_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	LED_enumWrongState, 
	/**
	 *@brief : Select LED Status Not Found .
	 */ 
	LED_enumWrongStatus   
}LED_enumError_t;

/**
*@brief : Function to initialize all LEDs
*@param : void 
*@return: Error State
*/
LED_enumError_t LED_enumInit(void);

/**
*@brief : Function to set the LEDs ON or OFF
*@param : void
*@return: Error State
*/
LED_enumError_t LED_enumSetValue(u8 LED_Name,LED_enumOutputState OUTPUT);

#endif /* LED_H_ */