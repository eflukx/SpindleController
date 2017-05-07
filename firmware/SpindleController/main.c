/*
* SpindleController.c
*
* Created: 6-5-2017 22:48:47
* Author : Rogier Lodewijks
*/

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

#include "max7219_config.h"
#include "max7219.h"

// http://www.fourwalledcubicle.com/files/LUFA/Doc/120730/html/_page__software_bootloader_start.html

/***
Display int16_t value on 4 digit LED display
***/
static void display_value(int16_t value)
{
	uint8_t digit = MAX7219_DIGITS;

	while(digit--)
	{
		if ( value < 0 ) break; // were done
		
		uint8_t digit_value = value % 10;
		uint8_t leading_zeroes = 0;
		
		if (digit_value > 0) leading_zeroes++;
		
		if(leading_zeroes) max7219_digit(digit, digit_value);
		value /= 10;
	};
}


int main(void)
{
	begin:
	
	/* Initialize MAX7219 and setup pins */
	max7219_init();
	
	/* Build-in test feature of MAX7219 */
	max7219_test_on();
	_delay_ms(1000);
	max7219_test_off();

	/* Display HELO message */
	max7219_helo();
	_delay_ms(2000);
	max7219_clear_all();

	/* Count from 0 to 9 on a last display */
	for ( uint8_t i = 0; i < 0x1f; i++ )
	{
		for(uint8_t d= 1; d <= MAX7219_DIGITS; d++)	max7219_digit(d, i + d);
		_delay_ms(100);
	}
	max7219_clear_all();

	/* Display value with a decimal dot */
	for ( uint8_t i = 1; i <= MAX7219_DIGITS; i++ )
	if ( i == 2 )
	max7219_digit(i, i | MAX7219_DECIMAL);
	else
	max7219_digit(i, i);

	for ( uint8_t i = 15; i > 0; i-- ) {
		max7219_intensity(i);
		_delay_ms(50);
	};

	/* Fade out and back */
	for (uint8_t i = 0; i < 16; i++ ) {
		max7219_intensity(i);
		_delay_ms(50);
	};
	max7219_clear_all();

	/* Count from 0 to 9999 at full speed */
	for ( uint16_t  j = 0; j < 10000; j++ )
	display_value(j);
	_delay_ms(1000);
	max7219_clear_all();

	/* Shut the chip down for 5 seconds */
	//max7219_shutdown();
	//_delay_ms(5000);
	//max7219_crank();

	/* Display four "-" slowly */
	for (uint8_t i = 1; i <= MAX7219_DIGITS; i++ ) {
		max7219_digit(i, MAX7219_CHAR_MINUS);
		_delay_ms(50);
	};

	/* Flash fade*/
	uint8_t count = 10;
	while ( count-- )
	{
		for(uint8_t i = 15; i > 0; i--)
		{
			max7219_intensity(i);
			_delay_ms(20);
		}
		
		for(uint8_t i= 0; i <=15; i++)
		{
			max7219_intensity(i);
			_delay_ms(20);
		}
	};
	
	goto begin;
}


