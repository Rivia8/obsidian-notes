16-10-2025 21:27

Tags: [[C]]

# Strings

In C strings are just [[Programming Languages and Frameworks/C/01 - Core Language Concepts/Arrays|arrays]] that are comprised of characters and end with a special character, `\0.

We can declare strings as follows:

```C
char my_string[6] = "Hello";
char my_string2[] = "Hello";
```

Here the compiler will automatically include the termination character for these so we do not have to do anything, but remember that when setting the size of the array remember to consider the null character.

## String to Integer Conversion

We can use the `atoi` function to convert strings to integers:

```C
#include <stdlib.h> // this library is needed for atoi

int main(int argc, char **argv) {
    int a, b;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("%d + %d = %d\n", a, b, a+b);
    return 0;
}
``````

This is quite dangerous code since there may not be arguments that are passed so if the code is called with less than 2 arguments we will get a memory error.

To convert a string to a `double` there is `atof`.

