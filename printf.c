#include <stdarg.h>
#include <unistd.h>

/* ---- Helpers ---- */

int write_char(char c)
{
    return (write(1, &c, 1));
}

int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write_char(c));
}

int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int i = 0;

    if (!s)
        s = "(null)";

    while (s[i])
    {
        write_char(s[i]);
        i++;
    }
    return (i);
}

int print_percent(void)
{
    return (write(1, "%", 1));
}

/* ---- Core format processing ---- */

int handle_specifier(const char *format, int *i, va_list args)
{
    int count = 0;

    (*i)++;
    if (format[*i] == '\0')
        return (-1);

    if (format[*i] == 'c')
        count = print_char(args);
    else if (format[*i] == 's')
        count = print_string(args);
    else if (format[*i] == '%')
        count = print_percent();
    else
    {
        write(1, "%", 1);
        write(1, &format[*i], 1);
        count = 2;
    }

    return (count);
}

int process_format(const char *format, va_list args)
{
    int count = 0, i = 0, add;

    while (format[i])
    {
        if (format[i] == '%')
        {
            add = handle_specifier(format, &i, args);
            if (add == -1)
                return (-1);
            count += add;
        }
        else
            count += write_char(format[i]);
        i++;
    }

    return (count);
}

/* ---- MAIN _printf FUNCTION ---- */

int _printf(const char *format, ...)
{
    va_list args;
    int printed;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    printed = process_format(format, args);
    va_end(args);

    return (printed);
}

/* ---- Example main to test ---- */
int main(void)
{
    _printf("Hello %corld%s %%\n", 'W', "!");
    _printf("%s\n", NULL);
    _printf("Just a percent sign: %%\n");
    return (0);
}

