#include "i2c_digital_clock.h"

u8 data;

/*  
    lcd_cu_** to move the cursor to the hr/min/sec/day/month/year
	lcd_next_** to change the value in the respective position
*/

void lcd_cu_hr(u8 n)
{
	lcd_cmd(0x2);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input(':');
	lcd_cmd(0x6);
}

void lcd_next_hr(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data =	int_to_hex(n);
	lcd_hex(data);
	lcd_input(':');
	i2c_write_data(0xD0,0x02,data);
}

void lcd_cu_min(u8 n)
{
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input(':');
	lcd_cmd(0x6);
}

void lcd_next_min(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data = int_to_hex(n);
	lcd_hex(data);
	lcd_input(':');
	i2c_write_data(0xD0,0x01,data);
}

void lcd_cu_sec(u8 n)
{
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
}

void lcd_next_sec(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data =	int_to_hex(n);
	lcd_hex(data);
	i2c_write_data(0xD0,0x00,data);
}

void lcd_cu_day(u8 n)
{
	lcd_cmd(0xC0);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input('/');
	lcd_cmd(0x6);
}

void lcd_next_day(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data =	int_to_hex(n);
	lcd_hex(data);
	lcd_input('/');
	i2c_write_data(0xD0,0x04,data);
}

void lcd_cu_mon(u8 n)
{
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input('/');
	lcd_cmd(0x6);
}

void lcd_next_mon(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data =	int_to_hex(n);
	lcd_hex(data);
	lcd_input('/');
	i2c_write_data(0xD0,0x05,data);
	lcd_input('2');
	lcd_input('0');
	lcd_input('0');
}

void lcd_cu_year(u8 n)
{
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
	lcd_integer(n);
	lcd_cmd(0x4);
	lcd_input(' ');
	lcd_cmd(0x6);
}

void lcd_next_year(u8 n)
{
	if (n > 10) {
		lcd_cmd(0x4);
		lcd_input(' ');
		lcd_cmd(0x6);
	}
	data =	int_to_hex(n);
	lcd_hex(data);
	i2c_write_data(0xD0,0x06,data);
}