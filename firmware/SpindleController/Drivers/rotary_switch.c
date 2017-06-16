/*
* rotary_switch.c
*
* Created: 12-6-2017 9:34:11
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "gpio_pcint.h"
#include "rotary_switch.h"
#include "time_keeping.h"

volatile int8_t direction = 1;
volatile int16_t position = 80;

void renc_a_edge_isr();

void renc_init()
{
	GPIO_INPUT(GPIO_DDR_FROM_PORT(RENC_PORT), RENC_PIN_A);
	GPIO_INPUT(GPIO_DDR_FROM_PORT(RENC_PORT), RENC_PIN_B);
	
	pcint_attach_function(020 + RENC_PIN_A, renc_a_edge_isr, RISING_EDGE);
}

void renc_a_edge_isr()
{
	direction = (GPIO_PIN_FROM_PORT(RENC_PORT) & _BV(RENC_PIN_B)) ? -1 : 1; //  value of RENC_B on edge of RENC_A indicates direction.
	
#if RENC_ACCELERATE
	static uint32_t last_time = 0;
	uint32_t now = timer_get_msecs();

	position +=  (now - last_time < 15) ? direction << RENC_ACCELERATE : direction;

	last_time = timer_get_msecs();
#else
	position += direction;
#endif
	
	renc_print_position();
}

void renc_print_position()
{
	volatile static uint8_t mutex = 0;
	if(mutex) return;
	wdt_reset();
	int16_t pos = position;
	
	mutex = 1;
		for(int16_t x = 0; x < pos; x++) xputc ('*');
		xprintf("\nPosition: %d, rpm: %d\n", pos, pos * 250);
	mutex = 0;
}

