/*
*File: Source File of EEPROM
*Author:  Fatma Ezzat
*Created: 5/2/2024
*Target:  ATMEGA32
*/
#include"EEPROM.h"

void EEPROM_WriteSingleData(u8 address,u8 data){

	/*Init Master Clock*/
	I2C_MASTER_init(50000);

	_delay_ms(500);

	/*Send Start Condition*/
	I2C_SendSTART();

	/*
	 * Send Device ID and Operation type
	 * Device ID is 1010 that is fixed
	 * */
	I2C_SendAddress(0b1010000,WRITE_OPERATION);

	/*Send Word Address = EEPROM Address*/
	I2C_SendData(address);

	/*Send Data*/
	I2C_SendData(data);

	/*Send Stop Condition*/
	I2C_SendSTOP();


}
void EEPROM_ReadSingleData(u8 address,u8 *data){

	/*First, Master writes address of EPROM Location on the bus*/

	/*Send Start Condition*/
	I2C_SendSTART();

	/*
	 * Send Device ID and Operation type
	 * Device ID is 1010 that is fixed
	 * */
	I2C_SendAddress(0b1010000,WRITE_OPERATION);

	/*Send Word Address = EEPROM Address*/
	I2C_SendData(address);


	/*
	 * Then, Master reads the content of this location so that
	 * It needs to change the data direction by sending Repeated start
	 * */
	I2C_SendRepeatedStart();

	I2C_SendAddress(0b1010000,READ_OPERATION);

	/*Get Data*/
	I2C_MasterReadDataWithNACK(data);


	/*Send Stop Condition*/
	I2C_SendSTOP();
}




