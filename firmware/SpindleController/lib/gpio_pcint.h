/*
* gpio_pcint.h
*
* Created: 5-9-2016 22:19:30
*  Author: Rogier Lodewijks
*/


#ifndef GPIO_PCINT_H_
#define GPIO_PCINT_H_

typedef void (*service_routine)();

typedef enum {
	DISABLED = 0,
	BOTH_EDGES = 1,
	ENABLED = 1,
	RISING_EDGE,
	FALLING_EDGE,
} pcint_modes;

typedef struct {
	service_routine isr;
	pcint_modes mode;
} pcint_handler;

void pcint_init();
char pcint_attach_function(uint8_t pcint_nr, service_routine isr, pcint_modes mode);
char pcint_set_mode(uint8_t pcint_nr, pcint_modes mode);

#endif /* GPIO_PCINT_H_ */