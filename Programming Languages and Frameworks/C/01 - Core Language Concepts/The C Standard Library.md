25-10-2025 22:28

Tags: [[C]]

# The C Standard Library

The C standard library is a collection of essential functions, macros and data types that comes with every C compiler. It provides a standard, portable way to perform common, low-level tasks so you don't have to write them yourself every time.

It's like an **inbuilt tool-kit for your C** programs. To use a tool from the kit you have to include its corresponding **header file** at the top of your code using the `#include` directive.

The [notes](https://olivierpierre.github.io/comp26020/12-standard-library-1.html) will go in further detail for each of these.

- [[String Manipulation]]

## Manual Pages

Every function in the standard library can be found in the manual.

## Input/Output - `stdio.h`

`stdio.h` stands for 'Standard I/O'. This is the most common header, it gives you functions to communicate with the user (via the terminal and files).
- `printf()`: prints formatted text to the console.
- `scanf()`: reads formatted input from the user.
- `fopen()`: opens a file.
- `fclose()`: closes a file.
- `fprintf()`: prints to a file.
- `fgets()`: reads a line of text (a string) from a file or console.

## Memory Management - `stdlib.h`

This is the 'Standard Library' header, contains general purpose functions and its most important being  [[Dynamic Memory Allocation|dynamic memory allocation]]

- `malloc()`
- `free()`
- `calloc()`
- `realloc()`
- `atoi()`: Converts a string to an `int`
- `exit()`: Terminates the program
- `memset()`: Writes bytes to memory,
`memset` repeatedly writes the byte `c`, `n` times starting from address `s`:
```c
void *memset(void *s, int c, size_t n);
```



## Math Operations (`math.h`)

- **`sqrt()`**: Calculates the square root.
- **`pow(base, exp)`**: Calculates `base` raised to the **pow**er of `exp`.

## Generating Random 

We use the `rand()` function to generate a random int.
It returns an `int` from 0 to a large constant named `RAND_MAX`:

```C
int rand(void);
```

If we want to constrain the number to fall within a particular interval we can use the modulo operator:

```C
for(int i=0; i<10; i++)
    printf("%d ", rand()%100);
```

The above code will produce numbers ranging from between 0 and 99.




