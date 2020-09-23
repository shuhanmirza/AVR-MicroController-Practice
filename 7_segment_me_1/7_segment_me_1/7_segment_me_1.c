#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB=0xFF;
	int i,j;
	
      
	 int word[6]={0x6D,0x74,0x1C,0x74,0x77,0x54,0x40};
		 int digit[10]={63,6,91,79,102,109,125,7,127,111};
	  
    while(1)
    {
        for(i=0;i<=6;i++)
		{
			PORTB=word[i];
			
			if(i<6)  _delay_ms(800);
			
			else
			{
				for(j=0;j<8;j++)
				{
					PORTB=0;
					PORTB=0x40;
					_delay_ms(100);
					
					PORTB=0;
					_delay_ms(100);
				}
			}
			
			
			PORTB=0;
			_delay_ms(100);
		}
		
		
		
		 for(i=0;i<10;i++)
		 {
			 PORTB=digit[i];
			 
			   _delay_ms(800);
			 
			 if(i==9)
			 {
				 PORTB=0;
				 for(j=0;j<8;j++)
				 {
					 PORTB=192;
					 _delay_ms(100);
					 
					 PORTB=0;
					 _delay_ms(100);
				 }
			 }
			 
			 
			 PORTB=0;
			 _delay_ms(100);
		 }
		
		
		
		
    }
}