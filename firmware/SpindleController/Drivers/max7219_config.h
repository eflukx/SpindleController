#ifndef MAX7219_CONFIG_H
#define MAX7219_CONFIG_H

/* Set the number of digits */
#define MAX7219_DIGITS          8
#define MAX7219_SWAP_DIGITS		1

#define MAX7219_MAX_INTENSITY	4

 /* Pin configuration  */

#define MAX7219_BIT_BANG		0 //use bit-banging or hardware SPI?

	/* Set port with LOAD pin */
	#define MAX7219_CS_PORT			PORTB
	#define MAX7219_CS_DDR			DDRB
	#define MAX7219_PIN_LOAD		2

#if MAX7219_BIT_BANG
	/* Set port with DATA pin */
	#define MAX7219_DATA_PORT		MAX7219_CS_PORT
	#define MAX7219_DATA_DDR		MAX7219_CS_DDR
	#define MAX7219_DATA_PIN		3

	/* Set port with CLK pin */
	#define MAX7219_CLK_PORT		MAX7219_CS_PORT
	#define MAX7219_CLK_DDR			MAX7219_CS_DDR
	#define MAX7219_CLK_PIN			5
#endif

#endif  /* MAX7219_CONFIG_H */