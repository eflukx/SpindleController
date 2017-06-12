/*
 * Copyright (C) 2014 Kaito Kumashiro <kumashiro.kaito@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License Version
 * 3.0 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef MAX7219_H
#define MAX7219_H

#include <stdint.h>
#include "max7219_config.h"

#define MAX7219_ADDR_NOOP           0x00
#define MAX7219_ADDR_DIGIT0         0x01
#define MAX7219_ADDR_DIGIT1         0x02
#define MAX7219_ADDR_DIGIT2         0x03
#define MAX7219_ADDR_DIGIT3         0x04
#define MAX7219_ADDR_DIGIT4         0x05
#define MAX7219_ADDR_DIGIT5         0x06
#define MAX7219_ADDR_DIGIT6         0x07
#define MAX7219_ADDR_DIGIT7         0x08
#define MAX7219_ADDR_DECMODE        0x09
#define MAX7219_ADDR_INTENSITY      0x0A
#define MAX7219_ADDR_SCANLIM        0x0B
#define MAX7219_ADDR_SHUTDOWN       0x0C
#define MAX7219_ADDR_DISPTEST       0x0F

#define MAX7219_CHAR_MINUS          0x0A
#define MAX7219_CHAR_E              0x0B
#define MAX7219_CHAR_H              0x0C
#define MAX7219_CHAR_L              0x0D
#define MAX7219_CHAR_P              0x0E
#define MAX7219_CHAR_BLANK          0x0F

#define MAX7219_DECIMAL             0x80

/* Initialize MAX7219 and setup pins */
void  max7219_init(void);

/* Push a command with data to MAX7219. Register address
   `regaddr' can be one of MAX7219_ADDR_* macros. In case
   of pushing a digit, register address can be a number of
   display unit (in range 1-8) as unit IDs correspond to
   the register address values. I.e.:

     max7219_push(3, 7)

   will update unit 3 to display number 7.
 */
void  max7219_push(uint8_t  regaddr, uint8_t  data);

/* Update digits with values allocated in `digits' array.
   The array *MUST* be of size MAX7219_DIGITS at minimum!
   Displays will be updated in order of values in array,
   i.e.:

     uint8_t    values[MAX7219_DIGITS] = { MAX7219_CHAR_E, 0, 5, 2 };
     max7219_digits(values);

   will update display 1 with character 'E', display 2 with
   value '0', display 3 with value '5' and display 4 with
   value '2'.
   Padding digits should be defined as MAX7219_CHAR_BLANK
   for empty space or 0.
 */
void  max7219_digits(uint8_t  *digits);

/* Clear (blank) all digits */
void  max7219_clear_all(void);

/* Print "HELO" on displays.
   Requires at least 4 display units!
 */
void  max7219_helo(void);

/* Send NOOP command */
#define max7219_noop()              max7219_push(MAX7219_ADDR_NOOP, 0)

/* Set LED intensity to maximum (15) */
#define max7219_intensity_max()     max7219_push(MAX7219_ADDR_INTENSITY, MAX7219_MAX_INTENSITY)

/* Set LED intensity to minimum (0) */
#define max7219_intensity_min()     max7219_push(MAX7219_ADDR_INTENSITY, 0)

/* Set LED intensity to ~half (8) */
#define max7219_intensity_dim()     max7219_push(MAX7219_ADDR_INTENSITY, (MAX7219_MAX_INTENSITY >> 1))

/* Set LED intensity to value `L', which must
   be of uint8_t type. If value is larger than
   maximum (15) it will be clipped.
 */
#define max7219_intensity(L)        max7219_push(MAX7219_ADDR_INTENSITY, L > MAX7219_MAX_INTENSITY ? MAX7219_MAX_INTENSITY : L)

/* Enable test pattern (all LEDs to on) */
#define max7219_test_on()           max7219_push(MAX7219_ADDR_DISPTEST, 1)

/* Disable test pattern */
#define max7219_test_off()          max7219_push(MAX7219_ADDR_DISPTEST, 0)

/* Shutdown the chip and enter low-power mode */
#define max7219_shutdown()          max7219_push(MAX7219_ADDR_SHUTDOWN, 0)

/* Wake up the chip from shutdown mode */
#define max7219_crank()             max7219_push(MAX7219_ADDR_SHUTDOWN, 1)

/* Update digit `D' with value `V' */
#if MAX7219_SWAP_DIGITS
#define max7219_digit(D, V)         max7219_push((MAX7219_DIGITS + 1) - D, V)
#else
#define max7219_digit(D, V)         max7219_push(D, V)
#endif 

/* Blank digit `D' */
#define max7219_clear(D)            max7219_push(D, MAX7219_CHAR_BLANK)

#endif  /* MAX7219_H */

/* vim: set filetype=c expandtab tabstop=4 sts=4 shiftwidth=4 noai nocp: */
