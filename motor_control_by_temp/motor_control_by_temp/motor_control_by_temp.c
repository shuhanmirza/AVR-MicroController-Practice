/*
 * motor_control_by_temp.c
 *
 * Created: 11-Jan-15 10:25:36 AM
 *  Author: Shuhan
 */ 


#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>



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
	DDRC= 0b11000000;
	
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	adc_init ();//ADC initialization
	
	
	
	
	
	
	while(1)
	{
      int adc_val = adc_Read();
		
		if( adc_val > 45 && adc_val < 58 ) // when 27C > Temp > 22C
		{
			PORTC |= (1<<PC0) | (1<<PC1);
		}
		
		else if(adc_val <= 45)    //when temp <= 22C
		{
			PORTC=0;
		}
		
		else   //when temp > 27C
		{
			PORTC=1;
		}
		
    }
}