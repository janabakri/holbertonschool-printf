#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int buff_index = 0, count = 0, i = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = (char)va_arg(args, int);
                buffer[buff_index++] = c;
            }
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    buffer[buff_index++] = *s++;
                    if (buff_index == BUFFER_SIZE)
                    {
                        write(1, buffer, buff_index);
                        count += buff_index;
                        buff_index = 0;
                    }
                }
            }
            else if (format[i] == '%')
                buffer[buff_index++] = '%';
            else
            {
                buffer[buff_index++] = '%';
                buffer[buff_index++] = format[i];
            }
        }
        else
        {
            buffer[buff_index++] = format[i];
        }

        if (buff_index == BUFFER_SIZE)
        {
            write(1, buffer, buff_index);
            count += buff_index;
            buff_index = 0;
        }
        i++;
    }

    if (buff_index > 0)
    {
        write(1, buffer, buff_index);
        count += buff_index;
    }

    va_end(args);
    return (count);
}

