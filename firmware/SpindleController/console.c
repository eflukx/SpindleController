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

void console_init(uint8_t reset_reason)
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
	
	if(reset_reason) print_reset_reason(reset_reason);
}

void print_reset_reason(uint8_t reset_reason)
{
	if(reset_reason & _BV(WDRF)) xputs_P("Watchdog ");
	if(reset_reason & _BV(BORF)) xputs_P("Brown-out ");
	if(reset_reason & _BV(EXTRF)) xputs_P("External ");
	if(reset_reason & _BV(PORF)) xputs_P("Power on ");
	xprintf_P("reset (0x%02x).\n", reset_reason);
}