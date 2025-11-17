#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>   /* مكتبة دوال العاملات المتغيرة */
#include <unistd.h>   /* مكتبة write */

int _printf(const char *format, ...);          /* البروتوتايب الموجود */
int _putchar(char c);
int print_string(char *str);
int print_number(int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);

#endif
