# holbertonschool-printf

Custom implementation of a subset of the C standard library `printf` function for educational purposes.

This repository implements `_printf` and a set of supporting helpers. It is written to compile with `-std=gnu89` and follows the Holberton/low-level project constraints.

## Features implemented

Supported standard conversion specifiers:

- %c — character
- %s — string
- %% — literal percent sign
- %d, %i — signed decimal integers
- %u — unsigned decimal
- %o — unsigned octal
- %x, %X — unsigned hexadecimal (lower/upper)
- %p — pointer (prints as 0x...)

Supported flags and behaviors:

- Flags: +, space, #, 0, - (basic handling)
- Field width (numeric and \* form)
- Precision (numeric and \* form)
- Length modifiers: h, l for integer conversions
- Precision rules for integers/strings (including suppression when precision is 0 and value is 0)

Custom (extra) conversion specifiers implemented:

- %b — prints unsigned integer as binary
- %r — prints string in reverse
- %R — prints string with ROT13
- %S — prints string but non-printable characters as \xHH

## Notes / limitations

- This is a learning implementation and does not aim to be a drop-in replacement for the libc `printf`.
- Some subtle edge-cases of the standard `printf` (exact interaction ordering of flags, locale-dependent behavior, and platform-specific corner cases) may differ.
- The implementation keeps a single `_putchar` in `functions.c`. Make sure you do not compile another `_putchar.c` alongside it (duplicate symbol).

## Files of interest

- `printf.c` — the `_printf` entry point and format string parser
- `functions.c` — printing helpers (characters, strings, numbers, custom specifiers)
- `main.h` — shared prototypes and the `fmt_options` struct

## Quick manual tests

After compiling, you can run small checks from a `main` that calls `_printf`:

```c
_printf("Hello %c %s %d%%\n", 'A', "world", 42);
_printf("%8d\n", 42);            // width
_printf("%08d\n", 42);           // zero pad
_printf("%+d\n", 42);            // plus flag
_printf("%#x\n", 0x1a);          // alternate form for hex
_printf("%r\n", "hello");     // reversed string
_printf("%R\n", "Hello");     // ROT13
_printf("%S\n", "\x01\x02A"); // non-printable
_printf("%b\n", 10);             // binary
_printf("%p\n", (void*)ptr);    // pointer
```

## Testing suggestions

- Compare `_printf` against the standard `printf` for many format strings to find mismatches. Start with simple cases (c, s, d) then add flags, width, precision and custom specifiers.
- Add unit tests (small C mains) for edge cases: `INT_MIN`, `LONG_MIN`, `NULL` strings, precision `0` with value `0`, `*` width/precision.

## Authors

Jana Rasheed Bakri
Badr Abdulaziz Almutairi
