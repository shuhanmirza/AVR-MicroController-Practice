#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	MCUCSR |= 1 << JTD;
	MCUCSR |= 1 << JTD;
	
	DDRC=0b11111111;
	int i,j,k;



    while(1)
    {
         for(i=1;i<=3;i++)
		 {
			PORTC = 0b11111111;
			_delay_ms(500);
			PORTD= 0b000000;
			_delay_ms(500);
		 }

		 //goining down

		for(j=1; j<=5; j++)
		{
				for( i=1; i<=128; i=2*i)
				{
					PORTC=i;

					_delay_ms(100);
				}
        }

		 //goining up

		 for(j=1; j<=5; j++)
		 {
			 for( i=128; i>=1; i=i/2)
			 {
				 PORTC=i;

				 _delay_ms(100);
			 }
		 }


		  //goining up+down

		  for(j=1; j<=5; j++)
		  {
			  for( i=1; i<=128; i=2*i)
			  {
				  PORTC=i;

				  _delay_ms(100);
			  }

			  for( i=128; i>=1; i=i/2)
			  {
				  PORTC=i;

				  _delay_ms(100);
			  }


		  }

		  //special

		   for(j=1; j<=5; j++)
		   {
			   for(k=16 , i=8; i>=1; i=i/2,k=k*2)
			   {
				   PORTC |=i;
				   PORTC |=k;
				    _delay_ms(200);

				   PORTC=0b00000000;
				   _delay_ms(25);
			   }

			    for(k=128 , i=1; i<=8; i=i*2,k=k/2)
			    {
				    PORTC |=i;
				    PORTC |=k;
				    _delay_ms(200);

				    PORTC=0b00000000;

			    }

		   }






	}
}
