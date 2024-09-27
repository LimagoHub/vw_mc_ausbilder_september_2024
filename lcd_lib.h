#define LCD_DATA PORTB
#define LCD_DDR DDRB
#define rs PB0
#define rw PB1
#define en PB2
#define LCD_D4 PB4
#define LCD_D5 PB5
#define LCD_D6 PB6
#define LCD_D7 PB7

#define F_CPU 16000000UL

#define CLEAR 0b00000001
#define INSERT_MODE 0b00000110
#define TWO_LINES 0b00101000
#define DISPLAYon 0b00001100
#define DDRAMADRESS_1 0b00110011
#define DDRAMADRESS_2 0b00110010
#define OFF 0b00001000
#define ON 0b00001110
#define NEXT_LINE 0b11000000
#define SECOND_LINE 0b11000000
#define FIRST_LINE 0b10000000

#include <avr/io.h>
#include <util/delay.h>


void LCD4_cmd(unsigned char);
void LCD4_init();
void LCD4_write(unsigned char);
void LCD4_write_string(const char *data);
void LCD4_gotoxy(int, int);
void LCD4_clear();