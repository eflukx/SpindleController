/*
 * triac_drive.c
 *
 * Created: 13-6-2017 23:32:20
 *  Author: Rogier Lodewijks
 */ 

#include "globals.h"
#include "zero_cross.h"
#include "triac_drive.h"



void triac_init()
{
	GPIO_OUTPUT(GPIO_DDR_FROM_PORT(TRIAC_PORT), TRIAC_PIN);
}

int8_t is_next_second()
{
	static uint32_t next_second = 0;
	
	if(!next_second) next_second = timer_get_seconds() + 1;
	
	uint32_t current_second = timer_get_seconds();
	if(current_second >= next_second)
	{
		next_second = current_second + 1;
		return true;
	}
	
	return false;
}

void triac_test()
{
	while(1)
	{
		GPIO_BIT_LOW(TRIAC_PORT, TRIAC_PIN);
		xputs_P("OFF!\n");
		while(!is_next_second());
		
		zero_cross_wait();
		GPIO_BIT_HI(TRIAC_PORT, TRIAC_PIN);
		xputs_P("ON!\n");
		while(!is_next_second());
	}
}
