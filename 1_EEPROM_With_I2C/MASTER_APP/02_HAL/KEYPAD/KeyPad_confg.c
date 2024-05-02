/*
 * KeyPad_confg.c
 *
 * Created: 1/7/2024 1:42:40 PM
 *  Author: FatmaEzzat
 */ 
#include "KeyPad.h"

KEYPAD_strPinConfg KeyPadPins[NUM_OF_ROWS + NUM_OF_COLS]=
{
	/*Let Rows as Inputs --> (Internal Pull up)*/
	[ROW1]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin0 ,
		.confg = DIO_enumInputInternalPU ,
	},
	[ROW2]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin1 ,
		.confg = DIO_enumInputInternalPU,
	},
	[ROW3]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin2 ,
		.confg = DIO_enumInputInternalPU, 
	},
	[ROW4]={
	.port =DIO_enumPortA ,
	.pin  = DIO_enumPin3 ,
	.confg = DIO_enumInputInternalPU ,
	},
	/*Let Rows as Outputs --> (HIGH)*/
    [COL1]={
	    .port =DIO_enumPortA ,
	    .pin  = DIO_enumPin4 ,
	    .confg = DIO_enumOutputHIGH,
    },
	[COL2]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin5 ,
		.confg = DIO_enumOutputHIGH ,
	},
	[COL3]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin6 ,
		.confg = DIO_enumOutputHIGH ,
	},
	[COL4]={
		.port =DIO_enumPortA ,
		.pin  = DIO_enumPin7 ,
		.confg = DIO_enumOutputHIGH ,
	}
};

/*
*@brief : KeyPad Style
*/
u8 KeyPadStyle[NUM_OF_COLS][NUM_OF_ROWS]=
{{KEY1,KEY2,KEY3,KEY4},
 {KEY5,KEY6,KEY7,KEY8},
 {KEY9,KEY10,KEY11,KEY12},
 {KEY13,KEY14,KEY15,KEY16}
};