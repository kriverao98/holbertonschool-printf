#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int (*get_func(char format))(va_list args);
int _printf(const char *format, ...)
{
	int count = 0;
	int (*handler)(va_list args);

	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			handler = get_func(*format);

			if (handler != NULL)
			{
				count += handler(args);
			}

			else
			{
				write(1, "%", 1);
				count++;
			}
			format++;
		}

		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}
	va_end(args);
	return count;
}
