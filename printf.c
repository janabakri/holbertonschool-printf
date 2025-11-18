#include "main.h"
#include <string.h>

/* Flush buffer to stdout */
int flush_buffer(char *buffer, int *buff_index)
{
    int written = write(1, buffer, *buff_index);
    *buff_index = 0;
    return written;
}

/* Add a character to buffer */
int buffer_char(char c, char *buffer, int *buff_index)
{
    int count = 0;
    buffer[*buff_index] = c;
    (*buff_index)++;
    if (*buff_index == BUFFER_SIZE)
        count += flush_buffer(buffer, buff_index);
    return count;
}

/* Add a string to buffer */
int buffer_string(char *s, char *buffer, int *buff_index)
{
    int count = 0;
    if (!s)
        s = "(null)";
    while (*s)
        count += buffer_char(*s++, buffer, buff_index);
    return count;
}

/* Print number in given base to buffer */
int buffer_number(unsigned int n, int base, char *digits, char *buffer, int *buff_index)
{
    char temp[32];
    int i = 0, count = 0;

    if (n == 0)
        return buffer_char('0', buffer, buff_index);

    while (n)
    {
        temp[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        count += buffer_char(temp[i], buffer, buff_index);

    return count;
}

/* Print binary */
int buffer_binary(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 2, "01", buffer, buff_index);
}

/* Print unsigned decimal */
int buffer_unsigned(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 10, "0123456789", buffer, buff_index);
}

/* Print octal */
int buffer_octal(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 8, "01234567", buffer, buff_index);
}

/* Print lowercase hex */
int buffer_hex(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789abcdef", buffer, buff_index);
}

/* Print uppercase hex */
int buffer_HEX(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789ABCDEF", buffer, buff_index);
}

/* Main _printf with buffer */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0, buff_index = 0;
    char buffer[BUFFER_SIZE];
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
                    count += buffer_char(c, buffer, &buff_index);
                    break;

                case 's':
                    s = va_arg(args, char *);
                    count += buffer_string(s, buffer, &buff_index);
                    break;

                case '%':
                    count += buffer_char('%', buffer, &buff_index);
                    break;

                case 'b':
                    n = va_arg(args, unsigned int);
                    count += buffer_binary(n, buffer, &buff_index);
                    break;

                case 'u':
                    n = va_arg(args, unsigned int);
                    count += buffer_unsigned(n, buffer, &buff_index);
                    break;

                case 'o':
                    n = va_arg(args, unsigned int);
                    count += buffer_octal(n, buffer, &buff_index);
                    break;

                case 'x':
                    n = va_arg(args, unsigned int);
                    count += buffer_hex(n, buffer, &buff_index);
                    break;

                case 'X':
                    n = va_arg(args, unsigned int);
                    count += buffer_HEX(n, buffer, &buff_index);
                    break;

                default:
                    count += buffer_char('%', buffer, &buff_index);
                    count += buffer_char(format[i], buffer, &buff_index);
            }
        }
        else
        {
            count += buffer_char(format[i], buffer, &buff_index);
        }
        i++;
#include "main.h"
#include <string.h>

/* Flush buffer to stdout */
int flush_buffer(char *buffer, int *buff_index)
{
    int written = write(1, buffer, *buff_index);
    *buff_index = 0;
    return written;
}

/* Add a character to buffer */
int buffer_char(char c, char *buffer, int *buff_index)
{
    int count = 0;
    buffer[*buff_index] = c;
    (*buff_index)++;
    if (*buff_index == BUFFER_SIZE)
        count += flush_buffer(buffer, buff_index);
    return count;
}

/* Add a string to buffer */
int buffer_string(char *s, char *buffer, int *buff_index)
{
    int count = 0;
    if (!s)
        s = "(null)";
    while (*s)
        count += buffer_char(*s++, buffer, buff_index);
    return count;
}

/* Print number in given base to buffer */
int buffer_number(unsigned int n, int base, char *digits, char *buffer, int *buff_index)
{
    char temp[32];
    int i = 0, count = 0;

    if (n == 0)
        return buffer_char('0', buffer, buff_index);

    while (n)
    {
        temp[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        count += buffer_char(temp[i], buffer, buff_index);

    return count;
}

/* Print binary */
int buffer_binary(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 2, "01", buffer, buff_index);
}

/* Print unsigned decimal */
int buffer_unsigned(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 10, "0123456789", buffer, buff_index);
}

/* Print octal */
int buffer_octal(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 8, "01234567", buffer, buff_index);
}

/* Print lowercase hex */
int buffer_hex(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789abcdef", buffer, buff_index);
}

/* Print uppercase hex */
int buffer_HEX(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789ABCDEF", buffer, buff_index);
}

/* Main _printf with buffer */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0, buff_index = 0;
    char buffer[BUFFER_SIZE];
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
                    count += buffer_char(c, buffer, &buff_index);
                    break;

                case 's':
                    s = va_arg(args, char *);
                    count += buffer_string(s, buffer, &buff_index);
                    break;

                case '%':
                    count += buffer_char('%', buffer, &buff_index);
                    break;

                case 'b':
                    n = va_arg(args, unsigned int);
                    count += buffer_binary(n, buffer, &buff_index);
                    break;

                case 'u':
                    n = va_arg(args, unsigned int);
                    count += buffer_unsigned(n, buffer, &buff_index);
                    break;

                case 'o':
                    n = va_arg(args, unsigned int);
                    count += buffer_octal(n, buffer, &buff_index);
                    break;

                case 'x':
                    n = va_arg(args, unsigned int);
                    count += buffer_hex(n, buffer, &buff_index);
                    break;

                case 'X':
                    n = va_arg(args, unsigned int);
                    count += buffer_HEX(n, buffer, &buff_index);
                    break;

                default:
                    count += buffer_char('%', buffer, &buff_index);
                    count += buffer_char(format[i], buffer, &buff_index);
            }
        }
        else
        {
            count += buffer_char(format[i], buffer, &buff_index);
        }
        i++;

