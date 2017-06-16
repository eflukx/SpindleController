#ifndef MAX7219_CONFIG_H
#define MAX7219_CONFIG_H

/* Set boot delay (in miliseconds) */
#define MAX7219_BOOT_TIME		1

/* Define this to use much slower, time based clock */
// #define MAX7219_SLOW_CLOCK_US 10

/* Set the number of digits */
#define MAX7219_DIGITS          8

#define MAX7219_SWAP_DIGITS		1

/***
* Pin configurations
*
* MAX7219 is using three pins for communication:
*   DATA (also known as DIN) is an internal shift
*   register input. We'll feed data through it.
*
*   CLK (or CLOCK) is an input pin for clock.
*
*   LOAD (or CS) is used to block the internal
*   shift register output, so shifted bits are
*   not propagated during transfer.
*
* Pin numbers for DIP24:
*   DATA       1
*   CLK        13
*   LOAD       12
***/

//din 2	pd1
//cs	3	pd0
//clk	4	pd4

/* Set port with DATA pin */
#define MAX7219_PORT_DATA       PORTD

/* Set direction register for DATA */
#define MAX7219_DREG_DATA       DDRD

/* Set pin for DATA */
#define MAX7219_PIN_DATA        1

/* Set port with CLK pin */
#define MAX7219_PORT_CLK        MAX7219_PORT_DATA

/* Set direction register for CLK */
#define MAX7219_DREG_CLK        MAX7219_DREG_DATA

/* Set pin for CLK */
#define MAX7219_PIN_CLK         4

/* Set port with LOAD pin */
#define MAX7219_PORT_LOAD       MAX7219_PORT_DATA

/* Set direction register for LOAD */
#define MAX7219_DREG_LOAD       MAX7219_DREG_DATA

/* Set pin for LOAD */
#define MAX7219_PIN_LOAD        0

#endif  /* MAX7219_CONFIG_H */