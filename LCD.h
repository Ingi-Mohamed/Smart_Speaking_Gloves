#include"BIT_MATH.h"
#include"STD_TYPES.h"
//----------------------------------
#define LcdHome 0x02
#define FuncSet 0x38
#define OnOffControl 0x0c
#define DisplayClear 0x01
#define EntryModeSet 0x06
#define SetHome 0x80
//----------------------------------
#define RS 5
#define RW 6
#define E  7
#define d0 4
#define d1 3
#define d2 2
#define d3 3
#define d4 4
#define d5 5
#define d6 6
#define d7 7

//----------------------------------
#define dataport_2    PORTD
#define dataport_1    PORTC
#define controlport PORTC
//----------------------------------
void LCD_Init();
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_GoToXy(u8 x,u8 y);
void LCD_WriteNumber(s16 number);
void LCD_WriteString(u8 *str);
void   LCD_Clear();
void LCD_ShiftRight();
void LCD_ShiftLeft();
void LCD_IncNoShift();
void LCD_DecNoShift();