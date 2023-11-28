#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int (*get_func(char format))(va_list args)
{
	int i = 0;
	spec arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_d},
		{"i", print_int},
		{NULL, NULL}
	};

	while (arr[i].format != NULL)
	{
		if (arr[i].format[0] == format)
		{
			return (arr[i].f);
		}
		i++;
	}
return (NULL);
}
