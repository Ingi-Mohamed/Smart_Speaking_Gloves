
#ifndef UART_REG_H
#define	UART_REG_H
#define UDR     *((volatile u8*) 0x2C)
#define UCSRC   *((volatile u8*) 0x40)//UBRRH
#define UCSRA   *((volatile u8*) 0x2B)
#define UCSRB   *((volatile u16*) 0x2A)
#define UBRRL   *((volatile u8*) 0x29)






#endif	

