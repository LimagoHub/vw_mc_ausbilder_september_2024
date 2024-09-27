/*
 * serial.c
 *
 * Created: 26.09.2024 12:23:51
 *  Author: JoachimWagner
 */ 

#include "serial.h"

void serial_init(uint32_t baudrate){
	
	uint16_t MYUBRR = (F_CPU/(16L*baudrate))-1;
	
	// Baudrate
	UBRRH = (uint8_t) (MYUBRR >> 8);
	UBRRL = (uint8_t) MYUBRR;

	UCSRB |= (1 << RXCIE);
	// Senden und empfangen aktivieren
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	// Protokoll
	UCSRC |= (1 << UCSZ1) | (1 << UCSZ0) |(1 << URSEL);
	
}

void serial_send_char(uint8_t valueToSend){
	while (! (UCSRA & (1<<UDRE))); // warten bis der Sendepuffer leer ist
	UDR =valueToSend;
	
}

uint8_t serial_receive_char(){
	while ((UCSRA & (1 << RXC)) == 0){} // Warten bis empfangspuffer voll ist. (Daten wurden emfangen)
	return UDR;
	
}

void serial_send_string(uint8_t * string){
	int i = 0;
	while(string[i]) {
		serial_send_char(string[i++]);
	}
}


void serial_send_int(int valueToSend){
	const int datenbasisDezimal = 10;
	char buffer [50];
	itoa(valueToSend, buffer, datenbasisDezimal );
	serial_send_string(buffer);
}

void serial_send_double(double valueToSend){
	const int mindestZahlDerStellen = 1;
	const int nachkommastellen = 2;
	char buffer [50];
	
	dtostrf(valueToSend, mindestZahlDerStellen, nachkommastellen, buffer);
	serial_send_string(buffer);
	
}

void serial_send_new_line() {
	serial_send_string("\r\n");
}


