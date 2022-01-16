#include <reg51.h>

#include "i2c_digital_clock.h"

/* Initializing the 16*2 LCD */
void lcd_init()
{
	lcd_cmd(0x2);
	lcd_cmd(0x1);
	lcd_cmd(0xE);
	lcd_cmd(0x38);
}

/* Input to the LCD */
void lcd_input(u8 ch)
{
	port = ch;
	rs = 1;
	rw = 0;
	en = 1;
	delay_1s(2);
	en = 0;
}

/* Func to execute the cmd */
void lcd_cmd(u8 ch)
{
	port = ch;
	rs = 0;
	rw = 0;
	en = 1;
	delay_1s(2);
	en = 0;
}

/* Reading from LCD */
u8 read_lcd()
{
	u8 r;
	// lcd_cmd(0x88);
	rs = 1;
	rw = 1;
	delay_1s(3);
	en = 1;
	delay_1s(3);
	en = 0;
	r = port;
	return r;
}

/* Converting integer to Hex Value */
u8 int_to_hex(u8 h)
{
	u8 te = 0, x, y;
	x = h / 10;
	te |= x << 4;
	y = h % 10;
	te |= y;
	return te;
}

/* Converting Hex to integer Value */
u8 hex_to_int(u8 h)
{
	u8 te = 0, x, y;
	x = h / 16;
	y = h % 16;
	te = (x * 10) + y;
	return te;
}

/* Func to send integer values to LCD */
void lcd_integer(u8 n)
{
	u8 buf[6];
	s8 ik = 0;
	if (n == 0) {
		lcd_input('0');
		lcd_input('0');
	}
	if (n > 0 && n < 10)
		lcd_input('0');
	while (n) {
		buf[ik] = n % 10 + 48;
		ik++;
		n = n / 10;
	}
	for (--ik; ik >= 0; ik--)
		lcd_input(buf[ik]);
}

/* Func to send Hex values to LCD */
void lcd_hex(u8 n)
{
	u8 n1;
	u8 buf[6];
	s8 ik = 0;
	if (n == 0) {
		lcd_input('0');
	}
	while (n) {
		n1 = n % 16;
		if (n1 >= 10)
			buf[ik] = n1 + 55;
		else
			buf[ik] = n1 + 48;
		ik++;
		n = n / 16;
	}
	for (--ik; ik >= 0; ik--)
		lcd_input(buf[ik]);
}
