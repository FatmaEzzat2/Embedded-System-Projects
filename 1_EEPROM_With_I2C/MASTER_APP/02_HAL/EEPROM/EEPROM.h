/*
*File: Header File of EEPROM
*Author:  Fatma Ezzat
*Created: 5/2/2024
*Target:  ATMEGA32
*/
#ifndef _HAL_EEPROM_EEPROM_H_
#define _HAL_EEPROM_EEPROM_H_


#include "../../00_Lib/STD_TYPES.h"
#include "../../01_MCAL/I2C/I2C.h"
#include<util/delay.h>
/*
 * @brief: Write a single byte of data to an EEPROM address
 * @parameter:
 *      - address: The address in the EEPROM memory where the data will be written
 *      - data: The data byte to be written
 * @return: None
 * @Note: This function writes a single byte of data to the specified address in the EEPROM memory.
 */
void EEPROM_WriteSingleData(u8 address, u8 data);


/*
 * @brief: Read a single byte of data from an EEPROM address
 * @parameter:
 *      - address: The address in the EEPROM memory from where the data will be read
 *      - data: Pointer to a variable where the read data will be stored
 * @return: None
 * @Note: This function reads a single byte of data from the specified address in the EEPROM memory.
 */
void EEPROM_ReadSingleData(u8 address, u8 *data);





#endif /* _HAL_EEPROM_EEPROM_H_ */
