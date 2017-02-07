/*
 * lcd_stopwatch_me.c
 *
 * Created: 08-Jan-15 10:51:48 AM
 *  Author: Shuhan
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	long long i,h,m,s,j;
	char ch[3];
	
	DDRD &=~ (1<<PD2);
	
	lcd_init (LCD_DISP_ON);

	
    while(1)
    {
		lcd_gotoxy(0,0);
       lcd_puts("Press the button");
	   lcd_gotoxy(0,1);
	   lcd_puts("to start");
	   
	   
	 if (!(PIND & (1<<PD2)))
	  {
	   
	   
			for(i=0 ; i<=99999999999 ;i++)
			{
				lcd_clrscr();
				
				
				
				//hour
				j=i;
              	h=(j/3600);
				  
				  if(h==1000)
				  {
					  lcd_puts("overflow");
					  _delay_ms(10000);
					  break;
				  }
				  
				  	itoa(h,ch,10);
					  lcd_gotoxy(0,0);
					  lcd_puts(ch);
					  lcd_gotoxy(3,0);
					  lcd_putc('H');
					  
					  
					  
					//minute
					
					  j=i%3600;
					  
					  m=j/60;
					  
					  itoa(m,ch,10);
					  lcd_gotoxy(5,0);
					  lcd_puts(ch);
					  lcd_gotoxy(7,0);
					  lcd_puts("MIN");
					  
					  //second
					  
					  j=i%60;
					  
					  s=j;
					  
					  itoa(s,ch,10);
					  lcd_gotoxy(11,0);
					  lcd_puts(ch);
					  lcd_gotoxy(13,0);
					  lcd_puts("sec");
					  
					  _delay_ms(1000);
					  
              	
			}
	
	  }
	
	}
}