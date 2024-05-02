/*
 * SW_Confg.h
 *
 * Created: 12/16/2023 9:56:29 AM
 *  Author: FatmaEzzat
 */ 

#ifndef SW_CONFG_H_
#define SW_CONFG_H_

/*Number of Switches*/
#define NUM_OF_SWs  1

/*Names of Switches*/
#define SW1         0
#define SW2         1 
#define SW3         2
#define SW4         3
#define SW5         4

/*Switch Configuration Data type*/
typedef enum{
 InternalPullUp,
 ExternalPullDown	
}SW_enumConfg;   

/*Information for every switch*/
typedef struct{
	DIO_enumPorts_t port;
	DIO_enumPins_t pin;
	SW_enumConfg confgType;
}SW_Confg;


#endif /* SW_CONFG_H_ */
