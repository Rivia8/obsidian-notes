08-10-2025 10:39

Tags: [[C]]

# Printing to the Terminal

We use `printf` to print to the console.

The convention that we use is:

```C
printf(<format string>, <variable1>, <variable2>, etc.);
```

The first argument is the format string containing the text to print as well as optional marker that will be replaced with the variable's values. 
The next arguments are optional - they are the list of variables which values need printing.

Here is a complete example:

```C
int int_var = -1;
unsigned int uint_var = 12;
long int lint_var = 10;
float float_var = 2.5;
double double_var = 2.5;
char char_var = 'a';
char string_var[] = "hello";

printf("Integer: %d\n", int_var);
printf("Unsigned integer: %u\n", uint_var);
printf("Long integer: %ld\n", lint_var);
printf("Float: %f\n", float_var);
printf("Double: %lf\n", double_var);
printf("Characters: %c\n", char_var);
printf("String: %s\n", string_var);
printf("Several variables: %d, %lf, %s\n", int_var, double_var, string_var);
```

The `\n` is to signify a line break, its an *escape* character.

- `%d` is used for signed integers, `%u` for unsigned ones,
- `%l` is used to indicate the `long` qualifier, for example we have `%ld` for a signed `long int`.
- `%f` is used for floats and `%lf` for doubles.

So here is a table to make things easier to digest:

| **Specifier**        | **Expected Data Type** | **printf (Output) Description**                                                                | **scanf (Input) Description**                           |
| -------------------- | ---------------------- | ---------------------------------------------------------------------------------------------- | ------------------------------------------------------- |
| **`%d`** or **`%i`** | `int`                  | Prints a signed decimal (base-10) integer.                                                     | Scans a signed decimal integer.                         |
| **`%u`**             | `unsigned int`         | Prints an unsigned decimal (base-10) integer.                                                  | Scans an unsigned decimal integer.                      |
| **`%f`** or **`%F`** | `double`               | Prints a decimal floating-point number.                                                        | **Scans a `float *`**. (This is a common "gotcha"!)     |
| **`%e`** or **`%E`** | `double`               | Prints a number in scientific (exponential) notation.                                          | **Scans a `float *`**.                                  |
| **`%g`** or **`%G`** | `double`               | Prints either in `%f` or `%e` format, whichever is shorter.                                    | **Scans a `float *`**.                                  |
| **`%c`**             | `char`                 | Prints a single character.                                                                     | Scans a single character (including whitespace).        |
| **`%s`**             | `char *`               | Prints a string (array of `char` ending in `\0`).                                              | Scans a string (stops at the first whitespace).         |
| **`%x`** or **`%X`** | `unsigned int`         | Prints an unsigned hexadecimal (base-16) integer.                                              | Scans a hexadecimal integer.                            |
| **`%o`**             | `unsigned int`         | Prints an unsigned octal (base-8) integer.                                                     | Scans an octal integer.                                 |
| **`%p`**             | `void *`               | Prints a memory address (pointer).                                                             | Scans a memory address (pointer).                       |
| **`%n`**             | `int *`                | (No output) Stores the number of characters printed so far into the provided `int *` variable. | (No input) Stores the number of characters read so far. |
| **`%%`**             | N/A                    | Prints a single literal `%` character.                                                         | N/A                                                     |
| `%s`                 | `string`               | Prints an array of characters                                                                  |                                                         |

These are modifiers that are placed *before* the specifier to change the size of the datatype. 

| **Modifier**  | **Applies to...** | **Resulting Type (Example)**                            | **scanf Notes**                                 |
| ------------- | ----------------- | ------------------------------------------------------- | ----------------------------------------------- |
| **`h`**       | `d, i, u, o, x`   | `short int` (e.g., `%hd`)                               | Scans for a `short *`.                          |
| **`hh`**      | `d, i, u, o, x`   | `signed char` or `unsigned char` (e.g., `%hhd`)         | Scans for a `char *`.                           |
| **`l`** (L)   | `d, i, u, o, x`   | `long int` (e.g., `%ld`)                                | Scans for a `long *`.                           |
| **`l`** (L)   | `f, e, g`         | **No effect for `printf`** (it expects `double` anyway) | **CRITICAL:** Use for `double *` (e.g., `%lf`). |
| **`L`**       | `f, e, g`         | `long double` (e.g., `%Lf`)                             | Scans for a `long double *`.                    |
| **`ll`** (LL) | `d, i, u, o, x`   | `long long int` (e.g., `%lld`)                          | Scans for a `long long *`.                      |