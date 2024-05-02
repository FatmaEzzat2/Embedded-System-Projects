/*
*File: Source File of I2C
*Author:  Fatma Ezzat
*Created: 5/2/2024
*Target:  ATMEGA32
*/

#ifndef I_2_C_H
#define I_2_C_H

#include "../../00_Lib/Registers.h"
#include "../../00_Lib/STD_TYPES.h"



/********************************************/
/***************** Defines ******************/
/********************************************/

typedef void (*Error_cb)(void);

/*Prescaler of the clock*/
#define PRESCALER_VALUE_1		0
#define PRESCALER_VALUE_4		1
#define PRESCALER_VALUE_16		2
#define PRESCALER_VALUE_64		3

#define CLOCK_PRESCALER 		PRESCALER_VALUE_1


#define ENABLE			1
#define DISABLE			0


/*MASTR Transmitter Mode*/
#define  START_COND_TRANSMITTED								0x08
#define  REPEATED_START_COND_TRANSMITTED					0x10
#define	 TX_SLA_W_TRANSMITTED_PLUS_ACK_RECEIVED				0x18
#define  TX_SLA_W_TRANSMITTED_PLUS_NACK_RECEIVED			0x20
#define  TX_DATA_TRANSMITTED_PLUS_ACK_RECEIVED				0x28
#define  TX_DATA_TRANSMITTED_PLUS_NACK_RECEIVED				0X30
#define  ARBITRATION_LOST_MASTER							0x38

/*MASTR Receiver Mode*/
#define	 RX_SLA_W_TRANSMITTED_PLUS_ACK_RECEIVED				0x40
#define  RX_SLA_W_TRANSMITTED_PLUS_NACK_RECEIVED			0x48
#define  RX_DATA_TRANSMITTED_PLUS_ACK_RECEIVED				0x50
#define  RX_DATA_TRANSMITTED_PLUS_NACK_RECEIVED				0X58


/*SLAVE Receiver Mode*/
#define	 SLA_W_RECEIVED_PLUS_ACK_RETURNED				0x60
#define  GENERAL_CALL_RECEIVED_ACK_RETURNED				0x70
#define  DATA_RECEIVED_SLA_PLUS_ACK_RETURNED    		0x80
#define  DATA_RECEIVED_SLA_PLUS_NACK_RETURNED	    	0x88
#define  DATA_RECEIVED_GENERAL_CALL_PLUS_ACK_RETURNED   0x90
#define  DATA_RECEIVED_GENERAL_CALL_PLUS_NACK_RETURNED  0x98
#define  STOP_COND_OR_REPEATED_START_RECEIVED			0xA0

/*Operations*/
#define READ_OPERATION			1
#define WRITE_OPERATION			0


/********************************************/
/***************** Functions ****************/
/********************************************/
/**
 *@brief : The Error List Type
 */
typedef enum{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	I2C_enumOk,
	/**
	 *@brief : Select Wrong Configuration.
	*/
	I2C_enumWrongConfiguraion,
	/**
	*@brief : Operation fail.
	*/
	I2C_enumWrongInOperation,
	/**
	*@brief : Time out
	*/
	I2C_enumTimeOut,

	/**
	*@brief : Send Wrong Data.
	*/
	I2C_enumWrongData,
	/**
	 *@brief : Send Wrong Address.
	 */
	I2C_enumWrongAddress,
	/**
	*@brief : Send NULL Pointer.
	*/
	I2C_enumNULLPointer

}I2C_enuErrorStatus;

/********************************************************************/
/*----------------------Master Transmitter--------------------------*/
/********************************************************************/
/*
 * @brief: Initialize the I2C peripheral in master mode
 * @parameter:
 *      - clock: The clock frequency (in kHz) to be used for I2C communication
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the initialization
 *          - I2C_OK: Initialization successful
 *          - I2C_ERROR: Initialization failed
 * @Note: This function initializes the I2C peripheral in master mode with the specified clock frequency.
 * SCL frequency = (CPU Clock frequency)/(16+ 2(TWBR)*4^(TWPS))
 */
I2C_enuErrorStatus I2C_MASTER_init(u16 clock);
/*
 * @brief: Send START condition on the I2C bus
 * @parameter: None
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: START condition sent successfully
 *          - I2C_ERROR: Failed to send START condition
 * @Note: This function sends a START condition on the I2C bus to initiate communication.
 */
I2C_enuErrorStatus I2C_SendSTART(void);
/*
 * @brief: Send a repeated START condition on the I2C bus
 * @parameter: None
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Repeated START condition sent successfully
 *          - I2C_ERROR: Failed to send repeated START condition
 * @Note: This function sends a repeated START condition on the I2C bus to initiate a repeated communication sequence.
 */
I2C_enuErrorStatus I2C_SendRepeatedStart(void);
/*
 * @brief: Send STOP condition on the I2C bus
 * @parameter: None
 * @return:	None
 * @Note: This function sends a STOP condition on the I2C bus to end communication.
 */
void I2C_SendSTOP(void);

/*
 * @brief: Set the slave address for I2C communication
 * @parameter:
 *      - address: The 7-bit address of the slave device
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Slave address set successfully
 *          - I2C_ERROR: Failed to set slave address
 * @Note: This function sets the 7-bit address of the slave device for I2C communication.
 */
I2C_enuErrorStatus I2C_SetSlaveAddress(u8 address,u8 generalCallActivate);

/*
 * @brief: Send data over the I2C bus
 * @parameter:
 *      - data: The data byte to be transmitted
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Data sent successfully
 *          - I2C_ERROR: Failed to send data
 * @Note: This function sends a single byte of data over the I2C bus.
 */
I2C_enuErrorStatus I2C_SendData(u8 data);

/*
 * @brief: Send address byte over the I2C bus
 * @parameter:
 *      - address: The 7-bit address of the slave device with the read/write bit
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Address sent successfully
 *          - I2C_ERROR: Failed to send address
 * @Note: This function sends the address byte with the read/write bit over the I2C bus.
 */
I2C_enuErrorStatus I2C_SendAddress(u8 address,u8 operation);

/***************************************************************/
/*----------------------Slave Receiver-------------------------*/
/***************************************************************/

/*
 * @brief: Read data from the I2C bus as a slave device
 * @parameter:
 *      - data: Pointer to a variable where the received data will be stored
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Data read successfully
 *          - I2C_ERROR: Failed to read data
 * @Note: This function reads data from the I2C bus when the device is operating as a slave.
 */
I2C_enuErrorStatus I2C_SlaveReadData(u8* data);

/***************************************************************/
/*----------------------Master Receiver-----------------------*/
/***************************************************************/
/*
 * @brief: Read a byte of data from the I2C bus as a master with ACK
 * @parameter:
 *      - data: Pointer to a variable where the received data will be stored
 * @return:
 *      - I2C_enuErrorStatus: Enumeration indicating the status of the operation
 *          - I2C_OK: Data read successfully with ACK
 *          - I2C_ERROR: Failed to read data with ACK
 * @Note: This function reads a byte of data from the I2C bus as a master with ACK (acknowledge).
 */
I2C_enuErrorStatus I2C_MasterReadDataWithACK(u8* data);









#endif
