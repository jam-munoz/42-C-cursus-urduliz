*This project has been created as part of the 42 curriculum by joamunoz.*
# ft_printf

## Description

`ft_printf` is a custom implementation of the C `printf` function.

The mandatory part supports the following conversions:

- `%c` - character
- `%s` - string
- `%p` - pointer address
- `%d` / `%i` - signed decimal integer
- `%u` - unsigned decimal integer
- `%x` / `%X` - hexadecimal integer
- `%%` - percent sign

The bonus part was not implemented.

## Instructions

Compile the library with:

```bash
make
```

Available Makefile commands:

```bash
make
make clean
make fclean
make re
```

To use the library:

```bash
cc main.c -L. -lftprintf
```

## Algorithm and Data Structures

The implementation uses a `t_printf` structure to keep the `va_list`, format string, output buffer, buffer size, and total character count together.

The format string is processed sequentially. When a conversion is found, the corresponding function retrieves its argument with `va_arg` and writes the result to the buffer.

### Numeric conversions

For decimal and hexadecimal conversions, the number of digits is calculated before writing the value. This makes it possible to check whether the complete result fits in the remaining buffer space.

Once the required space is reserved, digits are written backwards from the end of the reserved area. Hexadecimal conversion uses bitwise operations (`& 0xF` and `>> 4`) to extract each digit.

### Buffer management

Output is accumulated in a fixed-size buffer instead of writing every character individually.

When there is not enough space for the next complete value, the buffer is flushed with `write()` and reused. Strings are handled incrementally because their length can exceed the buffer size.

This reduces the number of system calls while keeping the implementation simple and avoiding dynamic allocation.

## Resources

- *C Programming: A Modern Approach*, K. N. King
  - Chapter 26.1 - The `<stdarg.h>` Header: Variable Arguments
  - Chapter 3.1 - The `printf` Function
  - Chapter 22.3 - Formatted I/O
  - Chapter 18.2 - The `static` Storage Class
  - Chapter 20.1 - Bitwise Operators
- *Advanced Programming in the UNIX Environment*, W. Richard Stevens
  - Chapter 3.2 - File Descriptors
  - Chapter 3.8 - `write` Function
  - Chapter 3.9 - I/O Efficiency
- *The GNU C Reference Manual*
- `printf(3)` and related C library man pages.
- Struct design inspired by discussions with my 42 peers and sensei.

## AI Usage

AI was used to help format and structure this README.md.
