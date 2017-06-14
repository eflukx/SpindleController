/*
* ftoa.c
*
* Created: 27-2-2017 20:50:20
*  Author: Rogier Lodewijks
*/
#include <stdlib.h>

char *ftoa(char *buffer, unsigned char len, double d, int precision) {

	long wholePart = (long) d;
	char* start_of_buffer = buffer;

	// Deposit the whole part of the number.

	itoa(wholePart,buffer,10);

	// Now work on the faction if we need one.

	if (precision > 0) {

		// We do, so locate the end of the string and insert
		// a decimal point.

		//char *buffer = buffer;
		while (*++buffer != '\0');
		
		*buffer++ = '.';

		double fraction = d - wholePart;
		if (fraction < 0) fraction *= -1; // absolute fraction please.
		
		while (precision-- && buffer < (buffer + len - 1)) {

			// Multiply by ten and pull out the digit.

			fraction *= 10;
			wholePart = (long) fraction;
			*buffer++ = '0' + wholePart; // single digit itoa

			// Update the fraction and move on to the
			// next digit.

			fraction -= wholePart;
		}

		// Terminate the string.

		*buffer = '\0';
	}

	return start_of_buffer;
}