/*
 * Timer440HZNormalMode.c
 *
 * Created: 24.09.2024 17:11:03
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
ISR(TIMER0_OVF_vect)
{
	PORTB=~PORTB;		/* Toggle PORTB */
	TCNT0 = 0xB9;
}

int main(void)
{
	// Port B auf Ausgang alle LED aus
	DDRB = 0xFF;
	PORTB = 0;
	
	//TCCR0 = 0;
	
	TCNT0 = 0xB9; // (16MHZ / (2*440) / 256) - 1 = 70. Timer counter mit 255 -70 = 185 = 0xB9 vorbelegen 
	//TIMSK
	//Bit 7		6		5		4		3		2		1		0
	//	OCIE2	TOIE2	TICIE1	OCIE1A	OCIE1B	TOIE1	OCIE0	TOIE0		
	
	TIMSK=(1<<TOIE0); // Overflow Interrupt aktivieren
	sei();
	TCCR0 = (1 << CS02); // auf normal mode Prescaler auf 256 und Timer starten
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

