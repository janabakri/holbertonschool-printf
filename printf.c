#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - prints according to a format
 * @format: format string
 *
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0, i = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                count += write(1, &c, 1);
            }
            else if (format[i] == 's')
            {
                char *s = va_arg(args, char *);
                int j = 0;
                if (!s)
                    s = "(null)";
                while (s[j])
                {
                    write(1, &s[j], 1);
                    j++;
                }
                count += j;
            }
            else if (format[i] == '%')
            {
                count += write(1, "%", 1);
            }
            else
            {
                count += write(1, "%", 1);
                count += write(1, &format[i], 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1);
        }
        i++;
    }

    va_end(args);
    return (count);
}

/* ---- Example main to test ---- */
#ifdef TEST_PRINTF
int main(void)
{
    _printf("Hello %corld%s %%\n", 'W', "!");
    _printf("%s\n", NULL);
    _printf("Just a percent sign: %%\n");
    return (0);
}
#endif

