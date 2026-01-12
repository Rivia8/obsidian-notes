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