#include <avr/io.h>
#include <util/delay.h>

#include "max7219_config.h"
#include "max7219.h"

#define DATA_HIGH()	(MAX7219_PORT_DATA	|=	(1 << MAX7219_PIN_DATA))
#define DATA_LOW()	(MAX7219_PORT_DATA	&= ~(1 << MAX7219_PIN_DATA))
#define	CLK_HIGH()	(MAX7219_PORT_CLK	|=	(1 << MAX7219_PIN_CLK))
#define CLK_LOW()	(MAX7219_PORT_CLK	&= ~(1 << MAX7219_PIN_CLK))
#define	CS_HIGH()	(MAX7219_PORT_LOAD	|=	(1 << MAX7219_PIN_LOAD))
#define	CS_LOW()	(MAX7219_PORT_LOAD	&= ~(1 << MAX7219_PIN_LOAD))


void  max7219_init(void)
{
	MAX7219_DREG_DATA |= (1 << MAX7219_PIN_DATA);
	MAX7219_DREG_CLK |= (1 << MAX7219_PIN_CLK);
	MAX7219_DREG_LOAD |= (1 << MAX7219_PIN_LOAD);

	#if defined MAX7219_BOOT_TIME && MAX7219_BOOT_TIME > 0
	/* Wait for MAX7219 chip to settle down */
	_delay_ms(MAX7219_BOOT_TIME);
	#endif

	/* We support only 7-segment LED displays in BCD mode */
	max7219_push(MAX7219_ADDR_DECMODE, 0xff);

	/* Set the number of digits */
	max7219_push(MAX7219_ADDR_SCANLIM, MAX7219_DIGITS - 1);

	/* Put the torches high! */
	max7219_intensity_max();

	/* Crank up the chip */
	max7219_crank();

	/* Clear all digits */
	max7219_clear_all();

	/* Let the chip boot in peace */
	max7219_noop();
}

void  max7219_clear_all(void)
{
	for (uint8_t digit = 1; digit <= MAX7219_DIGITS; digit++) max7219_clear(digit);
}

void  max7219_push_byte(uint8_t byte)
{
	uint8_t bit = 8;
	while(bit--)
	{
		CLK_LOW();
		(byte & 0x80) ?  DATA_HIGH() : DATA_LOW();
		byte <<= 1;
		CLK_HIGH();

		#ifdef MAX7219_SLOW_CLOCK_US
		_delay_us(MAX7219_SLOW_CLOCK_US);
		#endif
	};
}

void max7219_push(uint8_t  regaddr, uint8_t  data)
{
	CS_LOW();
	max7219_push_byte(regaddr);
	max7219_push_byte(data);
	CS_HIGH();	
}

void max7219_digits(uint8_t  *digits)
{
	uint8_t digit = 0;
	
	while ( digit++ < MAX7219_DIGITS )
	max7219_digit(digit, digits[digit]);
}

void max7219_helo(void)
{
	uint8_t digit = 0;

	if ( MAX7219_DIGITS > 4 )
	for ( digit = 1; digit <= (MAX7219_DIGITS - 4) / 2; digit++ )
	max7219_digit(digit, MAX7219_CHAR_BLANK);

	max7219_digit(++digit, MAX7219_CHAR_H);
	max7219_digit(++digit, MAX7219_CHAR_E);
	max7219_digit(++digit, MAX7219_CHAR_L);
	max7219_digit(++digit, 0);
}
