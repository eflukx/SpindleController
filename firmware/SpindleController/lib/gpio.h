/*
* gpio.h
*
* Created: 9-1-2016 11:17:20
*  Author: Rogier Lodewijks
*/
#ifndef GPIO_H_
#define GPIO_H_

#define GPIO_PIN_FROM_PORT(port) _MMIO_BYTE(&port - 2)
#define GPIO_DDR_FROM_PORT(port) _MMIO_BYTE(&port - 1)

#define GPIO_PIN_FROM_DDR(port)	 _MMIO_BYTE(&port - 1)
#define GPIO_PORT_FROM_DDR(port) _MMIO_BYTE(&port + 1)

#define GPIO_DDR_FROM_PIN(port)	 _MMIO_BYTE(&port + 1)
#define GPIO_PORT_FROM_PIN(port) _MMIO_BYTE(&port + 2)


#define GPIO_OUTPUT(port, pin)	((port) |= _BV(pin))
#define GPIO_INPUT(port, pin)	((port) &= ~_BV(pin))

#define GPIO_BIT_HI		GPIO_OUTPUT
#define GPIO_BIT_LOW	GPIO_INPUT

#define GPIO_BIT_READ(pin, bit) ((pin & _BV(bit)) >> bit)

#endif /* GPIO_H_ */