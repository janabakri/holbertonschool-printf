#include "main.h"

/* Print unsigned int */
int print_unsigned(unsigned int n)
{
    char buffer[20];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* Print octal */
int print_octal(unsigned int n)
{
    char buffer[20];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n)
    {
        buffer[i++] = (n % 8) + '0';
        n /= 8;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* Print lowercase hex */
int print_hex(unsigned int n)
{
    char buffer[20];
    char *hex = "0123456789abcdef";
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n)
    {
        buffer[i++] = hex[n % 16];
        n /= 16;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* Print uppercase hex */
int print_HEX(unsigned int n)
{
    char buffer[20];
    char *hex = "0123456789ABCDEF";
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n)
    {
        buffer[i++] = hex[n % 16];
        n /= 16;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* Print binary */
int print_binary(unsigned int n)
{
    char buffer[32];
    int i = 0, count = 0;

    if (n == 0)
        return write(1, "0", 1);

    while (n)
    {
        buffer[i++] = (n % 2) + '0';
        n /= 2;
    }

    while (i--)
        count += write(1, &buffer[i], 1);

    return count;
}

/* Main _printf */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c, *s;
    unsigned int n;

    if (!format)
        return -1;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;

            if (!format[i])
                return -1;

            switch (format[i])
            {
                case 'c':
                    c = va_arg(args, int);
                    count += write(1, &c, 1);
                    break;

                case 's':
                    s = va_arg(args, char *);
                    if (!s)
                        s = "(null)";
                    while (*s)
                        count += write(1, s++, 1);
                    break;

                case '%':
                    count += write(1, "%", 1);
                    break;

                case 'b':
                    n = va_arg(args, unsigned int);
                    count += print_binary(n);
                    break;

                case 'u':
                    n = va_arg(args, unsigned int);
                    count += print_unsigned(n);
                    break;

                case 'o':
                    n = va_arg(args, unsigned int);
                    count += print_octal(n);
                    break;

                case 'x':
                    n = va_arg(args, unsigned int);
                    count += print_hex(n);
                    break;

                case 'X':
                    n = va_arg(args, unsigned int);
                    count += print_HEX(n);
                    break;

                default:
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

