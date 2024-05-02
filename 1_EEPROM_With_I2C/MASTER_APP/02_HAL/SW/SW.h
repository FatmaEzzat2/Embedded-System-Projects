/*
 * SW.h
 *
 * Created: 12/16/2023 9:56:09 AM
 *  Author: FatmaEzzat
 */ 

#ifndef SW_H_
#define SW_H_

#include "../../00_Lib/Registers.h"
#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/STD_TYPES.h"
#include "../../01_MCAL/DIO/DIO.h"
#include "SW_Confg.h"

/**
 *@brief : The Error List Type                                           
 */
typedef enum {
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	SW_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	SW_enumNOk,             
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	SW_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	SW_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	SW_enumWrongConfg, 
	/**
	 *@brief : Send NULL Pointer.
	 */  
	SW_enumNULLPointer
	  
}SW_enumError_t;

/**
*@brief : Function to initialize all Switches
*@param : void 
*@return: Error State
*/
SW_enumError_t SW_enumInit(void);

/**
*@brief : Function to read The logic state of the switch
*@param : Switch Number and Pointer points to unsigned char passed by address
*@return: Error State
*/

SW_enumError_t SW_enumReadSWState(u8 SW_Name,LogicState_t* Add_Pu8PinValue);
#endif /* SW_H_ */