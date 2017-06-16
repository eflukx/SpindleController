/*
 * globals.h
 *
 * Created: 12-6-2017 9:38:58
 *  Author: Rogier Lodewijks
 */ 


#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <util/atomic.h>

#include "lib/xprintf.h"
#include "ftoa.h"
#include "gpio.h"
#include "time_keeping.h"


#define CONSOLE_BAUDRATE 460800 //115200
#define true 1
#define false 0

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

#endif /* GLOBALS_H_ */