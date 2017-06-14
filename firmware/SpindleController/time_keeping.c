/*
* time_keeping.c
*
* Created: 13-6-2017 0:35:04
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include <util/atomic.h>

volatile static uint16_t msecs = 0;
volatile static uint16_t dsecs = 0;	// 10 ms counter
volatile static uint32_t seconds = 0;

void timer_tick_init()
{
	TCNT0 = 0;
	TCCR0B = _BV(CS01) | _BV(CS00);	// Prescaler 64 16MHz / 64 = 250KHz
	
	TIMSK0 = _BV(OCIE0A);			// Enable interrupts on Output Compare A
}

uint32_t timer_get_seconds()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		return seconds;
	}
	return 0; //Dummy to prevent spurious "control reaches end of non-void function [-Wreturn-type]" compiler warning
}

uint32_t timer_get_msecs()
{
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
		{
			return seconds * 1000 + msecs;
		}
		return 0;
}

time_t timer_get_time()
{
	time_t time;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		time.secs = seconds;
		time.msecs = msecs;
	}
	return time;
}



ISR(TIMER0_COMPA_vect)
{
	OCR0A += 250;		// 250 ticks @ 250kHz --> 1ms timer interrupt
	
	static uint8_t _dusec = 0;
	_dusec++;
	msecs++;
	
	if(msecs >= 1000)
	{
		msecs = 0;
		seconds++;
	}
	
	if(_dusec >= 100)
	{
		_dusec = 0;
		dsecs++;
	}
}

