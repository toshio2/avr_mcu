#include <avr/io.h>
#include <stdio.h>

#ifndef BAUD
#define BAUD 9600
#endif

#include <util/setbaud.h>

void uart_init(void)
{
	UBRR0H = UBRRH_VALUE;
	UBRR0L = UBRRL_VALUE;

	#if USE_2X
		UCSR0A |= _BV(U2X0);
	#else
		UCSR0A &= ~(_BV(U2X0));
	#endif
		UCSR0C = _BV(UCSZ01) | _BV(UCSZ00);
		UCSR0B = _BV(RXEN0) | _BV(TXEN0);
}

void uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
	{
		uart_putchar('\r', stream);
	}
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
}

char uart_getchar(FILE *stream)
{
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}
