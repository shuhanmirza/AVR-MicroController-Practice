

#include <avr/io.h>

int main(void)
{
	DDRC |= (1<<PC0);
	DDRA &= ~ (1<<PA0);
	
    while(1)
    {
        if(PINA & (1<<PA0))
		{
		    PORTC=1;	
		}
		
		else
		{
		   PORTC =0;	
		}
    }
}