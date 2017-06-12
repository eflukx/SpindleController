/*------------------------------------------------------------------------*/
/* Universal string handler for user console interface  (C)ChaN, 2011     */
/*------------------------------------------------------------------------*/

#include "globals.h"

#ifndef _STRFUNC
#define _STRFUNC

//Defined in globals.h
#define ENABLE_DEBUG_MESSAGES 1
#define ENABLE_INFO_MESSAGES 1

#define _USE_XFUNC_OUT	1	/* 1: Use output functions */
#define	_CR_CRLF		1	/* 1: Convert \n ==> \r\n in the output char */

#define _USE_XFUNC_IN	0	/* 1: Use input function */
#define	_LINE_ECHO		0	/* 1: Echo back input chars in xgets function */

#if _USE_XFUNC_OUT

// Easy printing from PGM space
#define xputs_P(str)		xputs_PSTR(PSTR(str))
#define xprintf_P(fmt, ...)	xprintf_PSTR(PSTR(fmt), __VA_ARGS__)

#if ENABLE_DEBUG_MESSAGES
  #define dbg_puts_P(str)					xputs_PSTR(PSTR(str))
  #define dbg_puts(str)						xputs(str)
  #define dbg_printf_P(fmt, ...)			xprintf_PSTR(PSTR(fmt), __VA_ARGS__)
  #define dbg_printf(fmt, ...)				xprintf(fmt, __VA_ARGS__)
  #define dbg_print_byte_array(data, len)	xprint_byte_array(data, len)
  
#else
  #define dbg_puts_P(str)
  #define dbg_puts(str)
  #define dbg_printf_P(fmt, ...)
  #define dbg_print_byte_array(data, len)
  
  #pragma GCC diagnostic ignored "-Wunused-variable"
  #pragma GCC diagnostic ignored "-Wunused-value"
#endif

#if ENABLE_INFO_MESSAGES
  #define info_puts_P(str)			xputs_PSTR(PSTR(str))
  #define info_puts(str)			xputs(str)
  #define info_printf_P(fmt, ...)	xprintf_PSTR(PSTR(fmt), __VA_ARGS__)
  #define info_printf(fmt, ...)		xprintf(fmt, __VA_ARGS__)
  
#else
  #define info_puts_P(str)
  #define info_puts(str)
  #define info_printf_P(fmt, ...)
#endif

#define xdev_out(func) xfunc_out = (void(*)(unsigned char))(func)
extern void (*xfunc_out)(unsigned char);

void xprint_byte_array(void* data, int len);
void xnputs (const char* str, int len);
void put_dump (const void* buff, unsigned long addr, int len, int width);

void xputc (char c);
void xputs (const char* str);
void xputs_PSTR (const char* str);
void xfputs (void (*func)(unsigned char), const char* str);
void xprintf (const char* fmt, ...);
void xprintf_PSTR (const char*	PROGMEM fmt, ...);
void xsprintf (char* buff, const char* fmt, ...);
void xfprintf (void (*func)(unsigned char), const char*	fmt, ...);

#define DW_CHAR		sizeof(char)
#define DW_SHORT	sizeof(short)
#define DW_LONG		sizeof(long)

#define PRINT_LINE_BREAK xputc('\n')
#endif

#if _USE_XFUNC_IN
#define xdev_in(func) xfunc_in = (unsigned char(*)(void))(func)
extern unsigned char (*xfunc_in)(void);
int xgets (char* buff, int len);
int xfgets (unsigned char (*func)(void), char* buff, int len);
int xatoi (char** str, long* res);
#endif

#endif
