                                                                                                                                                                                                                                                                                                                                                                                                                                    #include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/* Helper to write a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* Helper to print number with flags */
int print_number(int n, int plus_flag, int space_flag)
{
    int count = 0;
    unsigned int num;

    if (n < 0)
    {
        count += _putchar('-');
        num = -n;
    }
    else
    {
        if (plus_flag)
            count += _putchar('+');
        else if (space_flag)
            count += _putchar(' ');
        num = n;
    }

    /* Print the number */
    if (num / 10)
        count += print_number(num / 10, 0, 0);
    count += _putchar((num % 10) + '0');

    return count;
}

/* Helper to print unsigned in base with # flag */
int print_unsigned(unsigned int n, int base, int hash_flag, int uppercase)
{
    int count = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (hash_flag && n != 0)
    {
        if (base == 8)
            count += _putchar('0');
        else if (base == 16)
        {
            count += _putchar('0');
            count += _putchar(uppercase ? 'X' : 'x');
        }
    }

    if (n / base)
        count += print_unsigned(n / base, base, 0, uppercase);

    count += _putchar(digits[n % base]);

    return count;
}

/* Simplified _printf handling +, space, # flags */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            int plus_flag = 0, space_flag = 0, hash_flag = 0;
            i++;

            /* Parse flags */
            while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
            {
                if (format[i] == '+') plus_flag = 1;
                else if (format[i] == ' ') space_flag = 1;
                else if (format[i] == '#') hash_flag = 1;
                i++;
            }

            /* Handle specifiers */
            if (format[i] == 'd' || format[i] == 'i')
                count += print_number(va_arg(args, int), plus_flag, space_flag);
            else if (format[i] == 'o')
                count += print_unsigned(va_arg(args, unsigned int), 8, hash_flag, 0);
            else if (format[i] == 'x')
                count += print_unsigned(va_arg(args, unsigned int), 16, hash_flag, 0);
            else if (format[i] == 'X')
                count += print_unsigned(va_arg(args, unsigned int), 16, hash_flag, 1);
            else if (format[i] == '%')
                count += _putchar('%');
            else
                count += _putchar(format[i]);
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);
    return count;
}

/* Example main */
int main(void)
{
    _printf("%+d\n", 42);        // +42
    _printf("% d\n", 42);        //  42
    _printf("%#o\n", 10);        // 012
    _printf("%#x\n", 255);       // 0xff
    _printf("%#X\n", 255);       // 0XFF
    return 0;
}

