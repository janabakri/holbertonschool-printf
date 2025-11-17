#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Core function */
int _printf(const char *format);

/* Format processing */
int process_format(const char *format, va_list args);
int handle_specifier(const char *format, int *i, va_list args);

/* Print helpers */
int write_char(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);

#endif /* MAIN_H */

