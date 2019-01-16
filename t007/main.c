/*
 *	Project:	t007 (timer and interrupt)
 *	Date:		Nov 23, 2018
 */

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU   16000000UL
#endif

int main(void)
{
	cli();
    TCCR1B = 0;
    TCCR1B |= (1 << CS12) | (1 << CS10); // set the prescaler to 1024
    OCR1A = 15624;
    TCCR1B |= (1 << WGM12); // put timer/counter 1 in CTC mode
    TIMSK1 |= (1 << OCIE1A);
    sei();

    DDRB |= (1 << PINB0);
    PORTB |= (1 << PINB0);

    while(1)
    {

    }
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1 << PINB0);
}
