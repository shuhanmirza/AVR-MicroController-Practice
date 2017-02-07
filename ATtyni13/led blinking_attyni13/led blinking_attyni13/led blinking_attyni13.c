/*
 * led_blinking_attyni13.c
 *
 * Created: 2/6/2015 7:29:02 PM
 *  Author: Shuhan Mirza
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB=0b000111;
	
    while(1)
    {
        
		
		PORTB = 0b000111;
		
		_delay_ms(1000);
		
		PORTB= 0b000000 ;
		
		_delay_ms(1000);
    }
}