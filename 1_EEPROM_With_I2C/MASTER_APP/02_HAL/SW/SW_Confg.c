/*
 * SW_Confg.c
 *
 * Created: 12/16/2023 9:56:50 AM
 *  Author: FatmaEzzat
 */ 

#include "SW.h"

SW_Confg SWs[NUM_OF_SWs]={

	[SW1]={
		.port = DIO_enumPortD,
		.pin  =  DIO_enumPin2,
		.confgType = InternalPullUp
	}
};
