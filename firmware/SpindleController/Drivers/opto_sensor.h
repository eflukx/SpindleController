/*
 * opto_sensor.h
 *
 * Created: 13-6-2017 20:18:01
 *  Author: Rogier Lodewijks
 */ 


#ifndef OPTO_SENSOR_H_
#define OPTO_SENSOR_H_

#define OPTO_PORT		PORTD
#define OPTO_SENSOR_PIN	2

void opto_init();
void opto_print_rpm();
int32_t opto_get_rpm();

#endif /* OPTO_SENSOR_H_ */