

#include <avr/io.h>

int main(void)
{
	DDRB=0xFF;
	DDRD =0 ;
	
	int show[5]={1,64,48,6,8} ;
	
    while(1)
    {
          PORTB=0;
		  
		 /* if(!(PIND & (1<<PD1)))  
		  {
			  PORTB = 1;
		  }
		  */
		  if(!(PIND & (1<<PD2)))
		  {
			  PORTB = show[1];
		  }
		  
		  
		  if(!(PIND & (1<<PD3)))
		  {
			  PORTB = show[2];
		  }
		  
		 
		  
		  /*if(!(PINA & (1<<PA6)))
		  {
			  PORTB = show[3];
		  }
		  
		  
		  if(!(PINA & (1<<PA7)))
		  {
			  PORTB = show[4];
		  }
		  
		  */
		  
	}
}