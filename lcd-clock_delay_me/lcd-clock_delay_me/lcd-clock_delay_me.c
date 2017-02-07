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


//GLOBAL VARIABLE
long long i,j,init;
long long       hour,minute,second,flag,h;
char      ch[5];
//	

void print_num(int num,int x,int y)
{
	
	itoa(num,ch,10);
	lcd_gotoxy(x,y);
	lcd_puts(ch);
}


void toggle_flag()
{
	if(flag==1)
	{
		flag=0;
	}
	
	else
	{
		flag=1;
	}
}


void set_time_hour()
{
	while (!(PIND & (1<<PD0)))
	{
		
	
		lcd_gotoxy(0,0);
		lcd_puts("Set Hour");
	
		print_num(hour,10,0);
	
		if(!(PIND & (1<<PD2)))
		{
			if(hour == 12)
			{
				hour=1;
			}
		
			else
				{
					hour++;
				}
				
				_delay_ms(500);
		}	
	
	_delay_ms(100);
	lcd_clrscr();
	}
	
	
}


void set_time_minute()
{
	while (!(PIND & (1<<PD0)))
	{
		
		
		lcd_gotoxy(0,0);
		lcd_puts("Set minute");
		
		print_num(minute,12,0);
		
		if(!(PIND & (1<<PD2)))
		{
			if(minute == 59)
			{
				minute=0;
			}
			
			else
			{
				minute++;
			}
			_delay_ms(500);
		}
		
		_delay_ms(100);
		lcd_clrscr();
	}
	
}


void set_time_flag()
{
	while (!(PIND & (1<<PD0)))
	{
		
		lcd_gotoxy(0,0);
		
		if(flag == 0)  lcd_puts("AM");
		else lcd_puts("PM");
		
		_delay_ms(250);
		lcd_clrscr();
		_delay_ms(100);
		
		
		if(!(PIND & (1<<PD2)))
		{
			toggle_flag();
			_delay_ms(500);
		}
		
		
	}
}





int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	
	DDRD &=~ (1<<PD2);
	DDRD &=~ (1<<PD0);
	
	lcd_init (LCD_DISP_ON);
	
	hour = 12;
	second = 0;
	minute = 0;
	flag = 0;
	
	
	
	set_time_hour();
	_delay_ms(1000);
	set_time_minute();
	_delay_ms(1000);
	set_time_flag();
	
	lcd_clrscr();
	if(hour == 12) h=0;
	else h=hour;
	
     init = ((h*3600) + (minute * 60));
	
    while(1)
    {
		
	   
	   
	
	   
	   
			for(i=init ; i < 43200 ;i++)
			{
				init=0;
				
				lcd_clrscr();
				
				
				lcd_gotoxy(5,0);
	   lcd_puts("CLOCK:");
				
				//hour
				j=i;
              	h=(j/3600);
				  
				 if(h<1) hour = 12;
				 else hour=h;
				  
				  	print_num(hour,1,1);
					  
					  lcd_gotoxy(4,1);
					  lcd_putc(':');
					  
					  
					  
					//minute
					
					  j=i%3600;
					  
					  minute=j/60;
					  
					 print_num(minute,6,1);
						
						lcd_gotoxy(9,1);
					 lcd_putc(':');
					 
					  
					  //second
					  
					  j=i%60;
					  
					  second=j;
					  
					print_num(second,11,1);
					
					//Flag
					if(flag == 0) 
					{
						lcd_gotoxy(14,1);
						lcd_puts("AM");
					}
					  else
					  {
						  lcd_gotoxy(14,1);
						  lcd_puts("PM");
					  }
					  
					  //toggle
					  
					  if(i == 43199)
					  {
						
						   toggle_flag();
					  }
					  
					  
					  
					  //delay
					  _delay_us(994800);
              	
			}
	
}

}
	
