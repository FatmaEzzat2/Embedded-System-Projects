/*
 * LED_Confg.h
 *
 * Created: 12/11/2023 7:05:29 PM
 *  Author: FatmaEzzat
 */ 


#ifndef LED_CONFG_H_
#define LED_CONFG_H_

#include "../../01_MCAL/DIO/DIO.h"
#define NUM_Of_LEDs   1


#define LED1     0
#define LED2     1
#define LED3     2


typedef enum{
	ActiveHIGH,
	ActiveLOW
}LED_enumActiveState;

typedef enum{
	LED_OFF,
	LED_ON
}LED_enumOutputState;

typedef struct{
	DIO_enumPorts_t port;
	DIO_enumPins_t pin;
	LED_enumActiveState state;
	LED_enumOutputState output;
}LED_StrCfg;

#endif /* LED_CONFG_H_ */
