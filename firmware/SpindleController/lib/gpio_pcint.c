/*
* gpio_pcint.c
*
* Created: 5-9-2016 22:10:23
*  Author: Rogier Lodewijks
*/
#include "globals.h"
#include "gpio_pcint.h"

static pcint_handler pcint_handlers[3][8];
static char inited = 0;
static char old_pins[3];

#define GET_PIN(prt)  (prt ? (prt == 2 ? &PIND : &PINC) : &PINB)
#define GET_PCMSK(prt)  (prt ? (prt == 2 ? &PCMSK2 : &PCMSK1) : &PCMSK0)

void pcint_init()
{
	old_pins[0] = *GET_PIN(0);
	old_pins[1] = *GET_PIN(1);
	old_pins[2] = *GET_PIN(2);
	
	memset(pcint_handlers, 0, sizeof(pcint_handlers)); //disable all interrupts
	inited = 1;
}

char pcint_attach_function(uint8_t pcint_nr, service_routine isr, pcint_modes mode)
{
	if(!inited) pcint_init();
	
	if(pcint_nr > 23) return -1; // PCINT nr out of bounds
	
	uint8_t pcint_port = pcint_nr >> 3;
	uint8_t pcint_bit = pcint_nr & 7;
	
	pcint_handlers[pcint_port][pcint_bit].isr = isr;
	
	pcint_set_mode(pcint_nr, mode);
	
	PCICR |= _BV(pcint_port);
	
	return 0;
}

char pcint_set_mode(uint8_t pcint_nr, pcint_modes mode)
{
	if(pcint_nr > 23) return -1; // PCINT nr out of bounds
	
	uint8_t pcint_port = pcint_nr >> 3;
	uint8_t pcint_bit = pcint_nr & 7;
	
	pcint_handlers[pcint_port][pcint_bit].mode = mode;
	
	if(mode)
	{
		*GET_PCMSK(pcint_port) |= _BV(pcint_bit);
	}
	else
	{
		*GET_PCMSK(pcint_port) &= ~_BV(pcint_bit);
	}
	
	return 0;
}

static inline void pcint_isr_dispatcher(uint8_t pcint_reg)
{
	char pins, changed_pins, pin_changed, bvi;
	pcint_handler pin_handler;
	
	pins = *GET_PIN(pcint_reg);
	changed_pins = (pins ^ old_pins[pcint_reg]) & *GET_PCMSK(pcint_reg);
	
	for(uint8_t i = 0; i < 8; i++)
	{
		bvi = _BV(i);
		pin_changed = changed_pins & bvi;
		pin_handler = pcint_handlers[pcint_reg][i];
		
		if(pin_handler.mode == DISABLED || !pin_changed) continue;
		
		if(pin_handler.mode == BOTH_EDGES){
			if(pin_handler.isr) pin_handler.isr();
		}
		else if(pin_handler.mode == RISING_EDGE && (pins & bvi) ){
			if(pin_handler.isr) pin_handler.isr();
		}
		else if(pin_handler.mode == FALLING_EDGE && !(pins & bvi) ){
			if(pin_handler.isr) pin_handler.isr();
		}
	}
	
	old_pins[pcint_reg] = *GET_PIN(pcint_reg);
}

ISR(PCINT0_vect)
{
	pcint_isr_dispatcher(0);
}

ISR(PCINT1_vect)
{
	pcint_isr_dispatcher(1);
}

ISR(PCINT2_vect)
{
	pcint_isr_dispatcher(2);
}
