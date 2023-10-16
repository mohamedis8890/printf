#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
  * print_format - selects the proper print function based on the
  * specifier.
  *
  * @specifier: determines the type of data to be printed.
  * @arg: a pointer to the arg containing the data.
  *
  * Return: the number of characters printed.
  */
int print_format(char specifier, va_list arg)
{
	int count = 0;

	if (specifier == 'c')
		count += print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(arg, int), 10);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(arg, unsigned int), 16);
	else
		count += write(1, &specifier, 1);

	return (count);
}

/**
  * _printf - prints formatted string to the stdout.
  *
  * @format: the string to be formatted.
  *
  * Return: the number of characters printed.
  */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), args);
		}
		else
			count += write(1, format, 1);

		++format;
	}

	va_end(args);

	return (count);
}
