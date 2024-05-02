/*
 * Ext_Interrupts.h
 *
 * Created: 12/24/2023 2:04:43 PM
 *  Author: FatmaEzzat
 */ 


#ifndef EXT_INTERRUPTS_H_
#define EXT_INTERRUPTS_H_

#include "Ext_Interrupts_Confg.h"
#include"../../00_Lib/BIT_Math.h"
#include "../../00_Lib/STD_TYPES.h"
#include "../../00_Lib/Registers.h"
#include <avr/interrupt.h>
/*
*@brief  : Function to initialize all Interrupts
*@param  : void
*@return : void
*/
void EXT_INT_enumInit(void);

/*
*@brief  : Function to set the application function to ISR  
*@param  : pointer to function 
*@return : void
*/
void setcallback_INT0(void (*cpf)(void));
void setcallback_INT1(void (*cpf)(void));
void setcallback_INT2(void (*cpf)(void));

#endif /* EXT_INTERRUPTS_H_ */