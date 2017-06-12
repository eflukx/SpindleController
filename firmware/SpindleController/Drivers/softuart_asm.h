#ifndef SOFTUART_INLINEASM_H_
#define SOFTUART_INLINEASM_H_

#include "globals.h"

#define UART_Port _SFR_IO_ADDR(PORTD)
#define UART_DDR DDRD
#define UART_Tx 4
#define UART_Rx 4
#define SU_ENABLE_RX 0


//Define baudrate
#define BAUD_RATE CONSOLE_BAUDRATE

void softuart_init(uint32_t baudrate);
void softuart_putchar(char ch);
void softuart_puts(const char *string);
char softuart_getchar();

#endif /* SOFTUART_INLINEASM_H_ */