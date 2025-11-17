#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string to stdout
 * @s: The string to print
 *
 * Return: The number of characters printed
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
 * print_number - prints an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

