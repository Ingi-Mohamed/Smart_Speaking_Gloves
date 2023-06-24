#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DioInterface.h"
#include"DIO_registers.h"

void DioSetPinDirection(u8 port,u8 pin,u8 direction){
if(direction==OUTPUT){
switch(port){
case PORTA: SET_BIT(DDRA_REG,pin);	break;
case PORTB: SET_BIT(DDRB_REG,pin);	break;	
case PORTC: SET_BIT(DDRC_REG,pin);	break;
case PORTD: SET_BIT(DDRD_REG,pin);	break;
	
}	

	
}
else if (direction==INPUT){
	switch(port){
case PORTA: CLR_BIT(DDRA_REG,pin);	break;
case PORTB: CLR_BIT(DDRB_REG,pin);  break; 
case PORTC: CLR_BIT(DDRC_REG,pin);	break;
case PORTD: CLR_BIT(DDRD_REG,pin);	break;
	}
	
}	
}
void DioSetPinValue(u8 port,u8 pin,u8 value){
	if(value==1){
switch(port){
case PORTA: SET_BIT(PORTA_REG,pin);	break;
case PORTB: SET_BIT(PORTB_REG,pin);	break;	
case PORTC: SET_BIT(PORTC_REG,pin);	break;
case PORTD: SET_BIT(PORTD_REG,pin);	break;
	
}	

	
}
else if (value==0){
	switch(port){
case PORTA: CLR_BIT(PORTA_REG,pin);	break;
case PORTB: CLR_BIT(PORTB_REG,pin);  break; 
case PORTC: CLR_BIT(PORTC_REG,pin);	break;
case PORTD: CLR_BIT(PORTD_REG,pin);	break;
	}
	
}	
}
u8 DioGetPinValue(u8 port,u8 pin){
    u8 result=0xff;
	switch(port){
case PORTA: result=GET_BIT(PINA_REG,pin);	break;
case PORTB: result=GET_BIT(PINB_REG,pin);  break; 
case PORTC: result=GET_BIT(PINC_REG,pin);	break;
case PORTD: result=GET_BIT(PIND_REG,pin);	break; 	}
	return result;
	
}
void DioSetPortDirection(u8 port,u8 direction){
switch(port){
case PORTA: DDRA_REG=direction;	break;
case PORTB: DDRB_REG=direction;	break;	
case PORTC: DDRC_REG=direction;	break;
case PORTD: DDRD_REG=direction;	break;
	
}	
	
}	
void DioSetPortValue(u8 port,u8 value){
	switch(port){
case PORTA: PORTA_REG=value;	break;
case PORTB: PORTB_REG=value;	break;	
case PORTC: PORTC_REG=value;	break;
case PORTD: PORTD_REG=value;	break;
	}	
	
	
	
	
	
	
}
u8 DioGetPortValue(u8 port){
    u8 result=0x00;
	switch(port){
case PORTA: result=PINA_REG;	break;
case PORTB: result=PINB_REG;	break;
case PORTC: result=PINC_REG;	break;
case PORTD: result=PIND_REG;	break; 	}
	return result;
	
}

