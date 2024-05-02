
/*
 * Assembler1.S
 *
 * Created: 12/5/2023 11:04:39 AM
 *  Author: KimoStore
 */ 
 /*For Pin 2 --> PORTB*/
#if   DIO_PIN10 == INPUT_PU
#define PIN10_DIR        PORT_LOW
#define PIN10_PORT	    PORT_HIGH
#elif DIO_PIN10 == INPUT_HI
#define PIN10_DIR        PORT_LOW
#define PIN10_PORT	    PORT_LOW
#elif  DIO_PIN10 == OUTPUT_LOW
#define PIN10_DIR        PORT_HIGH
#define PIN10_PORT	    PORT_LOW
#elif  DIO_PIN10 == OUTPUT_HIGH
#define PIN10_DIR        PORT_HIGH
#define PIN10_PORT	    PORT_HIGH
#else
#error "Invalid Configuration"
#endif
