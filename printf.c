#include "main.h"

/**
 * _printf - Custom printf function (mandatory tasks only)
 * @format: Format string
 * Return: Number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *s;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            /* ----- IMPORTANT FIX ----- */
            if (!format[i])   /* format ends with % */
            {
                va_end(args);
                return (-1);
            }

            if (format[i] == 'c')
            {
                c = (char)va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    count += write(1, s, 1);
                    s++;
                }
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                /* For unsupported specifiers: print literally */
                count += write(1, "%", 1);
                count += write(1, &format[i], 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }

        i++;
    }

    va_end(args);
    return (count);
}

