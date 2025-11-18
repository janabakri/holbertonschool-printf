#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * _putchar - writes a character to stdout
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_string - prints a string
 */
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";
    while (*s)
        count += _putchar(*s++);
    return count;
}

/**
 * print_S - prints string with non-printables as \xHH
 */
int print_S(char *s)
{
    int count = 0;
    char hex[] = "0123456789ABCDEF";

    if (!s)
        s = "(null)";
    while (*s)
    {
        if ((*s > 0 && *s < 32) || *s >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar(hex[(*s >> 4) & 0xF]);
            count += _putchar(hex[*s & 0xF]);
        }
        else
            count += _putchar(*s);
        s++;
    }
    return count;
}

/**
 * print_number - prints signed numbers
 */
int print_number(long n)
{
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        n = -n;
    }
    if (n / 10)
        count += print_number(n / 10);
    count += _putchar(n % 10 + '0');
    return count;
}

/**
 * print_unsigned - prints unsigned numbers in given base
 */
int print_unsigned(unsigned long n, int base, int uppercase)
{
    int count = 0;
    char *digits;

    digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n / base)
        count += print_unsigned(n / base, base, uppercase);
    count += _putchar(digits[n % base]);
    return count;
}

/**
 * print_pointer - prints pointer address
 */
int print_pointer(void *p)
{
    unsigned long addr = (unsigned long)p;
    int count = 0;

    count += _putchar('0');
    count += _putchar('x');
    count += print_unsigned(addr, 16, 0);
    return count;
}

/**
 * _printf - main printf function
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *s;
    char c;
    long lnum;
    unsigned long unum;
    void *ptr;
    int is_long = 0, is_short = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            is_long = 0;
            is_short = 0;

            /* Length modifiers */
            if (*format == 'l')
            {
                is_long = 1;
                format++;
            }
            else if (*format == 'h')
            {
                is_short = 1;
                format++;
            }

            switch (*format)
            {
                case 'c':
                    c = (char)va_arg(args, int);
                    count += _putchar(c);
                    break;
                case 's':
                    s = va_arg(args, char *);
                    count += print_string(s);
                    break;
                case 'S':
                    s = va_arg(args, char *);
                    count += print_S(s);
                    break;
                case 'd':
                case 'i':
                    if (is_long)
                        lnum = va_arg(args, long);
                    else if (is_short)
                        lnum = (short)va_arg(args, int);
                    else
                        lnum = va_arg(args, int);
                    count += print_number(lnum);
                    break;
                case 'u':
                    if (is_long)
                        unum = va_arg(args, unsigned long);
                    else if (is_short)
                        unum = (unsigned short)va_arg(args, unsigned int);
                    else
                        unum = va_arg(args, unsigned int);
                    count += print_unsigned(unum, 10, 0);
                    break;
                case 'o':
                    if (is_long)
                        unum = va_arg(args, unsigned long);
                    else if (is_short)
                        unum = (unsigned short)va_arg(args, unsigned int);
                    else
                        unum = va_arg(args, unsigned int);
                    count += print_unsigned(unum, 8, 0);
                    break;
                case 'x':
                    if (is_long)
                        unum = va_arg(args, unsigned long);
                    else if (is_short)
                        unum = (unsigned short)va_arg(args, unsigned int);
                    else
                        unum = va_arg(args, unsigned int);
                    count += print_unsigned(unum, 16, 0);
                    break;
                case 'X':
                    if (is_long)
                        unum = va_arg(args, unsigned long);
                    else if (is_short)
                        unum = (unsigned short)va_arg(args, unsigned int);
                    else
                        unum = va_arg(args, unsigned int);
                    count += print_unsigned(unum, 16, 1);
                    break;
                case 'p':
                    ptr = va_arg(args, void *);
                    count += print_pointer(ptr);
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    count += _putchar('%');
                    count += _putchar(*format);
            }
        }
        else
            count += _putchar(*format);
        format++;
    }

    va_end(args);
    return count;
}

