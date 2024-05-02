/*
 * Registers.h
 *
 * Created: 12/3/2023 10:07:50 AM
 *  Author: FatmaEzzat
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

/*Data Direction Registers*/
#define DDRA   *((volatile u8*)(0X3A))
#define DDRB   *((volatile u8*)(0X37))
#define DDRC   *((volatile u8*)(0X34))
#define DDRD   *((volatile u8*)(0X31))

/*Output Registers*/
#define PORTA   *((volatile u8*)(0X3B))
#define PORTB   *((volatile u8*)(0X38))
#define PORTC   *((volatile u8*)(0X35))
#define PORTD   *((volatile u8*)(0X32))

/*Input Registers*/
#define PINA   *((volatile u8*)(0X39))
#define PINB   *((volatile u8*)(0X36))
#define PINC   *((volatile u8*)(0X33))
#define PIND   *((volatile u8*)(0X30))

/*Interrupt Registers*/
#define SREG    *((volatile u8*)(0x5F))
#define MCUCR   *((volatile u8*)(0x55))
#define MCUCSR  *((volatile u8*)(0x54))
#define GICR    *((volatile u8*)(0x5B))
#define GIFR    *((volatile u8*)(0x5A))

/*Timer0 Registers*/
#define TCCR0   *((volatile u8*)(0x53))
#define TCNT0   *((volatile u8*)(0x52))
#define TIMSK   *((volatile u8*)(0x59))
#define TIFR    *((volatile u8*)(0x58))
#define OCR0    *((volatile u8*)(0x5C))

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/*TCCR*/
#define		WGM00					 6
#define		COM01					 5
#define		COM00					 4
#define		WGM01					 3

/*Timer1 Registers*/
#define TCNT1  		*((volatile u16*)(0x4C))
#define OCR1A 		*((volatile u16*)(0x4A))
#define OCR1B 		*((volatile u16*)(0x48))
#define ICR1		*((volatile u16*)(0x46))

#define TCCR1B 		*((volatile u8*)(0x4E))
#define TCCR1A 		*((volatile u8*)(0x4F))

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0


/*GICR*/
#define INT1     7
#define INT0     6
#define INT2     5

/*SREG*/
#define I_BIT    7

/*MCUCSR*/
#define ISC2     6

#define NULL (void * )0


/*********I2C Registers******/
#define TWCR	 *((volatile u8*)(0x56))
#define TWDR	 *((volatile u8*)(0x23))
#define TWAR	 *((volatile u8*)(0x22))
#define TWSR	 *((volatile u8*)(0x21))
#define TWBR	 *((volatile u8*)(0x20))

/**TWAR**/
#define	TWGCE	0

/**TWCR**/
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

/**TWSR**/
#define TWPS0		0
#define TWPS1		1

#endif /* REGISTERS_H_ */
