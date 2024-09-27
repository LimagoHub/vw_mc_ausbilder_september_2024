/*
 * Seriell.c
 *
 * Created: 26.09.2024 09:21:17
 * Author : JoachimWagner
 */ 

#include <avr/io.h>
#include <stdlib.h> // Für itoa
#include <avr/interrupt.h>
#include "serial.h"

ISR(USART_RXC_vect){
	uint8_t value = UDR;// Empfange
	//serial_send_char(value);
	UDR = value; // .. und gleich wieder raus
}

int main(void)
{
	serial_init(BAUD9600);
	
	serial_send_string("Hallo Putty");
	serial_send_new_line();
	
	uint16_t wert = 4711;
	serial_send_int(wert);
	serial_send_new_line();
	
	double kommazahl =  3.14;
	serial_send_double(kommazahl);
	serial_send_new_line();
	sei();
    while (1) 
    {
		//uint8_t value = serial_receive_char();
		
		//serial_send_char(value + 1);
    }
}

