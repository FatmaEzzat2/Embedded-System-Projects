/*
 * LED.c
 *
 * Created: 12/11/2023 7:04:37 PM
 *  Author: FatmaEzzat
 */ 
#include "LED.h"


extern LED_StrCfg LEDs[NUM_Of_LEDs];
/**
*@brief : Function to initialize all LEDs
*@param : void
*@return: Error State
*/
LED_enumError_t LED_enumInit(void){
	
	LED_enumError_t Ret_enuError = LED_enumNOk;
    u8 counter ;
 

for(counter=0; counter < NUM_Of_LEDs ;counter++){
	
/****************Check on Port number************/
  if(( LEDs[counter].port > DIO_enumPortD )||( LEDs[counter].port < DIO_enumPortA)){
	  Ret_enuError = LED_enumWrongPort;
	  
/****************Check on PIN number************/
  }else if(( LEDs[counter].pin > DIO_enumPin7)||( LEDs[counter].pin < DIO_enumPin0)){
	  Ret_enuError = LED_enumWrongPin;
	  
/****************Check on LED State ************/
  }else if(( LEDs[counter].state != ActiveHIGH)&&( LEDs[counter].state != ActiveLOW)){
	   Ret_enuError = LED_enumWrongState;	
	   
/****************Check on The output ************/
  }else if((LEDs[counter].output != LED_ON)&&(LEDs[counter].output != LED_OFF)){
	  Ret_enuError = LED_enumWrongStatus;
  }else{
	  Ret_enuError = LED_enumOk;
	  
	  /*Code Implementation */
	  if((LEDs[counter].state == ActiveHIGH)&&(LEDs[counter].output == LED_OFF)){
		  
		 DIO_enumSetPinConfig(LEDs[counter].port,LEDs[counter].pin,DIO_enumOutputLOW);
		 
	  }else if((LEDs[counter].state == ActiveHIGH)&&(LEDs[counter].output == LED_ON)){
		  DIO_enumSetPinConfig(LEDs[counter].port,LEDs[counter].pin,DIO_enumOutputHIGH);
		  
	  }else if((LEDs[counter].state == ActiveLOW)&&(LEDs[counter].output == LED_OFF)){
	  DIO_enumSetPinConfig(LEDs[counter].port,LEDs[counter].pin,DIO_enumOutputHIGH);
	  
      }else if((LEDs[counter].state == ActiveLOW)&&(LEDs[counter].output == LED_ON)){
      DIO_enumSetPinConfig(LEDs[counter].port,LEDs[counter].pin,DIO_enumOutputLOW);
      }else{
		  /*do nothing*/
	  }
  

	  }
	  }
  return Ret_enuError;
}
/**
*@brief : Function to set the LEDs ON or OFF
*@param : void
*@return: Error State
*/
LED_enumError_t LED_enumSetValue(u8 LED_Name,LED_enumOutputState OUTPUT){
	
	LED_enumError_t Ret_enuError = LED_enumNOk;

   
  /****************Check on The output ************/
	   if(( OUTPUT != LED_ON )&&( OUTPUT != LED_OFF)){
	   Ret_enuError = LED_enumWrongStatus;

	   }else{
		   switch(LEDs[LED_Name].state){
			   
			   case ActiveHIGH:
			   switch(OUTPUT){
				   case LED_ON:
				   DIO_enumSetPin(LEDs[LED_Name].port,LEDs[LED_Name].pin,LogicHigh);
				   break;
				   case LED_OFF:
				   DIO_enumSetPin(LEDs[LED_Name].port,LEDs[LED_Name].pin,LogicLow);
				   break;
				   default:
				   break;
			   }
			   break;
			   case ActiveLOW:
               switch(OUTPUT){
               	case LED_ON:
				   	DIO_enumSetPin(LEDs[LED_Name].port,LEDs[LED_Name].pin,LogicLow);
               	break;
               	case LED_OFF:
				   	DIO_enumSetPin(LEDs[LED_Name].port,LEDs[LED_Name].pin,LogicHigh);

               	break;
               	default:
               	break;
               }			   
			   break;
			   default:
			   break;   
		   } 
	   }	
	   return Ret_enuError;
}
