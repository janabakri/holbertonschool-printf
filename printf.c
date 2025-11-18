#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_index = 0, count = 0;
    int i = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;

            if (format[i] == 'c')
                buffer[buff_index++] = va_arg(args, int);
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                    buffer[buff_index++] = *s++;
            }
            else if (format[i] == '%')
                buffer[buff_index++] = '%';
            else if (format[i] == 'd' || format[i] == 'i')
            {
                int n = va_arg(args, int);
                char num[12];
                int j = 0, neg = 0;

                if (n < 0)
                {
                    neg = 1;
                    n = -n;
                }
                if (n == 0)
                    num[j++] = '0';
                while (n > 0)
                {
                    num[j++] = (n % 10) + '0';
                    n /= 10;
                }
                if (neg)
                    num[j++] = '-';
                while (j--)
                    buffer[buff_index++] = num[j];
            }
            else if (format[i] == 'b')
            {
                unsigned int n = va_arg(args, unsigned int);
                char bin[32];
                int j = 0;

                if (n == 0)
                    bin[j++] = '0';
                while (n > 0)
                {
                    bin[j++] = (n % 2) + '0';
                    n /= 2;
                }
                while (j--)
                    buffer[buff_index++] = bin[j];
            }
            else if (format[i] == 'u' || format[i] == 'o' || format[i] == 'x' || format[i] == 'X')
            {
                unsigned int n = va_arg(args, unsigned int);
                char num[32];
                int j = 0;
                char *digits = (format[i] == 'X') ? "0123456789ABCDEF" :
                               (format[i] == 'x') ? "0123456789abcdef" :
                               (format[i] == 'o') ? "01234567" : "0123456789";
                int base = (format[i] == 'o') ? 8 : (format[i] == 'x' || format[i] == 'X') ? 16 : 10;

                if (n == 0)
                    num[j++] = '0';
                while (n > 0)
                {
                    num[j++] = digits[n % base];
                    n /= base;
                }
                while (j--)
                    buffer[buff_index++] = num[j];
            }
            else
                buffer[buff_index++] = format[i];

            if (buff_index >= BUFFER_SIZE - 1)
            {
                write(1, buffer, buff_index);
                count += buff_index;
                buff_index = 0;
            }
        }
        else
        {
            buffer[buff_index++] = format[i];
            if (buff_index >= BUFFER_SIZE - 1)
            {
                write(1, buffer, buff_index);
                count += buff_index;
                buff_index = 0;
            }
        }
        i++;
    }

    if (buff_index > 0)
    {
        write(1, buffer, buff_index);
        count += buff_index;
    }

    va_end(args);
    return count;
}

