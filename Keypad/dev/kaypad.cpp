/*******************************************
 Title	:   Multiplexed 4x4 keypad library
 Author:    GSM Rana <gsmranay@gmail.com>  http://gsmworldbd.tripod.com
 File:	    $Id: keypad.c,v 1.0.0.0 2012/01/12 19:51:33 GSM Project $
 Software:  AVR-GCC 3.3
 Hardware:  any AVR device

Function return the keycode of keypress/keyclick
on the Keypad. Keys are numbered as follows

[11] [12] [13] [14]
[21] [22] [23] [24]
[31] [32] [33] [34]
[41] [42] [43] [44]


*******************************************/

#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include "keypad.h"

uint8_t new_keycode;
uint8_t prev_keycode;


/* 
** constants/macros 
*/
#define DDR(x) (*(&x - 1))      /* address of data direction register of port x */
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
    /* on ATmega64/128 PINF is on port 0x00 and not 0x60 */
    #define PIN(x) ( &PORTF==&(x) ? _SFR_IO8(0x00) : (*(&x - 2)) )
#else
	#define PIN(x) (*(&x - 2))    /* address of input register of port x          */
#endif


void keypad_fixedpin_init(void)		//input pin number fixed as shown in header file
{
	DDR(KEYPAD_ROW_PORT) &= ~(0x0F&(0x0F<<(4-KEYPAD_ROW)));		//all row pin as input
	DDR(KEYPAD_COL_PORT) &= ~(0xF0&(0xF0>>(4-KEYPAD_COL)));		//all COL pin as input
	KEYPAD_ROW_PORT &=  ~(0x0F&(0x0F<<(4-KEYPAD_ROW)));			//row 4 pins pull up low 
	KEYPAD_COL_PORT |=  (0xF0&(0xF0>>(4-KEYPAD_COL)));			//COL 4 pins pull up high	
}

void keypad_specificpin_init(void)	//input pin number can be changed via header file
{
	
	switch(KEYPAD_ROW){
		
		case 1:{
		//all row and COL pins as input
		DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN);
		
		//row pins pull up low
		KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
		}break;
		
		case 2:{
		//all row and COL pins as input
		DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN);
		DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN);
		
		//row pins pull up low
		KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
		KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
		}break;
		
		case 3:{
		//all row and COL pins as input
		DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN);
		DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN);
		DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN);
		
		//row pins pull up low
		KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
		KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
		KEYPAD_ROW3_PORT &= ~_BV(KEYPAD_ROW3_PIN);
		}break;
		
		case 4:{
		//all row and COL pins as input
		DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN);
		DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN);
		DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN);
		DDR(KEYPAD_ROW4_PORT) &= ~_BV(KEYPAD_ROW4_PIN);
		
		//row pins pull up low
		KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
		KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
		KEYPAD_ROW3_PORT &= ~_BV(KEYPAD_ROW3_PIN);
		KEYPAD_ROW4_PORT &= ~_BV(KEYPAD_ROW4_PIN);
		}break;
	}
	
	switch(KEYPAD_COL){
		
		case 1:{
		//all row and COL pins as input
		DDR(KEYPAD_COL1_PORT) &= ~_BV(KEYPAD_COL1_PIN);
		
		//COL pins pull up high
		KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
		}break;
		
		case 2:{
		//all row and COL pins as input
		DDR(KEYPAD_COL1_PORT) &= ~_BV(KEYPAD_COL1_PIN);
		DDR(KEYPAD_COL2_PORT) &= ~_BV(KEYPAD_COL2_PIN);
	
		//COL pins pull up high
		KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
		KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
		}break;
		
		case 3:{
		//all row and COL pins as input
		DDR(KEYPAD_COL1_PORT) &= ~_BV(KEYPAD_COL1_PIN);
		DDR(KEYPAD_COL2_PORT) &= ~_BV(KEYPAD_COL2_PIN);
		DDR(KEYPAD_COL3_PORT) &= ~_BV(KEYPAD_COL3_PIN);
	
		//COL pins pull up high
		KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
		KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
		KEYPAD_COL3_PORT |= _BV(KEYPAD_COL3_PIN);
		}break;
		
		case 4:{
		//all row and COL pins as input
		DDR(KEYPAD_COL1_PORT) &= ~_BV(KEYPAD_COL1_PIN);
		DDR(KEYPAD_COL2_PORT) &= ~_BV(KEYPAD_COL2_PIN);
		DDR(KEYPAD_COL3_PORT) &= ~_BV(KEYPAD_COL3_PIN);
		DDR(KEYPAD_COL4_PORT) &= ~_BV(KEYPAD_COL4_PIN);
	
		//COL pins pull up high
		KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
		KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
		KEYPAD_COL3_PORT |= _BV(KEYPAD_COL3_PIN);
		KEYPAD_COL4_PORT |= _BV(KEYPAD_COL4_PIN);
		}break;
	}		
	
			
}

void keypad_init(void)
{
	if ( ( &KEYPAD_ROW1_PORT == &KEYPAD_ROW2_PORT) && ( &KEYPAD_ROW2_PORT == &KEYPAD_ROW3_PORT ) && ( &KEYPAD_ROW3_PORT == &KEYPAD_ROW4_PORT )
      && ( &KEYPAD_COL1_PORT == &KEYPAD_COL2_PORT) && ( &KEYPAD_COL2_PORT == &KEYPAD_COL3_PORT ) && ( &KEYPAD_COL3_PORT == &KEYPAD_COL4_PORT ) )
		  
	keypad_fixedpin_init();
	
	else keypad_specificpin_init();
}


uint8_t get_key_down_fixedpin(void)		//use single port pins
{
	uint8_t r,c,prev_keycode1;
	
	//KEYPAD_DATA_PORT &=  ~(0x0F);			//row 4 pin pull up low 
	//KEYPAD_DATA_PORT |=  (0xF0);			//COL 4 pin pull up high	
	//prev_keycode1=prev_keycode;
	//prev_keycode=0;

	for(r=0;r<KEYPAD_ROW;r++)
	{
		DDR(KEYPAD_ROW_PORT) |= (0x08>>r);		//set 1 row pin output mode with previously set low sequentially 
		{
		for(c=0;c<KEYPAD_COL;c++)
			if(((KEYPAD_COL_PIN & (0x10<<c))==0))	//checking input COL pin as low sequentially due to they pull up high previously
			{
				new_keycode=((r+1)*10+(c+1));	
				
				if(new_keycode!=prev_keycode)
					{
					prev_keycode=new_keycode;
					return new_keycode;				//return press button row and COL position
					}
				//prev_keycode=new_keycode;				
				//return new_keycode;	
			}
		}
		DDR(KEYPAD_ROW_PORT) &= ~(0x08>>r);		//reset the set low row pins as input again sequentially 
	}
	
	return 0;	//no button press
}

uint8_t get_key_press_fixedpin(void)		//use single port pins
{
	uint8_t r,c;
	
	//KEYPAD_DATA_PORT &=  ~(0x0F);			//row 4 pin pull up low 
	//KEYPAD_DATA_PORT |=  (0xF0);			//COL 4 pin pull up high	

	for(r=0;r<KEYPAD_ROW;r++)
	{
		DDR(KEYPAD_ROW_PORT) |= (0x08>>r);		//set 1 row pin output mode with previously set low sequentially 
		{
		for(c=0;c<KEYPAD_COL;c++)
			if((KEYPAD_COL_PIN & (0x10<<c))==0)	//checking input COL pin as low sequentially due to they pull up high previously
			{
				return ((r+1)*10+(c+1));	//return press button row and COL position
			}
		}
		DDR(KEYPAD_ROW_PORT) &= ~(0x08>>r);		//reset the set low row pins as input again sequentially 
	}
	return 0;	//no button press
}
	
uint8_t get_key_click_fixedpin(void)		//use single port pins
{
	uint8_t r,c;
	
	//KEYPAD_DATA_PORT &=  ~(0x0F);			//row 4 pin pull up low 
	//KEYPAD_DATA_PORT |=  (0xF0);			//COL 4 pin pull up high	

	for(r=0;r<KEYPAD_ROW;r++)
	{
		DDR(KEYPAD_DATA_PORT) |= (0x08>>r);		//set 1 row pin output mode with previously set low sequentially 
		for(c=0;c<KEYPAD_COL;c++)
		{
			if((KEYPAD_DATA_PIN & (0x10<<c))==0)			//checking input COL pin as low sequentially due to they pull up high previously
			{
				while((KEYPAD_DATA_PIN & (0x10<<c))==0);	//wait until pull up COL pin goes high ie until release the button
				return ((r+1)*10+(c+1));					//return click button row and COL position
			}
		}	
		DDR(KEYPAD_DATA_PORT) &= ~(0x08>>r);		//reset the set low row pins as input again sequentially 
	}
	return 0;	//no button click
}


uint8_t get_key_down_specificpin(void)		//can be use different port pin
{
	uint8_t r,c,prev_keycode1;

	prev_keycode1=prev_keycode;
	prev_keycode=0;

	/*
	//row pin pull up low
	KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
	KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
	KEYPAD_ROW3_PORT &= ~_BV(KEYPAD_ROW3_PIN);
	KEYPAD_ROW4_PORT &= ~_BV(KEYPAD_ROW4_PIN);
	
	//COL pin pull up high
	KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
	KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
	KEYPAD_COL3_PORT |= _BV(KEYPAD_COL3_PIN);
	KEYPAD_COL4_PORT |= _BV(KEYPAD_COL4_PIN);
	*/
	
	
	for(r=1;r<=KEYPAD_ROW;r++)
	{				
		//set 1 row pin output mode with previously set low sequentially 
		switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) |= _BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) |= _BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) |= _BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) |= _BV(KEYPAD_ROW4_PIN); break;
			}		
		
		for(c=1;c<=KEYPAD_COL;c++)
		{
			//checking input COL pin as low sequentially due to they pull up high previously
			switch(c){
				
				case 1:{ 
				if((PIN(KEYPAD_COL1_PORT) & _BV(KEYPAD_COL1_PIN))==0) return ((r*10)+c);	//return press button row and COL position
				}break;
				
				case 2: { 
				if((PIN(KEYPAD_COL2_PORT) & _BV(KEYPAD_COL2_PIN))==0) return ((r*10)+c);
				}break;
				
				case 3: { 
				if((PIN(KEYPAD_COL3_PORT) & _BV(KEYPAD_COL3_PIN))==0) return ((r*10)+c);
				}break;
				
				case 4: { 
				if((PIN(KEYPAD_COL4_PORT) & _BV(KEYPAD_COL4_PIN))==0) return ((r*10)+c);
				}break;
				
				}//end switch

			}//end inner for
			//reset the set low row pins as input again sequentially 
			switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) &= ~_BV(KEYPAD_ROW4_PIN); break;
			}
	
	}//end outer for
	
	return 0;		//no button press	
}


uint8_t get_key_press_specificpin(void)		//can be use different port pin
{
	uint8_t r,c;

	/*
	//row pin pull up low
	KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
	KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
	KEYPAD_ROW3_PORT &= ~_BV(KEYPAD_ROW3_PIN);
	KEYPAD_ROW4_PORT &= ~_BV(KEYPAD_ROW4_PIN);
	
	//COL pin pull up high
	KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
	KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
	KEYPAD_COL3_PORT |= _BV(KEYPAD_COL3_PIN);
	KEYPAD_COL4_PORT |= _BV(KEYPAD_COL4_PIN);
	*/
	
	
	for(r=1;r<=KEYPAD_ROW;r++)
	{				
		//set 1 row pin output mode with previously set low sequentially 
		switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) |= _BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) |= _BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) |= _BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) |= _BV(KEYPAD_ROW4_PIN); break;
			}		
		
		for(c=1;c<=KEYPAD_COL;c++)
		{
			//checking input COL pin as low sequentially due to they pull up high previously
			switch(c){
				
				case 1:{ 
				if((PIN(KEYPAD_COL1_PORT) & _BV(KEYPAD_COL1_PIN))==0) return ((r*10)+c);	//return press button row and COL position
				}break;
				
				case 2: { 
				if((PIN(KEYPAD_COL2_PORT) & _BV(KEYPAD_COL2_PIN))==0) return ((r*10)+c);
				}break;
				
				case 3: { 
				if((PIN(KEYPAD_COL3_PORT) & _BV(KEYPAD_COL3_PIN))==0) return ((r*10)+c);
				}break;
				
				case 4: { 
				if((PIN(KEYPAD_COL4_PORT) & _BV(KEYPAD_COL4_PIN))==0) return ((r*10)+c);
				}break;
				
				}//end switch

			}//end inner for
			//reset the set low row pins as input again sequentially 
			switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) &= ~_BV(KEYPAD_ROW4_PIN); break;
			}
	
	}//end outer for
	
	return 0;		//no button press	
}
	
uint8_t gets_key_click_specificpin(void)		//can be use different port pin
{
	uint8_t r,c;

	/*
	//row pin pull up low
	KEYPAD_ROW1_PORT &= ~_BV(KEYPAD_ROW1_PIN);
	KEYPAD_ROW2_PORT &= ~_BV(KEYPAD_ROW2_PIN);
	KEYPAD_ROW3_PORT &= ~_BV(KEYPAD_ROW3_PIN);
	KEYPAD_ROW4_PORT &= ~_BV(KEYPAD_ROW4_PIN);
	
	//COL pin pull up high
	KEYPAD_COL1_PORT |= _BV(KEYPAD_COL1_PIN);
	KEYPAD_COL2_PORT |= _BV(KEYPAD_COL2_PIN);
	KEYPAD_COL3_PORT |= _BV(KEYPAD_COL3_PIN);
	KEYPAD_COL4_PORT |= _BV(KEYPAD_COL4_PIN);
	*/
	
	
	for(r=1;r<=KEYPAD_ROW;r++)
	{
		//reset all row pins as input
		DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN);
		DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN);
		DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN);
		DDR(KEYPAD_ROW4_PORT) &= ~_BV(KEYPAD_ROW4_PIN);
		
		//set 1 row pin output mode with previously set low sequentially 
		switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) |= _BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) |= _BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) |= _BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) |= _BV(KEYPAD_ROW4_PIN); break;
			}		
		
		for(c=1;c<=KEYPAD_COL;c++)
		{
			//checking input COL pin as low sequentially due to they pull up high previously
			switch(c){
				
				case 1:{ 
				if((PIN(KEYPAD_COL1_PORT) & _BV(KEYPAD_COL1_PIN))==0){ 
					//wait until pull up COL pin goes high ie until release the button
					while((PIN(KEYPAD_COL1_PORT) & _BV(KEYPAD_COL1_PIN))==0);
					return ((r*10)+c);				//return press button row and COL position
					}					
				}break;
				
				case 2: { 
				if((PIN(KEYPAD_COL2_PORT) & _BV(KEYPAD_COL2_PIN))==0){ 
					while((PIN(KEYPAD_COL2_PORT) & _BV(KEYPAD_COL2_PIN))==0);
					return ((r*10)+c);
					}					
				}break;
				
				case 3: { 
				if((PIN(KEYPAD_COL3_PORT) & _BV(KEYPAD_COL3_PIN))==0){ 
					while((PIN(KEYPAD_COL3_PORT) & _BV(KEYPAD_COL3_PIN))==0);
					return ((r*10)+c);
					}					
				}break;
				
				case 4: { 
				if((PIN(KEYPAD_COL4_PORT) & _BV(KEYPAD_COL4_PIN))==0){ 
					while((PIN(KEYPAD_COL4_PORT) & _BV(KEYPAD_COL4_PIN))==0);
					return ((r*10)+c);
					}					
				}break;
				
				}//end switch

			}//end inner for
			//reset the set low row pins as input again sequentially 
			switch(r){
			case 1: DDR(KEYPAD_ROW1_PORT) &= ~_BV(KEYPAD_ROW1_PIN); break;
			case 2: DDR(KEYPAD_ROW2_PORT) &= ~_BV(KEYPAD_ROW2_PIN); break;
			case 3: DDR(KEYPAD_ROW3_PORT) &= ~_BV(KEYPAD_ROW3_PIN); break;
			case 4: DDR(KEYPAD_ROW4_PORT) &= ~_BV(KEYPAD_ROW4_PIN); break;
			}
				
	}//end outer for
	
	return 0;		//no button click	
}

uint8_t get_key_press(void)
{
	if ( ( &KEYPAD_ROW1_PORT == &KEYPAD_ROW2_PORT) && ( &KEYPAD_ROW2_PORT == &KEYPAD_ROW3_PORT ) && ( &KEYPAD_ROW3_PORT == &KEYPAD_ROW4_PORT )
      && ( &KEYPAD_COL1_PORT == &KEYPAD_COL2_PORT) && ( &KEYPAD_COL2_PORT == &KEYPAD_COL3_PORT ) && ( &KEYPAD_COL3_PORT == &KEYPAD_COL4_PORT ) )
		  
	return get_key_press_fixedpin();
	
	else return get_key_press_specificpin();
}

uint8_t get_key_click(void)
{
	if ( ( &KEYPAD_ROW1_PORT == &KEYPAD_ROW2_PORT) && ( &KEYPAD_ROW2_PORT == &KEYPAD_ROW3_PORT ) && ( &KEYPAD_ROW3_PORT == &KEYPAD_ROW4_PORT )
      && ( &KEYPAD_COL1_PORT == &KEYPAD_COL2_PORT) && ( &KEYPAD_COL2_PORT == &KEYPAD_COL3_PORT ) && ( &KEYPAD_COL3_PORT == &KEYPAD_COL4_PORT ) )
		  
	return get_key_click_fixedpin();
	
	else return gets_key_click_specificpin();
}


