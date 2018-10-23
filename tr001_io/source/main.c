// insert the code
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define DELAY_TIME 50
#define sbi(x, y) x |= _BV(y)
#define cbi(x, y) x &= ~(_BV(y))
#define tbi(x, y) x ^= _BV(y)

void io_init()
{
	sbi(DDRB, PB1);
}

void PWM_init()
{
	TCCR1A |= _BV(COM1A1) | _BV(WGM10);
	TCCR1B |= _BV(CS10) | _BV(WGM12);
}

int main(void)
{
	io_init();
	PWM_init();
	uint8_t pwm = 0x00;
	bool up = true;

	while(1)
	{
		OCR1A = pwm;
		pwm += up ? 1 : -1;
		if(pwm == 0xff)
			up = false;
		else if (pwm == 0x00)
			up = true;

		_delay_ms(DELAY_TIME);
	}
}
