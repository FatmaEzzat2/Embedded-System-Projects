/*
 * LED_Confg.c
 *
 * Created: 12/11/2023 7:04:59 PM
 *  Author: FatmaEzzat
 */
 
 #include "LED_Confg.h"

/* LEDs Configuration */
LED_StrCfg LEDs[NUM_Of_LEDs]=
{
	[LED1]={
	 .port = DIO_enumPortB,
	 .pin  = DIO_enumPin0,
	 .state= ActiveHIGH,
	 .output=LED_OFF,
	}
};
