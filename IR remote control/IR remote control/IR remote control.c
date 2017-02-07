
#define F_CPU 8000000 UL

#include <avr/io.h>
#include "lcd.h"
#include "remote.h"
#include <stdlib.h>


int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;
	
   int  cmd=0;
   char ch[10];

	RemoteInit();
	
	lcd_init(LCD_DISP_ON);
	
	lcd_clrscr();
	
	
    while(1)
    {
       cmd=GetRemoteCmd(1);
	   
	   itoa(cmd,ch,10);
	   
	   lcd_gotoxy(5,0);
	   lcd_puts(ch);
	   
	   lcd_puts("                          ");	   
    }
}