/*
* console.c
*
* Created: 12-6-2017 10:06:19
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "Drivers/softuart_asm.h"
#include "Drivers/uart.h"
#include "console.h"

#define SOFTUART 1

void console_init()
{
	#if SOFTUART
		softuart_init(CONSOLE_BAUDRATE);
		xdev_out(softuart_putchar);
	#else
		uart_init(CONSOLE_BAUDRATE);
		xdev_out(uart_putbyte);	
	#endif
	
	#ifdef SERIAL_BANNER
		info_puts_P(SERIAL_BANNER);
	#endif
}