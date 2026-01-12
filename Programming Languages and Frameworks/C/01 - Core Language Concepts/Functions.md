17-10-2025 14:52

Tags: [[C]]

# Functions

Functions have a name, zero or more parameters.
They have a **type**, a **name** and a **return type**.

Here is an example:

```C
int add_two_integers(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int x = 1, y = 2;
    int sum = add_two_integers(x, y);
    printf("result: %d", sum);

    if(add_two_integers(x, y))
        printf(" (non zero)\n");
    else
        printf(" (zero)\n");
    return 0;
}
```

The code above has very simple logic, it takes two integers as parameters named `a` and `b`. It returns an integer which is hte sum of the two parameters.

## Call by Copy

One thing to remember is that in C function parameters are passed by copy and not by reference like in other languages like Python, what this means is that each function call gets its own local copy of the parameters' values and updating will not modify the calling context.

Look at the following code:

```C
void my_function(int parameter) {
    parameter = 12; // does not update x in main
}
int main() {
    int x = 10;
    my_function(x);
    printf("x is %d\n", x); // prints 10
    return 0;
}
```

We can see that because the function gets its own parameter copy it does not get updated to 12.

## Forward Declaration

You can do something called forward declaration whereby you just declare the function name, return type and parameters (the function template) and then instantiating its code later, the reason you might want to do this is for organisation purposes.

```C
/* Forward declaration, also called function _prototype_ */
int add(int a, int b);
int main(int argc, char **argv) {
    int a = 1;
    int b = 2;
    /* Here we need the function to be at least declared -- not necessarily defined */
    printf("%d + %d = %d\n", a, b, add(a, b));
    return 0;
}
/* The actual function definition */
int add(int a, int b) {
    return a + b;
}
```




