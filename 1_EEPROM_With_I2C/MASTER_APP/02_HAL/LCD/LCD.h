/*
 * LCD.h
 *
 * Created: 1/2/2024 10:11:37 AM
 *  Author: KimoStore
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../00_Lib/Bit_Math.h"
#include "../../00_Lib/STD_TYPES.h"
#include "../../00_Lib/Delay.h"
#include "LCD_Config.h"

/**
 *@brief : The Error List Type                                           
 */
typedef enum{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	LCD_enumOk,
	/**
	 *@brief : Everything NOT Ok, Function had Performed InCorrectly.
	 */
	LCD_enumNOk,             
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	LCD_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	LCD_enumWrongPin, 
	/**
	 *@brief : Select Position Not exist ! .
	 */
	LCD_enumWrongPosition,
	/**
	 *@brief : Select Wrong Number to display !.
	 */
	LCD_enumWrongNumber,
	/**
	 *@brief : Select Wrong Block Number in the CGRAM !.
	 */
	LCD_enumWrongBlockNumber
}LCD_enuErrorStatus;
	
/*Commands*/	
#define CLEAR_SCREEN             0X01
#define RETURN_HOME              0X02
#define EIGHT_BIT_FUNCTION_SET   0X38
#define FOUR_BIT_FUNCTION_SET    0x28

#define ENTRY_MODE_INCR          0x06
#define ENTRY_MODE_DECR          0x04
#define DISPLAY_OFF_CURSOR_OFF	         0x08
#define DISPLAY_ON_CURSOR_OFF	         0x0C
#define DISPLAY_ON_CURSOR_ON_BLINK_OFF	 0x0E
#define DISPLAY_ON_CURSOR_ON_BLINK_ON	 0x0F
#define SHIFT_CURSOR_LEFT                0X10
#define SHIFT_CURSOR_RIGHT               0X14
#define SHIFT_ENTIRE_DISPLAY_LEFT        0X18
#define SHIFT_ENTIRE_DISPLAY_RIGHT       0X1C
	
/*
*@brief  : Function to initialize LCD
*@param  : void
*@return : void
*/
void LCD_init(void);
/*
*@brief  : Function to display the character on the LCD
*@param  : ASCII code that represents the desired data to display on the LCD
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data);

/*
*@brief  : Function to execute the given instruction 
*@param  : ASCII code that represents the command or instruction that needs to be executed
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command);

/*
*@brief  : Function to jump on a specific location on DDRAM (On the LCD screen)
*@param  : The position of the desired location on the LCD (X:Row & Y:Columns) 
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);

/*
*@brief  : Function to display a number on the LCD screen 
*@param  : Number
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteNumber(u16 Copy_u8Number);

/*
*@brief  : Function to display a string on the LCD screen
*@param  : String and its length 
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteString(const char* Copy_pchPattern, u8 Copy_u8Length);

/*
*@brief  : Function to store a pattern in CGRAM and display it in a specific location 
*@param  : Pattern, Block number in CGRAM,and the position
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(const u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);
#endif /* LCD_H_ */
