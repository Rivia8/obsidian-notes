26-10-2025 17:21

Tags: [[C]]

# String Manipulation

**[[Programming Languages and Frameworks/C/01 - Core Language Concepts/Strings|String]] Manipulation** is a big topic.

To get the main string manipulation tools you must have the header:

```C
#include <string.h>
```

## Getting the Length of Strings

We use the `strlen()` function.
It returns the length of a string, one thing to note is that it counts **until** it hits the `\0` - the `\0` is not included in the count.

```C
char my_string[] = "Hello"; // Really 6 bytes: 'H', 'e', 'l', 'l', 'o', '\0'
size_t len = strlen(my_string); // len will be 5
```

## Copying Strings

`strcpy():` Copies one string into another.

If you were to just use the `=` operator you would just create a copy of the pointer of the string (since strings are arrays of `char` types).
Here is the proper way of performing such a copy:

```C
char *strcpy(char *dest, const char *src);
```

*Careful if `*dest` is smaller than `*src` it will overflow and a memory error will occur.

We do have a variation called `strncpy()` that is safer since it accepts a 3rd argument, n and copies only up to n bytes.

```C
char source[] = "Hello World";
char destination[10];

// DANGEROUS! "Hello World" (11 chars) is too big for destination[10].
// strcpy(destination, source); // This will corrupt memory!

// SAFE WAY:
strncpy(destination, source, 9); // Copy 9 chars to leave room
destination[9] = '\0';           // MANUALLY add the null terminator
// destination now holds "Hello Wor"
```

## Concatenation

We use the `strcat()` function where the general arguments are:

``` C
char* strcat(char *dest, const char *src)
```

This will append the `src` string to the **end** of the `dest` string.
This has the same issue as with `strcpy` where it assumes `dest` is large enough to hold *both* its original content *and* all of `src`.

`char* strncat(char *dest, const char *src, size_t n)`
This the safer version, it has a very similar approach as you can see taken to that of copying strings:

```C
char greeting[20] = "Hello "; // Size 20, but current string is "Hello "
char name[] = "Armaan";

// This is safe because greeting[20] is large enough
strncat(greeting, name, 19 - strlen(greeting)); // (Max size - current size)
// greeting now holds "Hello Armaan"
```

## Comparing Strings

You **cannot** use `==` to compare strings, this just compares the memory addresses of the two arrays.
We instead use the `stcmp()` function.

``` C
int strcmp(const char *s1, const char *s2)
```

This compares two strings **alphabetically**.
It returns:
- **`0`** if the strings are **equal** (e.g., "abc" and "abc")
- **`< 0`** (a negative number) if `s1` comes **before** `s2` (e.g., "abc" < "abd")
- **`> 0`** (a positive number) if `s1` comes **after** `s2` (e.g., "abd" > "abc")

## Searching Strings


