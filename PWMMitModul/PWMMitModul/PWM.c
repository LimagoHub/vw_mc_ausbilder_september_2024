/*
 * PWM.c
 *
 * Created: 26.09.2024 08:20:14
 *  Author: JoachimWagner
 */ 

#include "PWM.h"

void PWM_init()
{

	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | ( 1 << CS00);
}


void PWM_set_value(uint8_t value)
{
	OCR0 = value;
}
/*
	wie machtr sie es
*/
void PWM_set_duty(double duty) {
	PWM_set_value((uint8_t) (duty * 2.55));
}
