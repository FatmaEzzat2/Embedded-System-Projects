/*
 * KeyPad.h
 *
 * Created: 1/7/2024 1:41:46 PM
 *  Author: FatmaEzzat
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/Registers.h"
#include "../../00_Lib/STD_TYPES.h"
#include "../../01_MCAL/DIO/DIO.h"
#include "KeyPad_confg.h"
/*
*@brief : The Error List Type
*/
typedef enum{
	
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	KEYPAD_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	KEYPAD_enumNOk,             
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	KEYPAD_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	KEYPAD_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	KEYPAD_enumWrongConfg, 
	/**
	 *@brief : Send NULL Pointer.
	 */  
	KEYPAD_enumNULLPointer
}KEYPAD_enumError_t;

/*
*@brief  : Function to initialize Keypad
*@param  : void
*@return : Error state
*/
KEYPAD_enumError_t KEYPAD_init(void);
/*
*@brief  : Function to Get the pressed Key
*@param  : A pointer points to unsigned char passed by address
*@return : Error state
*/
KEYPAD_enumError_t KEYPAD_enuGetKey(u8* Add_Pu8PressedKey);
#endif /* KEYPAD_H_ */