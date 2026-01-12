06-10-2025 12:28

Tags: [[C]]

# Variables

```C
#include <stdio.h>

int main() {
    int a;                          // declare a of type int (signed integer)

    a = 12;                         // set the value of a to 12
    printf("a's value: %d\n", a);   // print the value of a

    return 0;
}
```

The variable `a` is set to 12, and then printed to the standard output.
Variables have a `name` and **must** start with a **letter** or **underscore ('\_')**.  

## Using Variables

```C
int a; int b; int c;
int d = 12;  // declare and set
int x, y = 10, z = 11;

a = 12;      // set a to 12
b = 20;      // set b to 20

c = 10 + 10; // set c to 20
a = b;       // a = 20
d++;         // d = d + 1
y *= 2       // y = y * 2;

```

Here we can see some things called '*Syntactic Sugar*':
- `d++`

## Types of Variables and Effect on Memory

Each variable must have a **type**, types are used by the compiler to do two things:
1. Compiler does some checks on the operations realised on the variable,
2. It allocates the memory space for the variable *(Each type defines a given size in bytes for this).*

The types of variables define the data storage size in memory. 
For example the `int` type on the x86-64 architecture is 4 bytes long, the compiler then reserves 4 bytes in memory when declaring the variable.

![[types.svg#invert|500]]

### Primitive Types

`int` is a type called known as a 'Primitive Type'. 
We also have other primitive types such as:
- `char`: for single characters,

*One thing to note about `char` is that it can be signed or unsigned, a **signed** `char` will have the MSB used to signify whether (if it is a number) is positive or negative, this however reduces the 'largest' number that can be displayed.* 
*For example an unsigned `char` is 1 byte (8 bits) so can display 256 combinations (256 numbers) like 0 to 255*
*A signed `char` is also 1 byte (8 bits) and still can display 256 combinations but can show -128 to 127*

- `float`: for single-precision floating point numbers,
- `double`: for double-precision floating point numbers,

When declaring a variable we use a combination of a type and optional qualifiers, that will define the variable can hold and how much space is reserved. 
It is very important to be aware of the storage size of variables, as things like overflows can have bad consequences.

```C
short int a;              // signed, at least 16 bits: [-32,767,        +32,767]
int b;                    // signed, at least 16 bits: [-32,767,        +32,767]
unsigned int c;           // unsigned:                 [0,              +65,535]
long int d;               // at least 32 bits:         [-2,147,483,647, +2,147,483,647]
unsigned long int e;      // unsigned:                 [0,              +4,294,967,295]
long long int f;          // at least 64 bits:         [-9x10^18,       +9x10^18]
long long unsigned int g; // unsigned:                 [0,              +18x10^18]
float h;                  // storage size unspecified, generally 32 bits
double i;                 // storage size unspecified, generally 64 bits
```

### sizeof

To get the exact storage size we can use the `sizeof` function, that takes a type as parameter and returns its storage size in bytes.

```C
int so_short = sizeof(short int);
int so_int = sizeof(int);
int so_uint = sizeof(unsigned int);
int so_long = sizeof(long int);
int so_longlong = sizeof(long long int);
int so_float = sizeof(float);
int so_double = sizeof(double);

printf("size of short:         %d bytes\n", so_short);
printf("size of int:           %d bytes\n", so_int);
printf("size of unsigned int:  %d bytes\n", so_uint);
printf("size of long int:      %d bytes\n", so_long);
printf("size of long long int: %d bytes\n", so_longlong);
printf("size of float:         %d bytes\n", so_float);
printf("size of double:        %d bytes\n", so_double);
```


