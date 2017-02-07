/*************************************************************************
 Title	:   C include file for Multiplexed 4x4 keypad (keypad.c)
 Author:    GSM Rana <gsmranay@gmail.com>  http://gsmworldbd.tripod.com
 File:	    $Id: main_keypad.c,v 1.0.0.0 2012/01/12 19:51:33 GSM Project $
 Software:  AVR-GCC 3.3
 Hardware:  any AVR device

Program to use of Multiplexed 4x4 keypad with AVR Micro controller.

******************************************************************************/

#include <avr/io.h>
#include <stdlib.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "lcd.h"
#include "keypad.h"




void zero_fill(char *value)		// with leading zero
{           
  if (value[1] == 0) 
	  {                  
		value[1] = value[0];
		value[0] = '0';
	  }
}

void lcd_put_intXY(uint8_t x,uint8_t y,uint8_t num)
{
	char buffer[7];
	lcd_gotoxy(y-1,x-1);
	itoa( num , buffer, 10);	//convert int to string
    zero_fill(buffer);			//fill string with leading zero
	lcd_puts(buffer);
}

void lcd_putcXY(uint8_t x,uint8_t y,char ch)
{
	lcd_gotoxy(y-1,x-1);
	lcd_putc(ch);
}


void lcd_putsXY(uint8_t x,uint8_t y,char *txt)
{
	lcd_gotoxy(y-1,x-1);
	lcd_puts(txt);
}


int main(void)
{
  uint8_t cnt = 0;                              
  uint8_t kp = 0;
  uint8_t oldstate=0;
  
  lcd_init(LCD_DISP_ON);
  keypad_init();                                                     
  
  
  lcd_putsXY(1, 1, "Key  :");              
  lcd_putsXY(2, 1, "Times:");

  do {
    
		kp = 0;                                

				do{
				  //kp=get_key_click();
				  //kp = get_key_click();  
				  kp = get_key_press();
				  //kp=0;                        
				}while (!kp);
	
	//lcd_put_intXY(1, 10, kp); 			
	//keypad_state_check();		
    switch (kp) {

      case  11: kp = '1'; break; 
      case  21: kp = '2'; break; 
      case  31: kp = '3'; break; 
      case  41: kp = '4'; break; 
      case  12: kp = '5'; break; 
      case  22: kp = '6'; break; 
      case  32: kp = '7'; break; 
      case  42: kp = '8'; break;        
      case  13: kp = '9'; break; 
      case	23: kp = 'a'; break; 
      case	33: kp = 'b'; break; 
      case	43: kp = 'c'; break; 
      case	14: kp = 'd'; break; 
      case	24: kp = 'e'; break; 
      case	34: kp = 'f'; break; 
      case	44: kp = 'g'; break; 

    }

    if (kp != oldstate) {                  // click key differs from previous
      cnt = 1;
      oldstate = kp;
    }
    else {                                 // click key is same as previous
      cnt++;
    }

    lcd_putcXY(1, 10, kp);                   

    if (cnt == 255) {                      // If counter variable overflow
      cnt = 0;
      lcd_putsXY(2, 10, "   ");
    }

    lcd_put_intXY(2, 10, cnt);                  
  
  } while (1);


}
