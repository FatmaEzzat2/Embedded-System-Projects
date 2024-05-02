/*
*File: Connects an ATmega32 microcontroller with an EEPROM through I2C
*Author:  Fatma Ezzat
*Created: 5/2/2024
*Target:  ATMEGA32
*/

#include "../../00_Lib/STD_TYPES.h"
#include "../../02_HAL/EEPROM/EEPROM.h"
#include "../../02_HAL/LED/LED.h"

#define EEPROM_ADDREESS		0x00

int main(void){

	u8 data;
	LED_enumInit();
	EEPROM_WriteSingleData(EEPROM_ADDREESS,0x32);

	_delay_ms(500);

	EEPROM_ReadSingleData(EEPROM_ADDREESS,&data);

	if(data == 0x32){
		LED_enumSetValue(LED1,LED_ON);
	}else{

		LED_enumSetValue(LED1,LED_OFF);
	}
	while(1){

	}
	return 0;
}

