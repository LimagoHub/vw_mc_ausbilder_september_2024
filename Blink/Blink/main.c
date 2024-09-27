/*
 * Blink.c
 *
 * Created: 23.09.2024 08:20:25
 * Author : JoachimWagner
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void setup();
void loop();



int main(void)
{
    setup();
    while (1) 
    {
		loop();
    }
}

void setup() {
	
	uint16_t x;
	
	DDRB = 0b00000001; // Data Direction Register (B) -> PB0 auf ausgang
	PORTB = 0b00000001; //  PB0 auf 5 Volt
}

void loop() {
	//PORTB ^=   0xFF;
	PORTB = ~PORTB;
	_delay_ms(500);
	
}

