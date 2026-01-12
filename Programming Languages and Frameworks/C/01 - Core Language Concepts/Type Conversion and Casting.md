08-11-2025 14:47

Tags: [[C]]

# Type Conversion and Casting

This is the process of converting one data type to another, this can either be done by the programmer (explicit) or *automatically* by the compiler (implicit).

## Implicit Type Conversions

In many situations the compiler performs **implicit conversions** between types. What happens is that the compiler will make the smaller data type into the bigger data type to avoid data loss. 

```C
int a = 10;
double b = 5.5;
double result = a + b;
```

In this case, the integer `10` is automatically converted to the double `10.0` so addition can occur smoothly.

## Implicit Conversion when Passing Parameters

Conversion also happens implicitly when calling functions.

Here is a clear example below:

```C
void f1(int i) {
    printf("%d\n", i);
}

void f2(double d) {
    printf("%lf\n", d);
}

void f3(unsigned int ui) {
    printf("%u\n", ui);
}

int main(int argc, char **argv) {
    char c = 'a';
    unsigned long long ull = 0x400000000000;

    f1(c);    // prints 97 (ascii code for 'a')
    f2(c);    // prints 97.0
    f3(ull);  // overflows int ... prints 0 (lower 32 bits of 0x400000000000)

    return 0;
}
```

Although this code is logically incorrect, to the compiler its completely fine, highlighting the importance of understanding what is happening in C when it comes to data types.
## Integer Promotion

C has a 'silent' integer promotion mechanism, this causes data type that are smaller than an `int` to be made an `int` (like a `short` and `char`) since the `int` size is the size of a word on the system which is deemed to be more efficient and to prevent Integer Overflows. However, this can cause subtle bugs:

```C
int si = -1;
unsigned int ui = 1;
printf("d\n", si < ui); 
```

You expect it to print '1' since this would be true, however, for this comparison `si` is promoted to a `unsigned int`, `-1` to `4294967295` (in a 32-bit machine) and that number is then evaluated against `ui`.

The ranks are here as follows:

- `long long int`, `unsigned long long int` (highest rank).
- `long int`, `unsigned long int`.
- `int`, `unsigned int`.
- `short int`, `unsigned short int`.
- `signed char`, `char`, `unsigned char` (lowest rank).


The promotion rules for 2 operands of an operation are as follows:

1. If the operands have the same type there is no need for promotion.
2. If both operands are signed or both operands are unsigned, the operand of lesser rank is promoted to the type of the operand of higher rank.
3. If the rank of the unsigned operand is superior or equal to the rank of the other operand, the signed operand is promoted to the type of the unsigned operand.
4. If the signed operand type can represent all the values of the unsigned operand type, the unsigned operand gets promoted to the signed type.
5. Otherwise, both operands are converted to the unsigned type corresponding to the signed operand's type.

Another note is that an integer will be promoted to a `float` if one of them in an operand is a `float` (or `double`).

## Type Casting

Type castings lets the programmer force a conversion, you do this by having parentheses in front of the expression that you want to convert.

```C
// prints 3.75: 4 gets converted to 4.0
printf("%lf\n", (float)15/4);
```

Remember before due to integer promotion `unisgned int` equal to `1` was evaluated incorrectly. We can now fix that with type casting:

```C
int si = -1;
unsigned int ui = 1;
printf("%d\n", si < (int)ui); // prints 1
```

## Generic Pointers

We can create a function using casting to create generic [[Pointers|pointers]] in C. Essentially we can *choose* what to do with some data and by typecasting with it:

```C
typedef enum {
    CHAR, INT, DOUBLE
} type_enum;

void print(void *data, type_enum t) {
    switch(t) {
        case CHAR:
            printf("character: %c\n",
                *(char *)data);
            break;
        case INT:
            printf("integer: %d\n",
                *(int *)data);
            break;
        case DOUBLE:
            printf("double: %lf\n",
                *(double *)data);
            break;
        default:
            printf("Unknown type ...\n");
    }
}
```