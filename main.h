#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char c);

int handle_conversion(const char **format, va_list args);
int handle_long(const char **format, va_list args);
int handle_short(const char **format, va_list args);

/* Print functions */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(va_list args);
int print_unsigned(va_list args, int base, int uppercase);

/* Number base printer */
int print_number_base(unsigned long n, int base, int uppercase);

#endif

