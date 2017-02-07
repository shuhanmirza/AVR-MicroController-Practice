#define F_CPU 1000000

#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#define EEPROM_ADDRESS 	10

int main(void)
{
	char data1 = 'A';
	//eeprom_write_byte((uint8_t*)EEPROM_ADDRESS,(uint8_t)data1);
	
	
	char data2 = eeprom_read_byte((uint8_t*)EEPROM_ADDRESS);
	

	while(1)
	{

		
	}
}