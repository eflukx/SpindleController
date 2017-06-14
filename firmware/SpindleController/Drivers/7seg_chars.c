/*
 * _7seg_chars.c
 *
 * Created: 14-6-2017 23:56:59
 *  Author: Rogier Lodewijks
 */ 

#include "globals.h"
#include "7seg_chars.h"

uint8_t led_char(char chr)
{
	uint8_t data = (char)pgm_read_byte(&(led_charset)[chr  & ~0x80]); // Lookup without decimal point.. (chr 0x80)
	return data | (chr & 0x80); // add decimal point
}