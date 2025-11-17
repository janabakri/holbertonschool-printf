#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing format specifiers
 * 
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += handle_conversion(&format, args);
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}

/**
 * handle_conversion - handles conversion specifiers
 * @format: pointer to current position in format string
 * @args: variable arguments list
 * 
 * Return: number of characters printed
 */
int handle_conversion(const char **format, va_list args)
{
    switch (**format)
    {
        case 'd':
        case 'i':
            return (print_number(va_arg(args, int)));
        case '%':
            write(1, "%", 1);
            return (1);
        default:
            write(1, "%", 1);
            write(1, *format, 1);
            return (2);
    }
}

/**
 * print_number - prints an integer
 * @n: integer to print
 * 
 * Return: number of characters printed
 */
int print_number(int n)
{
    int count = 0;
    char buffer[12]; /* Enough for int min: -2147483648 */
    int i = 0;
    unsigned int num;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    /* Handle zero case */
    if (num == 0)
    {
        write(1, "0", 1);
        return (count + 1);
    }

    /* Convert number to string in reverse order */
    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    /* Print in correct order */
    while (i > 0)
    {
        write(1, &buffer[--i], 1);
        count++;
    }

    return (count);
}

