/*author : shuhan mirza

date: 25/1/2015

*/

#define F_CPU 1000000

#define setBit(port, bit)   (_SFR_BYTE(port)|=(1<<bit))
#define clearBit(port, bit) (_SFR_BYTE(port)&=~(1<<bit))

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "lcd.h"
#include "sonar.h"





int main()
{
	setBit(DDRB,PB0);
	setBit(DDRB,PB3);
		
	setBit(PORTB,PB0); //vcc
	clearBit(PORTB,PB3);//gnd
	
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
	lcd_init (LCD_DISP_ON);
	
	char ch[10];
	int distance_in_cm =0 ;
	
   while(1)
   {
	  distance_in_cm = read_sonar();
	  
	  
	  if (distance_in_cm == TRIG_ERROR)
	  {
		  lcd_gotoxy(0,0);
		  lcd_puts("ERROR!!!");
		  _delay_ms(DELAY_BETWEEN_TESTS/2);
		  lcd_clrscr();
		  _delay_ms(DELAY_BETWEEN_TESTS/2);
		  
		init_sonar();
		distance_in_cm=0;
	  }
	  else if (distance_in_cm == ECHO_ERROR)
	  {
		  lcd_gotoxy(0,0);
		  lcd_puts("CLEAR!!!");
		  _delay_ms(DELAY_BETWEEN_TESTS);
		  lcd_clrscr();
	  }
	  else
	  {
		  lcd_gotoxy(0,0);
		  lcd_puts("Distance is");
		 
		 itoa(distance_in_cm,ch,10);
		 lcd_gotoxy(10,1);
		 lcd_puts(ch);
		 
		 
		  _delay_ms(DELAY_BETWEEN_TESTS);
		  lcd_clrscr();
	  }
   }

	
}