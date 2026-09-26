*This project has been created as part of the 42 curriculum by joamunoz.*
# Libft

## Description

Libft is a custom C library containing general-purpose functions that can be reused throughout the 42 curriculum.

The project consists of reimplementing a selection of standard libc functions, developing additional string and memory utilities, and creating a set of linked-list functions.

The library is divided into three main parts:

- Part 1 - Libc functions
- Part 2 - Additional functions
- Part 3 - Linked lists

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

The resulting `libft.a` library is created at the root of the repository.

To use the library in another C project:

```bash
cc main.c -L. -lft
```

## Library Functions

### Part 1 - Libc Functions

This part reimplements commonly used functions from the C standard library, following their original behavior while using the `ft_` prefix.

Character handling:
- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

String and memory handling:
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_strdup`

General Utilities:
- `ft_atoi`
- `ft_calloc`

The project requires these functions to be implemented without relying on external functions, with the exception of malloc for ft_calloc and ft_strdup.

### Part 2 - Additional Functions

This part extends the library with functions for string creation, transformation, and file-descriptor output.

String manipulation and allocation:
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

File-descriptor output:
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

These functions introduce more extensive use of dynamic memory allocation and function pointers.

### Part 3 - Linked Lists

The final part introduces a generic singly linked list using the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

The implemented list functions are:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

The use of `void *` allows each node to store arbitrary data, while the `next` pointer links the nodes together.

## Technical Approach

Most of the libc functions were implemented by reproducing behavior already practiced during the Piscine, while paying closer attention to edge cases, pointer manipulation, memory safety, and the original function specifications.

Dynamic allocation is used for functions that create new strings, arrays, or list nodes. Memory is allocated with `malloc()` and must be properly freed when no longer needed.

Function pointers are used in `ft_strmapi`, `ft_striteri`, and several linked-list functions to make the library more generic and reusable.

## Resources

- *C Programming: A Modern Approach*, K. N. King
  - Chapter 23.5 - The `<ctype.h>` Header: Character Handling
  - Chapter 23.6 - The `<string.h>` Header: String Handling
  - Chapter 26.2 - The `<stdlib.h>` Header: General Utilities
  - Chapter 17 - Advanced Uses of Pointers
  - Chapter 17.3 - Dynamically Allocated Arrays: The `calloc` Function
  - Chapter 17.5 - Linked Lists
  - Chapter 17.7 - Pointers to Functions
- *Advanced Programming in the UNIX Environment*, W. Richard Stevens
  - Chapter 3.8 - write Function
  - Chapter 3.9 - I/O Efficiency
- *The GNU C Reference Manual*
- `man` pages
- [GLib Documentation](https://docs.gtk.org/glib/)
- [File I/O in C - `<unistd.h>`](https://medium.com/@scarletskynned/file-i-o-unistd-h-80dd92b9f782)

The `man` pages were particularly useful for checking the expected behavior and edge cases of the functions.

## AI Usage

AI was used to help format and structure this README.md.
