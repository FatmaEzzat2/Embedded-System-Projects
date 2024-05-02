/*
 * SW.c
 *
 * Created: 12/16/2023 9:55:37 AM
 *  Author: FatmaEzzat
 */ 

#include "SW.h"
extern SW_Confg SWs[NUM_OF_SWs];

/**
*@brief : Function to initialize all Switches
*@param : void
*@return: Error State
*/
SW_enumError_t SW_enumInit(void){
	
	SW_enumError_t Return_enumError = SW_enumNOk; 
	u8 counter;
	
for(counter =0;counter <NUM_OF_SWs;counter++){
	
/*Check on PORT Number*/
if((SWs[counter].port >DIO_enumPortD)||(SWs[counter].port<DIO_enumPortA)){
	Return_enumError = SW_enumWrongPort;
	
/*Check on PIN Number*/
}else if((SWs[counter].pin >DIO_enumPin7 )||( SWs[counter].pin < DIO_enumPin0)){
	Return_enumError = SW_enumWrongPin;
	
/*Check on The Configuration Type*/
}else if((SWs[counter].confgType != InternalPullUp)&&(SWs[counter].confgType !=ExternalPullDown)){
	Return_enumError = SW_enumWrongConfg;
}else{
	Return_enumError = SW_enumOk;
	switch(SWs[counter].confgType){
	case InternalPullUp:
	DIO_enumSetPinConfig(SWs[counter].port,SWs[counter].pin,DIO_enumInputInternalPU);
	break;
	case ExternalPullDown:
	DIO_enumSetPinConfig(SWs[counter].port,SWs[counter].pin,DIO_enumInputExternalPD);
	break;
	default:
	break;	
	}
}	
}
return Return_enumError;
}

/**
*@brief : Function to read The logic state of the switch
*@param : Switch Number and Pointer points to unsigned char passed by address
*@return: Error State
*/
SW_enumError_t SW_enumReadSWState(u8 SW_Name,LogicState_t* Add_Pu8PinValue){
	
    SW_enumError_t SWReturn_enumError = SW_enumNOk;
	DIO_enumError_t DIOReturn_enumError = DIO_enumNOk;

	
	/***********Check on the value of the pointer***********/
	if(Add_Pu8PinValue == NULL){
		
         SWReturn_enumError = SW_enumNULLPointer;
	}else{
		
		 SWReturn_enumError = SW_enumOk;
		 /*
		   Add_Pu8PinValue = The address of passed variable from main function 
		 */
		 DIOReturn_enumError= DIO_enumReadState(SWs[SW_Name].port,SWs[SW_Name].pin,Add_Pu8PinValue);
		 
		 if (DIOReturn_enumError != DIO_enumOk){
             SWReturn_enumError = SW_enumNOk;			 
		 }
	}
	return SWReturn_enumError;
}