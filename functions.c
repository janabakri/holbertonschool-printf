#include <stdarg.h>
#include "main.h"

/* Print a single char */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return _putchar(c);
}

/* Print a string */
int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        count += _putchar(*s);
        s++;
    }
    return count;
}

/* Print percent sign */
int print_percent(va_list args)
{
    (void)args;
    return _putchar('%');
}

/* Print number */
int print_number(va_list args)
{
    int n = va_arg(args, int);
    if (n < 0)
    {
        _putchar('-');
        return print_number_base((unsigned int)(-n), 10, 0) + 1;
    }
    return print_number_base((unsigned int)n, 10, 0);
}

/* Print unsigned number with base */
int print_unsigned(va_list args, int base, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    return print_number_base(n, base, uppercase);
}

/* Helper to print numbers in any base */
int print_number_base(unsigned long n, int base, int uppercase)
{
    char buffer[50];
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    int i = 0, count = 0;

    if (n == 0)
        return _putchar('0');

    while (n > 0)
    {
        buffer[i++] = digits[n % base];
        n /= base;
    }

    while (--i >= 0)
        count += _putchar(buffer[i]);

    return count;
}

