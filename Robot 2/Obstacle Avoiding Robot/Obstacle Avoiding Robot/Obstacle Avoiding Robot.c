#define F_CPU 1000000
#define setBit(port, bit)   (_SFR_BYTE(port)|=(1<<bit))
#define clearBit(port, bit) (_SFR_BYTE(port)&=~(1<<bit))

#define MOTORPORT	  PORTB
#define LEFTMOTORA	  PB1
#define LEFTMOTORB	  PB0
#define RIGHTMOTORA   PB3
#define RIGHTMOTORB	  PB2

#include <avr/io.h>
#include <util/delay.h>



void pwm_init()
{
	setBit(DDRD, PD4);	// output mode
	setBit(DDRD, PD5);	// output mode
	
	TCCR1A |= (1<<WGM10);				//fast pwm 8 bit
	TCCR1B |= (1<<WGM12);				//fast pwm 8 bit
	TCCR1A |= (1<<COM1A1)|(1<<COM1B1);	//enable OC1A and OC1B
	
	TCCR1B |= (1<<CS11);				//set timer1 prescaler 8
	
	OCR1A = 100;		//duty cycle for motor2
	OCR1B = 100;		//duty cycle for motor1
}


void Robot_Forward()
{
	setBit(MOTORPORT, LEFTMOTORB);		// high
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	
	setBit(MOTORPORT, RIGHTMOTORB);		// high
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
}

void Robot_Backward()
{
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	setBit(MOTORPORT, LEFTMOTORA);		// high
	
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
	setBit(MOTORPORT, RIGHTMOTORA);		// high
}

void Robot_Left()
{
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	setBit(MOTORPORT, LEFTMOTORA);		// high
	
	setBit(MOTORPORT, RIGHTMOTORB);		// high
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
}

void Robot_Right()
{
	setBit(MOTORPORT, LEFTMOTORB);		// high
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
	setBit(MOTORPORT, RIGHTMOTORA);		// high
}

void Robot_Stop()
{
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
}





int main(void)
{
   
   DDRD = 0xff;
   DDRB=0xff;
   
   pwm_init();
   
   
   
   while(1)
   {
	   _delay_ms(5000);
	   
	   Robot_Forward();
	   _delay_ms(1000);
	   
	   Robot_Backward();
	   _delay_ms(1000);
	   
	   Robot_Stop();
	   _delay_ms(4000);
	   
	  Robot_Right(); //45
	  _delay_ms(70);
	  Robot_Stop();
	  _delay_ms(2000);
		   
		   Robot_Left(); //90
		   _delay_ms(47.5 * 5.2);
		   Robot_Stop();
		   _delay_ms(2000);
		   
		   Robot_Right(); //180
		   _delay_ms(90 * 5.2);
		   Robot_Stop();
		   _delay_ms(2000);
	   
	   
	   Robot_Left();//360
	   _delay_ms(190 * 5.2);
	   Robot_Stop();
	   _delay_ms(2000);
   }
}