/*
 * KeyPad.c
 *
 * Created: 1/7/2024 1:41:37 PM
 *  Author: FatmaEzzat
 */ 
#include "KeyPad.h"

extern KEYPAD_strPinConfg KeyPadPins[NUM_OF_ROWS + NUM_OF_COLS];
extern u8 KeyPadStyle[NUM_OF_ROWS][NUM_OF_COLS];

/*
*@brief  : Function to initialize Keypad
*@param  : void
*@return : Error state
*/

KEYPAD_enumError_t KEYPAD_init(void){

	KEYPAD_enumError_t KeyPadReturn_enumError =KEYPAD_enumNOk;
	u8 counter ;
	for ( counter =0 ; counter<(NUM_OF_COLS+NUM_OF_ROWS) ;counter++)
	{
		/****************Check on Port number of every PIN************/
		if((KeyPadPins[counter].port>DIO_enumPortD)||(KeyPadPins[counter].port<DIO_enumPortA)){
			KeyPadReturn_enumError	= KEYPAD_enumWrongPort;
			
		/****************Check on pin number of every PIN************/
		}else if((KeyPadPins[counter].pin>DIO_enumPin7)||(KeyPadPins[counter].pin<DIO_enumPin0)){
			KeyPadReturn_enumError  = KEYPAD_enumWrongPin;
			
		/****************Check on the configuration of every PIN************/
		}else if((KeyPadPins[counter].confg<DIO_enumOutputLOW)||(KeyPadPins[counter].confg>DIO_enumInputExternalPD)){
			KeyPadReturn_enumError = KEYPAD_enumWrongConfg;
		}else{
			KeyPadReturn_enumError =KEYPAD_enumOk;
			
			/*Code Implementation*/
			DIO_enumSetPinConfig(KeyPadPins[counter].port,KeyPadPins[counter].pin,KeyPadPins[counter].confg);
		}
	}
	
	return 	KeyPadReturn_enumError;
}
/*
*@brief  : Function to Get the pressed Key
*@param  : A pointer points to unsigned char passed by address
*@return : Error state
*/

KEYPAD_enumError_t KEYPAD_enuGetKey(u8* Add_Pu8PressedKey){
	KEYPAD_enumError_t KeyPadReturn_enumError =KEYPAD_enumNOk;
	if (Add_Pu8PressedKey == NULL)
	{
		KeyPadReturn_enumError = KEYPAD_enumNULLPointer;
	}else{
		KeyPadReturn_enumError = KEYPAD_enumOk;
		
		/*Code Implementation*/
		u8 Col_counter ;
		u8 Row_counter ;
		u8 Loc_u8PinValue = LogicHigh;
		*Add_Pu8PressedKey = NOT_PRESSED; /*Initial state*/
		
		for (Col_counter = 0 ; Col_counter < NUM_OF_COLS; Col_counter++)
		{   /*Assign Zero to a specific column */
			DIO_enumSetPin(KeyPadPins[Col_counter+NUM_OF_COLS].port,KeyPadPins[Col_counter+NUM_OF_COLS].pin,DIO_enumOutputLOW);
			
			/*Read the states of the Rows*/
			for (Row_counter = 0 ; Row_counter < NUM_OF_ROWS; Row_counter++)
			{
				/*Check the state of the Rows*/
				DIO_enumReadState(KeyPadPins[Row_counter].port,KeyPadPins[Row_counter].pin, &Loc_u8PinValue); 
				if(Loc_u8PinValue ==LogicLow)
				{
					*Add_Pu8PressedKey  = KeyPadStyle[Col_counter][Row_counter];
					break;				
				}
			}
			/*To break out of the outer loop if it finds the pressed key*/
			if (*Add_Pu8PressedKey != NOT_PRESSED)
			{
				break;
			}
			/*Return the column state to high*/
			DIO_enumSetPin(KeyPadPins[Col_counter+NUM_OF_COLS].port,KeyPadPins[Col_counter+NUM_OF_COLS].pin,DIO_enumOutputHIGH);
		}
	}
	return KeyPadReturn_enumError;
}