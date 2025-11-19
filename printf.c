#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            count += handle_conversion(&format, args);
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

int handle_conversion(const char **format, va_list args)
{
    if (**format == 'l')
        return handle_long(format, args);

    if (**format == 'h')
        return handle_short(format, args);

    switch (**format)
    {
        case 'c':
            return print_char(args);
        case 's':
            return print_string(args);
        case '%':
            return print_percent(args);
        case 'd':
        case 'i':
            return print_number(args);
        default:
            return _putchar('%') + _putchar(**format);
    }
}

int handle_long(const char **format, va_list args)
{
    long num;

    (*format)++; /* Skip 'l' */

    switch (**format)
    {
        case 'd':
        case 'i':
            num = va_arg(args, long);
            if (num < 0)
            {
                _putchar('-');
                return print_number_base((unsigned long)(-num), 10, 0) + 1;
            }
            return print_number_base((unsigned long)num, 10, 0);
        default:
            return _putchar('l') + _putchar(**format);
    }
}

int handle_short(const char **format, va_list args)
{
    int num;

    (*format)++; /* Skip 'h' */

    switch (**format)
    {
        case 'd':
        case 'i':
            num = va_arg(args, int);
            if ((short)num < 0)
            {
                _putchar('-');
                return print_number_base((unsigned short)(-(short)num), 10, 0) + 1;
            }
            return print_number_base((unsigned short)num, 10, 0);
        default:
            return _putchar('h') + _putchar(**format);
    }
}
