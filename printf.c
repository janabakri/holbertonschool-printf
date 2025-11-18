#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Custom printf handling length modifiers l and h
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    const char *p;
    int count = 0;

    va_start(args, format);

    p = format;
    while (*p)
    {
        int is_long;
        int is_short;

        /* Declare all variables at the top of the block */
        char buffer[1024]; /* example buffer */
        int i;
        
        is_long = 0;
        is_short = 0;

        if (*p == '%')
        {
            p++;

            /* Handle length modifiers */
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

            /* Handle conversion specifiers */
            if (*p == 'd' || *p == 'i')
            {
                long lnum;
                int inum;

                if (is_long)
                {
                    lnum = va_arg(args, long);
                    count += printf("%ld", lnum);
                }
                else if (is_short)
                {
                    inum = (short)va_arg(args, int); /* promoted to int */
                    count += printf("%d", inum);
                }
                else
                {
                    inum = va_arg(args, int);
                    count += printf("%d", inum);
                }
            }
            else if (*p == 'u' || *p == 'o' || *p == 'x' || *p == 'X')
            {
                unsigned long lnumu;
                unsigned int inumu;

                if (is_long)
                    lnumu = va_arg(args, unsigned long);
                else
                    inumu = va_arg(args, unsigned int);

                if (*p == 'u')
                    count += printf(is_long ? "%lu" : "%u", is_long ? lnumu : inumu);
                else if (*p == 'o')
                    count += printf(is_long ? "%lo" : "%o", is_long ? lnumu : inumu);
                else if (*p == 'x')
                    count += printf(is_long ? "%lx" : "%x", is_long ? lnumu : inumu);
                else if (*p == 'X')
                    count += printf(is_long ? "%lX" : "%X", is_long ? lnumu : inumu);
            }
            /* Add other specifiers as needed */
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

