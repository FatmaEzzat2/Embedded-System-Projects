/*
 * PORT_Confg.c
 *
 * Created: 12/3/2023 9:43:46 AM
 *  Author: FatmaEzzat
 */ 
#include "PORT.h"

#if CONFG_TYPE == POSTCOMPILE

/*Create a variable as an array of pins and assign initial value for every pin*/
PORT_enuPinOpt PORT_PinConfg[]={
	PORT_enuOutput,  /*Pin 0 --> PORT A*/
	PORT_enuOutput,  /*Pin 1 --> PORT A*/
	PORT_enuOutput,  /*Pin 2 --> PORT A*/
	PORT_enuOutput,  /*Pin 3 --> PORT A*/
	PORT_enuOutput,  /*Pin 4 --> PORT A*/
	PORT_enuOutput,  /*Pin 5 --> PORT A*/
	PORT_enuOutput,  /*Pin 6 --> PORT A*/
	PORT_enuOutput,  /*Pin 7 --> PORT A*/
	PORT_enuOutput,  /*Pin 0 --> PORT B*/
	PORT_enuOutput,  /*Pin 1 --> PORT B*/
	PORT_enuOutput,  /*Pin 2 --> PORT B*/
	PORT_enuOutput,  /*Pin 3 --> PORT B*/
	PORT_enuOutput,  /*Pin 4 --> PORT B*/
	PORT_enuOutput,  /*Pin 5 --> PORT B*/
	PORT_enuOutput,  /*Pin 6 --> PORT B*/
	PORT_enuOutput,  /*Pin 7 --> PORT B*/
	PORT_enuOutput,  /*Pin 0 --> PORT C*/
	PORT_enuOutput,  /*Pin 1 --> PORT C*/
	PORT_enuOutput,  /*Pin 2 --> PORT C*/
	PORT_enuOutput,  /*Pin 3 --> PORT C*/
	PORT_enuOutput,  /*Pin 4 --> PORT C*/
	PORT_enuOutput,  /*Pin 5 --> PORT C*/
	PORT_enuOutput,  /*Pin 6 --> PORT C*/
	PORT_enuOutput,  /*Pin 7 --> PORT C*/
	PORT_enuOutput,  /*Pin 0 --> PORT D*/
	PORT_enuOutput,  /*Pin 1 --> PORT D*/
	PORT_enuOutput,  /*Pin 2 --> PORT D*/
	PORT_enuOutput,  /*Pin 3 --> PORT D*/
	PORT_enuOutput,  /*Pin 4 --> PORT D*/
	PORT_enuOutput,  /*Pin 5 --> PORT D*/
	PORT_enuOutput,  /*Pin 6 --> PORT D*/
	PORT_enuOutput,  /*Pin 7 --> PORT D*/
};
#endif
