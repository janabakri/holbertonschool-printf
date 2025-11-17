#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 (number of characters printed)
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
        _putchar(*s++);
        count++;
    }
    return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
    unsigned int num;
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

