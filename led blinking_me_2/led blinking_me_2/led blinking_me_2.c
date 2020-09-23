#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>


int main(void)
{
	MCUCSR |= 1<<JTD;
	MCUCSR |= 1<<JTD;

	DDRC=0b11111111;
	int i,j,k;

	MCUCSR |= 1<<JTD;



	while(1)
	{
		for(i=1;i<=3;i++)
		{
			PORTC = 0b11111111;
			_delay_ms(500);
			PORTC= 0b000000;
			_delay_ms(500);
		}

		//goining down

		for(j=1; j<=5; j++)
		{
			for( i=1; i<=128; i=2*i)
			{
				PORTC=i;

				_delay_ms(150);
			}
		}

		//goining up

		for(j=1; j<=5; j++)
		{
			for( i=128; i>=1; i=i/2)
			{
				PORTC=i;

				_delay_ms(150);
			}
		}


		//goining up+down

		for(j=1; j<=5; j++)
		{
			for( i=1; i<=128; i=2*i)
			{
				PORTC=i;

				_delay_ms(150);
			}

			for( i=128; i>=1; i=i/2)
			{
				PORTC=i;

				_delay_ms(150);
			}


		}

		//special_1_following
		for(j=1;j<=5;j++)
		{
			for(i=1,k=4; i<=32; i=i*2,k=k*2)
			{
				PORTC |= i;
				PORTC |= k;

				_delay_ms(150);

				PORTC=0b00000000;
				_delay_ms(50);
			}
		}



		for(j=1;j<=5;j++)
		{
			for(i=128,k=32; i>=4; i=i/2,k=k/2)
			{
				PORTC |= i;
				PORTC |= k;

				_delay_ms(150);

				PORTC=0b00000000;
				_delay_ms(50);
			}
		}






		//special_2_going far and coming back
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
}

		for(j=1; j<=5; j++)
		{

			for(k=128 , i=1; i<=8; i=i*2,k=k/2)
			{
				PORTC |=i;
				PORTC |=k;
				_delay_ms(200);

				PORTC=0b00000000;

			}

		}






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



		//special_3
/* for(j=1;j<=5;j++)
{
	PORTC= 0b00000011;
	for(i=1 ,k=2 ; i<=128 ;)
	{
		PORTC |= i ;
		PORTC |= k ;
		_delay_ms(150);

		PORTC =0;

		k=

		PORTC |=
	}
}


	*/
//special_4 _ rise


		for(j=1;j<=2;j++)
		{
			for(i=1,k=2; i<=64; i=i*2,k=k*2)
			{
				PORTC |= i;
				_delay_ms(25);
				PORTC |= k;

				_delay_ms(150);

			}

			PORTC=0;
			_delay_ms(200);
			PORTC=255;
			_delay_ms(200);
			PORTC=0;
			_delay_ms(200);
		}


	for(j=1;j<=2;j++)
	{
		for(i=128,k=64; i>=1; i=i/2,k=k/2)
		{
			PORTC |= i;
			_delay_ms(25);
			PORTC |= k;

			_delay_ms(150);

		}

		PORTC=0;
		_delay_ms(200);
		PORTC=255;
		_delay_ms(200);
		PORTC=0;
		_delay_ms(200);
	}

//special_5 rise 2

for(j=1;j<=2;j++)
{
	for(k=16 , i=8; i>=1; i=i/2,k=k*2)
	{
		PORTC |=i;
		_delay_ms(25);
		PORTC |=k;
		_delay_ms(150);
	}

	PORTC=0;
	_delay_ms(200);
	PORTC=255;
	_delay_ms(200);
	PORTC=0;
	_delay_ms(200);

}



    for(j=1;j<=2;j++)
    {

        for(k=128 , i=1; i<=8; i=i*2,k=k/2)
        {
            PORTC |=i;
            _delay_ms(25);
            PORTC |=k;
            _delay_ms(150);
        }

	PORTC=0;
	_delay_ms(200);
	PORTC=255;
	_delay_ms(200);
	PORTC=0;
	_delay_ms(200);

}
	}
}
