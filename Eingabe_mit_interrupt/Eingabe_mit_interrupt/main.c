/*
 * Eingabe_mit_interrupt.c
 *
 * Created: 24.09.2024 10:50:05
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect) {
	PORTB = 0xFF;
}

ISR(INT1_vect) {
	PORTB = 0;
}

int main(void)
{
	
	DDRD = 0; // D auf Eingang
	PORTD = 0xFF;// interner Pullup
	
	DDRB = 0xFF;
	PORTB = 0;
	
	GICR = (1 << INT0) | (1 << INT1);// 0 =d2 1 = d3
	MCUCR = (1 << ISC01) | (1 << ISC11);
	
	sei();  // cli()
	
	/* Replace with your application code */
	while (1);
}