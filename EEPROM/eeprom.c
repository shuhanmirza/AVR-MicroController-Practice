#define F_CPU 1000000

#include <avr/io.h>
#include <avr/eeprom.h>
#include <util/delay.h>

#define EEPROM_ADDRESS 	10

int main(void)
{
    lcd_init(LCD_DISP_ON);
	
    eeprom_write_byte((uint8_t*)46,(uint8_t)ByteOfData);
	char data = eeprom_read_byte((uint8_t*)46);
	

	while(1)
    {

	
    }
}