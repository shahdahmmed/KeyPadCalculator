/*
 * Key_prog.c
 *
 *  Created on: Aug 14, 2023
 *      Author: dell
 */

#include "../../MCAL/DIO.h"
#include "../../LIB/STD_TYPES.h"
#include "Key_int.h"
#include <util/delay.h>

#define SIZE 4

static const u8 GKPD_KEYS[4][4]={{'7','8','9','/'},
		                         {'4','5','6','*'},
								 {'1','2','3','-'},
								 {'c','0','=','+'}};


void HKPD_voidInt()
{
MDIO_voidSetPortDirection(KPD_PORT,0X0f);
MDIO_voidSetPortValue(KPD_PORT,0Xff);

}

u8 HKPD_u8GetPressedKey()
{
	u8 PressedKey=70;
	for (u8 col = 0; col < SIZE; col++) {
	    MDIO_voidSetPinValue(KPD_PORT, col, LOW);  // Activate a column by setting it to LOW
	    for (u8 row = 0; row < SIZE; row++) {
	        if (MDIO_U8GetPinValue(KPD_PORT, row + 4) == 0) {  // Check if the corresponding row is LOW
	            PressedKey = GKPD_KEYS[col][row];  // Corrected the indices here
	        }
	        while (MDIO_U8GetPinValue(KPD_PORT, row + 4) == 0) {
	            // Wait for the key to be released
	        }
	        _delay_ms(10);  // Debounce delay
	    }
	    MDIO_voidSetPinValue(KPD_PORT, col, HIGH);  // Deactivate the column by setting it to HIGH
	}

	return PressedKey;
}
