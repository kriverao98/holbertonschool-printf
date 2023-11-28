#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int print_char(va_list args)
{
	int ch;

	ch = va_arg(args, int);
	return _putchar(ch);
}

int print_string(va_list args)
{
	int i, count = 0;
	char *str;

	i = 0;
	str = va_arg(args, char *);
	if (str == NULL)
	str = "(NULL)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}

int print_percent(va_list args)
{
	char *str;
	str = "%";
	if (va_arg(args, int) == *str)
	{
		return (*str);
	}
	return (*str);
}

int print_d(va_list args)
{
	unsigned int a = 0, b, c, d;
	int n;

	d = 0;
	n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		n = abs(n);
	}

	b = n;
	c = 1;

	while (b > 9)
	{
		b /= 10;
		c *= 10;
	}

	while (c >= 1)
	{
		d += _putchar(((a/c) % 10) + '0');
		c /= 10;
	}
		return (d);
}

int print_int(va_list args)
{
	return (print_d(args));
}
