/*
 * Key_int.h
 *
 *  Created on: Aug 14, 2023
 *      Author: dell
 */

#include "../../MCAL/DIO.h"
#include "../../LIB/STD_TYPES.h"

#ifndef KEY_INT_H_
#define KEY_INT_H_

#define KPD_PORT PORTA

void HKPD_voidInt();
u8 HKPD_u8GetPressedKey();

#endif /* KEY_INT_H_ */
