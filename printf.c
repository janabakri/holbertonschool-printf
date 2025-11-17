#include <stdarg.h>
#include <unistd.h>

/* Helper function to print a single character */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/* _printf: simplified printf supporting %c, %s, %% */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
                break;

            switch (format[i])
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                    {
                        count += _putchar(*str);
                        str++;
                    }
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    /* Unknown specifier: print % and the character */
                    count += _putchar('%');
                    count += _putchar(format[i]);
                    break;
            }
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

/* Example main to test all cases */
int main(void)
{
    char *str = "This is a big test string for _printf function to check large output handling.\n";

    _printf("Simple sentence:\nLet's print a simple sentence.\n");
    _printf("%c\n", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let's check the cast: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c",
            'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("Percent signs: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    _printf("css%ccs%scscscs\n", 'T', "Test");
    _printf("%s", str);
    _printf("man gcc:\n%s", str);
    _printf("%s\n", NULL);
    _printf("%c\n", '\0');
    _printf("Unknown specifiers: %!\n");
    _printf("Another unknown: %K\n");

    return 0;
}

