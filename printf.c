unsigned short num = (unsigned short)va_arg(args, unsigned int);
                return print_number_base(num, 16, 0);
            }
        case 'X':
            {
                unsigned short num = (unsigned short)va_arg(args, unsigned int);
                return print_number_base(num, 16, 1);
            }
        default:
            /* If no valid specifier after 'h', print both characters */
            return _putchar('h') + _putchar(**format);
    }
}

/**
 * print_number_base - Print number in specified base
 * @n: Number to print
 * @base: Base to use (2-16)
 * @uppercase: Use uppercase for hex (1) or lowercase (0)
 * Return: Number of characters printed
 */
int print_number_base(unsigned long n, unsigned int base, int uppercase)
{
    int count = 0;
    char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    
    if (base < 2 || base > 16)
        return 0;

    if (n / base)
        count += print_number_base(n / base, base, uppercase);
    
    count += _putchar(digits[n % base]);
    return count;
}

/**
 * print_number - Print signed integer
 * @args: Variable arguments list
 * Return: Number of characters printed
 */
int print_number(va_list args)
{
    int num = va_arg(args, int);
    
    if (num < 0)
    {
        _putchar('-');
        return print_number_base(-num, 10, 0) + 1;
    }
    return print_number_base(num, 10, 0);
}

/**
 * print_unsigned - Print unsigned integer
 * @args: Variable arguments list
 * @base: Base to use
 * @uppercase: Use uppercase for hex
 * Return: Number of characters printed
 */
int print_unsigned(va_list args, int base, int uppercase)
{
    unsigned int num = va_arg(args, unsigned int);
    return print_number_base(num, base, uppercase);
}

/**
 * print_octal - Print octal number
 * @args: Variable arguments list
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
    return print_unsigned(args, 8, 0);
}

/**
 * print_hex - Print hexadecimal number
 * @args: Variable arguments list
 * @uppercase: Use uppercase letters
 * Return: Number of characters printed
 */
int print_hex(va_list args, int uppercase)
{
    return print_unsigned(args, 16, uppercase);
}

/* Basic conversion handlers */
int print_char(va_list args)
{
    return _putchar(va_arg(args, int));
}

int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;
    
    if (!str)
        str = "(null)";
    
    while (*str)
        count += _putchar(*str++);
    
    return count;
}

int print_percent(va_list args)
{
    (void)args;
    return _putchar('%');
}

/**
 * _putchar - Write a character to stdout
 * @c: Character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

