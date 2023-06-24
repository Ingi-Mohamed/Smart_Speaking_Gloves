
#ifndef ADC_REGISTERS_H
#define	ADC_REGISTERS_H 

#include "STD_TYPES.h"

#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)
#define ADCL  *((volatile u16*)0x24)
#define ADCH  *((volatile u8*)0x25)
#define SFIOR  *((volatile u8*)0x50)


#endif

