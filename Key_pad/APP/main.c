/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: dell
 */

#include "../HAL/KEY_PAD/Key_int.h"
#include "../HAL/7Segment/7_segment.h"
#include "../MCAL/DIO.h"

int main(){
	HKPD_voidInt();
	HSSD_voidInit(PORTB);//11111111

	u8 L_Num=100;
	while(1){
		L_Num=HKPD_u8GetPressedKey();
		HSSD_VoidDisplayNumber(PORTB,L_Num-'0');
	}
	return 0;
}
