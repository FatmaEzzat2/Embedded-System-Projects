/*
 * LCD.c
 * Created: 1/2/2024 9:56:27 AM
 *  Author: Fatma Ezzat
 */
#include "LCD.h"
extern LCD_strCfg LCD_Pins[NUM_OF_LCD_PINS];

/*
*@brief  : Function to send pulses on the Enable pin
*@param  : void
*@return : void
*/
static void Enable (void);
/*
*@brief  : Function to display the character on the LCD
*@param  : ASCII code that represents the desired data to display on the LCD
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data){
	
	 LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	 
	/*RS = 1 --> To deal with data as a ASCII code for a character*/
	DIO_enumSetPin(LCD_Pins[RS].port,LCD_Pins[RS].pin,DIO_enumOutputHIGH);
	
	/*Check on the LCD mode */
	#if (LCD_MODE == EIGHT_BIT_MODE)
	for (u8 counter=0;counter<NUM_OF_LCD_PINS; counter++)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Data,counter));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	#elif (LCD_MODE == FOUR_BIT_MODE)
	
	/*Send higher bits */
	for (u8 counter= 7; counter>3 ; counter--)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Data,counter));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	/*Send lower bits */
	for (u8 counter =7; counter > 3;counter--)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Data,(counter-4)));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	#endif
	return Ret_enumErrorStatus;
}

/*
*@brief  : Function to execute the given instruction
*@param  : ASCII code that represents the command or instruction that needs to be executed
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command){
	
	LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	
	/*RS = 0 --> To deal with data as a command that needs to be executed */
	DIO_enumSetPin(LCD_Pins[RS].port,LCD_Pins[RS].pin,DIO_enumOutputLOW);
	
	/*Check on the LCD mode */
	#if (LCD_MODE == EIGHT_BIT_MODE)
	for (u8 counter  = 0 ;counter<NUM_OF_LCD_PINS; counter++)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Command,counter));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	#elif (LCD_MODE == FOUR_BIT_MODE)
	
	/*Send higher bits */
	for (u8 counter =7; counter > 3;counter--)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Command,counter));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	/*Send lower bits */
	for (u8 counter =7; counter > 3;counter--)
	{
		DIO_enumSetPin(LCD_Pins[counter].port,LCD_Pins[counter].pin,GET_BIT(Copy_u8Command,(counter-4)));
	}
	/*Send a pulse on Enable pin*/
	Enable();
	
	#endif
	return Ret_enumErrorStatus;	
}
 
/*
*@brief  : Function to initialize LCD
*@param  : void
*@return : void
*/
void LCD_init(void){
	/*
	*@For 8-Bit Mode
	*/
	#if (LCD_MODE == EIGHT_BIT_MODE)
	
	/*Step0: Make LCD Pins as outputs*/
	for(u8 counter=0; counter < NUM_OF_LCD_PINS ; counter++){
		DIO_enumSetPinConfig(LCD_Pins[counter].port,LCD_Pins[counter].pin,DIO_enumOutputLOW);
	}
	/*Set Enable pin as an output*/
	DIO_enumSetPinConfig(LCD_Pins[EN].port,LCD_Pins[EN].pin,DIO_enumOutputLOW);
	/*Set Register select pin as an output*/
	DIO_enumSetPinConfig(LCD_Pins[RS].port,LCD_Pins[RS].pin,DIO_enumOutputLOW);
	
	/*Step1: Wait for more than 30ms after VDD rises to 4.5V. */
	Delay(0.05);
	
	/*Step2: Function Set*/
	LCD_enuWriteCommand(EIGHT_BIT_FUNCTION_SET);
	
	/*
	*@For 4-Bit Mode
	*/
	#elif (LCD_MODE == FOUR_BIT_MODE)
	
	/*Step0: Make LCD Pins as outputs*/
	for(u8 counter = 4; counter < NUM_OF_LCD_PINS+4 ; counter++){
		DIO_enumSetPinConfig(LCD_Pins[counter].port,LCD_Pins[counter].pin,DIO_enumOutputLOW);
	}
	/*Set Enable pin as an output*/
	DIO_enumSetPinConfig(LCD_Pins[EN].port,LCD_Pins[EN].pin,DIO_enumOutputLOW);
	/*Set Register select pin as an output*/
	DIO_enumSetPinConfig(LCD_Pins[RS].port,LCD_Pins[RS].pin,DIO_enumOutputLOW);
	
	/*Step1: Wait for more than 30ms after VDD rises to 4.5V. */
	Delay(0.05);
	
	LCD_enuWriteCommand(RETURN_HOME);
	Delay(0.01);
	/*Step2: Function Set*/
	LCD_enuWriteCommand(FOUR_BIT_FUNCTION_SET);
	#endif
	
	/*Step3: Wait for more than 39 s */
	Delay(0.05);
	
	/*Step4: Display ON/OFF ControL */
	LCD_enuWriteCommand(DISPLAY_ON_CURSOR_OFF);
	
	/*Step5: Wait for more than 39 s */
	Delay(0.05);
	/*Step6: Display Clear*/
	LCD_enuWriteCommand(CLEAR_SCREEN);
	
	/*Step7: Wait for more than 1.53ms */
	Delay(0.002);
	/*Step8: ENTRY_MODE*/
	LCD_enuWriteCommand(ENTRY_MODE_INCR);
	Delay(0.002);
}
/*
*@brief  : Function to jump on a specific location on DDRAM (On the LCD screen)
*@param  : The position of the desired location on the LCD (X:Row & Y:Columns)
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y){
	
	LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	u8 address=0;
	
    if((Copy_u8X > SECOND_LINE)||(Copy_u8Y > NO_OF_Columns)){
		
	  Ret_enumErrorStatus =	LCD_enumWrongPosition;
	}else{
	  Ret_enumErrorStatus = LCD_enumOk;
	 /*Code implementation*/
	 switch(Copy_u8X){
		 case FIRST_LINE:
			address = Copy_u8Y-1;
		 break;
		 case SECOND_LINE:
		    address = 0x40+ Copy_u8Y-1;
		 break;
		 default:
		 break;	 
	 }	
	 LCD_enuWriteCommand(0x80 + address);
	}
	return Ret_enumErrorStatus;	
}
/*
*@brief  : Function to display a number on the LCD screen
*@param  : Number
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteNumber(u16 Copy_u8Number){
	LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	
	/*Check on the number*/
	if(Copy_u8Number >65535){
		Ret_enumErrorStatus = LCD_enumWrongNumber;
	}else{
		Ret_enumErrorStatus = LCD_enumOk;
	    /*Code Implementation */	
		u8 numOfDigits = 0;
		u16 temp = Copy_u8Number ;
		
		/*Array to store the number of digits of the input number*/
		u8 arr[5];
		while(temp != 0){
			
			arr[numOfDigits]= temp%10;
			numOfDigits++;
			temp /= 10; 
		}
		
		/*Print the array element and add 48 to convert the number to its ASCII code*/
		for (u8 counter =numOfDigits; counter > 0;counter--)
		{
			LCD_enuWriteData(arr[counter-1]+48);
		}
	}
	return Ret_enumErrorStatus;
}

/*
*@brief  : Function to display a string on the LCD screen
*@param  : String and its length
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuWriteString(const char* Copy_pchPattern, u8 Copy_u8Length){
	
	LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	for( u8 counter = 0; counter < Copy_u8Length ;counter++){
		
		LCD_enuWriteData(Copy_pchPattern[counter]);
	}
	return Ret_enumErrorStatus;
}
/*
*@brief  : Function to store a pattern in CGRAM and display it in a specific location
*@param  : Pattern, Block number in CGRAM,and the position
*@return : Error state
*/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(const u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y){
	
	LCD_enuErrorStatus Ret_enumErrorStatus = LCD_enumNOk;
	
	/*Check on the given position */
	if((Copy_u8X > SECOND_LINE)||(Copy_u8Y > NO_OF_Columns)){
		
		Ret_enumErrorStatus =	LCD_enumWrongPosition;
		
	/*Check the number of CGRAM blocks to determine if it exceeds 8 or not*/
	}else if (Copy_u8CGRAMBlockNumber >8)
	{
		Ret_enumErrorStatus = LCD_enumWrongBlockNumber;
	}else{
		Ret_enumErrorStatus = LCD_enumOk;
	   /*Code implementation*/
	   /*Step1 :Get the location in the CGRAM*/
	   u8 Loc_u8CGRAMLocation = Copy_u8CGRAMBlockNumber *8;
	   
	   /*Step2: Load this value in Address counter*/
	   LCD_enuWriteCommand(64+Loc_u8CGRAMLocation);
	   
	   /*Step3: Store the pattern in this location*/
	   for (u8 counter = 0 ; counter<8;counter++)
	   {
	   	LCD_enuWriteData(Copy_pu8Pattern[counter]);	
	   }
	   
	   /*Step4: Set AC pointer to the DDRAM again*/
       LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
	   
	   /*Step5: Display The pattern on the LCD Location (x,y)*/
	   /*LCD_enuWriteData function takes a value (0 to 7), so it starts searching in the CGRAM, not in the CGROM */
	   LCD_enuWriteData(Copy_u8CGRAMBlockNumber);
	   
	   }
	return Ret_enumErrorStatus;
}
/*
*@brief  : Function to send pulses on the Enable pin
*/
static void Enable (void){
	DIO_enumSetPin(LCD_Pins[EN].port,LCD_Pins[EN].pin, DIO_enumOutputHIGH);
	Delay(0.01);
	DIO_enumSetPin(LCD_Pins[EN].port,LCD_Pins[EN].pin, DIO_enumOutputLOW);
	Delay(0.02);
}
