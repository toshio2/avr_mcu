/*
 *	Project:	t008
 *	Reference:	https://exploreembedded.com/wiki/AVR_Timer_programming
 *
 */

#ifndef	F_CPU
#define	F_CPU	16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD |= (1 << PINB0);

	TCCR1B = 0x00;
	TCCR1B |= (1 << CS12) | (1 << CS10);
	OCR1A = 0x0f42;
	TCNT1 = 0x00;

	while(1)
	{
		while((TIFR1 & (1 << OCF1A)) == 0);
		PORTB ^= (1 << PINB0);
		TCNT1 = 0x00;
		TIFR1 |= (1 << OCF1A);

	}
	return 0;
}
