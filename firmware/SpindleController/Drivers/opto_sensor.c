/*
* opto_sensor.c
*
* Created: 13-6-2017 20:17:52
*  Author: Rogier Lodewijks
*/

#include "globals.h"
#include "gpio_pcint.h"
#include "opto_sensor.h"

static void opto_isr();
static void _update_rpm();

volatile static uint8_t rpm_max_cnt = 10; //adjust counts for responsiveness/precision in high and low rpm situations
volatile static uint32_t rpm_cnt = 0;
volatile static uint32_t rpm_msecs_used = 0;

void opto_init()
{
	GPIO_INPUT(GPIO_DDR_FROM_PORT(OPTO_PORT), OPTO_SENSOR_PIN);
	pcint_attach_function(020 + OPTO_SENSOR_PIN, opto_isr, RISING_EDGE);
}

void _update_rpm()
{
	static uint32_t start_time;
	static uint8_t first_run = 1;
	
	xputs("ur!");
	
	if(first_run)
	{
		start_time = timer_get_msecs();
		first_run = 0;
	}
	else
	{
		uint32_t current_time = timer_get_msecs();
		rpm_msecs_used = current_time - start_time;
		xprintf("msecs %d", rpm_msecs_used);
		xprintf("rpm %d", (int32_t)(600000 / rpm_msecs_used));
		xprintf("rpm %d", opto_get_rpm());
		start_time = current_time;
		rpm_cnt = 0;
	}
}

void opto_print_rpm()
{
	//xprintf("RPM: %d %d %d\n", 42, opto_get_rpm(), 24);
		char buf[16];
		
		xputs("RPM: ");
		xputs(ftoa(buf, sizeof(buf), (float)opto_get_rpm(), 2));
		xputs("\n");
}


int32_t opto_get_rpm()
{
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
	{
		if(rpm_msecs_used) return ((int32_t)rpm_max_cnt * 1000 * 60) / rpm_msecs_used;
	}
	return 0;
}

void opto_isr()
{
	if(rpm_cnt >= rpm_max_cnt) _update_rpm();
	rpm_cnt++;
	xputc('.');
}


