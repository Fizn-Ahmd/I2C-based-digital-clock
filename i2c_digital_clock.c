#include "i2c_digital_clock.h"

/* Main Funtion */
void main() 
{
	s8 hr,min,sec,day,mon,year,fl;
	lcd_init();
	i2c_write_data(0xD0,0x02,0x23);
	i2c_write_data(0xD0,0x01,0x59);
	i2c_write_data(0xD0,0x00,0x45);
	i2c_write_data(0xD0,0x04,0x29);
	i2c_write_data(0xD0,0x05,0x02);
	i2c_write_data(0xD0,0x06,0x20);

	l2:

	lcd_cmd(0xc);

	while (1) {
		hr = i2c_read_data(0xD0,0x02);
		min = i2c_read_data(0xD0,0x01);
		sec = i2c_read_data(0xD0,0x00);
		day = i2c_read_data(0xD0,0x04);
		mon = i2c_read_data(0xD0,0x05);
		year = i2c_read_data(0xD0,0x06);
		lcd_cmd(0x80);
		lcd_input(hr/16+48);
		lcd_input(hr%16+48);
		lcd_input(':');
		lcd_input(min/16+48);
		lcd_input(min%16+48);
		lcd_input(':');
		lcd_input(sec/16+48);
		lcd_input(sec%16+48);
		lcd_cmd(0xC0);
		lcd_input(day/16+48);
		lcd_input(day%16+48);
		lcd_input('/');
		lcd_input(mon/16+48);
		lcd_input(mon%16+48);
		lcd_input('/');
		lcd_input('2');
		lcd_input('0');
		lcd_input(year/16+48);
		lcd_input(year%16+48);
		if (sw0 == 0) {
			fl = 0;
			break;
		}
		delay_1s(500);
	}
	hr   = hex_to_int(hr);
	min  = hex_to_int(min);
	sec  = 0;
	day  = hex_to_int(day);
	mon  = hex_to_int(mon);
	year = hex_to_int(year);

	lcd_cmd(0xe);
	lcd_cmd(0x2);

	while (1) {
		if (sw1 == 0) {
			while(sw1 == 0);
			lcd_cmd(0xe);
			if (fl == 0) {
				hr = hr+1;
				if (hr == 24)
					hr = 0;
				lcd_cu_hr(hr);
			}
			if (fl == 1) {
				min = min+1;
				if (min == 60)
					min = 0;
				lcd_cu_min(min);
			}
			if (fl == 2) {
				sec = sec+1;
				if (sec == 60)
					sec = 0;
				lcd_cu_sec(sec);
			}
			if (fl == 3) {
				day = day+1;
				if (day == 32)
					day = 1;
				lcd_cu_day(day);
			}
			if (fl == 4) {
				mon = mon+1;
				if (mon == 13)
					mon = 1;
				lcd_cu_mon(mon);
			}
			if (fl == 5) {
				year = year+1;
				if (year == 100)
					year = 0;
				lcd_cu_year(year);
			}
		}
		if (sw2 == 0) {
			while (sw2 == 0);
			lcd_cmd(0xe);
			if (fl == 5) {
				lcd_next_year(year);
				goto l2;
			}
			if (fl == 4) {	
				lcd_next_mon(mon);
				fl = fl + 1;
			}
			if (fl == 3) {
				lcd_next_day(day);
				fl = fl + 1;
				if(mon < 10)
					lcd_input('0');
				else
					lcd_input('1');
			}
			if (fl == 2) {
				lcd_next_sec(sec);
				fl = fl +1;
				lcd_cmd(0xC0);
				if (day < 10)
					lcd_input('0');
				else if (day < 20)
					lcd_input('1');
				else if (day < 30)
					lcd_input('2');
				else
					lcd_input('3');
			}
			if (fl == 1) {
				lcd_next_min(min);
				fl = fl +1;
				lcd_input('0');
				lcd_cu_sec(sec);
			}
			if (fl == 0) {
				lcd_next_hr(hr);
				fl = fl+1;
				if (min < 10)
					lcd_input('0');
				else if (min < 20)
					lcd_input('1');
				else if (min < 30)
					lcd_input('2');
				else if (min < 40)
					lcd_input('3');
				else if (min < 50)
					lcd_input('4');
				else
					lcd_input('5');
			}
		}
		if (sw3 == 0) {
			while (sw3 == 0);
			lcd_cmd(0xc);
			goto l2;
		}
	}
}