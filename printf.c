#include "main.h"
#include <stdarg.h>

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

            switch (*format)
            {
                case 'c':
                    count += print_char(args);
                    break;

                case 's':
                    count += print_string(args);
                    break;

                case '%':
                    count += print_percent(args);
                    break;

                case 'd':
                case 'i':
                    count += print_number(args);
                    break;

                default:
                    count += _putchar('%');
                    count += _putchar(*format);
                    break;
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
