/*
* SpindleController.c
*
* Created: 6-5-2017 22:48:47
* Author : Rogier Lodewijks
*/

#include "globals.h"

#include "drivers/max7219.h"
#include "console.h"

#include "rotary_switch.h"
#include "zero_cross.h"
#include "opto_sensor.h"
#include "triac_drive.h"

int main(void)
{
	uint8_t reset_reason =	MCUSR;
	MCUSR = 0;
	
	wdt_reset();
	//wdt_enable(WDTO_500MS);
	
	timer_tick_init();
		
	console_init(reset_reason);
	
	max7219_init();
	
	
	renc_init();
		
	init_zerocross(true);
	
	opto_init();
	
	triac_init();
	
	//triac_test();
	
	while(0)
	{
		_delay_ms(200);
		
		xputs("fMains: ");
		zero_cross_print_freq_hz(2);
		xputs("Hz\n");
		
		opto_print_rpm();
		
		_delay_ms(800);
	}
	
	while(1) max7219_demo();
}


