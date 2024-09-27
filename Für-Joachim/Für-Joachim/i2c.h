/* HEADER-Datei für den I2C-Bus
*	Autor
*	Datum
*/
#define F_CPU 16000000UL
#include <avr/io.h>
void i2c_init()
{
	TWSR = 0x00;
	TWBR = 0x08;
	TWCR = (1<<TWEN);
}
void i2c_start()
{
	TWCR	=(1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while (!(TWCR & (1<<TWINT)));
}
void i2c_write(char x)
{
	TWDR = x;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
}
char i2c_read()
{
	TWCR = (1<<TWEN) | (1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}