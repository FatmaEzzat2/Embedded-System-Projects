/*
 * PORT.c
 *
 * Created: 12/3/2023 9:43:13 AM
 *  Author: FatmaEzzat
 */ 
#include "PORT.h"

/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin. 
 *@param  : void
 *@return : void                                             
 */	

void PORT_vidInit(void){
	
#if   CONFG_TYPE == PRECOMPILE

/*Set Configuration for pins*/
/*For Pin 0 --> PORTA*/
#if   PORT_PORTA_PIN0 == INPUT_PU
 #define PIN0_DIR         PORT_LOW 
 #define PIN0_PORT	      PORT_HIGH
#elif PORT_PORTA_PIN0 == INPUT_HI
 #define PIN0_DIR         PORT_LOW
 #define PIN0_PORT	      PORT_LOW
#elif  PORT_PORTA_PIN0 == OUTPUT
 #define PIN0_DIR         PORT_HIGH
 #define PIN0_PORT	      PORT_LOW
#else
 #error "Invalid Configuration" 
#endif

/*For Pin 1 --> PORTA*/
#if   PORT_PORTA_PIN1 == INPUT_PU
#define PIN1_DIR          PORT_LOW
#define PIN1_PORT	      PORT_HIGH
#elif PORT_PORTA_PIN1 == INPUT_HI
#define PIN1_DIR          PORT_LOW
#define PIN1_PORT	      PORT_LOW
#elif  PORT_PORTA_PIN1 == OUTPUT
#define PIN1_DIR          PORT_HIGH
#define PIN1_PORT	      PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 2 --> PORTA*/
#if   PORT_PORTA_PIN2 == INPUT_PU
#define PIN2_DIR          PORT_LOW
#define PIN2_PORT	      PORT_HIGH
#elif PORT_PORTA_PIN2 == INPUT_HI
#define PIN2_DIR          PORT_LOW
#define PIN2_PORT	      PORT_LOW
#elif  PORT_PORTA_PIN2 == OUTPUT
#define PIN2_DIR          PORT_HIGH
#define PIN2_PORT	      PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 3 --> PORTA*/
#if   PORT_PORTA_PIN3 == INPUT_PU
#define PIN3_DIR          PORT_LOW
#define PIN3_PORT	      PORT_HIGH
#elif PORT_PORTA_PIN3 == INPUT_HI
#define PIN3_DIR          PORT_LOW
#define PIN3_PORT	      PORT_LOW
#elif  PORT_PORTA_PIN3 == OUTPUT
#define PIN3_DIR          PORT_HIGH
#define PIN3_PORT	      PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 4 --> PORTA*/
#if   PORT_PORTA_PIN4 == INPUT_PU
#define PIN4_DIR         PORT_LOW
#define PIN4_PORT	     PORT_HIGH
#elif PORT_PORTA_PIN4 == INPUT_HI
#define PIN4_DIR         PORT_LOW
#define PIN4_PORT	     PORT_LOW
#elif  PORT_PORTA_PIN4 == OUTPUT
#define PIN4_DIR         PORT_HIGH
#define PIN4_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 5 --> PORTA*/
#if   PORT_PORTA_PIN5 == INPUT_PU
#define PIN5_DIR         PORT_LOW
#define PIN5_PORT	     PORT_HIGH
#elif PORT_PORTA_PIN5 == INPUT_HI
#define PIN5_DIR         PORT_LOW
#define PIN5_PORT	     PORT_LOW
#elif  PORT_PORTA_PIN5 == OUTPUT
#define PIN5_DIR         PORT_HIGH
#define PIN5_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 6 --> PORTA*/
#if   PORT_PORTA_PIN6 == INPUT_PU
#define PIN6_DIR         PORT_LOW
#define PIN6_PORT	     PORT_HIGH
#elif PORT_PORTA_PIN6 == INPUT_HI
#define PIN6_DIR         PORT_LOW
#define PIN6_PORT	     PORT_LOW
#elif  PORT_PORTA_PIN6 == OUTPUT
#define PIN6_DIR         PORT_HIGH
#define PIN6_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 7 --> PORTA*/
#if   PORT_PORTA_PIN7 == INPUT_PU
#define PIN7_DIR         PORT_LOW
#define PIN7_PORT	     PORT_HIGH
#elif PORT_PORTA_PIN7 == INPUT_HI
#define PIN7_DIR         PORT_LOW
#define PIN7_PORT	     PORT_LOW
#elif  PORT_PORTA_PIN7 == OUTPUT
#define PIN7_DIR         PORT_HIGH
#define PIN7_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 0 --> PORTB*/
#if   PORT_PORTB_PIN0 == INPUT_PU
#define PIN8_DIR         PORT_LOW
#define PIN8_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN0 == INPUT_HI
#define PIN8_DIR         PORT_LOW
#define PIN8_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN0 == OUTPUT
#define PIN8_DIR         PORT_HIGH
#define PIN8_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 1 --> PORTB*/
#if   PORT_PORTB_PIN1 == INPUT_PU
#define PIN9_DIR         PORT_LOW
#define PIN9_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN1 == INPUT_HI
#define PIN9_DIR         PORT_LOW
#define PIN9_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN1 == OUTPUT
#define PIN9_DIR         PORT_HIGH
#define PIN9_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 2 --> PORTB*/
#if   PORT_PORTB_PIN2 == INPUT_PU
#define PIN10_DIR        PORT_LOW
#define PIN10_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN2 == INPUT_HI
#define PIN10_DIR        PORT_LOW
#define PIN10_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN2 == OUTPUT
#define PIN10_DIR        PORT_HIGH
#define PIN10_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 3 --> PORTB*/
#if   PORT_PORTB_PIN3 == INPUT_PU
#define PIN11_DIR        PORT_LOW
#define PIN11_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN3 == INPUT_HI
#define PIN11_DIR        PORT_LOW
#define PIN11_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN3 == OUTPUT
#define PIN11_DIR        PORT_HIGH
#define PIN11_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 4 --> PORTB*/
#if   PORT_PORTB_PIN4 == INPUT_PU
#define PIN12_DIR        PORT_LOW
#define PIN12_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN4 == INPUT_HI
#define PIN12_DIR        PORT_LOW
#define PIN12_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN4 == OUTPUT
#define PIN12_DIR        PORT_HIGH
#define PIN12_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 5 --> PORTB*/
#if   PORT_PORTB_PIN5 == INPUT_PU
#define PIN13_DIR        PORT_LOW
#define PIN13_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN5 == INPUT_HI
#define PIN13_DIR        PORT_LOW
#define PIN13_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN5 == OUTPUT
#define PIN13_DIR        PORT_HIGH
#define PIN13_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 6 --> PORTB*/
#if   PORT_PORTB_PIN6 == INPUT_PU
#define PIN14_DIR        PORT_LOW
#define PIN14_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN6 == INPUT_HI
#define PIN14_DIR        PORT_LOW
#define PIN14_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN6 == OUTPUT
#define PIN14_DIR        PORT_HIGH
#define PIN14_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 7 --> PORTB*/
#if   PORT_PORTB_PIN7 == INPUT_PU
#define PIN15_DIR        PORT_LOW
#define PIN15_PORT	     PORT_HIGH
#elif PORT_PORTB_PIN7 == INPUT_HI
#define PIN15_DIR        PORT_LOW
#define PIN15_PORT	     PORT_LOW
#elif  PORT_PORTB_PIN7 == OUTPUT
#define PIN15_DIR        PORT_HIGH
#define PIN15_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 0 --> PORTC*/
#if   PORT_PORTC_PIN0 == INPUT_PU
#define PIN16_DIR        PORT_LOW
#define PIN16_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN0 == INPUT_HI
#define PIN16_DIR        PORT_LOW
#define PIN16_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN0 == OUTPUT
#define PIN16_DIR        PORT_HIGH
#define PIN16_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 1 --> PORTC*/
#if   PORT_PORTC_PIN1 == INPUT_PU
#define PIN17_DIR        PORT_LOW
#define PIN17_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN1 == INPUT_HI
#define PIN17_DIR        PORT_LOW
#define PIN17_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN1 == OUTPUT
#define PIN17_DIR        PORT_HIGH
#define PIN17_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 2 --> PORTC*/
#if   PORT_PORTC_PIN2 == INPUT_PU
#define PIN18_DIR        PORT_LOW
#define PIN18_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN2 == INPUT_HI
#define PIN18_DIR        PORT_LOW
#define PIN18_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN2 == OUTPUT
#define PIN18_DIR        PORT_HIGH
#define PIN18_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 3 --> PORTC*/
#if   PORT_PORTC_PIN3 == INPUT_PU
#define PIN19_DIR        PORT_LOW
#define PIN19_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN3 == INPUT_HI
#define PIN19_DIR        PORT_LOW
#define PIN19_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN3 == OUTPUT
#define PIN19_DIR        PORT_HIGH
#define PIN19_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 4 --> PORTC*/
#if   PORT_PORTC_PIN4 == INPUT_PU
#define PIN20_DIR        PORT_LOW
#define PIN20_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN4 == INPUT_HI
#define PIN20_DIR        PORT_LOW
#define PIN20_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN4 == OUTPUT
#define PIN20_DIR        PORT_HIGH
#define PIN20_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 5 --> PORTC*/
#if   PORT_PORTC_PIN5 == INPUT_PU
#define PIN21_DIR        PORT_LOW
#define PIN21_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN5 == INPUT_HI
#define PIN21_DIR        PORT_LOW
#define PIN21_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN5 == OUTPUT
#define PIN21_DIR        PORT_HIGH
#define PIN21_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 6 --> PORTC*/
#if   PORT_PORTC_PIN6 == INPUT_PU
#define PIN22_DIR        PORT_LOW
#define PIN22_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN6 == INPUT_HI
#define PIN22_DIR        PORT_LOW
#define PIN22_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN6 == OUTPUT
#define PIN22_DIR        PORT_HIGH
#define PIN22_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 7 --> PORTC*/
#if   PORT_PORTC_PIN7 == INPUT_PU
#define PIN23_DIR        PORT_LOW
#define PIN23_PORT	     PORT_HIGH
#elif PORT_PORTC_PIN7 == INPUT_HI
#define PIN23_DIR        PORT_LOW
#define PIN23_PORT	     PORT_LOW
#elif  PORT_PORTC_PIN7 == OUTPUT
#define PIN23_DIR        PORT_HIGH
#define PIN23_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 0 --> PORTD*/
#if   PORT_PORTD_PIN0 == INPUT_PU
#define PIN24_DIR        PORT_LOW
#define PIN24_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN0 == INPUT_HI
#define PIN24_DIR        PORT_LOW
#define PIN24_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN0 == OUTPUT
#define PIN24_DIR        PORT_HIGH
#define PIN24_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 1 --> PORTD*/
#if   PORT_PORTD_PIN1 == INPUT_PU
#define PIN25_DIR        PORT_LOW
#define PIN25_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN1 == INPUT_HI
#define PIN25_DIR        PORT_LOW
#define PIN25_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN1 == OUTPUT
#define PIN25_DIR        PORT_HIGH
#define PIN25_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 2 --> PORTD*/
#if   PORT_PORTD_PIN2 == INPUT_PU
#define PIN26_DIR        PORT_LOW
#define PIN26_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN2 == INPUT_HI
#define PIN26_DIR        PORT_LOW
#define PIN26_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN2 == OUTPUT
#define PIN26_DIR        PORT_HIGH
#define PIN26_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 3 --> PORTD*/
#if   PORT_PORTD_PIN3 == INPUT_PU
#define PIN27_DIR        PORT_LOW
#define PIN27_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN3 == INPUT_HI
#define PIN27_DIR        PORT_LOW
#define PIN27_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN3 == OUTPUT
#define PIN27_DIR        PORT_HIGH
#define PIN27_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 4 --> PORTD*/
#if   PORT_PORTD_PIN4 == INPUT_PU
#define PIN28_DIR        PORT_LOW
#define PIN28_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN4 == INPUT_HI
#define PIN28_DIR        PORT_LOW
#define PIN28_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN4 == OUTPUT
#define PIN28_DIR        PORT_HIGH
#define PIN28_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 5 --> PORTD*/
#if   PORT_PORTD_PIN5 == INPUT_PU
#define PIN29_DIR        PORT_LOW
#define PIN29_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN5 == INPUT_HI
#define PIN29_DIR        PORT_LOW
#define PIN29_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN5 == OUTPUT
#define PIN29_DIR        PORT_HIGH
#define PIN29_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 6 --> PORTD*/
#if   PORT_PORTD_PIN6 == INPUT_PU
#define PIN30_DIR        PORT_LOW
#define PIN30_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN6 == INPUT_HI
#define PIN30_DIR        PORT_LOW
#define PIN30_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN6 == OUTPUT
#define PIN30_DIR        PORT_HIGH
#define PIN30_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/*For Pin 7 --> PORTD*/
#if   PORT_PORTD_PIN7 == INPUT_PU
#define PIN31_DIR        PORT_LOW
#define PIN31_PORT	     PORT_HIGH
#elif PORT_PORTD_PIN7 == INPUT_HI
#define PIN31_DIR        PORT_LOW
#define PIN31_PORT	     PORT_LOW
#elif  PORT_PORTD_PIN7 == OUTPUT
#define PIN31_DIR        PORT_HIGH
#define PIN31_PORT	     PORT_LOW
#else
#error "Invalid Configuration"
#endif

/* concatenate the pins in the registers */
/*For PORTA Registers*/
DDRA = CONCAT(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR);
PORTA= CONCAT(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);

/*For PORTB Registers*/
DDRB = CONCAT(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR);
PORTB= CONCAT(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT);

/*For PORTC Registers*/
DDRC = CONCAT(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR);
PORTC= CONCAT(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT);

/*For PORTD Registers*/
DDRD = CONCAT(PIN31_DIR,PIN30_DIR,PIN29_DIR,PIN28_DIR,PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_DIR);
PORTD= CONCAT(PIN31_PORT,PIN30_PORT,PIN29_PORT,PIN28_PORT,PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT);

#elif CONFG_TYPE == POSTCOMPILE
PORTS Loc_enuPortNum;
PINS Loc_enuPinNum;

extern PORT_enuPinOpt PORT_PinConfg[NUM_OF_PINS];

for(int i=0 ; i < NUM_OF_PINS ; i++){
	
	/*Get PORT Number -->PORTA = 0,PORTB = 1,PORTC = 2,PORTD = 3*/
	Loc_enuPortNum = i / 8;
	
	/*Get PIN Number to use it to assign the values in DDRx and PORTx Registers*/
	Loc_enuPinNum  = i % 8;
	
	/*Steps :
	1-Check on PORT Number : PORT_A ,PORT_B ,PORT_C,PORT_D
	2-Check on the configuration of the specific pin
	*/
	switch(Loc_enuPortNum){
		case PORT_A :
		switch(PORT_PinConfg[i]){
			case PORT_enuInput_PU:
			CLR_BIT(DDRA,Loc_enuPinNum);
			SET_BIT(PORTA,Loc_enuPinNum);
			break;
			
			case PORT_enuInput_HI:
			CLR_BIT(DDRA,Loc_enuPinNum);
			CLR_BIT(PORTA,Loc_enuPinNum);
			break;
			
			case PORT_enuOutput:
			SET_BIT(DDRA,Loc_enuPinNum);
			break;
			default:
			break;
		}
		break;
		
		case PORT_B:
		switch(PORT_PinConfg[i]){
			
			case PORT_enuInput_PU:
			CLR_BIT(DDRB,Loc_enuPinNum);
			SET_BIT(PORTB,Loc_enuPinNum);
			break;
			
			case PORT_enuInput_HI:
			CLR_BIT(DDRB,Loc_enuPinNum);
			CLR_BIT(PORTB,Loc_enuPinNum);
			break;
			
			case PORT_enuOutput:
			SET_BIT(DDRB,Loc_enuPinNum);
			break;
			default:
			break;
		}
		break;
		case PORT_C:
		switch(PORT_PinConfg[i]){
			case PORT_enuInput_PU:
			CLR_BIT(DDRC,Loc_enuPinNum);
			SET_BIT(PORTC,Loc_enuPinNum);
			break;
			
			case PORT_enuInput_HI:
			CLR_BIT(DDRC,Loc_enuPinNum);
			CLR_BIT(PORTC,Loc_enuPinNum);
			break;
			
			case PORT_enuOutput:
			SET_BIT(DDRC,Loc_enuPinNum);
			break;
			default:
			break;
		}
		break;
		case PORT_D:
		switch(PORT_PinConfg[i]){
			case PORT_enuInput_PU:
			CLR_BIT(DDRD,Loc_enuPinNum);
			SET_BIT(PORTD,Loc_enuPinNum);
			break;
			case PORT_enuInput_HI:
			CLR_BIT(DDRD,Loc_enuPinNum);
			CLR_BIT(PORTD,Loc_enuPinNum);
			break;
			case PORT_enuOutput:
			SET_BIT(DDRD,Loc_enuPinNum);
			break;
			default:
			break;
		}
		break;
		default:
		break;
}
#endif
}
}