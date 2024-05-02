/*
 * KeyPad_confg.h
 *
 * Created: 1/7/2024 1:42:05 PM
 *  Author: FatmaEzzat
 */ 
#include "../../01_MCAL/DIO/DIO.h"

#ifndef KEYPAD_CONFG_H_
#define KEYPAD_CONFG_H_

/*
*@brief : Keypad Configuration
*/
#define NUM_OF_ROWS   4
#define NUM_OF_COLS   4

#define ROW1    0
#define ROW2    1
#define ROW3    2
#define ROW4    3
#define COL1    4
#define COL2    5
#define COL3    6
#define COL4    7
/*
Keypad Matrix
1  -  2  -  3  - A 
4  -  5  -  6  - B
7  -  8  -  9  - C 
*  -  0  -  #  - D 
*/

/*First Row*/
#define KEY1    '7'
#define KEY2    '8'
#define KEY3    '9'
#define KEY4    '/'
/*Second Row*/
#define KEY5    '4'
#define KEY6    '5'
#define KEY7    '6'
#define KEY8    '*'
/*Third Row*/
#define KEY9    '1'
#define KEY10   '2'
#define KEY11   '3'
#define KEY12   '-'
/*Forth Row*/
#define KEY13   'N'
#define KEY14   '0'
#define KEY15   '='
#define KEY16   '+'

#define NOT_PRESSED 255
/*
*@brief : KeyPad configuration Type 
*/
typedef struct{
	DIO_enumPorts_t port;
	DIO_enumPins_t pin;
	DIO_enumConfig_t confg;
}KEYPAD_strPinConfg;

#endif /* KEYPAD_CONFG_H_ */