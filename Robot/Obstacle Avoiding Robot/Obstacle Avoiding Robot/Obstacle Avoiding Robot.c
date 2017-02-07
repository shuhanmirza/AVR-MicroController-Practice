#define F_CPU 1000000UL
#define setBit(port, bit)   (_SFR_BYTE(port)|=(1<<bit))
#define clearBit(port, bit) (_SFR_BYTE(port)&=~(1<<bit))

#define MOTORPORT	  PORTB
#define LEFTMOTORA	  PB1
#define LEFTMOTORB	  PB0
#define RIGHTMOTORA   PB3
#define RIGHTMOTORB	  PB2

#include <avr/io.h>
#include <util/delay.h>

void Robot_Forward()
{
	setBit(MOTORPORT, LEFTMOTORA);		// high
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	
	setBit(MOTORPORT, RIGHTMOTORA);		// high
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
}

void Robot_Backward()
{
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	setBit(MOTORPORT, LEFTMOTORB);		// high
	
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
	setBit(MOTORPORT, RIGHTMOTORB);		// high
}

void Robot_Left()
{
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	setBit(MOTORPORT, LEFTMOTORB);		// high
	
	setBit(MOTORPORT, RIGHTMOTORA);		// high
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
}

void Robot_Right()
{
	setBit(MOTORPORT, LEFTMOTORA);		// high
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
	setBit(MOTORPORT, RIGHTMOTORB);		// high
}

void Robot_Stop()
{
	clearBit(MOTORPORT, LEFTMOTORA);	// low
	clearBit(MOTORPORT, LEFTMOTORB);	// low
	
	clearBit(MOTORPORT, RIGHTMOTORA);	// low
	clearBit(MOTORPORT, RIGHTMOTORB);	// low
}

int detect_Obstacle()
{
	return 50;
}



int main(void)
{
    DDRD = 0xff;
DDRB=0xff;
	
	int i,j;
	
	while(1)
    {
		_delay_ms(5000);
		
        Robot_Forward();
		_delay_ms(1000);
		
		Robot_Backward();
		_delay_ms(1000);
		
		Robot_Stop();
		_delay_ms(4000);
		
	for(i=45;i<=720;i=i+45)
	{
		j=i*190;
		
	  if(i % 2 == 0)
	  {
		Robot_Right();
		
		
		_delay_ms(j);
		
		Robot_Stop();
		_delay_ms(4000);  
	  }
		
		 else
		 {
			 Robot_Left();
			 
			 
			 _delay_ms(j);
			 
			 Robot_Stop();
			 _delay_ms(4000);
		 }
		
    }
	}
}