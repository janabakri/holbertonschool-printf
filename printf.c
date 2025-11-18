int handle_long(const char **format, va_list args)
{
    long lnum;
    unsigned long unum;

    (*format)++; /* Skip 'l' */

    if (**format == '\0')
        return _putchar('l');

    switch (**format)
    {
        case 'd':
        case 'i':
            lnum = va_arg(args, long);
            if (lnum < 0)
            {
                _putchar('-');
                return print_number_base((unsigned long)(-lnum), 10, 0) + 1;
            }
            return print_number_base((unsigned long)lnum, 10, 0);
        case 'u':
            unum = va_arg(args, unsigned long);
            return print_number_base(unum, 10, 0);
        case 'o':
            unum = va_arg(args, unsigned long);
            return print_number_base(unum, 8, 0);
        case 'x':
            unum = va_arg(args, unsigned long);
            return print_number_base(unum, 16, 0);
        case 'X':
            unum = va_arg(args, unsigned long);
            return print_number_base(unum, 16, 1);
        default:
            return _putchar('l') + _putchar(**format);
    }
}

int handle_short(const char **format, va_list args)
{
    int inum;
    short snum;
    unsigned int uinum;
    unsigned short usnum;

    (*format)++; /* Skip 'h' */

    if (**format == '\0')
        return _putchar('h');

    switch (**format)
    {
        case 'd':
        case 'i':
            inum = va_arg(args, int);
            snum = (short)inum;
            if (snum < 0)
            {
                _putchar('-');
                return print_number_base((unsigned short)(-snum), 10, 0) + 1;
            }
            return print_number_base((unsigned short)snum, 10, 0);
        case 'u':
            uinum = va_arg(args, unsigned int);
            usnum = (unsigned short)uinum;
            return print_number_base(usnum, 10, 0);
        case 'o':
            uinum = va_arg(args, unsigned int);
            usnum = (unsigned short)uinum;
            return print_number_base(usnum, 8, 0);
        case 'x':
            uinum = va_arg(args, unsigned int);
            usnum = (unsigned short)uinum;
            return print_number_base(usnum, 16, 0);
        case 'X':
            uinum = va_arg(args, unsigned int);
            usnum = (unsigned short)uinum;
            return print_number_base(usnum, 16, 1);
        default:
            return _putchar('h') + _putchar(**format);
    }
}

