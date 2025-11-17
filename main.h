#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Prototype for _printf function */
int _printf(const char *format, ...);

/* Helper functions */
int _putchar(char c);
int print_string(char *s);
int print_number(int n);

#endif /* MAIN_H */

