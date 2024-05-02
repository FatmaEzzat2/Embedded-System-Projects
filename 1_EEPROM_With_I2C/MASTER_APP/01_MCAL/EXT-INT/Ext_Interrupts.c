/*
 * Ext_interrupts.c
 *
 * Created: 12/24/2023 2:04:21 PM
 *  Author: FatmaEzzat
 */ 

#include "Ext_Interrupts.h"

/*
*@brief  : Function to initialize all Interrupts
*@param  : void
*@return : void
*/
void EXT_INT_enumInit(void){
	
	/*Set Global Enable --> I bit*/
	SET_BIT(SREG,I_BIT);
	
	/*Set Peripheral Interrupt Enables*/
	/*For Interrupt 0*/
    #if(EXT_INT0_MODE == ENABLE)
		SET_BIT(GICR,INT0);
	#else
		CLR_BIT(GICR,INT0);
	#endif	
	
	/*For Interrupt 1*/
	#if(EXT_INT1_MODE == ENABLE)
		SET_BIT(GICR,INT1);
	#else
		CLR_BIT(GICR,INT1);
	#endif
	
	/*For Interrupt 2*/
	#if(EXT_INT2_MODE == ENABLE)
		SET_BIT(GICR,INT2);
	#else
		CLR_BIT(GICR,INT2);
	#endif
	
    /*
	To configure Interrupt sense modes :
	1- Create Local variable
	2- Assign the register value in the new variable
	3- Clear the specific bits in the variable
	4- Insert new configuration 
	5- Reassign the new variable in the register
	*/
	/*For Interrupt 0*/
	u8 Loc_u8RegValueINT0 = MCUCR ;
	Loc_u8RegValueINT0   &= MCUCR_INT0_MASK ;
	Loc_u8RegValueINT0   |= INT0_SENSE_MODE;
	MCUCR = Loc_u8RegValueINT0;
	
	/*For Interrupt 1*/
	u8 Loc_u8RegValueINT1 = MCUCR ;
	Loc_u8RegValueINT1   &= MCUCR_INT1_MASK ;
	Loc_u8RegValueINT1   |= INT1_SENSE_MODE;
		
	/*For Interrupt 2*/
	#if (INT2_SENSE_MODE == INT2_RISING_EDGE_TRIG)
		SET_BIT(MCUCSR,ISC2);
	#else
	    CLR_BIT(MCUCSR,ISC2);
	#endif	
	
}
/*
*@brief:A pointer to function that takes void and returns void is used to implement the callback function concept
*/
void (*EXTI0_ISR)(void) = NULL;
void (*EXTI1_ISR)(void) = NULL;
void (*EXTI2_ISR)(void) = NULL;

/*
*@brief  : Function to set the application function to ISR
*@param  : pointer to function
*@return : void
*/
void setcallback_INT0(void (*cpf)(void)){
	EXTI0_ISR = cpf;
}
void setcallback_INT1(void (*cpf)(void)){
	EXTI1_ISR = cpf;
}
void setcallback_INT2(void (*cpf)(void)){
	EXTI2_ISR = cpf;
}

/*
*@brief: Call the application function during the interrupt"
*/

/*For INT 0*/

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	/*Check if the pointer is assigned by a function from APP layer or still holds a NULL value*/
	if(EXTI0_ISR != NULL){
		EXTI0_ISR();
	}
} 

/*For INT 1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
	
	/*Check if the pointer is assigned by a function from APP layer or still holds a NULL value*/
	if (EXTI1_ISR != NULL){
		EXTI1_ISR();
	}
}

/*For INT 2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	
	/*Check if the pointer is assigned by a function from APP layer or still holds a NULL value*/
	if (EXTI2_ISR != NULL){
		EXTI2_ISR();
	}
}