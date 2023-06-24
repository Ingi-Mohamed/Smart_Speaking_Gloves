#include"LCD.h"
#include"DioInterface.h"
#include<avr/delay.h>
void LCD_Init(){
DioSetPinDirection(dataport_1,d0,1);
DioSetPinDirection(dataport_1,d1,1);
DioSetPinDirection(dataport_2,d2,1);
DioSetPinDirection(dataport_2,d3,1);
DioSetPinDirection(dataport_2,d4,1);
DioSetPinDirection(dataport_2,d5,1);
DioSetPinDirection(dataport_2,d6,1);
DioSetPinDirection(dataport_2,d7,1);

DioSetPinDirection(controlport,RS,1);
DioSetPinDirection(controlport,RW,1);
DioSetPinDirection(controlport,E,1);
_delay_ms(50);
LCD_WriteCommand(FuncSet);
_delay_ms(1);
LCD_WriteCommand(OnOffControl);
_delay_ms(1);
LCD_WriteCommand(DisplayClear);
_delay_ms(5);
LCD_WriteCommand(EntryModeSet);
_delay_ms(1);
LCD_WriteCommand(SetHome);
	
}
void LCD_WriteData(u8 data){
DioSetPinValue(dataport_1,d0,GET_BIT(data,0));
DioSetPinValue(dataport_1,d1,GET_BIT(data,1));
DioSetPinValue(dataport_2,d2,GET_BIT(data,2));
DioSetPinValue(dataport_2,d3,GET_BIT(data,3));
DioSetPinValue(dataport_2,d4,GET_BIT(data,4));
DioSetPinValue(dataport_2,d5,GET_BIT(data,5));
DioSetPinValue(dataport_2,d6,GET_BIT(data,6));
DioSetPinValue(dataport_2,d7,GET_BIT(data,7));

DioSetPinValue(controlport,RS,1);
DioSetPinValue(controlport,RW,0);
DioSetPinValue(controlport,E,1);
_delay_ms(1);
DioSetPinValue(controlport,E,0);
_delay_ms(1);
}
void LCD_WriteCommand(u8 command){
DioSetPinValue(dataport_1,d0,GET_BIT(command,0));
DioSetPinValue(dataport_1,d1,GET_BIT(command,1));
DioSetPinValue(dataport_2,d2,GET_BIT(command,2));
DioSetPinValue(dataport_2,d3,GET_BIT(command,3));
DioSetPinValue(dataport_2,d4,GET_BIT(command,4));
DioSetPinValue(dataport_2,d5,GET_BIT(command,5));
DioSetPinValue(dataport_2,d6,GET_BIT(command,6));
DioSetPinValue(dataport_2,d7,GET_BIT(command,7));

DioSetPinValue(controlport,RS,0);
DioSetPinValue(controlport,RW,0);
DioSetPinValue(controlport,E,1);
_delay_ms(1);
DioSetPinValue(controlport,E,0);
_delay_ms(1);	
}
void LCD_GoToXy(u8 x,u8 y){
if((x>=0)&&(x<=15)&&((y==0)||(y==1))){
switch(y){
case 0:LCD_WriteCommand(128+x);	 break;
case 1:LCD_WriteCommand(192+x);	 break;	
}	
}
	
	
}

void LCD_WriteString(u8 *str){
	u8 i=0;
while(str[i]!='\0'){
	LCD_WriteData(str[i]);
	 _delay_ms(1);
	i++;
}	
	
}
void   LCD_Clear(){
   LCD_WriteCommand(0x01);
_delay_ms(10);
}

void LCD_WriteNumber(s16 number){
u16 number_reversed=0;	
if (number==0) LCD_WriteData('0');	
else if(number<0){number=-number;
while(number!=0){
number_reversed=number_reversed*10+number%10;
number/=10;
}
LCD_WriteData('-');
while(number_reversed!=0){
	LCD_WriteData((number_reversed%10)+'0');
	number_reversed/=10;
}


}
else{while(number!=0){
number_reversed=number_reversed*10+number%10;
number/=10;
}

while(number_reversed!=0){
	LCD_WriteData((number_reversed%10)+'0');
	number_reversed/=10;
}

}	
	
	
}
void LCD_ShiftRight(){
LCD_WriteCommand(0x05);
}
void LCD_ShiftLeft(){
LCD_WriteCommand(0x07);
}
void LCD_IncNoShift(){
LCD_WriteCommand(0x06);
}
void LCD_DecNoShift(){
LCD_WriteCommand(0x04);
}

