#include "globals.h"
#include "spi.h"
#include "7seg_chars.h"
#include "max7219_config.h"
#include "max7219.h"

#define DATA_HIGH()	(MAX7219_DATA_PORT	|=	(1 << MAX7219_DATA_PIN))
#define DATA_LOW()	(MAX7219_DATA_PORT	&= ~(1 << MAX7219_DATA_PIN))
#define	CLK_HIGH()	(MAX7219_CLK_PORT	|=	(1 << MAX7219_CLK_PIN))
#define CLK_LOW()	(MAX7219_CLK_PORT	&= ~(1 << MAX7219_CLK_PIN))
#define	CS_HIGH()	(MAX7219_CS_PORT	|=	(1 << MAX7219_PIN_LOAD))
#define	CS_LOW()	(MAX7219_CS_PORT	&= ~(1 << MAX7219_PIN_LOAD))

static void max7219_send_byte(uint8_t byte);

void  max7219_init(void)
{
	#if MAX7219_BIT_BANG
	MAX7219_DATA_DDR |= (1 << MAX7219_DATA_PIN);
	MAX7219_CLK_DDR |= (1 << MAX7219_CLK_PIN);
	#else
	SPI_Init();
	#endif
	
	MAX7219_CS_DDR |= (1 << MAX7219_PIN_LOAD);

	/* Wait for MAX7219 chip to settle down */
	_delay_ms(1);
	max7219_test_off();

	/* Select non BCD mode */
	max7219_write_reg(MAX7219_ADDR_DECMODE, 0x0);

	/* Set the number of digits */
	max7219_write_reg(MAX7219_ADDR_SCANLIM, MAX7219_DIGITS - 1);

	/* Put the torches high! */
	max7219_intensity_dim();

	/* Crank up the chip */
	max7219_crank();

	/* Clear all digits */
	max7219_clear_display();

	/* Let the chip boot in peace */
	max7219_noop();
}

void max7219_demo(void)
{
	/* Display HELO message */
	max7219_putscroll("       Welcome to the Spindle Controller        ");
	max7219_clear_display();

	/* Count from 0 to 9 on a last display */
	for ( uint8_t i = 'A'; i < 'z'; i++ )
	{
		for(uint8_t d= 1; d <= MAX7219_DIGITS; d++)	max7219_putc(d, i + d);
		_delay_ms(100);
	}
	max7219_clear_display();

	/* Display value with a decimal dot */
	for ( uint8_t i = 1; i <= MAX7219_DIGITS; i++ )
	if ( i == 2 )
	max7219_putc(i, i | MAX7219_DECIMAL);
	else
	max7219_putc(i, i);

	for ( uint8_t i = 15; i > 0; i-- ) {
		max7219_intensity(i);
		_delay_ms(50);
	};

	/* Fade out and back */
	for (uint8_t i = 0; i < 16; i++ ) {
		max7219_intensity(i);
		_delay_ms(50);
	};
	max7219_clear_display();

	/* Count from 0 to 9999 at full speed */
	for ( uint16_t  j = 0; j < 10000; j++ )
	max7219_display_value(j);
	_delay_ms(1000);
	max7219_clear_display();

	/* Display four "-" slowly */
	for (uint8_t i = 1; i <= MAX7219_DIGITS; i++ ) {
		max7219_putc(i, '-');
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
}

void  max7219_clear_display(void)
{
	for (uint8_t digit = 1; digit <= MAX7219_DIGITS; digit++) max7219_putc(digit, ' ');
}

/* Display int16_t value on 4 digit LED display */
void max7219_display_value(int16_t value)
{
	uint8_t digit = MAX7219_DIGITS;

	while(digit--)
	{
		if ( value < 0 ) break; // were done
		
		uint8_t digit_value = value % 10;
		uint8_t leading_zeroes = 0;
		
		if (digit_value > 0) leading_zeroes++;
		
		if(leading_zeroes) max7219_putc(digit, digit_value);
		value /= 10;
	};
}

void max7219_puts(char  *string)
{
	uint8_t pos = 0;
	
	while ( pos++ < MAX7219_DIGITS && *string)
	{
		max7219_putc(pos, *string++);
	}
}

void max7219_putscroll(char *str)
{
	xprintf("max7219_putZcroll!\n");
	uint8_t len = strlen(str);
	int8_t excess_chars = len - MAX7219_DIGITS;
	
	if(excess_chars <= 0)
	{
		max7219_puts(str);
	}
	else
	{
		for(uint8_t i = 0; i <= excess_chars; i++)
		{
			max7219_puts(str + i);
			_delay_ms(100);
		}
	}
}

void max7219_putc(uint8_t pos, uint8_t data)
{
	data = led_char(data);
	
	#if MAX7219_SWAP_DIGITS
	max7219_write_reg((MAX7219_DIGITS + 1) - pos, data);
	#else
	max7219_write_reg(pos, data);
	#endif
}

void max7219_write_reg(uint8_t  regaddr, uint8_t  data)
{
	CS_LOW();
	max7219_send_byte(regaddr);
	max7219_send_byte(data);
	CS_HIGH();
}

void max7219_send_byte(uint8_t byte)
{
	#if MAX7219_BIT_BANG
	uint8_t bit = 8;
	while(bit--)
	{
		CLK_LOW();
		(byte & 0x80) ?  DATA_HIGH() : DATA_LOW();
		byte <<= 1;
		CLK_HIGH();
	};
	#else
	SPI_Write_Byte(byte);
	#endif
}
