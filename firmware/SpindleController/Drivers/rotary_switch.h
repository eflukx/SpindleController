/*
 * rotary_switch.h
 *
 * Created: 12-6-2017 9:34:18
 *  Author: Rogier Lodewijks
 */ 


#ifndef ROTARY_SWITCH_H_
#define ROTARY_SWITCH_H_

#define RENC_PORT	PORTD
#define RENC_PIN_B	6
#define RENC_PIN_A	7

#define RENC_ACCELERATE		2	// acceleration factor, zero disables

void renc_init();

#endif /* ROTARY_SWITCH_H_ */