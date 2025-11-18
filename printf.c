#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* Flush buffer to stdout */
int flush_buffer(char *buffer, int *buff_index)
{
    int written = 0;

    if (*buff_index > 0)
    {
        written = write(1, buffer, *buff_index);
        *buff_index = 0;
    }
    return written;
}

/* Add a single character to buffer */
int buffer_char(char c, char *buffer, int *buff_index)
{
    int count = 0;

    buffer[(*buff_index)++] = c;
    if (*buff_index == 1024)
        count += flush_buffer(buffer, buff_index);
    return count + 1;
}

/* Add a string to buffer */
int buffer_string(char *s, char *buffer, int *buff_index)
{
    int count = 0;
    int i;

    if (!s)
        s = "(null)";
    for (i = 0; s[i]; i++)
        count += buffer_char(s[i], buffer, buff_index);
    return count;
}

/* Add number to buffer in given base */
int buffer_number(long n, int base, char *digits, char *buffer, int *buff_index)
{
    int count = 0;
    unsigned long num;
    char rev[65];
    int i = 0, j;

    if (base == 10 && n < 0)
    {
        count += buffer_char('-', buffer, buff_index);
        num = (unsigned long)(-n);
    }
    else
        num = (unsigned long)n;

    if (num == 0)
        return count + buffer_char('0', buffer, buff_index);

    while (num > 0)
    {
        rev[i++] = digits[num % base];
        num /= base;
    }

    for (j = i - 1; j >= 0; j--)
        count += buffer_char(rev[j], buffer, buff_index);

    return count;
}

/* Wrapper for binary */
int buffer_binary(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 2, "01", buffer, buff_index);
}

/* Wrapper for unsigned decimal */
int buffer_unsigned(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 10, "0123456789", buffer, buff_index);
}

/* Wrapper for octal */
int buffer_octal(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 8, "01234567", buffer, buff_index);
}

/* Wrapper for hex lowercase */
int buffer_hex(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789abcdef", buffer, buff_index);
}

/* Wrapper for hex uppercase */
int buffer_HEX(unsigned int n, char *buffer, int *buff_index)
{
    return buffer_number(n, 16, "0123456789ABCDEF", buffer, buff_index);
}

/* The main _printf function */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;
    char buffer[1024];
    int buff_index = 0;

    if (!format)
        return -1;

    va_start(args, format);

    for (i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;
            switch (format[i])
            {
                case 'c':
                    count += buffer_char(va_arg(args, int), buffer, &buff_index);
                    break;
                case 's':
                    count += buffer_string(va_arg(args, char *), buffer, &buff_index);
                    break;
                case '%':
                    count += buffer_char('%', buffer, &buff_index);
                    break;
                case 'd':
                case 'i':
                    count += buffer_number(va_arg(args, int), 10, "0123456789", buffer, &buff_index);
                    break;
                case 'u':
                    count += buffer_unsigned(va_arg(args, unsigned int), buffer, &buff_index);
                    break;
                case 'o':
                    count += buffer_octal(va_arg(args, unsigned int), buffer, &buff_index);
                    break;
                case 'x':
                    count += buffer_hex(va_arg(args, unsigned int), buffer, &buff_index);
                    break;
                case 'X':
                    count += buffer_HEX(va_arg(args, unsigned int), buffer, &buff_index);
                    break;
                case 'b':
                    count += buffer_binary(va_arg(args, unsigned int), buffer, &buff_index);
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
    }

    count += flush_buffer(buffer, &buff_index);
    va_end(args);
    return count;
}

