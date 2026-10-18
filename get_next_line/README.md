*This project has been created as part of the 42 curriculum by joamunoz.*

# get_next_line

## Description

`get_next_line` is a function that returns one line at a time from a file
descriptor, each time it is called. A line is everything up to and including
the `\n` character (the last line of a file may not end with one).

```c
char	*get_next_line(int fd);
```

**Return value:** the line that was read, or `NULL` if there is nothing else
to read or if an error occurred.

## Algorithm

### Chosen approach: persistent stash + chunked reads

The function keeps a `static char *stash` that survives between calls. Each
call to `get_next_line` does three things:

1. **Fill:** while the stash does not contain a `\n` and `read()` has not
   reached the end of the file, read `BUFFER_SIZE` bytes into a temporary
   buffer and append them to the stash with `ft_strjoin`.
2. **Extract:** locate the first `\n` in the stash with `ft_strchr` and copy
   everything up to and including it into a new string. If there is no `\n`
   (last line of a file without a trailing newline), the whole stash is the line.
3. **Trim:** copy whatever comes after the `\n` into a new string, free the old
   stash, and keep the new one for the next call.

When the stash is empty after a fill, there is nothing left to return, so it
is freed and `NULL` is returned.

### Why this algorithm

- **A `read()` is a system call, so there should be as few as possible.**
  Reading one byte at a time would be simple, but it would cost one system
  call per character. Reading in chunks of `BUFFER_SIZE` makes the cost
  depend on the number of chunks instead.
- **A `read()` cannot be told to stop at a newline.** It returns a fixed
  number of bytes, which may contain several lines, or only part of one.
  That is why the leftover must be saved between calls, and the only way to
  do that without global variables is a `static` variable.
- **Stopping as soon as a `\n` is in the stash** means the file is never read
  further than needed. This matters for pipes and standard input, where
  `read()` blocks until data arrives, and it keeps memory usage proportional
  to the current line and not to the whole file.
- **The result does not depend on `BUFFER_SIZE`.** The loop condition looks at
  the stash, not only at the last chunk, so any buffer size, from 1 to
  millions, produces the same lines. It only changes the number of system
  calls and the size of the temporary buffer.
- **Plain strings instead of a linked list of buffers.** A list of chunks
  avoids copying, but needs a more complex structure and more allocations
  per call. A single string is easy to reason about, easy to free, and is
  enough for the required behavior.

### Memory management

Every allocation has a single owner at any time:

- The temporary buffer is allocated and freed within one call to `get_stash`.
- The stash is replaced (never modified in place): each `ft_strjoin` creates
  a new string and frees the previous one.
- The returned line belongs to the caller, who must free it.
- On end of file or on an error, the stash is freed and set to `NULL`, so
  there is no memory left behind, and the next call starts clean.

### Edge cases handled

- Invalid file descriptor, or `BUFFER_SIZE <= 0`: returns `NULL`.
- Empty file: returns `NULL` on the first call.
- Last line without a trailing `\n`: returned as it is, and the next call
  returns `NULL`.
- A line longer than `BUFFER_SIZE`, or several lines in one chunk: handled by
  the stash.
- `read()` error or `malloc` failure: everything allocated is freed and `NULL`
  is returned.

### Bonus: one stash per file descriptor

The mandatory version has only one stash, so switching to another file
descriptor would mix their contents. The bonus replaces it with
`static char *stash[1024]`, indexed by `fd`. Each descriptor has its own
leftover, so reads from several files can be interleaved freely. An array was
chosen over a linked list of descriptors because the access is `O(1)` and
the size matches the per-process limit of open descriptors (`ulimit -n`).

### Files

| File                          | Content                                  |
| ----------------------------- | ---------------------------------------- |
| `get_next_line.c`             | Main function and its static helpers     |
| `get_next_line_utils.c`       | String helpers (`ft_strlen`, `ft_strchr`, `ft_strdup`, `ft_strjoin`) |
| `get_next_line.h`             | Prototypes, includes and `BUFFER_SIZE`   |
| `get_next_line_bonus.c`       | Bonus: multiple file descriptors         |
| `get_next_line_utils_bonus.c` | Bonus: string helpers                    |
| `get_next_line_bonus.h`       | Bonus: header                            |

## Instructions

### Compilation

The buffer size is set at compile time with the `-D BUFFER_SIZE=n` flag.
If it is not given, the header defines a default value.

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	get_next_line.c get_next_line_utils.c main.c -o gnl
```

For the bonus:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

The returned line is allocated with `malloc` and must be freed by the caller.

### Testing

It is recommended to test with several buffer sizes (for example `1`, `42`,
`9999` and `10000000`), with empty files, files without a trailing newline,
very long lines, invalid file descriptors and standard input, and to check
for leaks with `valgrind --leak-check=full`.

## Resources

**C Programming: A Modern Approach**, K. N. King

- Chapter 22 - Input/Output
  - 22.1 Streams
- Chapter 17 - Advanced Uses of Pointers
  - 17.1 Dynamic Storage Allocation
  - 17.2 Dynamically Allocated Strings
  - 17.4 Deallocating Storage
  - 17.6 Pointers to Pointers
- Chapter 10 - Program Organization
  - 10.1 Local Variables - Static Local Variables
  - 10.4 Scope
- Chapter 12 - Pointers and Arrays
  - 12.1 Pointer Arithmetic
  - 12.2 Using Pointers for Array Processing
- Chapter 14 - The Preprocessor
  - 14.3 Macro Definitions
  - 14.4 Conditional Compilation
- Chapter 18 - Declarations
  - 18.1 Declaration Syntax
  - 18.2 Storage Classes - The static Storage Class
  - 18.5 Initializers

**Advanced Programming in the UNIX Environment**, W. Richard Stevens

- Chapter 3.2 - File Descriptors
- Chapter 3.7 - `read` Function
- Chapter 3.9 - I/O Efficiency

## AI Usage

AI was used to help format and structure this README.md.
