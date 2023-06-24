/*
 * File:   main.c
 * Author: Ingi
 *
 * Created on September 30, 2022, 4:45 PM
 */
#define F_CPU 8000000
#include"ADC_interface.h"
#include"DioInterface.h"
#include "UART_interface.h"
#include "LCD.h"
#include<avr/delay.h>
#include "UART_interface.h"
#include "ADXL.h"
#define flex_sensor_port PORTA
#define flex_sensor1_pin  0
#define flex_sensor2_pin  1
#define flex_sensor3_pin  2
u16 results[3] = {};
u8 i = 0;
u8 final_result = 0b00000000;
u8 prev_final_result=0x00;
u8 translated_msg[9][30] = {"Welcome","I need help ", "I need coffee ", "I need food ", "I need to use WC ", "I need water ", "I need medicine ", "I need to go out "," "};
u8 trial=8;
void main(void) {
   
    DioSetPinDirection(PORTD,1,OUTPUT);
    DioSetPinValue(PORTD,1,0);
    UART_Init();
    _delay_ms(5); 
    DioSetPinDirection(flex_sensor_port, flex_sensor1_pin, INPUT);
    DioSetPinDirection(flex_sensor_port, flex_sensor2_pin, INPUT);
    DioSetPinDirection(flex_sensor_port, flex_sensor3_pin, INPUT);
    LCD_Init();
    ADC_Init();
    ADC_AutoTriggerEnable();
    ADC_SetChannel(i);
    _delay_ms(5);
    ADC_StartConversion();
     LCD_WriteString(translated_msg[0]);
        UART_Transmit_String(translated_msg[0]);
    while (1) {
    	prev_final_result=final_result;
        for (i = 0; i < 3; i++) {

            
            //check on flex sensor resding 
            //we have 8 combinations from 0 to 7 --> array

            results[i] = ADC_GetResult(); //0-1023
            if (i < 2)
                ADC_SetChannel(i + 1);
            else if (i == 2)
                ADC_SetChannel(0);
            _delay_ms(5);
            if (results[i] > 250) {
                CLR_BIT(final_result, i);
            }
            if ((results[i] > 100)&&(results[i] < 240)) {
                SET_BIT(final_result, i);
            }

            _delay_ms(50);

        }

        if (i == 3 && prev_final_result!=final_result) {
            LCD_Clear();
            LCD_GoToXy(0,0);
            switch (final_result) {
                 case 0b00000000:
                    { LCD_WriteString(translated_msg[8]);
                UART_Transmit_String(translated_msg[8]);
                    break;}
                
                case 0b00000001:
                    { LCD_WriteString(translated_msg[1]);
                UART_Transmit_String(translated_msg[1]);
                    break;}
                case 0b00000010:
                     { LCD_WriteString(translated_msg[2]);
                UART_Transmit_String(translated_msg[2]);
                    break;}
                case 0b00000011:
                 { LCD_WriteString(translated_msg[3]);
                UART_Transmit_String(translated_msg[3]);
                    break;}
                case 0b00000100:
                 { LCD_WriteString(translated_msg[4]);
                UART_Transmit_String(translated_msg[4]);
                    break;}
                case 0b00000101:
                    { LCD_WriteString(translated_msg[5]);
                UART_Transmit_String(translated_msg[5]);
                    break;}
                case 0b00000110:
                    { LCD_WriteString(translated_msg[6]);
                UART_Transmit_String(translated_msg[6]);
                    break;}
                case 0b00000111:
                     { LCD_WriteString(translated_msg[7]);
                UART_Transmit_String(translated_msg[7]);
                    break;}

            }
            _delay_ms(100);
           

        }
        }
    return;
}
