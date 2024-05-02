/*
*File: Source File of I2C
*Author:  Fatma Ezzat
*Created: 5/2/2024
*Target:  ATMEGA32
*/
#include "I2C.h"


/********************************************/
/***************** Defines ******************/
/********************************************/

#define CLR_REG_MSK				0xff
#define GET_STATUS_MSK			0xf8

#define MAX_ADDRESS_OF_SLAVES		129
#define MAX_DATA_VALUE				255
#define GENERAL_CALL_ADDRESS		0x00
#define F_CPU 8000000UL

/****************************************************/
/***************** Static Functions *****************/
/****************************************************/
/*
 * @brief: Calculate the power of a base raised to an exponent
 * @parameter:
 *      - base: The base value
 *      - exponent: The exponent value
 * @return:
 *      - The result of the base raised to the exponent
 * @Note: This function calculates the power of a base raised to an exponent.
 */

static int GetPower( u8 base ,u8 exponent ){
    int num=1;
	while (exponent >0){

		num*=base;
		exponent --;
	}
	return num;
}

/****************************************************/
/*********************Functions *********************/
/****************************************************/

I2C_enuErrorStatus I2C_MASTER_init(u16 clock){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on Clock*/
	if(CLOCK_PRESCALER > PRESCALER_VALUE_64){
		returneError =I2C_enumWrongConfiguraion;
	}else{
	/*******************Implementation Part*************************/
		/*Set the prescaler of the clock*/
			TWSR = (CLOCK_PRESCALER<<TWPS0);

		/*Get the value of Bit rate */
			TWBR =(u8) (((F_CPU/clock)-16)/(2*GetPower(4,CLOCK_PRESCALER)));
	}
	return returneError;
}
I2C_enuErrorStatus I2C_SendSTART(void){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*******************Implementation Part*************************/

	volatile u32 timeout =50000;

	/*Enable I2C, Clear Interrupt flag and Send Start Condition */
	TWCR =((ENABLE<<TWEN)|(ENABLE<<TWINT)|(ENABLE<<TWSTA));

	/*Wait on the TWI Interrupt Flag*/
	while(timeout--&&~((TWCR>>TWINT)&1));

	/*Check on time out*/
	if(timeout == 0){
		returneError = I2C_enumTimeOut;
	}

	/*Check on the value of status of TWI*/
	if((TWSR & GET_STATUS_MSK)!=START_COND_TRANSMITTED){
		returneError = I2C_enumWrongInOperation;
	}
	return returneError;

}
void I2C_SendSTOP(void){

	/*******************Implementation Part*************************/
	/*Clear Interrupt flag, and Send Stop Condition  */
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

I2C_enuErrorStatus I2C_SetSlaveAddress(u8 address,u8 generalCallActivate){
	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*******************Implementation Part*************************/

	if (address>MAX_ADDRESS_OF_SLAVES){
		//Error
	}else{

		TWAR = (address<<1)+generalCallActivate;
	}
	return returneError;
}
I2C_enuErrorStatus I2C_SendData(u8 data){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on the transmitted data*/
	if(data > MAX_DATA_VALUE){
		returneError = I2C_enumWrongData;

	}else{
		/*******************Implementation Part*************************/
		volatile u32 timeout =50000;
		TWDR= data;

		/*Clear Interrupt flag and enable TWI*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout == 0){
			returneError = I2C_enumTimeOut;
		}

		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=TX_DATA_TRANSMITTED_PLUS_ACK_RECEIVED){
			returneError = I2C_enumWrongInOperation;
		}

	}
	return returneError;

}

I2C_enuErrorStatus I2C_SendAddress(u8 address,u8 operation){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on the slave address*/
	if (address > MAX_ADDRESS_OF_SLAVES){
		returneError =I2C_enumWrongAddress;

	}else{
		/*******************Implementation Part*************************/
		volatile u32 timeout =50000;

		TWDR= (address<<1)+operation;

		/*Clear Interrupt flag and enable TWI*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout == 0){
			returneError = I2C_enumTimeOut;
		}

		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=TX_SLA_W_TRANSMITTED_PLUS_ACK_RECEIVED){
			returneError = I2C_enumWrongInOperation;
		}

	}
	return returneError;
}
I2C_enuErrorStatus I2C_SlaveReadData(u8* data){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on the data pointer value*/
	if(data == NULL){
		returneError =I2C_enumNULLPointer;
	}else{
		/*******************Implementation Part*************************/

		volatile u32 timeout =50000;

		/*First, Receive Slave Address*/

		/*Clear Interrupt flag, enable TWI and ACK*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN)|(ENABLE<<TWEA);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout == 0){
			returneError = I2C_enumTimeOut;
		}


		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=SLA_W_RECEIVED_PLUS_ACK_RETURNED){
			returneError = I2C_enumWrongInOperation;
		}

		/*Second, Receive data*/
		volatile u32  timeout2 =50000;

		/*Clear Interrupt flag, enable TWI and ACK*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN)|(ENABLE<<TWEA);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout2--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout2 == 0){
			returneError = I2C_enumTimeOut;
		}

		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=DATA_RECEIVED_SLA_PLUS_ACK_RETURNED){
			returneError = I2C_enumWrongInOperation;
		}

		*data = TWDR;

	}
	return returneError;
}
I2C_enuErrorStatus I2C_SendRepeatedStart(void){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*******************Implementation Part*************************/

	volatile u32 timeout =50000;

	/*Enable I2C, Clear Interrupt flag and Send Start Condition */
	TWCR =((ENABLE<<TWEN)|(ENABLE<<TWINT)|(ENABLE<<TWSTA));

	/*Wait on the TWI Interrupt Flag*/
	while(timeout--&&~((TWCR>>TWINT)&1));

	/*Check on time out*/
	if(timeout == 0){
		returneError = I2C_enumTimeOut;
	}

	/*Check on the value of status of TWI*/
	if((TWSR & GET_STATUS_MSK)!=REPEATED_START_COND_TRANSMITTED){
		returneError = I2C_enumWrongInOperation;
	}
	return returneError;
}

I2C_enuErrorStatus I2C_MasterReadDataWithACK(u8* data){
	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on the data pointer value*/
	if(data == NULL){
		returneError =I2C_enumNULLPointer;
	}else{
		/*******************Implementation Part*************************/

		volatile u32 timeout =50000;

		/*First, Receive Slave Address*/

		/*Clear Interrupt flag, enable TWI and ACK*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN)|(ENABLE<<TWEA);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout == 0){
			returneError = I2C_enumTimeOut;
		}


		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=RX_DATA_TRANSMITTED_PLUS_ACK_RECEIVED){
			returneError = I2C_enumWrongInOperation;
		}

		*data = TWDR;

	}
	return returneError;
}
I2C_enuErrorStatus I2C_MasterReadDataWithNACK(u8* data){

	/*******************Validation Part*************************/
	I2C_enuErrorStatus returneError =I2C_enumOk;

	/*Check on the data pointer value*/
	if(data == NULL){
		returneError =I2C_enumNULLPointer;
	}else{
		/*******************Implementation Part*************************/

		volatile u32 timeout =50000;

		/*First, Receive Slave Address*/

		/*Clear Interrupt flag and enable TWI*/
		TWCR =(ENABLE<<TWINT)|(ENABLE<<TWEN);

		/*Wait on the TWI Interrupt Flag*/
		while(timeout--&&~((TWCR>>TWINT)&1));

		/*Check on time out*/
		if(timeout == 0){
			returneError = I2C_enumTimeOut;
		}


		/*Check on the value of status of TWI*/
		if((TWSR & GET_STATUS_MSK)!=RX_DATA_TRANSMITTED_PLUS_NACK_RECEIVED){
			returneError = I2C_enumWrongInOperation;
		}

		*data = TWDR;

	}
	return returneError;
}
