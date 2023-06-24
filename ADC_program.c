/*
 * File:   ADC_program.c
 * Author: Ingi
 *
 * Created on September 30, 2022, 2:06 PM
 */
#include<avr/io.h>
#include"ADC_interface.h"

void ADC_Init(){
    // CHANNEL             ADC0 00000
  /*  CLR_BIT(ADMUX,4);
    CLR_BIT(ADMUX,3);
    CLR_BIT(ADMUX,2);
    CLR_BIT(ADMUX,1);
    CLR_BIT(ADMUX,0);*/
    //VREF
    //7 6
    //0 1 AVCC
    SET_BIT(ADMUX,6); 
    CLR_BIT(ADMUX,7);
    
    // Prescaler Configuration as 128
    SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);
    //enable ADC
    SET_BIT(ADCSRA,7);
    //ADJUST Right 
    CLR_BIT(ADMUX,5);
    //set ADC interrupt enable
    //SET_BIT(ADCSRA,3);

}
u16 ADC_GetResult(){

 //start conversion
    u16 result=0;
    SET_BIT(ADCSRA,6);
 while(GET_BIT(ADCSRA,4)==0);
            //CLEAR FLAG
   SET_BIT(ADCSRA,4);
   //result=ADCL+(GET_BIT(ADCH,0)*(2^8))+(GET_BIT(ADCH,1)*(2^9));
   result=ADCL;
    return result;
  }
void ADC_SetChannel(u8 channel){
    
   //11100000 
    //9          0000 1001
    //             0000 0001
    channel&=0x07;//to insure input not exceeding 8 channels 
ADMUX&=0b11100000; 
ADMUX|=channel; 
}
void ADC_InterruptEnable(){
SET_BIT(ADCSRA,3);
}
u16 ADC_Interrupt_GetResult(){

   u16 result=0;
   result=ADCL;
    return result;
  }
void ADC_AutoTriggerEnable(){

SET_BIT(ADCSRA,5); //AUTO TRIGGER ENABLE
//source of triggering free running 000
 CLR_BIT(SFIOR,7);
 CLR_BIT(SFIOR,6);
 CLR_BIT(SFIOR,5);

}
void ADC_StartConversion(){

    //start conversion
    SET_BIT(ADCSRA,6);
}