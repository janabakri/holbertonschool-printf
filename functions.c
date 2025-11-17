#include "main.h"

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
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: string to print
 * 
 * Return: number of characters printed
 */
int print_string(char *str)
{
    int i = 0;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return (i);
}

/**
 * print_char - prints a character
 * @c: character to print
 * 
 * Return: number of characters printed (always 1)
 */
int print_char(char c)
{
    return (_putchar(c));
}
