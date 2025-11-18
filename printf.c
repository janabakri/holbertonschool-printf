#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Custom printf supporting l and h modifiers
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p = format;

    va_start(args, format);

    while (*p)
    {
        if (*p == '%')
        {
            p++;
            int is_long = 0;
            int is_short = 0;

            /* Check for length modifiers */
            if (*p == 'l')
            {
                is_long = 1;
                p++;
            }
            else if (*p == 'h')
            {
                is_short = 1;
                p++;
            }

            switch (*p)
            {
                case 'd':
                case 'i':
                    if (is_long)
                        count += printf("%ld", va_arg(args, long));
                    else if (is_short)
                        count += printf("%hd", (short)va_arg(args, int));
                    else
                        count += printf("%d", va_arg(args, int));
                    break;
                case 'u':
                    if (is_long)
                        count += printf("%lu", va_arg(args, unsigned long));
                    else if (is_short)
                        count += printf("%hu", (unsigned short)va_arg(args, unsigned int));
                    else
                        count += printf("%u", va_arg(args, unsigned int));
                    break;
                case 'o':
                    if (is_long)
                        count += printf("%lo", va_arg(args, unsigned long));
                    else if (is_short)
                        count += printf("%ho", (unsigned short)va_arg(args, unsigned int));
                    else
                        count += printf("%o", va_arg(args, unsigned int));
                    break;
                case 'x':
                    if (is_long)
                        count += printf("%lx", va_arg(args, unsigned long));
                    else if (is_short)
                        count += printf("%hx", (unsigned short)va_arg(args, unsigned int));
                    else
                        count += printf("%x", va_arg(args, unsigned int));
                    break;
                case 'X':
                    if (is_long)
                        count += printf("%lX", va_arg(args, unsigned long));
                    else if (is_short)
                        count += printf("%hX", (unsigned short)va_arg(args, unsigned int));
                    else
                        count += printf("%X", va_arg(args, unsigned int));
                    break;
                default:
                    putchar(*p);
                    count++;
                    break;
            }
        }
        else
        {
            putchar(*p);
            count++;
        }
        p++;
    }

    va_end(args);
    return count;
}

