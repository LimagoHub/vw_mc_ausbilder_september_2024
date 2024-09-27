/*
 * adc.c
 *
 * Created: 27.09.2024 09:38:02
 *  Author: JoachimWagner
 */ 

#include "adc.h"

void ADC_init(){
	DDRA=0x0;			/* Make ADC port as input */
	ADCSRA = (1 << ADEN	) | ( 1 << ADPS0) | ( 1 << ADPS1) | ( 1 << ADPS2) ;		/* Enable ADC, fr/128  */
	ADMUX = (1 << REFS0) ;
}

static void setChannel(uint8_t channel)
{
	ADMUX &= 0xF0; // Kanal auf 0 stellen d.h. die rechten 4 bit löschen
	ADMUX |= (channel & 0x0f);
}

static void startConversion()
{
	ADCSRA |= (1<<ADSC);	// Start conversion
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
}

static uint16_t getResult(uint16_t result)
{
	result = (uint16_t) ADCL | (uint16_t)  (ADCH << 8); 	return result;
}

uint16_t ADC_read(uint8_t channel){
	uint16_t result;
	
	setChannel(channel);
	startConversion();
	_delay_us(10);
	result = getResult(result);
	
	return result;
}

//uint8_t ADC_read_8Bit(uint8_t channel);

double ADC_read_voltage(uint8_t channel){
	uint16_t digitalValue = ADC_read(channel);
	return digitalValue * 0.0048828125;
}
