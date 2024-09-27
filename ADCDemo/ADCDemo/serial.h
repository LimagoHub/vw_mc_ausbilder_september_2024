/*
 * serial.h
 *
 * Created: 26.09.2024 12:17:37
 *  Author: JoachimWagner
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

#define BAUD9600 9600
#define BAUD19200 19200

/*
9.600 bit/s	104 탎
19.200 bit/s	52,1 탎
38.400 bit/s	26,0 탎
57.600 bit/s	17,4 탎
115.200 bit/s
*/


#include <avr/io.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#define BAUD 9600
//#define MYUBRR (F_CPU/(16L*BAUD))-1

void serial_init(uint32_t baudrate);
void serial_send_char(uint8_t valueToSend);
void serial_send_int(int valueToSend);
void serial_send_double(double valueToSend);
void serial_send_string(uint8_t * string);
void serial_send_new_line(void);
uint8_t serial_receive_char(void);



#endif /* SERIAL_H_ */