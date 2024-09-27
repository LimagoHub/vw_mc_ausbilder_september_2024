/*
 * adc.h
 *
 * Created: 27.09.2024 08:39:25
 *  Author: JoachimWagner
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

/*

*/
void ADC_init();
uint16_t ADC_read(uint8_t channel);

//uint8_t ADC_read_8Bit(uint8_t channel);

double ADC_read_voltage(uint8_t channel);

#endif /* ADC_H_ */