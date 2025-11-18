#include "main.h"

/**
 * _printf - Custom printf implementation
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (!format)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            count += handle_conversion(&format, args);
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}

/**
 * handle_conversion - Handle conversion specifiers
 * @format: Pointer to format string
 * @args: Variable arguments list
 * Return: Number of characters printed
 */
int handle_conversion(const char **format, va_list args)
{
    if (**format == 'l')
        return handle_long(format, args);
    
    if (**format == 'h')
        return handle_short(format, args);

    switch (**format)
    {
        case 'c':
            return print_char(args);
        case 's':
            return print_string(args);
        case '%':
            return print_percent(args);
        case 'd':
        case 'i':
            return print_number(args);
        case 'u':
            return print_unsigned(args, 10, 0);
        case 'o':
            return print_octal(args);
        case 'x':
            return print_hex(args, 0);
        case 'X':
            return print_hex(args, 1);
        default:
            return _putchar('%') + _putchar(**format);
    }
}

/**
 * handle_long - Handle 'l' length modifier
 * @format: Pointer to format string
 * @args: Variable arguments list
 * Return: Number of characters printed
 */
int handle_long(const char **format, va_list args)
{
    (*format)++; /* Skip the 'l' */
    
    if (**format == '\0')
        return _putchar('l');
    
    switch (**format)
    {
        case 'd':
        case 'i':
            {
                long num = va_arg(args, long);
                if (num < 0)
                {
                    _putchar('-');
                    return print_number_base((unsigned long)(-num), 10, 0) + 1;
                }
                return print_number_base((unsigned long)num, 10, 0);
            }
        case 'u':
            {
                unsigned long num = va_arg(args, unsigned long);
                return print_number_base(num, 10, 0);
            }
        case 'o':
            {
                unsigned long num = va_arg(args, unsigned long);
                return print_number_base(num, 8, 0);
            }
        case 'x':
            {
                unsigned long num = va_arg(args, unsigned long);
                return print_number_base(num, 16, 0);
            }
        case 'X':
            {
                unsigned long num = va_arg(args, unsigned long);
                return print_number_base(num, 16, 1);
            }
        default:
            return _putchar('l') + _putchar(**format);
    }
}

/**
 * handle_short - Handle 'h' length modifier
 * @format: Pointer to format string
 * @args: Variable arguments list
 * Return: Number of characters printed
 */
int handle_short(const char **format, va_list args)
{
    (*format)++; /* Skip the 'h' */
    
    if (**format == '\0')
        return _putchar('h');
    
    switch (**format)
    {
        case 'd':
        case 'i':
            {
                int num = va_arg(args, int);
                short s_num = (short)num;
                if (s_num < 0)
                {
                    _putchar('-');
                    return print_number_base((unsigned short)(-s_num), 10, 0) + 1;
                }
                return print_number_base((unsigned short)s_num, 10, 0);
            }
        case 'u':
            {
                unsigned int num = va_arg(args, unsigned int);
                unsigned short us_num = (unsigned short)num;
                return print_number_base(us_num, 10, 0);
            }
        case 'o':
            {

