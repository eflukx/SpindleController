#include "uart.h"
#include <avr/interrupt.h>

static void (*_irq_handler)() = 0;

void uart_init(uint32_t baudrate)
{
	// Not necessary; initialize anyway
	DDRD |= _BV(PD1);
	DDRD &= ~_BV(PD0);

	// Set baud rate; lower byte and top nibble
	#ifdef UART_DOUBLE_SPEED
	UBRR0 = (F_CPU >> 3) / baudrate - 1;
	UCSR0A |= _BV(U2X0);
	#else
	UBRR0 = (F_CPU >> 4) / baudrate - 1;
	#endif
	
	TX_START();
	RX_START();

	// Set frame format = 8-N-1
	UCSR0C = (_DATA << UCSZ00);
}

/*! \brief Returns a byte from the serial buffer
* 	Use this function if the RX interrupt is not enabled.
* 	Returns 0 on empty buffer
*/
uint8_t uart_getbyte(void)
{
	// Check to see if something was received
	while (!uart_data_available());
	return (uint8_t) UDR0;
}

/*! \brief Transmits a byte
* 	Use this function if the TX interrupt is not enabled.
* 	Blocks the serial port while TX completes
*/
void uart_putbyte(unsigned char data)
{
	// Stay here until data buffer is empty
	while (!(UCSR0A & _BV(UDRE0)));
	UDR0 = (unsigned char) data;
}

/*! \brief Writes an ASCII string to the TX buffer */
void uart_writestring(char *str)
{
	while (*str != '\0')
	{
		uart_putbyte(*str);
		++str;
	}
}

void uart_send_buffer(uint8_t *buf, uint16_t len)
{
	while (len)
	{
		uart_putbyte(*buf++);
		len --;
	}
}

const char* uart_readstring(void)
{
	static char rxstr[RX_STR_BUFF_SIZE];
	static char* temp;
	temp = rxstr;

	while((*temp = uart_getbyte()) != '\n')
	{
		++temp;
	}

	rxstr[RX_STR_BUFF_SIZE - 1] = 0; // Make sure we're 0-terminated
	
	return rxstr;
}

void uart_attach_irq_handler(void (*handler)())
{
	_irq_handler = handler;
}

int8_t uart_enable_interrupt()
{
	if(!_irq_handler){ return -1; }
	UCSR0B |= (1 << RXCIE0);
	return 0;
}

void uart_disable_interrupt()
{
	UCSR0B &= ~(1 << RXCIE0);
}

ISR(USART_RX_vect)
{
	_irq_handler();
}
