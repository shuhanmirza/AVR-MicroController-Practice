#define F_CPU 1000000UL


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR (INT0_vect)
{
	PORTC ^=(1<<PC1);
}

int main(void)
{
	DDRC = 0b11000000;
	
	MCUCR |= (1<<ISC00);
	
	GICR |=(1<<INT0);
	
	sei();
	
    while(1)
    {
        PORTC |= (1<<PC0);
		
		_delay_ms(3000); 
		
		 PORTC &= ~(1<<PC0);
		 
		 _delay_ms(3000);
    }
}