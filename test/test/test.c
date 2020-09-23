#define F_CPU 1000000UL


#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "lcd.h"

int ERROR()
{
	uint8_t i,sens,sens_r,sens_l;
	uint8_t err_r=0;
	uint8_t err_l=0;
	sens=PINA;
	for (i=5;i<9;i++)
	{
		err_r++;
		sens_r=sens&(0b11111111>>i);
		if(sens_r==0) break;
	}
	for (i=5;i<8;i++)
	{
		err_l++;
		sens_l=sens&(0b11111111<<i);
		if(sens_l==0)break;
	}
	return (err_r-err_l);
}

int main(void)
{
	DDRB=0xFF;
	PORTB|=(1<<PB0);
	int error;
	char buffer[8];
	MCUCSR|=(1<<JTD);
	MCUCSR|=(1<<JTD);
	DDRC = 0xFF;
	DDRA = 0x00;
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	while(1)
	{
		error=ERROR();
		itoa(error,buffer,10);
		lcd_gotoxy(7,0);
		lcd_puts(buffer);
		
		_delay_ms(25);
		
		lcd_clrscr();
	}
}