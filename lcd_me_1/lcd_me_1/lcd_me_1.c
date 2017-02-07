#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

#include "lcd.h"





char ch[20];

int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	
	
	
	long long i,j;
	
	
	
	lcd_init (LCD_DISP_ON);
	
	lcd_puts("shuhan");
	
	_delay_ms(3000);
	
	lcd_clrscr();
	
	
   
	while(1)
    {
		lcd_gotoxy(1,1);
		lcd_putc('0');
		
       for(i=1  ; i<=99999999 ; i++)
	   {
		   j=i-1;
		   itoa(j,ch,10);
		   lcd_gotoxy(0,0);
		   lcd_puts(ch);
		   
		   itoa(i,ch,10);
		   lcd_gotoxy(0,1);
		   lcd_puts(ch);
		   
		   if(i%100==0)
		   {
			   lcd_gotoxy(9,1);
			   lcd_puts("muhaha");
		   }
		   
		   
		   
		    if(j%100==0)
		    {
			    lcd_gotoxy(9,0);
			    lcd_puts("muhaha");
		    }
		    
		   
		   
		   
		   
		   
		   
		   
		   _delay_ms(300);
		   lcd_clrscr();
		   
	  }
	   
	   
	   
	   
    }
}