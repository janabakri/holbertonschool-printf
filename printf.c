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
				return (-1);

			switch (format[i])
			{
				case 'c':
					c = (char)va_arg(args, int);
					count += _putchar(c);
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					while (*str)
						count += _putchar(*str++);
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += print_number(args, 10, 0, 0);
					break;
				case 'u':
					count += print_number(args, 10, 1, 0);
					break;
				case 'o':
					count += print_number(args, 8, 1, 0);
					break;
				case 'x':
					count += print_number(args, 16, 1, 0);
					break;
				case 'X':
					count += print_number(args, 16, 1, 1);
					break;
				case 'b':
					count += print_binary(args);
					break;
				case 'S':
					count += print_S(args);
					break;
				case 'r':
					count += print_reverse(args);
					break;
				case 'R':
					count += print_rot13(args);
					break;
				default:
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
	return (count);
}

