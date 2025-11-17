#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to print
 * Return: number of characters printed
 */
int print_string(char *s)
{
    int count = 0;

    if (!s)
        s = "(null)";

    while (*s)
    {
        count += _putchar(*s);
        s++;
    }
    return (count);
}

/**
 * print_number - prints an integer
 * @n: number to print
 * Return: number of characters printed
 */
int print_number(long int n)
{
    unsigned long int num;
    int count = 0;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
        num = n;

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar((num % 10) + '0');
    return (count);
}

/**
 * _printf - produces output according to a format
 * @format: format string containing format specifiers
 * Return: number of characters printed (excluding null byte)
 */
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
            if (!*format)
                return (-1);

            switch (*format)
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    count += print_string(va_arg(args, char *));
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    count += print_number(va_arg(args, int));
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
    return (count);
}


