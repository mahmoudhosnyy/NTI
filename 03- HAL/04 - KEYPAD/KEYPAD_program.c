/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 22 Oct 2023				*/
/* Version : V01                        */
/****************************************/

#include<util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

#include "DIO_interface.h"


u8 COL_PORT_ARR[4]=COL_PORT_DATA;
u8 COL_PIN_ARR[4]=COL_PIN_DATA;
u8 ROW_PORT_ARR[4]=ROW_PORT_DATA;
u8 ROW_PIN_ARR[4]=ROW_PIN_DATA;

void KEYPAD_init(void){
	
	for (u8 row_counter=0;row_counter<4;row_counter++){
	DIO_SetPinDirection(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],INPUT);
	}
	
	for (u8 col_counter=0;col_counter<4;col_counter++){
	DIO_SetPinDirection(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter],INPUT); 
	}
}

u8 KEYPAD_getPressedKey(void){
	u8 col_counter,row_counter;
	while (1){
		for (row_counter=0;row_counter<KEYPAD_NUM_ROWS;row_counter++){
		DIO_SetPinDirection(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],OUTPUT);
		DIO_SetPinValue(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],LOW);
		
		 for (col_counter=0;col_counter<KEYPAD_NUM_COLS;col_counter++){
			if (DIO_GetPinValue(COL_PORT_ARR[col_counter],COL_PIN_ARR[col_counter])== KEYPAD_BUTTON_PRESSED){
				return KEYPAD_4x4_adjustKeyNumber((row_counter*KEYPAD_NUM_COLS)+col_counter+1);
			}
		}
	    DIO_SetPinDirection(ROW_PORT_ARR[row_counter],ROW_PIN_ARR[row_counter],INPUT);
		_delay_ms(5);
		}
	}
}

static u8 KEYPAD_4x4_adjustKeyNumber(u8 position){
	u8 keypad_button=0;
	switch (position){
			case 1: keypad_button = 7;
					break;
			case 2: keypad_button = 8;
					break;
			case 3: keypad_button = 9;
					break;
			case 4: keypad_button = '%'; // ASCII Code of %
					break;
			case 5: keypad_button = 4;
					break;
			case 6: keypad_button = 5;
					break;
			case 7: keypad_button = 6;
					break;
			case 8: keypad_button = '*'; /* ASCII Code of '*' */
					break;
			case 9: keypad_button = 1;
					break;
			case 10: keypad_button = 2;
					break;
			case 11: keypad_button = 3;
					break;
			case 12: keypad_button = '-'; /* ASCII Code of '-' */
					break;
			case 13: keypad_button = 13;  /* ASCII of Enter */
					break;
			case 14: keypad_button = 0;
					break;
			case 15: keypad_button = '='; /* ASCII Code of '=' */
					break;
			case 16: keypad_button = '+'; /* ASCII Code of '+' */
					break;
	}
	return keypad_button;
}


