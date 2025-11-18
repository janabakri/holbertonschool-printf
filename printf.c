#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @n: number
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
    char buffer[32];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n > 0)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/**
 * _printf - Custom printf including %b
 * @format: Format string
 * Return: Number of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c, *s;
    unsigned int n;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            if (!format[i])
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
                    count += write(1, s++, 1);
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else if (format[i] == 'b')
            {
                n = va_arg(args, unsigned int);
                count += print_binary(n);
            }
            else
            {
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
    return count;
}

