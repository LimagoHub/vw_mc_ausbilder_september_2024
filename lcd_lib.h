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

#include <avr/io.h>
#include <util/delay.h>


void LCD4_cmd(unsigned char);
void LCD4_init();
void LCD4_write(unsigned char);
void LCD4_write_string(const char *data);
void LCD4_gotoxy(int, int);
void LCD4_clear();