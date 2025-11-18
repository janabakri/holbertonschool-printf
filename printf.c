#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/* حجم البافر */
#define BUF_SIZE 1024

/* دالة لافراغ البافر */
int flush_buffer(char *buffer, int *index)
{
    if (*index > 0)
    {
        write(1, buffer, *index);
        *index = 0;
    }
    return 0;
}

/* دالة لإضافة حرف للبافر */
int buffer_char(char c, char *buffer, int *index)
{
    buffer[(*index)++] = c;
    if (*index == BUF_SIZE)
        flush_buffer(buffer, index);
    return 1;
}

/* دالة لإضافة سلسلة للبافر */
int buffer_string(char *s, char *buffer, int *index)
{
    int len = 0;
    while (*s)
    {
        buffer_char(*s++, buffer, index);
        len++;
    }
    return len;
}

/* دالة لتحويل رقم إلى سلسلة في base معين */
int buffer_number(unsigned int n, int base, char *digits, char *buffer, int *index)
{
    char tmp[32];
    int i = 0, len = 0;

    if (n == 0)
        return buffer_char('0', buffer, index);

    while (n > 0)
    {
        tmp[i++] = digits[n % base];
        n /= base;
    }

    while (i--)
        len += buffer_char(tmp[i], buffer, index);

    return len;
}

/* دالة خاصة للـ signed int */
int buffer_signed(int n, char *buffer, int *index)
{
    unsigned int num;
    int len = 0;

    if (n < 0)
    {
        len += buffer_char('-', buffer, index);
        num = -n;
    }
    else
        num = n;

    len += buffer_number(num, 10, "0123456789", buffer, index);
    return len;
}

/* الدالة الرئيسية _printf */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUF_SIZE];
    int buff_index = 0, len = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            buffer_char(*format, buffer, &buff_index);
            len++;
            format++;
            continue;
        }

        format++; /* تخطي % */

        switch (*format)
        {
            case 'c':
                len += buffer_char(va_arg(args, int), buffer, &buff_index);
                break;
            case 's':
                len += buffer_string(va_arg(args, char *), buffer, &buff_index);
                break;
            case 'd':
            case 'i':
                len += buffer_signed(va_arg(args, int), buffer, &buff_index);
                break;
            case 'u':
                len += buffer_number(va_arg(args, unsigned int), 10, "0123456789", buffer, &buff_index);
                break;
            case 'o':
                len += buffer_number(va_arg(args, unsigned int), 8, "01234567", buffer, &buff_index);
                break;
            case 'x':
                len += buffer_number(va_arg(args, unsigned int), 16, "0123456789abcdef", buffer, &buff_index);
                break;
            case 'X':
                len += buffer_number(va_arg(args, unsigned int), 16, "0123456789ABCDEF", buffer, &buff_index);
                break;
            case 'b':
                len += buffer_number(va_arg(args, unsigned int), 2, "01", buffer, &buff_index);
                break;
            case '%':
                len += buffer_char('%', buffer, &buff_index);
                break;
            default:
                len += buffer_char('%', buffer, &buff_index);
                len += buffer_char(*format, buffer, &buff_index);
                break;
        }
        format++;
    }

    flush_buffer(buffer, &buff_index);
    va_end(args);
    return len;
}

