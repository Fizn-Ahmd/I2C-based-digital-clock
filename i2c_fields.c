#include <reg51.h>
#include <intrins.h>

#include "i2c_digital_clock.h"

sbit sda = P2^0;
sbit scl = P2^1;

void start_condition()
{
	scl = 1;
	sda = 1;
	sda = 0;
}

void stop_condition()
{
	scl = 0;
	sda = 0;
	scl = 1;
	sda = 1;
}

void write(u8 d)
{
	s8 i;
	for (i = 7; i >= 0 ; i--) {
		scl = 0;
		sda = ((d>>i) & 1) ? 1 : 0;
		scl = 1;
	}
}

u8 read()
{
	s8 i;
	u8 temp = 0;
	for (i = 7; i >= 0; i--) {
		scl = 1;
		if (sda == 1)
			temp |= (1<<i);
		scl = 0;
	}
	return temp;
}

bit ack()
{
	scl = 0;
	sda = 1;
	scl = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	if (sda == 0) {
		scl = 0;
		return 0;
	} else {
		scl = 0;
		return 1;
	}
}

void no_ack()
{
	scl = 0;
	sda = 1;
	scl = 1;
}