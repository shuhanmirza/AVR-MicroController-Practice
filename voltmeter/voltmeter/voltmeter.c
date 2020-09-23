#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "lcd.h"


void adc_init()
{
	ADMUX |= (1<<REFS0);//set AVCC 5V as Vref
	ADCSRA |= (1<<ADEN);//Enable ADC Module
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);// set ADC prescaler to 128
	
}

int adc_Read()
{
	ADCSRA |= (1<<ADSC);//ADC Start convertion
	while(ADCSRA & (1<<ADSC));//wait for conversion complete
	return ADC;//read adc value
}



int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	adc_init ();//ADC initialization
	lcd_init (LCD_DISP_ON);
	
	
	
	
	
	while(1)
	{
		lcd_clrscr();
		char ch[20]={0};
		
		int adc_val = adc_Read();
		long long mvolt = adc_val * 102.5641026;
		
		ltoa(mvolt,ch,10);
		
		lcd_puts(ch);
		lcd_gotoxy(7,0);
		lcd_puts("mV");
		
		
		_delay_ms(100);
			
	}
}