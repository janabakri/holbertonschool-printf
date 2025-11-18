#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/* Main printf function */
int _printf(const char *format, ...);

/* Helper functions */
int handle_conversion(const char **format, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(va_list args);
int print_unsigned(va_list args, int base, int uppercase);
int print_octal(va_list args);
int print_hex(va_list args, int uppercase);

/* Length modifier handlers */
int handle_long(const char **format, va_list args);
int handle_short(const char **format, va_list args);

/* Utility functions */
int _putchar(char c);
int print_number_base(unsigned long n, unsigned int base, int uppercase);

#endif /* MAIN_H */

