#include "main.h"
#include <stdarg.h>
#include <limits.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count;
    char *s;
    char c;
    long lnum;
    unsigned long unum;
    void *ptr;
    int is_long;
    int is_short;
    char *str_ptr;

    va_start(args, format);
    count = 0;

    while (*format)
    {
        is_long = 0;
        is_short = 0;

        if (*format == '%')
        {
            format++;

            /* Check length modifiers */
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

            /* Conversion specifiers */
            if (*format == 'c')
            {
                c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (*format == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    count += _putchar(*s);
                    s++;
                }
            }
            else if (*format == 'S') /* Custom non-printable specifier */
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                str_ptr = s;
                while (*str_ptr)
                {
                    unsigned char uc = *str_ptr;
                    if (uc < 32 || uc >= 127)
                    {
                        count += _putchar('\\');
                        count += _putchar('x');
                        count += _putchar("0123456789ABCDEF"[uc / 16]);
                        count += _putchar("0123456789ABCDEF"[uc % 16]);
                    }
                    else
                        count += _putchar(uc);
                    str_ptr++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                if (is_long)
                    lnum = va_arg(args, long);
                else if (is_short)
                    lnum = (short)va_arg(args, int);
                else
                    lnum = va_arg(args, int);
                count += print_number(lnum);
            }
            else if (*format == 'u' || *format == 'o' ||
                     *format == 'x' || *format == 'X')
            {
                if (is_long)
                    unum = va_arg(args, unsigned long);
                else if (is_short)
                    unum = (unsigned short)va_arg(args, unsigned int);
                else
                    unum = va_arg(args, unsigned int);
                count += print_unsigned(unum, *format);
            }
            else if (*format == 'p')
            {
                ptr = va_arg(args, void *);
                count += print_pointer(ptr);
            }
            else
            {
                count += _putchar('%');
                if (*format)
                    count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);
    return count;
}

/* Helper functions */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* You need to implement print_number, print_unsigned, print_pointer in C90 style */

