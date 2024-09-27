/*
 * Eingabe_mit_Polling.c
 *
 * Created: 24.09.2024 09:10:58
 * Author : JoachimWagner
 */ 

#include <avr/io.h>

#define SET_BIT(byte,bit) byte|=(1<<bit)
#define CLEAR_BIT(byte,bit) byte&=~(1<<bit)
#define TOOGLE_BIT(byte,bit) BYTE^=(1<<bit)
#define GET_BIT(byte,bit) byte&(1<<bit)

int main(void)
{
	
	DDRD = 0; // D auf Eingang
	PORTD = 0xFF;// interner Pullup
	
	DDRB = 0xFF;
	PORTB = 0;
	
    /* Replace with your application code */
    while (1) 
    {
		if(!( PIND & (1 << PIND2))) {
			PORTB = 0xff;
		}
		
		if(!( PIND & (1 << PIND3))) {
			PORTB = 0;
		}
		
    }
}

