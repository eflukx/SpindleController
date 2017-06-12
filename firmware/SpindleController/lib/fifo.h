/*
 * fifo.h
 *
 * Created: 24-6-2016 13:51:07
 *  Author: Rogier Lodewijks
 */ 
#ifndef FIFO_H_
#define FIFO_H_

struct fifo {
	uint8_t size;           /* size of buffer in bytes */
	uint8_t read;           /* read pointer */
	uint8_t write;          /* write pointer */
	unsigned char buffer[]; /* fifo ring buffer */
};

/* define a FIFO type for 'size' bytes */
#define DEFINE_FIFO_TYPE(size) \
struct fifo_ ## size {                  \
	struct fifo f;                      \
	unsigned char buffer_bytes[size];   \
}

/* define a fifo (type: struct fifo *) with name 'name' for 's' bytes */
#define DEFINE_FIFO(name, s)                            \
struct fifo_##s _raw_##name = { .f = { .size = s } };   \
struct fifo *name = &_raw_##name.f;

uint8_t fifo_write (struct fifo *fifo, unsigned char data);
uint8_t fifo_read (struct fifo *fifo, unsigned char *data);
uint8_t fifo_inspect_at(struct fifo *fifo, unsigned char *data, uint8_t offset);

uint8_t fifo_data_length (struct fifo *fifo);
uint8_t fifo_size (struct fifo *fifo);
void fifo_reset(struct fifo *fifo);
uint8_t* fifo_read_pointer(struct fifo *fifo);
uint8_t* fifo_write_pointer(struct fifo *fifo);

#endif /* FIFO_H_ */