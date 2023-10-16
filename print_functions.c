#include <unistd.h>
#include <stdio.h>
#include "main.h"
/**
  * print_char - print a char
  *
  * @c: the char to be printed
  *
  * Return: the number of characters printed
  */
int print_char(int c)
{
	return (write(1, &c, 1));
}

/**
  * print_str - print a string
  *
  * @str: the string to be printed
  *
  * Return: the number of characters printed
  */
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

/**
  * print_digit - print a digit (decimal or hex)
  *
  * @digit: the digit to be printed
  * @base: the digit base (10 or 16)
  *
  * Return: the number of characters printed
  */
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
