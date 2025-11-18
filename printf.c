#include "main.h"
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
int _printf(const char *format, ...);
int flush_buffer(char *buffer, int *buff_index);
int buffer_char(char c, char *buffer, int *buff_index);
int buffer_string(char *s, char *buffer, int *buff_index);
int buffer_pointer(void *ptr, char *buffer, int *buff_index);

/* Flush buffer to stdout */
int flush_buffer(char *buffer, int *buff_index)
{
    int written = write(1, buffer, *buff_index);
    *buff_index = 0;
    return written;
}

/* Add char to buffer */
int buffer_char(char c, char *buffer, int *buff_index)
{
    int count = 0;
    buffer[*buff_index] = c;
    (*buff_index)++;
    if (*buff_index == BUFFER_SIZE)
        count += flush_buffer(buffer, buff_index);
    return count;
}

/* Add string to buffer */
int buffer_string(char *s, char *buffer, int *buff_index)
{
    int count = 0;
    if (!s)
        s = "(null)";
    while (*s)
        count += buffer_char(*s++, buffer, buff_index);
    return count;
}

/* Add pointer address to buffer */
int buffer_pointer(void *ptr, char *buffer, int *buff_index)
{
    int count = 0;
    unsigned long addr;
    char hex[16];
    int i;

    if (!ptr)
        return buffer_string("(nil)", buffer, buff_index);

    addr = (unsigned long)ptr;
    buffer_char('0', buffer, buff_index);
    buffer_char('x', buffer, buff_index);

    i = 0;
    while (addr > 0)
    {
        hex[i++] = "0123456789abcdef"[addr % 16];
        addr /= 16;
    }
    if (i == 0)
        hex[i++] = '0';
    while (--i >= 0)
        count += buffer_char(hex[i], buffer, buff_index);

    return count;
}

/* _printf implementation */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0, buff_index = 0;
    char buffer[BUFFER_SIZE];

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                count += buffer_string(va_arg(args, char *), buffer, &buff_index);
            else if (format[i] == 'c')
                count += buffer_char(va_arg(args, int), buffer, &buff_index);
            else if (format[i] == 'p')
                count += buffer_pointer(va_arg(args, void *), buffer, &buff_index);
            /* Add other specifiers here (d, i, b, S, etc.) */
            else
                count += buffer_char(format[i], buffer, &buff_index);
        }
        else
            count += buffer_char(format[i], buffer, &buff_index);
        i++;
    }

    count += flush_buffer(buffer, &buff_index);
    va_end(args);
    return count;
}

