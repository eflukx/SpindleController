/*
* rotary_switch.c
*
* Created: 12-6-2017 9:34:11
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "gpio_pcint.h"
#include "rotary_switch.h"

void renc_intA();
void renc_intB();

volatile uint8_t last_pulse = 'A';
volatile int8_t direction = 1;
volatile int16_t position = 0;

void renc_init()
{
	GPIO_INPUT(GPIO_DDR_FROM_PORT(RENC_PORT), RENC_PIN_A);
	GPIO_INPUT(GPIO_DDR_FROM_PORT(RENC_PORT), RENC_PIN_B);
	
	pcint_attach_function(020 + RENC_PIN_A, renc_intA, RISING_EDGE);
	pcint_attach_function(020 + RENC_PIN_B, renc_intB, RISING_EDGE);
}

void renc_print_position()
{
	volatile static uint8_t mutex = 0;
	if(mutex) return;
	wdt_reset();
	int16_t pos = position;
	
	mutex = 1;
		for(int16_t x = 0; x < pos; x++) xputc ('*');
		xprintf("\nPosition: %d\n", pos);
	mutex = 0;
}

void renc_intA()
{
	if(last_pulse == 'A') direction = 1;
	position += direction;
	last_pulse = 'A';
}

void renc_intB()
{
	if(last_pulse == 'B') direction = -1;
	position += direction;
	last_pulse = 'B';
	
	renc_print_position();
}


