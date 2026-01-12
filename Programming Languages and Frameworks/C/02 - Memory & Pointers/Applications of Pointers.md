25-10-2025 10:08

Tags: [[C]]

# Applications of Pointers

There are various applications for [[Pointers]].

## Allow a function to Access the Calling Context

Arguments are passed by copy in C so with arguments of regular types a function cannot change its calling context.

```C
void add_one(int param) {
    param++;
}
int main(int argc, char **argv) {
    int x = 20;
    printf("before call, x is %d\n", x);   // prints 20
    add_one(x);
    printf("after call, x is %d\n", x);    // prints 20
    return 0;
}
```

Looking at the example above, you can see that no matter what is in the `add_one()` function, outside of it the value of `x` will stay the same.

In order to ***actually*** increment the value held in `x` we can use pointers, so we pass a **pointer** to the `add_one()` function instead of a normal variable:

```C
void add_one(int *param) {
    (*param)++;
}

int main(int argc, char **argv) {
    int x = 20;
    printf("before call, x is %d\n", x);   // print 20
    add_one(&x);
    printf("after call, x is %d\n", x);    // print 21
    return 0;
}
```

In the second example above, we pass the *address* of `x` into `add_one` and change the parameter of the function to be a pointer. This is the same as creating a pointer, so you think of this is as creating and passing the pointer `param` into the function.
The reason this works is because we are not using a copy of the variable and having a temporary variable in memory but rather changing the contents of the original memory address.

## Allowing Functions to 'Return' More Than a Single Value

Pointers can be used to access the calling context when we want a function to 'return' more than a single value.

This works with the principle as in the above example, but in the sense that we have we are changing the values held at multiple addresses, whilst still only having one actual 'return' value.

Here is an example:

```C
// we want this function to return 3 things: the product and quotient of n1 by n2,
// as well as an error code in case division is impossible
int multiply_and_divide(int n1, int n2, int *product, int *quotient) {
    if(n2 == 0) return -1;      // Can't divide if n2 is 0
    *product = n1 * n2;
    *quotient = n1 / n2;
    return 0;
}

int main(int argc, char **argv) {
    int p, q, a = 5, b = 10;
    if(multiply_and_divide(a, b, &p, &q) == 0) {
        printf("10*5 = %d\n", p); printf("10/5 = %d\n", q);
    }
}
```


## Making Function Calls with Large Data Structures Efficient

If we have a large `struct` variable that has many 8-byte-fields and we want to update them. Without pointers we can do it like this:

```C
typedef struct {
    // lots of large (8 bytes) fields:
    double a; double b; double c; double d; double e; double f;
} large_struct;

large_struct f(large_struct s) { // very inefficient in terms of
    s.a += 42.0;                 // performance and memory usage!
    return s;
}

int main(int argc, char **argv) {
    large_struct x = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    large_struct y = f(x);
    printf("y.a: %f\n", y.a);
}
```

Here we create a `struct x` with assigned values to its fields, we then pass it as a parameter to the function and assign it to the `y` variable after doing whatever you need to do them.

This is extremely inefficient as C works on a **pass-by-value** basis, this means that a copy of the value of `x` is needed that is passed as `s` into the function and then **another** struct is created, `y`, which is the result we want:
- The struct, `large_struct` is comprised of 6 `long` types, 6 x 8 = 48 bytes of data for each struct,
- This means to just update one value we need to use 48 bytes of memory space.

We can essentially fix this issue with the same principles applied to the previous applications of pointers.
Its really simple too, we just alter the function to accept a pointer instead, pass the address of the struct we want to modify, dereference the struct when modifying to get the actual value held and not modify the address, and that's it!

Here it is:

```C
void f(large_struct *s) {  // now takes a pointer parameter
    (*s).a += 42.0;         // dereference to access x
    return;
}

int main(int argc, char **argv) {
    large_struct x = {1, 2, 3, 4, 5, 6};
    f(&x);                 // pass x's address
    printf("x.a: %f\n", x.a);
    return 0;
}
```

## Pointer Chains

We can create pointers to pointer and construct chains:

```C
int value = 42;         // integer
int *ptr1 = &value;     // pointer of integer
int **ptr2 = &ptr1;     // pointer of pointer of integer
int ***ptr3 = &ptr2;    // pointer of pointer of pointer of integer

printf("ptr1: %p, *ptr1: %d\n", ptr1, *ptr1);
printf("ptr2: %p, *ptr2: %p, **ptr2: %d\n", ptr2, *ptr2, **ptr2);
printf("ptr3: %p, *ptr3: %p, **ptr3: %p, ***ptr3: %d\n", ptr3, *ptr3,
        **ptr3, ***ptr3);
```

In memory we have this layout:

![[chain-3.svg#invert|600]]

There is a value of 42 stored in the variable `value`. We create a pointer to it, `*ptr1`, then we create a pointer to `*ptr1`, `**ptr2`. `**ptr2` holds the address of the first pointer. This carries on for the 3rd pointer.