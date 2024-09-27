/*
 * KnightRider.c
 *
 * Created: 23.09.2024 13:18:55
 * Author : JoachimWagner
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define PATTERN 0b00000111;

int main(void)
{
	DDRB = 0xFF;
	PORTB = 0;
	uint8_t richtung = 1; 
	uint8_t position = 0; 
    /* Replace with your application code */
    while (1) 
    {
		/*
		for(int8_t i=0; i < 8; i++) {
			PORTB = (PATTERN << i);
			_delay_ms(100);
		}
		for(int8_t i=7; i >= 0; i--) {
			PORTB = (PATTERN << i);
			_delay_ms(100);
		}
		*/
		PORTB = (PATTERN << position);
	    _delay_ms(100);
		
		if(position == 0){
			richtung = 1;
			
		}
		if(position == 7){
			richtung = -1;
			
		}
	
		position += richtung;
		
			
		
    }
}

