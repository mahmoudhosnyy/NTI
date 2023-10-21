/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 20 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


#include "DIO_interface.h"

void LED_init (void) {
	DIO_SetPinDirection(PORTB,PIN7,OUTPUT);
	DIO_SetPinDirection(PORTA,PIN4,OUTPUT);	
	DIO_SetPinDirection(PORTA,PIN5,OUTPUT);	
	DIO_SetPinDirection(PORTA,PIN6,OUTPUT);	
}

void LED_on(u8 led_colour){
	switch (led_colour){
		case LED_RED :
			DIO_SetValue(LED_RED_PORT,LED_RED_PIN,HIGH);
		break;
		case LED_GREEN :
			DIO_SetValue(LED_GREEN_PORT,LED_GREEN_PIN,HIGH);
		break;
		case LED_BLUE :
			DIO_SetValue(LED_BLUE_PORT,LED_BLUE_PIN,HIGH);
		break;
		case LED_YELLOW :
			DIO_SetValue(LED_YELLOW_PORT,LED_YELLOW_PIN,HIGH);
		break;		
	}
}

void LED_off(u8 led_colour){
	switch (led_colour){
		case LED_RED :
			DIO_SetValue(LED_RED_PORT,LED_RED_PIN,LOW);
		break;
		case LED_GREEN :
			DIO_SetValue(LED_GREEN_PORT,LED_GREEN_PIN,LOW);
		break;
		case LED_BLUE :
			DIO_SetValue(LED_BLUE_PORT,LED_BLUE_PIN,LOW);
		break;
		case LED_YELLOW :
			DIO_SetValue(LED_YELLOW_PORT,LED_YELLOW_PIN,LOW);
		break;		
	}
}