
 
#ifndef UART_INTERFACE_H
#define	UART_INTERFACE_H
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_reg.h"

void UART_Init();
void UART_Transmit_Byte(u8 data);
u8 UART_Receive_Byte();
void UART_Transmit_String(u8* sent_string);
void UART_TransmitNumber(s16 number);
//void UART_Receive_String(u8 data);
#endif	

