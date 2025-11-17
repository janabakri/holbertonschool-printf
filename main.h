#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* _printf function */
int _printf(const char *format, ...);

/* Character printing function */
int _putchar(char c);

/* String printing function */
int print_string(char *s);

/* Integer printing function */
int print_number(int n);

#endif /* MAIN_H */

