#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct format
{
	char *id;
	int (*f)();
} match;

int _printf(const char *format, ...);

int print_char(int c);
int print_str(char *str);
int print_digit(long digit, int base);

#endif
