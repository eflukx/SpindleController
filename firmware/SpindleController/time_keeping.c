/*
* time_keeping.c
*
* Created: 13-6-2017 0:35:04
*  Author: Rogier Lodewijks
*/

#include "globals.h"

volatile static uint16_t msec = 0;
volatile static uint32_t sec = 0;

void init_timer_tick()
{
	TCNT0 = 0;
	TCCR0B = _BV(CS01) | _BV(CS00);	// Prescaler 64 16MHz / 64 = 250KHz
	
	OCR0A = 250;					// Set Output Compare level @250 -> 1ms interrupt
	TIMSK0 = _BV(OCIE0A);			// Enable interrupts on Output Compare A
}

ISR(TIMER0_COMPA_vect)
{
	msec++;
	
	if(msec >= 1000)
	{
		msec = 0;
		sec++;
	}
}
