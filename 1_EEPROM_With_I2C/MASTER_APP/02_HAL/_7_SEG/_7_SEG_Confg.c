/*
 * _7_SEG_Confg.c
 *
 * Created: 12/18/2023 5:41:32 PM
 *  Author: FatmaEzzat
 */ 
#include "_7_SEG_Confg.h"

/*Create an array of 7 Segment*/
_7_SEG_strCfg _7SEGs[NUM_OF_7SEG]=
     {      
	  [_7_SEG1]={ /*For the first 7Seg*/
		  .PINs[_7_SEG_LED1].Port = DIO_enumPortC,      /*The first LED*/
		  .PINs[_7_SEG_LED1].Pin  = DIO_enumPin0,
		  .PINs[_7_SEG_LED2].Port = DIO_enumPortC,      /*The Second LED*/
		  .PINs[_7_SEG_LED2].Pin  = DIO_enumPin1,
		  .PINs[_7_SEG_LED3].Port = DIO_enumPortC,      /*The third LED*/
		  .PINs[_7_SEG_LED3].Pin  = DIO_enumPin2, 
		  .PINs[_7_SEG_LED4].Port = DIO_enumPortC,      /*The fourth LED*/    
		  .PINs[_7_SEG_LED4].Pin  = DIO_enumPin3,
		  .PINs[_7_SEG_LED5].Port = DIO_enumPortC,      /*The fifth LED*/
		  .PINs[_7_SEG_LED5].Pin  = DIO_enumPin4,
		  .PINs[_7_SEG_LED6].Port = DIO_enumPortC,      /*The sixth LED*/
		  .PINs[_7_SEG_LED6].Pin  = DIO_enumPin5,
		  .PINs[_7_SEG_LED7].Port = DIO_enumPortC,      /*The seventh LED*/
		  .PINs[_7_SEG_LED7].Pin  = DIO_enumPin6,
		  .PINs[_7_SEG_DOT].Port  = DIO_enumPortC,      /*The Dot LED*/ 
		  .PINs[_7_SEG_DOT].Pin   = DIO_enumPin7,
		  /*The Seven Segment Configuration*/
		  .confgType = COMMON_Anode
	  }
	  
	};
