/*
* zero_cross.c
*
* Created: 12-6-2017 23:28:28
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "gpio_pcint.h"
#include "zero_cross.h"

static void zero_cross_isr();
static void _update_frequency();

volatile static uint8_t crossed = 0;
volatile static uint32_t freq_track_cnt = 0;
volatile static uint32_t msecs_used = 0;

void init_zerocross(int8_t print_mains_freq)
{
	GPIO_INPUT(GPIO_DDR_FROM_PORT(ZC_PORT), ZC_PIN);
	GPIO_BIT_HI(ZC_PORT, ZC_PIN);

#if ZC_USE_PCINT
	pcint_attach_function(ZC_PCINT, zero_cross_isr, RISING_EDGE);
#else
	EICRA |= _BV(ISC10) + _BV(ISC11); // Rising edge on INT1
	EIMSK |= _BV(INT1);
#endif

	_update_frequency(); // Initialize start time

	if(print_mains_freq)
	{
		_delay_ms(ZC_TRACK_CYCLES * 25);  // let value settle for at least two tracker-cycles
		xputs_P("Zero-cross init. (fMain: ");
		zero_cross_print_freq_hz(2);
		xputs_P("Hz)\n");
	}

}

void zero_cross_print_freq_hz(uint8_t decimals)
{
	char buf[16];
	xputs(ftoa(buf, sizeof(buf), zero_cross_freq_hz(), decimals));
}

float zero_cross_freq_hz()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if(msecs_used) return (ZC_TRACK_CYCLES * 500.0) / msecs_used; // 500 --> 1000 for msecs -> secs, 0,5 for 2 crossings per Hz
	}
	return 0;
}

void _update_frequency()
{
	static uint32_t start_time;
	static uint8_t first_run = 1;
	
	if(first_run)
	{
		start_time = timer_get_msecs();
		first_run = 0;
	}
	else
	{
		uint32_t current_time = timer_get_msecs();
		msecs_used = current_time - start_time;
		start_time = current_time;
		freq_track_cnt = 0;
	}
}

void zero_cross_wait()
{
	crossed = 0;
	while(!crossed);
}

inline void zero_cross_isr()
{
	crossed = 1;
	
#if ZC_TRACK_FREQ
	freq_track_cnt += 1;
	if(freq_track_cnt >= ZC_TRACK_CYCLES) _update_frequency();
#endif
}

#if !ZC_USE_PCINT
ISR(INT1_vect)
{
	zero_cross_isr();
}
#endif
