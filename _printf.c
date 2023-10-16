#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

int print_format(char specifier, va_list arg)
{
	int count = 0;

	if (specifier == 'c')
		count += print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(arg, int), 10);
	else if (specifier == 'x')
		count += print_digit(va_arg(arg, int), 16);
	else
		count += write(1, &specifier, 1);

	return (count);
}

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
