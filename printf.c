#include "main.h"

/**
 * _putchar - writes a single character to stdout
 * @c: character to print
 *
 * Return: 1 on success
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;
    char c;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                return (-1); /* % at end of string */

            if (format[i] == 'c') /* Character */
            {
                c = (char)va_arg(args, int);
                count += _putchar(c);
            }
            else if (format[i] == 's') /* String */
            {
                str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                    count += _putchar(*str++);
            }
            else if (format[i] == '%') /* Percent sign */
            {
                count += _putchar('%');
            }
            else /* Unknown specifier */
            {
                count += _putchar('%');
                count += _putchar(format[i]);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}

