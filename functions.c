#include "main.h"

/**
 * print_char - prints a character
 * @args: arguments list
 * Return: number of characters printed
 */
int print_char(va_list args)
{
    char c = (char)va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @args: arguments list
 * Return: number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    return (count);
}

/**
 * print_percent - prints a percent sign
 * Return: number of characters printed
 */
int print_percent(void)
{
    return (write(1, "%", 1));
}

/**
 * print_int - prints an integer
 * @args: arguments list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    int count = 0;
    char buffer[12];
    int i = 0;
    unsigned int num;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        num = (n == -2147483648) ? 2147483648U : (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
        count++;
    }

    return (count);
}

/**
 * print_binary - converts unsigned int to binary
 * @args: arguments list
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;
    char buffer[32];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    while (n > 0)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
        count++;
    }

    return (count);
}

