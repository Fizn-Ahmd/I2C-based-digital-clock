#include "i2c_digital_clock.h"

/* I2C write Bit-Banging Method */
void i2c_write_data(u8 sa, u8 ma, u8 d)
{
	start_condition();
	write(sa);
	ack();
	write(ma);
	ack();
	write(d);
	ack();
	stop_condition();
}

/* I2C Read Bit-Banging method */
u8 i2c_read_data(u8 sa, u8 ma)
{
	u8 temp;
	start_condition();
	write(sa);
	ack();
	write(ma);
	ack();
	start_condition();
	write(sa | 1);
	ack();
	temp = read();
	no_ack();
	stop_condition();
	return temp;
}
