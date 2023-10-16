#include <unistd.h>
#include <stdio.h>
#include "main.h"

int print_char(int c)
{
	return write(1, &c, 1);
}

int print_str(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		print_char(*str);
		str++;
		count++;
	}

	return (count);
}

int print_digit(int digit, int base)
{
	return (digit + base);
}
