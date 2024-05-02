/*
 * _7_SEG.h
 *
 * Created: 12/18/2023 5:40:44 PM
 *  Author: FatmaEzzat
 */ 


#ifndef _7_SEG_H_
#define _7_SEG_H_


#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/Registers.h"
#include "../../00_Lib/STD_TYPES.h"
#include "../../01_MCAL/DIO/DIO.h"
#include "_7_SEG_Confg.h"
/**
 *@brief : The Error List Type                                           
 */
typedef enum{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	_7SEG_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	_7SEG_enumNOk,             
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	_7SEG_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	_7SEG_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	_7SEG_enumWrongConfg,
	/**
	 *@brief : Select Seven segment Not Found .
	 */     
	_7SEG_enumWrongSegmentNumber, 
	/**
	 *@brief : Select a Wrong Value .
	 */     
	_7SEG_enumWrongValue 
}_7_SEG_enumError_t ;

/*
*@brief  : Function to initialize all Seven Segments
*@param  : void
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_init(void);

/*
*@brief  : Function to Set the value for a specific Seven Segment
*@param  : 7Segment Name and its value
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_enuSetValue(u8 Copy_u8SegName, u8 Value);

/*
*@brief  : to set a value to all the 7 segments.
*@param  : The value for all 7 segments
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_enuSetValueForAllSegs(u16 Value);
#endif /* _7_SEG_H_ */