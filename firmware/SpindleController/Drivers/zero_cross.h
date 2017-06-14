/*
 * zero_cross.h
 *
 * Created: 12-6-2017 23:28:41
 *  Author: Rogier Lodewijks
 */ 


#ifndef ZERO_CROSS_H_
#define ZERO_CROSS_H_


#define ZC_PORT			PORTD
#define ZC_PIN			3
#define ROT_PIN			2

#define ZC_USE_PCINT	0				// User either PCINT of external INT1
#define ZC_PCINT		(020 + ZC_PIN)	// 020 (octal) for PORTD

#define	ZC_TRACK_FREQ	1
#define	ZC_TRACK_CYCLES	20 // Precision, lower is faster frequency updates, at a lower precision

void init_zerocross(int8_t print_mains_freq);
void zero_cross_wait();

void zero_cross_print_freq_hz(uint8_t decimals);
float zero_cross_freq_hz();

#endif /* ZERO_CROSS_H_ */