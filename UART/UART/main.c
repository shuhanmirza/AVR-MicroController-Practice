#define F_CPU 1000000


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "uart.h"


char buff[7];

int main(void)
{
	uart_init(UART_BAUD_SELECT(4800, F_CPU));
	sei();
	DDRB = 0xFF;
    
	uart_putc('T');
	
	uart_puts("This is a test String...");
	
	int value = 12345;
	itoa(value, buff, 10);
	uart_puts(buff);
	
    while(1)
    {
		char ch = uart_getc();
		
		if ( ch != UART_NO_DATA )
		{
			uart_putc(ch+1);
			PORTB = 1;
		}
		else PORTB = 2;
		
    }
}
