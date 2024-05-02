/*
 * PORT_Confg.h
 *
 * Created: 12/3/2023 9:44:17 AM
 *  Author: FatmaEzzat
 */ 


#ifndef PORT_CONFG_H_
#define PORT_CONFG_H_
/**
 *@brief :  Configuration Type : Pre_Compile or Post_Compile                     
 */
#define PRECOMPILE        0
#define POSTCOMPILE       1
#define CONFG_TYPE  POSTCOMPILE

/*Pre_Compilation Mode*/
#if CONFG_TYPE == PRECOMPILE
/**
 *@brief : The Configuration Type of Pins to be Input or Output !        
 */
/*Options :*/
 
#define INPUT_PU     0
#define INPUT_HI     1
#define OUTPUT       2

/*Assign initial value for every pin*/
#define PORT_PORTA_PIN0    OUTPUT     /*Pin 0 PORTA*/
#define PORT_PORTA_PIN1    OUTPUT     /*Pin 1 PORTA*/
#define PORT_PORTA_PIN2    OUTPUT     /*Pin 2 PORTA*/
#define PORT_PORTA_PIN3    OUTPUT     /*Pin 3 PORTA*/
#define PORT_PORTA_PIN4    OUTPUT     /*Pin 4 PORTA*/
#define PORT_PORTA_PIN5    OUTPUT     /*Pin 5 PORTA*/
#define PORT_PORTA_PIN6    OUTPUT     /*Pin 6 PORTA*/
#define PORT_PORTA_PIN7    OUTPUT     /*Pin 7 PORTA*/
#define PORT_PORTB_PIN0    INPUT_HI   /*Pin 0 PORTB*/
#define PORT_PORTB_PIN1    OUTPUT     /*Pin 1 PORTB*/
#define PORT_PORTB_PIN2    OUTPUT     /*Pin 2 PORTB*/
#define PORT_PORTB_PIN3    OUTPUT     /*Pin 3 PORTB*/
#define PORT_PORTB_PIN4    OUTPUT     /*Pin 4 PORTB*/
#define PORT_PORTB_PIN5    OUTPUT     /*Pin 5 PORTB*/
#define PORT_PORTB_PIN6    OUTPUT     /*Pin 6 PORTB*/
#define PORT_PORTB_PIN7    OUTPUT     /*Pin 7 PORTB*/
#define PORT_PORTC_PIN0    OUTPUT     /*Pin 0 PORTC*/
#define PORT_PORTC_PIN1    OUTPUT     /*Pin 1 PORTC*/
#define PORT_PORTC_PIN2    OUTPUT     /*Pin 2 PORTC*/
#define PORT_PORTC_PIN3    OUTPUT     /*Pin 3 PORTC*/
#define PORT_PORTC_PIN4    OUTPUT     /*Pin 4 PORTC*/
#define PORT_PORTC_PIN5    OUTPUT     /*Pin 5 PORTC*/
#define PORT_PORTC_PIN6    OUTPUT     /*Pin 6 PORTC*/
#define PORT_PORTC_PIN7    OUTPUT     /*Pin 7 PORTC*/
#define PORT_PORTD_PIN0    OUTPUT     /*Pin 0 PORTD*/
#define PORT_PORTD_PIN1    OUTPUT     /*Pin 1 PORTD*/
#define PORT_PORTD_PIN2    OUTPUT     /*Pin 2 PORTD*/
#define PORT_PORTD_PIN3    OUTPUT     /*Pin 3 PORTD*/
#define PORT_PORTD_PIN4    OUTPUT     /*Pin 4 PORTD*/
#define PORT_PORTD_PIN5    OUTPUT     /*Pin 5 PORTD*/
#define PORT_PORTD_PIN6    OUTPUT     /*Pin 6 PORTD*/
#define PORT_PORTD_PIN7    OUTPUT     /*Pin 7 PORTD*/
								      
#elif CONFG_TYPE == POSTCOMPILE

/*Determine the number of pins per target*/
#define NUM_OF_PINS    32

/*The data type for every pin*/
typedef enum {
	PORT_enuInput_PU,
	PORT_enuInput_HI,
	PORT_enuOutput,
}PORT_enuPinOpt;

#endif
#endif /* PORT_CONFG_H_ */