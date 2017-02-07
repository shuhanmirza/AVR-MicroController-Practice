

#ifndef KEYPAD_H_
#define KEYPAD_H_

/*************************************************************************
 Title	:   C include file for Multiplexed 4x4 keypad (keypad.c)
 Author:    GSM Rana <gsmranay@gmail.com>  http://gsmworldbd.tripod.com
 File:	    $Id: KEYPAD.h,v 1.0.0.0 2012/01/12 19:51:33 GSM Project $
 Software:  AVR-GCC 3.3
 Hardware:  any AVR device

Program to use of Multiplexed 4x4 keypad with AVR Micro controller.

******************************************************************************/

#if (__GNUC__ * 100 + __GNUC_MINOR__) < 303
#error "This library requires AVR-GCC 3.3 or later, update to newer AVR-GCC compiler !"
#endif

#include <inttypes.h>
#include <avr/pgmspace.h>


/**
 *  @name Definitions for Multiplexed 4x4 keypad
 *  Change KEYPAD_PORT if you want to use a different port for the keypad.
  
 KEYPAD

	ROW1 ->	PIN3
	ROW2 -> PIN2
	ROW3 ->	PIN1
	ROW4 -> PIN0
	
	COL1 ->	PIN4
	COL2 ->	PIN5
	COL3 ->	PIN6
	COL4 ->	PIN7
	 
 ***************************************************************************/

//define number of row and COL
#define KEYPAD_ROW	4     //number of keypad row between 1<->4
#define KEYPAD_COL	4     //number of keypad COL between 1<->4


//define single port for keypad
#define KEYPAD_DATA_PORT		PORTD				//port for keypad data line
#define KEYPAD_DATA_PIN 		PIND				//pin for keypad data line


//define for row COL different port
#define KEYPAD_ROW_PORT		KEYPAD_DATA_PORT		//port for keypad row data line
#define KEYPAD_COL_PORT		KEYPAD_DATA_PORT		//port for keypad COL data line
#define KEYPAD_ROW_PIN		KEYPAD_DATA_PIN		//port for keypad row data line
#define KEYPAD_COL_PIN		KEYPAD_DATA_PIN		//port for keypad COL data line

//define specific pin for row
#define KEYPAD_ROW1_PORT		KEYPAD_ROW_PORT			//port for keypad row1 data line
#define KEYPAD_ROW2_PORT		KEYPAD_ROW_PORT			//port for keypad row2 data line
#define KEYPAD_ROW3_PORT		KEYPAD_ROW_PORT			//port for keypad row3 data line
#define KEYPAD_ROW4_PORT		KEYPAD_ROW_PORT			//port for keypad row4 data line
#define KEYPAD_ROW1_PIN			3						//pin for keypad row1 data line 
#define KEYPAD_ROW2_PIN			2						//pin for keypad row2 data line 
#define KEYPAD_ROW3_PIN			1						//pin for keypad row3 data line 
#define KEYPAD_ROW4_PIN			0						//pin for keypad row4 data line 

//define specific pin for COL
#define KEYPAD_COL1_PORT		KEYPAD_COL_PORT		//port for keypad COL1 data line
#define KEYPAD_COL2_PORT		KEYPAD_COL_PORT		//port for keypad COL2 data line
#define KEYPAD_COL3_PORT		KEYPAD_COL_PORT		//port for keypad COL3 data line
#define KEYPAD_COL4_PORT		KEYPAD_COL_PORT		//port for keypad COL4 data line 
#define KEYPAD_COL1_PIN		4						//pin for keypad COL1 data line           
#define KEYPAD_COL2_PIN		5						//pin for keypad COL2 data line 
#define KEYPAD_COL3_PIN		6						//pin for keypad COL3 data line 
#define KEYPAD_COL4_PIN		7						//pin for keypad COL4 data line 



/** 
 *  @name Functions
 */

/**
 @brief		Initialize keypad with with row and COL 
 @param		r : number of row   
            c : number of COL 
 @return	none
*/
extern void keypad_fixedpin_init();

/**
 @brief		Initialize keypad with with row and COL 
 @param		r : number of row   
            c : number of COL 
 @return	none
*/
extern void keypad_specificpin_init(void);

/**
 @brief		Initialize keypad with with row and COL 
 @param		r : number of row   
            c : number of COL 
 @return	none
*/
extern void keypad_init(void);		

/**
 @brief		Detect any key press in keypad and give output recently (not pause program)
 @param		none  
             
 @return	Any number between 11-44 depending on 
			press key row and COL position
*/
extern uint8_t get_key_press_fixedpin(void);	//input pin number fixed as shown in header file

/**
 @brief		Detect any key click in keypad and pause program until release button
 @param		none    
             
 @return	Any number between 11-44 depending on 
			click key row and COL position
*/
extern uint8_t get_key_click_fixedpin(void);	//input pin number can be changed via header file

/**
 @brief		Detect any key press in keypad and give output recently (not pause program)
 @param		none  
             
 @return	Any number between 11-44 depending on 
			press key row and COL position
*/
extern uint8_t get_key_press_specificpin(void);

/**
 @brief		Detect any key click in keypad and pause program until release button
 @param		none    
             
 @return	Any number between 11-44 depending on 
			click key row and COL position
*/
extern uint8_t get_key_click_specificpin(void);

/**
 @brief		Detect any key press in keypad and give output recently (not pause program)
 @param		none  
             
 @return	Any number between 11-44 depending on 
			press key row and COL position
*/
extern uint8_t get_key_press(void);

/**
 @brief		Detect any key click in keypad and pause program until release button
 @param		none    
             
 @return	Any number between 11-44 depending on 
			click key row and COL position
*/
extern uint8_t get_key_click(void);



#endif /* KEYPAD_H_ */