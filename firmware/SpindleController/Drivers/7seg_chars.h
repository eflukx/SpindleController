/*
* _7seg_chars.h
*
* Created: 14-6-2017 22:29:23
*  Author: Rogier Lodewijks
*/


#ifndef LED_CHARSET_H_
#define LED_CHARSET_H_

#include <avr/pgmspace.h>

uint8_t led_char(char chr);

static const char led_charset[] PROGMEM = {
	0b01111110,0b00110000,0b01101101,0b01111001,0b00110011,0b01011011,0b01011111,0b01110010,  // Ascii decimal:0-7       hex:00-07
	0b01111110,0b01111011,0b01111101,0b00011111,0b00001101,0b00111101,0b01101111,0b01000111,  // Ascii decimal:8-15      hex:08-0F
	0b01111110,0b00000110,0b01101101,0b01001111,0b00010111,0b01011011,0b01111011,0b00011110,  // Ascii decimal:16-23     hex:10-17
	0b01111111,0b01011111,0b01101111,0b01110011,0b01100001,0b01100111,0b01111101,0b00111001,  // Ascii decimal:24-31     hex:18-1f
	0b00000000,0b10110000,0b00100010,0b01000001,0b01001001,0b00100101,0b00110001,0b00000010,  // Ascii decimal:32-39     hex:20-27
	0b01001010,0b01101000,0b01000010,0b00000111,0b00000100,0b00000001,0b00000000,0b00100101,  // Ascii decimal:40-47     hex:28-2F
	0b01111110,0b00110000,0b01101101,0b01111001,0b00110011,0b01011011,0b01011111,0b01110010,  // Ascii decimal:48-55     hex:30-37
	0b01111111,0b01111011,0b01001000,0b01011000,0b01000011,0b00001001,0b01100001,0b01100101,  // Ascii decimal:56-63     hex:38-3F
	0b01111101,0b01110111,0b01111111,0b01001110,0b00111101,0b01001111,0b01000111,0b01011110,  // Ascii decimal:64-71     hex:40-47
	0b00110111,0b00000110,0b00111100,0b01010111,0b00001110,0b01010100,0b01110110,0b01111110,  // Ascii decimal:72-79     hex:48-4F
	0b01100111,0b01101011,0b01100110,0b01011011,0b00001111,0b00111110,0b00111110,0b00101010,  // Ascii decimal:80-87     hex:50-57
	0b00110111,0b00111011,0b01101101,0b00011110,0b00010011,0b00110110,0b01100010,0b00001000,  // Ascii decimal:88-95     hex:58-5F
	0b00100000,0b01111101,0b00011111,0b00001101,0b00111101,0b01101111,0b01000111,0b01111011,  // Ascii decimal:96-103    hex:60-67
	0b00010111,0b00000100,0b00011000,0b01010111,0b00000110,0b00010100,0b00010101,0b00011101,  // Ascii decimal:104-111   hex:68-6F
	0b01100111,0b01110011,0b00000101,0b01011011,0b00001111,0b00011100,0b00011100,0b00010100,  // Ascii decimal:112-119   hex:70-77
	0b00110111,0b00111011,0b01101101,0b01001011,0b01010101,0b01100011,0b01000000,0b00000000   // Ascii decimal:120-127   hex:78-7F
};



#endif