/*
 * LCD_Config.c
 *
 * Created: 1/2/2024 9:56:45 AM
 *  Author: Fatma Ezzat
 */ 
#include "LCD_Config.h"

LCD_strCfg LCD_Pins[]=
{
 #if LCD_MODE == EIGHT_BIT_MODE
  [D0] = 
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin0
  },
  [D1] =
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin1
  },
  [D2] =
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin2
  },
  [D3] =
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin3
  },
  #endif
  
  [D4] =
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin4
  },
  [D5] =
  {
	  .port = DIO_enumPortC,
	  .pin  = DIO_enumPin5
	},
  [D6] =
  {
  	.port = DIO_enumPortC,
  	.pin  = DIO_enumPin6
  },
  [D7] =
  {
  	.port = DIO_enumPortC,
  	.pin  = DIO_enumPin7
  },
  [EN] =
  {
	  .port = DIO_enumPortD,
	  .pin  = DIO_enumPin0 
  },
  [RS] =
  {
	  .port = DIO_enumPortD,
	  .pin  = DIO_enumPin1
  }
};