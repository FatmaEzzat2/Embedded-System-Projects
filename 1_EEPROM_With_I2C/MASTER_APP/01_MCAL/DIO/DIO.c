/*
 * DIO.c
 *
 * Created: 11/26/2023 1:52:17 AM
 *  Author: FatmaEzzat
 */ 
#include "DIO.h"
/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig){
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOk;
	
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus = DIO_enumWrongPin;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				SET_BIT(DDRA,Copy_enumPinNum);
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumOutputHIGH:
				SET_BIT(DDRA,Copy_enumPinNum);
				SET_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRA,Copy_enumPinNum);
				SET_BIT(PORTA,Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRA,Copy_enumPinNum);
				CLR_BIT(PORTA,Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				SET_BIT(DDRB,Copy_enumPinNum);
				CLR_BIT(PORTB,Copy_enumPinNum);
				break;
				case DIO_enumOutputHIGH:
				SET_BIT(DDRB,Copy_enumPinNum);
				SET_BIT(PORTB,Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRB,Copy_enumPinNum);
				SET_BIT(PORTB,Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRB,Copy_enumPinNum);
				CLR_BIT(PORTB,Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				SET_BIT(DDRC,Copy_enumPinNum);
				CLR_BIT(PORTC,Copy_enumPinNum);
				break;
				case DIO_enumOutputHIGH:
				SET_BIT(DDRC,Copy_enumPinNum);
				SET_BIT(PORTC,Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRC,Copy_enumPinNum);
				SET_BIT(PORTC,Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRC,Copy_enumPinNum);
				CLR_BIT(PORTC,Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortD:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				SET_BIT(DDRD,Copy_enumPinNum);
				CLR_BIT(PORTD,Copy_enumPinNum);
				break;
				case DIO_enumOutputHIGH:
				SET_BIT(DDRD,Copy_enumPinNum);
				SET_BIT(PORTD,Copy_enumPinNum);
				break;
				case DIO_enumInputInternalPU:
				CLR_BIT(DDRD,Copy_enumPinNum);
				SET_BIT(PORTD,Copy_enumPinNum);
				break;
				case DIO_enumInputExternalPD:
				CLR_BIT(DDRD,Copy_enumPinNum);
				CLR_BIT(PORTD,Copy_enumPinNum);
				break;
				default:
				break;
			}
			break;

			default:
			break;
		}
	}
	return Ret_enumErrorStatus;	
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig){
	DIO_enumError_t Ret_enumErrorStatus = DIO_enumNOk;
	if(Copy_enumPortNum>DIO_enumPortD)
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPD)
	{
		Ret_enumErrorStatus = DIO_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus = DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				DDRA = 0xFF;
				PORTA = 0X00;
				break;
				case DIO_enumOutputHIGH:
				DDRA  = 0xFF;
				PORTA = 0Xff;
				break;
				case DIO_enumInputInternalPU:
				DDRA  = 0x00;
				PORTA = 0xff;
				break;
				case DIO_enumInputExternalPD:
				DDRA  = 0x00;
				PORTA = 0x00;
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				DDRB = 0xff;
				PORTB = 0X00;
				break;
				case DIO_enumOutputHIGH:
				DDRB = 0xff;
				PORTB = 0XFF;
				break;
				case DIO_enumInputInternalPU:
				DDRB  = 0x00;
				PORTB = 0xff;
				break;
				case DIO_enumInputExternalPD:
				DDRB  = 0x00;
				PORTB = 0x00;
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				DDRC = 0xff;
				PORTC = 0X00;
				break;
				case DIO_enumOutputHIGH:
				DDRC = 0xff;
				PORTC = 0XFF;
				break;
				case DIO_enumInputInternalPU:
				DDRC  = 0x00;
				PORTC = 0xff;
				break;
				case DIO_enumInputExternalPD:
				DDRC  = 0x00;
				PORTC = 0x00;
				break;
				default:
				break;
			}
			break;

			case DIO_enumPortD:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutputLOW:
				DDRD = 0xff;
				PORTD = 0X00;
				break;
				case DIO_enumOutputHIGH:
				DDRD = 0xff;
				PORTD = 0XFF;
				break;
				case DIO_enumInputInternalPU:
				DDRD  = 0x00;
				PORTD = 0xff;
				break;
				case DIO_enumInputExternalPD:
				DDRD  = 0x00;
				PORTD = 0x00;
				break;
				default:
				break;
			}
			break;

			default:
			break;
		}
	}
	return Ret_enumErrorStatus;	
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,LogicState_t Copy_enumLogicState){
	DIO_enumError_t RET_enuError = DIO_enumNOk;
	
	/*Check on Port Number*/
	if(Copy_enumPortNum >DIO_enumPortD){
		RET_enuError = DIO_enumWrongPort;
	/*Check on Pin Number*/
	}else if(Copy_enumPinNum >DIO_enumPin7){
		RET_enuError = DIO_enumWrongPin;
	}else{
		RET_enuError = DIO_enumOk;
		switch(Copy_enumPortNum){
		 case DIO_enumPortA:
		 /*Check on the values*/
		   switch(Copy_enumLogicState){
			   case LogicLow:
			   CLR_BIT(PORTA,Copy_enumPinNum);
			   break;
			   case LogicHigh:
			   SET_BIT(PORTA,Copy_enumPinNum);
			   break;
			   default:
			   break;
		   }
		 break;
		 case DIO_enumPortB:
		 /*Check on the values*/
		  switch(Copy_enumLogicState){
			  case LogicLow:
			  CLR_BIT(PORTB,Copy_enumPinNum);
			  break;
			  case LogicHigh:
			  SET_BIT(PORTB,Copy_enumPinNum);
			  break;
			  default:
			  break;
		  } 
		 break;
		 case DIO_enumPortC:
		 /*Check on the values*/
		  switch(Copy_enumLogicState){
			  case LogicLow:
			  CLR_BIT(PORTC,Copy_enumPinNum);
			  break;
			  case LogicHigh:
			  SET_BIT(PORTC,Copy_enumPinNum);
			  break;
			  default:
			  break;
		  }
		 break;
		 case DIO_enumPortD:
		 /*Check on the values*/
		 switch(Copy_enumLogicState){
			 case LogicLow:
			 CLR_BIT(PORTD,Copy_enumPinNum);
			 break;
			 case LogicHigh:
			 SET_BIT(PORTD,Copy_enumPinNum);
			 break;
			 default:
			 break;
		 }
		 break;
		 default:
		 break;	
		}
	}
	return RET_enuError;
}
/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,u8 Copy_u8Value){
	DIO_enumError_t RET_enuError = DIO_enumNOk;
	/*Check on Port Number*/
	if(Copy_enumPortNum > DIO_enumPortD){
		RET_enuError = DIO_enumWrongPort;
	}else{
		RET_enuError=DIO_enumOk;
		switch(Copy_enumPortNum){
			case DIO_enumPortA:
			PORTA = Copy_u8Value;
			break;
			case DIO_enumPortB:
			PORTB = Copy_u8Value;
			break;
			case DIO_enumPortC:
			PORTC = Copy_u8Value;
			break;
			case DIO_enumPortD:
			PORTD = Copy_u8Value;
			break;
			default:
			break;
		}
	}
	return RET_enuError;
}
/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,LogicState_t* Add_Pu8PinValue){
	DIO_enumError_t RET_enuError = DIO_enumNOk;
	/*Check on Port Number*/
	if(Copy_enumPortNum > DIO_enumPortD){
		RET_enuError = DIO_enumWrongPort;
	/*Check on Pin Number*/
	}else if(Copy_enumPinNum > DIO_enumPin7){
		RET_enuError = DIO_enumWrongPin;
	/*Check on pointer*/
	}else if(Add_Pu8PinValue == NULL){
		RET_enuError = DIO_enumNullPointer;
	}else{
		RET_enuError = DIO_enumOk;
		switch(Copy_enumPortNum){
			case DIO_enumPortA:
			* Add_Pu8PinValue = GET_BIT(PINA,Copy_enumPinNum);
			break;
			case DIO_enumPortB:
			* Add_Pu8PinValue = GET_BIT(PINB,Copy_enumPinNum);
			break;
			case DIO_enumPortC: 
			* Add_Pu8PinValue = GET_BIT(PINC,Copy_enumPinNum);
			break;
			case DIO_enumPortD:
			* Add_Pu8PinValue = GET_BIT(PIND,Copy_enumPinNum);
			break;
			default:
			break;
		}
	}
	return RET_enuError;
}
