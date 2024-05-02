/*
 * LCD_Config.h
 *
 * Created: 1/2/2024 9:58:25 AM
 *  Author: KimoStore
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_
#include "../../01_MCAL/DIO/DIO.h"

/*LCD Pins*/
/*
These pins need to be output
8_BIT MODE : 8 pins 
4_BIT MODE : 4 pins
*/
/*Choose LCD Mode*/
#define FOUR_BIT_MODE    0
#define EIGHT_BIT_MODE   1

#define LCD_MODE  FOUR_BIT_MODE

#if LCD_MODE == EIGHT_BIT_MODE
#define NUM_OF_LCD_PINS    8  
  
#elif LCD_MODE == FOUR_BIT_MODE
#define NUM_OF_LCD_PINS    4   
#endif

#define D0   0
#define D1   1
#define D2   2 
#define D3   3
#define D4   4
#define D5   5
#define D6   6
#define D7   7
#define EN   8
#define RS   9


/*LCD Details*/
#define FIRST_LINE      1
#define SECOND_LINE     2
#define NO_OF_Columns   16

typedef struct{
	DIO_enumPorts_t port;
	DIO_enumPins_t pin; 
}LCD_strCfg;


#endif /* LCD_CONFIG_H_ */