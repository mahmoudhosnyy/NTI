/****************************************/
/* Author  : Mahmoud Hosny				*/
/* Date    : 21 Oct 2023				*/
/* Version : V01                        */
/****************************************/
#include <util\delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SEVENSEG_interface.h"
void main (void){
/* COUNTING FROM 0 TO 99 on 2 SEGMENTS and From 99 TO 0 on Another 2 Segments  */
	SEVENSEG_init();
	u8 seg1_counter=0;
	u8 seg2_counter=0;
	u8 seg3_counter=9;
	u8 seg4_counter=9;
	SEVENSEG_displayNum(seg1_counter,COM1);
	SEVENSEG_displayNum(seg2_counter,COM2);
	SEVENSEG_displayNum(seg3_counter,COM3);
	SEVENSEG_displayNum(seg4_counter,COM4);
	while (1){
		if ((seg1_counter==9 && seg2_counter<9) && (seg3_counter==0 && seg4_counter>0)){
			seg2_counter++;
			seg4_counter--;
			seg1_counter=0;
			seg3_counter=9;
		}
		
		else if (seg2_counter==9 && seg4_counter==0 ){
			u8 seg1_counter=0;
			u8 seg2_counter=0;
			u8 seg3_counter=9;
			u8 seg4_counter=9;
		}
		
		else {
			SEVENSEG_displayNum(seg1_counter,COM1);
			SEVENSEG_displayNum(seg2_counter,COM2);
			SEVENSEG_displayNum(seg3_counter,COM3);
			SEVENSEG_displayNum(seg4_counter,COM4);
			seg1_counter++;
			seg3_counter--;
		}
	}
	
}