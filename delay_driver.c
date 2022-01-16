#include "i2c_digital_clock.h"

void delay_1s(s16 a)
{
	while (--a) {
		u8 i = 250;
		while (--i)
			;
		i = 249;
		while (--i)
			;
	}
}