#include <stdlib.h>
#include "lcd_lib.h"

void LCD4_cmd(unsigned char cmd)
{
	// Send upper nibble
	LCD_DATA = (LCD_DATA & 0x0F) | (cmd & 0xF0);
	LCD_DATA &= ~(1<<rs);  // RS = 0 for command
	LCD_DATA |= (1<<en);
	_delay_us(1);
	LCD_DATA &= ~(1<<en);
	_delay_us(200);
	
	// Send lower nibble
	LCD_DATA = (LCD_DATA & 0x0F) | ((cmd << 4) & 0xF0);
	LCD_DATA |= (1<<en);
	_delay_us(1);
	LCD_DATA &= ~(1<<en);
	_delay_ms(2);
}

void LCD4_write(unsigned char data)
{
	// Send upper nibble
	LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);
	LCD_DATA |= (1<<rs);  // RS = 1 for data
	LCD_DATA |= (1<<en);
	_delay_us(1);
	LCD_DATA &= ~(1<<en);
	_delay_us(200);
	
	// Send lower nibble
	LCD_DATA = (LCD_DATA & 0x0F) | ((data << 4) & 0xF0);
	LCD_DATA |= (1<<en);
	_delay_us(1);
	LCD_DATA &= ~(1<<en);
	_delay_ms(2);
}


void LCD4_init()
{
	LCD_DDR = 0xFF;  // Set LCD port as output
	_delay_ms(20);   // Wait for LCD to power up
	
	// Initialize in 4-bit mode
	LCD4_cmd(0x33);
	_delay_ms(5);
	LCD4_cmd(0x32);
	_delay_ms(2);
	LCD4_cmd(0x28);  // 4-bit mode, 2 lines, 5x8 font
	_delay_ms(2);
	LCD4_cmd(0x0C);  // Display on, cursor off
	_delay_ms(2);
	LCD4_cmd(0x06);  // Increment cursor
	_delay_ms(2);
	LCD4_cmd(0x01);  // Clear display
	_delay_ms(2);
}


void LCD4_write_string(const char *data)
{
	int n=0;
	while(data[n])
	{
		LCD4_write(data[n]);
		n++;
		if (n==16)
		{
			LCD4_cmd(0xC0);
		}
	}
}

void LCD4_gotoxy(int x, int y)
{
	y--;
	if (x==1)
	{
		LCD4_cmd(0x80+y);
	}
	if (x==2)
	{
		LCD4_cmd(0xC0+y);
	}
}

void LCD4_clear()
{
	LCD4_cmd(0x01);
}

void LCD4_write_int(int data){
	const int datenbasisDezimal = 10;
	char buffer [50];
	itoa(data, buffer, datenbasisDezimal );
	LCD4_write_string(buffer);
}

void LCD4_write_double(double data){
	const int mindestZahlDerStellen = 1;
	const int nachkommastellen = 2;
	char buffer [50];
	
	dtostrf(data, mindestZahlDerStellen, nachkommastellen, buffer);
	LCD4_write_string(buffer);
}