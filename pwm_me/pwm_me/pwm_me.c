/*
 * pwm_me.c
 *
 * Created: 1/31/2015 3:31:55 PM
 *  Author: Shahee Mirza
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>


void pwm_init_pB()
{
	DDRB |= (1<<PB3);
	
	 TCCR0 |= (1<< WGM00) | (1<< WGM01) ; //fast pwm mode
	 
	 TCCR0 |= (1<< COM00) | (1<<COM01); // enable OC0
	 
	 TCCR0 |= (1 << CS01);
	 
	 OCR0 =255;
}

int main(void)
{
	int i;
	pwm_init_pB();
	
    while(1)
    {
        for(i=0;i<=255 ;i++)
		{
		  OCR0=i;
		  _delay_ms(50);	
		}
		
		 for( i=255; i>=0 ;i--)
		 {
			 OCR0=i;
			 _delay_ms(50);
		 }
		
		
    }
}