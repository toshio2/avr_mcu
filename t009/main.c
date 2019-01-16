#include <avr/pgmspace.h>

const char PROGMEM txtHelloWorld[] = "Hello World!";

int main(void)
{
	for (unsigned char i = 0; i < 10; i++)
	{
		//c = pgm_read_byte(&txtHelloWorld[i]);
	}

	while(1);
}

