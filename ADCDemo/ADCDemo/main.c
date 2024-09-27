/*
 * ADCDemo.c
 *
 * Created: 27.09.2024 08:32:16
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include "adc.h"
#include "serial.h"

#define CHANNEL0 0
#define CHANNEL1 1

int main(void)
{
    
	ADC_init();
	serial_init(BAUD9600);
	PWM_init();
	
    while (1) 
    {
		uint16_t messwert1 = ADC_read(CHANNEL0);
		serial_send_string("Kanal Nr. 0: ");
		serial_send_int(messwert1);
		serial_send_new_line();
		
		PWM_set_value((uint8_t) (messwert1 >> 2));
		
		uint16_t messwert2 = ADC_read(CHANNEL1);
		serial_send_string("Kanal Nr. 1: ");
		serial_send_int(messwert2);
		serial_send_new_line();
		
		serial_send_new_line();
		
    }
}

