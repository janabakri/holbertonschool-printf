#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p;

    if (!format)
        return (-1);

    va_start(args, format);

    for (p = format; *p; p++)
    {
        if (*p == '%')
        {
            p++;
            if (!*p)
            {
                /* % في نهاية السلسلة */
                _putchar('%');
                count++;
                break;
            }

            if (*p == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*p == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    _putchar(*s++);
                    count++;
                }
            }
            else if (*p == '%')
            {
                _putchar('%');
                count++;
            }
            else
            {
                /* unknown specifier */
                _putchar('%');
                _putchar(*p);
                count += 2;
            }
        }
        else
        {
            _putchar(*p);
            count++;
        }
    }

    va_end(args);
    return (count);
}

