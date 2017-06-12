/*
* uart.h
*
* UART example for ATMega328P clocked at 16 MHz
*
* TODO :-
* 	- Implement string read function
* 	- Optimize for size
* 	- Add helper routines and compile to .a file
*
*  Created on: 22-Jan-2014
*      Author: Shrikant Giridhar
*/

#include <avr/io.h>
#ifndef UART_H_
#define UART_H_

//#include "globals.h"


#define UART_DOUBLE_SPEED

/* Settings */
#define _BAUD			CONSOLE_BAUDRATE
#define _DATA			0x03					// Number of data bits in frame = byte tranmission
#define RX_STR_BUFF_SIZE			10

/* Useful macros */
#define TX_START()		UCSR0B |= _BV(TXEN0)	// Enable TX
#define TX_STOP()		UCSR0B &= ~_BV(TXEN0)	// Disable TX
#define RX_START()		UCSR0B |= _BV(RXEN0)	// Enable RX
#define RX_STOP()		UCSR0B &= ~_BV(RXEN0)	// Disable RX
#define COMM_START()	TX_START(); RX_START()	// Enable communications

#define TX_COMPLETE		(UCSR0A & _BV(TXC0))

/* Interrupt macros; Remember to set the GIE bit in SREG before using (see datasheet) */
#define RX_INTEN()		UCSR0B |= _BV(RXCIE0)	// Enable interrupt on RX complete
#define RX_INTDIS()		UCSR0B &= ~_BV(RXCIE0)	// Disable RX interrupt
#define TX_INTEN()		UCSR0B |= _BV(TXCIE0)	// Enable interrupt on TX complete
#define TX_INTDIS()		UCSR0B &= ~_BV(TXCIE0)	// Disable TX interrupt

/* Prototypes */
void uart_init(uint32_t baudrate);
uint8_t uart_getbyte(void);
void uart_writestring(char *str);
void uart_send_buffer(uint8_t *buf, uint16_t len);
void uart_putbyte(unsigned char data);
const char* uart_readstring(void);

void uart_attach_irq_handler(void (*handler)());
int8_t uart_enable_interrupt();
void uart_disable_interrupt();

inline uint8_t uart_data_available()
{
	return (UCSR0A & _BV(RXC0));
}

#endif /* UART_H_ */