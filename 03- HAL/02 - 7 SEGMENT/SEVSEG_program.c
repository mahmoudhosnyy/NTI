/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SEVENSEG_interface.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_private.h"

#include "DIO_interface.h"

void SEVSEG_init(void){
	#if COM_NUM==COM1
	DIO_SetPinValue(PORTA,PIN3,LOW);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	#elif COM_NUM==COM2
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,LOW);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	#elif COM_NUM==COM3
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,LOW);	
	DIO_SetPinValue(PORTB,PIN6,HIGH);
	#elif COM_NUM==COM4
	DIO_SetPinValue(PORTA,PIN3,HIGH);
	DIO_SetPinValue(PORTA,PIN2,HIGH);	
	DIO_SetPinValue(PORTB,PIN5,HIGH);	
	DIO_SetPinValue(PORTB,PIN6,LOW);
	#elif COM_NUM==ALL_COM
	DIO_SetPinValue(PORTA,PIN3,LOW);
	DIO_SetPinValue(PORTA,PIN2,LOW);	
	DIO_SetPinValue(PORTB,PIN5,LOW);	
	DIO_SetPinValue(PORTB,PIN6,LOW);
	#else 
		/*DO NOTHING */
	#endif
	
	/* SET DIRECTIONS FOR 7SEG & DIP_SWTICH */
	DIO_SetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN4,OUTPUT);
	
	DIO_SetPinDirection(PORTA,PIN3,OUTPUT);
	DIO_SetPinDirection(PORTA,PIN2,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN5,OUTPUT);
	DIO_SetPinDirection(PORTB,PIN6,OUTPUT);
}

void SEVENSEG_displayNum(u8 num){
	switch (num){
		case 0 :
		DIO_setPinValue(PORTB,PIN0,LOW);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 1 :
		DIO_setPinValue(PORTB,PIN0,HIGH);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 2:
		DIO_setPinValue(PORTB,PIN0,LOW);
		DIO_setPinValue(PORTB,PIN1,HIGH);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 3:
		DIO_setPinValue(PORTB,PIN0,HIGH);
		DIO_setPinValue(PORTB,PIN1,HIGH);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;		
		case 4:
		DIO_setPinValue(PORTB,PIN0,LOW);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,HIGH);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 5:
		DIO_setPinValue(PORTB,PIN0,HIGH);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,HIGH);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 6:
		DIO_setPinValue(PORTB,PIN0,LOW);
		DIO_setPinValue(PORTB,PIN1,HIGH);
		DIO_setPinValue(PORTB,PIN2,HIGH);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 7:
		DIO_setPinValue(PORTB,PIN0,HIGH);
		DIO_setPinValue(PORTB,PIN1,HIGH);
		DIO_setPinValue(PORTB,PIN2,HIGH);
		DIO_setPinValue(PORTB,PIN4,LOW);
		break;
		case 8:
		DIO_setPinValue(PORTB,PIN0,LOW);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,HIGH);
		break;
		case 9:
		DIO_setPinValue(PORTB,PIN0,HIGH);
		DIO_setPinValue(PORTB,PIN1,LOW);
		DIO_setPinValue(PORTB,PIN2,LOW);
		DIO_setPinValue(PORTB,PIN4,HIGH);
		break;
	}	
}