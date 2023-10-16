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

int print_digit(long digit, int base)
{
	int count = 0;
	char *symbols;

	symbols = "0123456789abcdef";

	if (digit < 0)
	{
		count = write(1, "-", 1);
		count += print_digit(-digit, base);
	}
	else if (digit < base)
		count = print_char(symbols[digit]);
	else if (digit > base)
	{
		count = print_digit(digit / base, base);
		count += print_digit(digit % base, base);
	}
	return (count);
}
