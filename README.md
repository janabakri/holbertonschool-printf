The _printf project is a custom implementation of the standard C printf function. It allows formatted output to the standard output (stdout) and supports both basic and advanced format specifiers.

This project demonstrates the use of variadic functions, string and number handling, buffer optimization, and custom formatting.
Edge Cases

NULL format  return -1

Unknown specifier  print % and the character

Large strings  handled correctly

Mixing multiple specifiers  handled correctly

Non-printable characters in strings %S conversion
Man Page

man_3_printf explains:

Function prototype

Supported specifiers

Flags, width, precision, length modifiers

Example usage with expected output
Conclusion

The _printf project demonstrates:

Variadic functions in C

Safe handling of strings and characters

Number conversions in multiple bases

Custom specifiers (%b, %S, %r, %R)

Buffer optimization for efficient output

Proper handling of flags, width, and precision

This project serves as a foundation for implementing a full-featured printf function and enhances understanding of low-level output management in C.
