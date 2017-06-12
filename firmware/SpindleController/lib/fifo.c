/*
* fifo.c
*
* Created: 24-6-2016 13:51:00
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "fifo.h"

uint8_t fifo_read (struct fifo *fifo, unsigned char *data)
{
	// fifo empty : error
	if (fifo_data_length(fifo) == 0)
	{
		return 1;
	}
	// read data & increment read pointer
	*data = fifo->buffer[fifo->read];
	fifo->read = (fifo->read + 1) & (fifo->size - 1);
	return 0;
};

uint8_t fifo_write(struct fifo *fifo, unsigned char data)
{
	// fifo full : error
	if (fifo_data_length(fifo) == (fifo->size - 1)){ return 1; }
	
	// write data & increment write pointer
	fifo->buffer[fifo->write] = data;
	fifo->write = (fifo->write + 1) & (fifo->size - 1);
	return 0;
};

// returns value from fifo at a specified offset from read pointer, doesn't change pointers.
uint8_t fifo_inspect_at(struct fifo *fifo, unsigned char *data, uint8_t offset)
{
	// fifo empty : error
	if (fifo_data_length(fifo) == 0)
	{
		return 1;
	}
	*data = fifo->buffer[ (fifo->read + offset) & (fifo->size - 1) ];
	return 0;
};

// return length of valid data in fifo
uint8_t fifo_data_length(struct fifo *fifo)
{
	return (fifo->write - fifo->read) & (fifo->size - 1);
};

uint8_t fifo_size(struct fifo *fifo){
	return fifo->size;
}

void fifo_reset(struct fifo *fifo){
	unsigned char _sreg = SREG;
	cli();

	fifo->read = 0;
	fifo->write = 0;
	
	SREG = _sreg;
}

void fifo_rewind(struct fifo *fifo){
	fifo->read = 0;
}

uint8_t* fifo_read_pointer(struct fifo *fifo){
	return fifo->buffer + fifo->read;
}

uint8_t* fifo_write_pointer(struct fifo *fifo){
	return fifo->buffer + fifo->write;
}
