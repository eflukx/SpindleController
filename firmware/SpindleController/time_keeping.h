/*
* time_keeping.h
*
* Created: 13-6-2017 0:34:59
*  Author: Rogier Lodewijks
*/


#ifndef TIME_KEEPING_H_
#define TIME_KEEPING_H_

typedef struct {
	uint16_t	msecs;
	uint32_t	secs;
	
} time_t;

void timer_tick_init();

uint32_t timer_get_seconds();
uint32_t timer_get_msecs();
time_t timer_get_time();

#endif /* TIME_KEEPING_H_ */