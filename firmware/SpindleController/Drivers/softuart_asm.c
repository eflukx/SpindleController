#include "globals.h"
#include "softuart_asm.h"

static uint8_t txdelay, rxdelay;

void softuart_init(uint32_t baudrate)
{
	txdelay = (((F_CPU/baudrate) - 7 + 1.5) / 3);
	rxdelay = (((F_CPU/baudrate) - 7 + 1.5) / 3);
	
	if(SU_ENABLE_RX) UART_DDR &= ~(UART_Rx <<1);
	
	UART_DDR |= (UART_Tx <<1);
}

void softuart_putchar(char ch) {
	
	uint8_t delayCount = 0;

	__asm__ __volatile__(
	"0: cli\n\t"
	"   sbi %[uart_port]-1,%[uart_tx]\n\t"
	"   cbi %[uart_port],%[uart_tx]\n\t"
	"   in __tmp_reg__,%[uart_port]\n\t"
	"   ldi r25,3\n\t"
	"1: mov %[delayCount],%[txdelay]\n\t"
	"2: dec %[delayCount]\n\t"
	"   brne 2b\n\t"
	"   bst %[ch],0\n\t"
	"   bld __tmp_reg__,%[uart_tx]\n\t"
	"   lsr r25\n\t"
	"   ror %[ch]\n\t"
	"   out %[uart_port],__tmp_reg__\n\t"
	"   brne 1b\n\t"
	"   sei\n\t"
	:
	[ch] "+r" (ch),
	[delayCount] "+r" (delayCount)
	:
	[uart_port] "M" (UART_Port),
	[uart_tx] "M" (UART_Tx),
	[txdelay] "r" (txdelay)
	:
	"r25"
	);
}

void softuart_puts(const char *string) {
	while(*string) {
		softuart_putchar(*string++);
	}
}

char softuart_getchar() {
	
	uint8_t rxdelay15 = (rxdelay * 1.5) - 2.5;
	uint8_t delayCount = 0;

	__asm__ __volatile__(
	"0: cbi %[uart_port]-1,%[uart_rx]\n\t"
	"   sbi %[uart_port],%[uart_rx]\n\t"
	"   mov %[delayCount],%[rxdelay15]\n\t"
	"   ldi %[rxdelay15],0x80\n\t"
	"1: sbic %[uart_port]-2,%[uart_rx]\n\t"
	"   rjmp 1b\n\t"
	"   cli\n\t"
	"2: subi %[delayCount], 1\n\t"
	"   brne 2b\n\t"
	"   mov %[delayCount],%[rxdelay]\n\t"
	"   sbic %[uart_port]-2,%[uart_rx]\n\t"
	"   sec\n\t"
	"   ror %[rxdelay15]\n\t"
	"   brcc 2b\n\t"
	"3: dec %[delayCount]\n\t"
	"   brne 3b\n\t"
	"   sei\n\t"
	:
	[rxdelay15] "+r" (rxdelay15),
	[delayCount] "+r" (delayCount)
	:
	[uart_port] "M" (UART_Port),
	[uart_rx] "M" (UART_Rx),
	[rxdelay] "r" (rxdelay)
	);
	return rxdelay15;
}