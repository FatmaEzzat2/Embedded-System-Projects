/*
 * PORT.h
 *
 * Created: 12/3/2023 9:44:00 AM
 *  Author: FatmaEzzat
 */ 


#ifndef PORT_H_
#define PORT_H_
#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/Registers.h"
#include "../../00_Lib/STD_TYPES.h"
#include "PORT_Confg.h"

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin. 
 *@param  : void
 *@return : void                                             
 */	
void PORT_vidInit(void);

#if CONFG_TYPE == PRECOMPILE
/**
 *@brief :  Logic State Type : HIGH (5V) or LOW(0V )                     
 */
#define PORT_LOW     0  
#define PORT_HIGH    1

/*Concatenation as a micro like function*/
#define CONCAT(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)             HELPER(PIN7,PIN6,PIN5,PIN4,PIN3,PIN2,PIN1,PIN0)
#define HELPER(PIN_7,PIN_6,PIN_5,PIN_4,PIN_3,PIN_2,PIN_1,PIN_0)     0b##PIN_7##PIN_6##PIN_5##PIN_4##PIN_3##PIN_2##PIN_1##PIN_0

#elif CONFG_TYPE == POSTCOMPILE

/*PORT Options*/
typedef enum {
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}PORTS;

/*PIN Options*/
typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}PINS;
#endif

#endif /* PORT_H_ */