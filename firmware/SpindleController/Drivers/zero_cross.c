/*
 * zero_cross.c
 *
 * Created: 12-6-2017 23:28:28
 *  Author: Rogier Lodewijks
 */ 

#include "globals.h"
#include "zero_cross.h"
#include "gpio.h"
#include "gpio_pcint.h"

void zero_cross_isr();

void init_zerocross()
{
	GPIO_INPUT(GPIO_DDR_FROM_PORT(ZC_PORT), ZC_PIN);
	GPIO_BIT_HI(ZC_PORT, ZC_PIN);
	
	pcint_attach_function(020 + ZC_PIN, zero_cross_isr, ENABLED);
}

void zero_cross_isr()
{
	//xputc('.');
}