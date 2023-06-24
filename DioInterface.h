#ifndef  DioInterface_H
#define  DioInterface_H
#include"STD_TYPES.h"
#include"DIO_registers.h"
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
//----------------------------
#define OUTPUT 1
#define INPUT  0
//----------------------------
void DioSetPinDirection(u8 port,u8 pin,u8 directon);
void DioSetPinValue(u8 port,u8 pin,u8 value);
u8 DioGetPinValue(u8 port,u8 pin);
u8 DioGetPortValue(u8 port);
void DioSetPortDirection(u8 port,u8 directon);
void DioSetPortValue(u8 port,u8 value);
#endif