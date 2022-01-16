#ifndef i2c_digital_clock
#define i2c_digital_clock

#include <reg51.h>

#define port0 0
#define port1 1
#define port2 2
#define port3 3

/* standard_definition */
typedef signed char s8;
typedef signed int s16;
typedef signed long int s32;
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long int u32;

/* switches */
sbit sw0 = P1 ^ 0;
sbit sw1 = P1 ^ 1;
sbit sw2 = P1 ^ 2;
sbit sw3 = P1 ^ 3;
sbit sw4 = P1 ^ 4;
sbit sw5 = P1 ^ 5;

/* lcd */
sbit rw = P3 ^ 6;
sbit en = P3 ^ 7;
sbit rs = P3 ^ 5;

sfr port = 0x80;

/* delay */
extern void delay_1s(s16);

/* lcd_drivers */
extern void lcd_init();
extern void lcd_cmd(u8);
extern void lcd_input(u8);
extern u8 read_lcd();

/* lcd_Operation */
extern void lcd_integer(u8);
extern void lcd_hex(u8);
extern u8 int_to_hex(u8);
extern u8 hex_to_int(u8);

/* I2C Bit-Banging*/
extern void start_condition();
extern void stop_condition();
extern void write(u8);
extern u8 read();
extern bit ack();
extern void no_ack();
extern u8 i2c_read_data(u8, u8);
extern void i2c_write_data(u8, u8, u8);

/* Digital Clock */
extern void lcd_cu_hr(u8);
extern void lcd_next_hr(u8);
extern void lcd_cu_min(u8);
extern void lcd_next_min(u8);
extern void lcd_cu_sec(u8);
extern void lcd_next_sec(u8);

extern void lcd_cu_day(u8);
extern void lcd_next_day(u8);
extern void lcd_cu_mon(u8);
extern void lcd_next_mon(u8);
extern void lcd_cu_year(u8);
extern void lcd_next_year(u8);

#endif
