
#ifndef ADC_INTERFACE_H
#define	ADC_INTERFACE_H
#include "ADC_registers.h"
#include"BIT_MATH.h"
#include "STD_TYPES.h"
void ADC_Init();
u16 ADC_GetResult();
void ADC_SetChannel(u8 channel);
void ADC_InterruptEnable();
u16 ADC_Interrupt_GetResult();
void ADC_AutoTriggerEnable();
void ADC_StartConversion();
#endif

