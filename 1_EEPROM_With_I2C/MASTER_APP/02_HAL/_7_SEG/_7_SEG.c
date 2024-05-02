/*
 * _7_SEG.c
 *
 * Created: 12/18/2023 5:41:06 PM
 *  Author: FatmaEzzat
 */ 
#include "_7_SEG.h"

extern _7_SEG_strCfg _7SEGs[NUM_OF_7SEG];
/*
*@brief  : Function to initialize all Seven Segments
*@param  : void
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_init(void){
	_7_SEG_enumError_t _7SEGReturn_enumError = _7SEG_enumNOk;
	u8 SEGcounter ;
	u8 PINcounter ;
	
/*The outer loop ---> For looping on the 7 segments*/
for( SEGcounter = 0 ; SEGcounter < NUM_OF_7SEG ; SEGcounter++){
	
/****************Check on The configuration of the seven Segment************/
 if((_7SEGs[SEGcounter].confgType != COMMON_Cathode)&&(_7SEGs[SEGcounter].confgType != COMMON_Anode)){
   _7SEGReturn_enumError = _7SEG_enumWrongConfg;
   break;
   
 }else{
    /*The inner loop ---> For looping on the pins of every 7-segment */
    for(PINcounter = 0; PINcounter < NUM_OF_PINS_IN_ONE_SEG ;PINcounter ++){
		  
    /****************Check on Port number of every PIN************/
	 if((_7SEGs[SEGcounter].PINs[PINcounter].Port > DIO_enumPortD )||(_7SEGs[SEGcounter].PINs[PINcounter].Port<DIO_enumPortA))
	 {
	   _7SEGReturn_enumError = _7SEG_enumWrongPort;
	   break;
			  
	 /****************Check on Pin number of every PIN************/
	 }else if((_7SEGs[SEGcounter].PINs[PINcounter].Pin > DIO_enumPin7 )||(_7SEGs[SEGcounter].PINs[PINcounter].Pin<DIO_enumPin0))
	 {
	   _7SEGReturn_enumError = _7SEG_enumWrongPin;
	   break;
	 
	}else{
	  _7SEGReturn_enumError = _7SEG_enumOk;  
	/*Code Implementation*/
	
/*
Configure the pins of the Seven Segment display as outputs and initialize seven segments with zeros according to their configuration type
*/
	 switch(_7SEGs[SEGcounter].confgType){
		 case COMMON_Anode:
		 
		 /*To display zero, the middle LED (PIN 6) needs to be set to High in order to turn it off in case common anode*/
		 if(PINcounter != 6){
			 DIO_enumSetPinConfig(_7SEGs[SEGcounter].PINs[PINcounter].Port,_7SEGs[SEGcounter].PINs[PINcounter].Pin,DIO_enumOutputLOW);
		 }else{
			 DIO_enumSetPinConfig(_7SEGs[SEGcounter].PINs[PINcounter].Port,_7SEGs[SEGcounter].PINs[PINcounter].Pin,DIO_enumOutputHIGH);
		 }
		 break;
		 case COMMON_Cathode:
		 /*To display zero, the middle LED (PIN 6) needs to be set to High in order to turn it off in case common anode*/
         if(PINcounter != 6){
	         DIO_enumSetPinConfig(_7SEGs[SEGcounter].PINs[PINcounter].Port,_7SEGs[SEGcounter].PINs[PINcounter].Pin,DIO_enumOutputHIGH);
	     }else{
	         DIO_enumSetPinConfig(_7SEGs[SEGcounter].PINs[PINcounter].Port,_7SEGs[SEGcounter].PINs[PINcounter].Pin,DIO_enumOutputLOW);
}		 break;
		 default:
		 break;
	 }
			  		  
	}
   }
   /*Now, We are in the outer loop*/
   if(_7SEGReturn_enumError != _7SEG_enumOk){
	   break;
   }else{
	   /*do nothing*/
   }
 }
}
 return _7SEGReturn_enumError;
}
/*
*@brief  : Function to Set the value for a specific Seven Segment
*@param  : 7Segment Name and its value
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_enuSetValue(u8 Copy_u8SegName, u8 Value){
	
	_7_SEG_enumError_t _7SEGReturn_enumError = _7SEG_enumNOk;
	u8 AnodeArr[10]={[0]=0xC0,[1]=0xF9,[2]=0xA4,[3]=0xB0,[4]=0x99,[5]=0x92,[6]=0x82,[7]=0xF8,[8]=0x80,[9]=0x90};
	u8 counter;
		
  /****************Check on the number of the segment************/
  if(Copy_u8SegName > (NUM_OF_7SEG - 1)){
	_7SEGReturn_enumError = _7SEG_enumWrongSegmentNumber;  
	
	 /****************Check on the value************/
  }else if(Value > 9){
	 _7SEGReturn_enumError = _7SEG_enumWrongValue ; 
	  
  }else{
	  _7SEGReturn_enumError = _7SEG_enumOk ; 
	  
	  /*Code Implementation*/
	  switch(_7SEGs[Copy_u8SegName].confgType){
		case COMMON_Anode:
		for(counter = 0;counter<NUM_OF_PINS_IN_ONE_SEG;counter++){
			DIO_enumSetPin(_7SEGs[Copy_u8SegName].PINs[counter].Port,_7SEGs[Copy_u8SegName].PINs[counter].Pin,GET_BIT(AnodeArr[Value],counter));
		}
		break;  
		case COMMON_Cathode: 
		for(counter = 0;counter<NUM_OF_PINS_IN_ONE_SEG;counter++){
			DIO_enumSetPin(_7SEGs[Copy_u8SegName].PINs[counter].Port,_7SEGs[Copy_u8SegName].PINs[counter].Pin,GET_BIT(~AnodeArr[Value],counter));
		} 
		break;  
		default:
		break;  
	  }
  }
 return	_7SEGReturn_enumError;
}
/*
*@brief  : to set a value to all the 7 segments.
*@param  : The value for all 7 segments
*@return : Error State
*/
_7_SEG_enumError_t _7SEG_enuSetValueForAllSegs(u16 Value){
   _7_SEG_enumError_t _7SEGReturn_enumError = _7SEG_enumNOk;
   
	u16 temp = Value;
	u8 DigitsCounter = 0;
	u8 Forcounter = 0;

 /*Get the number of digits of the value*/ 
	while(Value != 0){
		DigitsCounter++;
		Value /= 10;	
	}
 
 /*Now, we have the number of digits of the value*/
	if(DigitsCounter > NUM_OF_7SEG){
	   _7SEGReturn_enumError = _7SEG_enumWrongValue ;
	   
	   /*Initialize the current Seven Segments with zeros*/
	   for(Forcounter = 0; Forcounter < DigitsCounter;Forcounter++){
		   _7SEG_enuSetValue(Forcounter, 0);
	   }
	}else{
	  _7SEGReturn_enumError = _7SEG_enumOk;
	/*Code Implementation*/
		for(Forcounter=0;Forcounter< DigitsCounter;Forcounter++){	 
			_7SEG_enuSetValue(Forcounter, (temp % 10));
			temp = temp /10;
		}
	}
return	_7SEGReturn_enumError;
}