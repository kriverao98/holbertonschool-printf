#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_d(va_list args);
int print_int(va_list args);

typedef struct {
  const char *format;
  int (*f)(va_list);
} spec;

#endif
