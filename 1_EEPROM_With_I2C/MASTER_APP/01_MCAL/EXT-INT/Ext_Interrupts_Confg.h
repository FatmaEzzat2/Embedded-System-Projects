/*
 * Ext_Interrupts_Confg.h
 *
 * Created: 12/24/2023 2:05:04 PM
 *  Author: FatmaEzzat
 */ 


#ifndef EXT_INTERRUPTS_CONFG_H_
#define EXT_INTERRUPTS_CONFG_H_

#define ENABLE     0
#define DISABLE    1

/*Determine the interrupts modes ---> Enable or Disable */
#define EXT_INT0_MODE   ENABLE    
#define EXT_INT1_MODE   ENABLE
#define EXT_INT2_MODE   ENABLE

/*Interrupt Sense Control --> For INT0 & INT1 */
#define INT01_LOW_LEVEL_TRIG      0
#define INT01_ANY_LOGIC_TRIG      1
#define INT01_FALLING_EDGE_TRIG   2
#define INT01_RISING_EDGE_TRIG    3

/*Interrupt Sense Control --> For INT2 */
#define INT2_FALLING_EDGE_TRIG    0
#define INT2_RISING_EDGE_TRIG     1

/*Choose the Interrupt sense control */
#define INT0_SENSE_MODE         INT01_FALLING_EDGE_TRIG
#define INT1_SENSE_MODE         INT01_RISING_EDGE_TRIG
#define INT2_SENSE_MODE         INT2_RISING_EDGE_TRIG
 
/*Generate masks for Interrupt Registers*/
/*
For MCUCR Register:
-INT0 sense control = (Bit 0: ISC00) & (Bit 1: ISC01)
-INT1 sense control = (Bit 2: ISC10) & (Bit 3: ISC11)
*/
#define MCUCR_INT0_MASK    0xFC     /*0b 1111 1100*/  
#define MCUCR_INT1_MASK    0xF3     /*0b 1111 0011*/

/*
typedef enum{
	INT0,
	INT1,
	INT2
}EXT_INT_Type;
*/
#endif /* EXT_INTERRUPTS_CONFG_H_ */
