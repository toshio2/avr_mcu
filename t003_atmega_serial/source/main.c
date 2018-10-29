#include <stdio.h>

#include "../header/main.h"
#include "../header/uart.h"

int main(void)
{
	uart_init();
	stdout = &uart_output;
	stdin = &uart_input;

	char input;

	while(1)
	{
		puts("Serial Communication\n");
		input = getchar();
		printf("\nYou wrote %c\n", input);
	}

	return 0;
}
