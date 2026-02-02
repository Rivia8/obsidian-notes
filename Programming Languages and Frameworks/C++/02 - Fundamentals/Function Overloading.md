02-02-2026 11:35

Tags: [[C++]]

# Function Overloading

In C++ you can do something called function overloading. 

This is where you have the same function names but they have different implementations with different arguments.
*C does **not** have this feature.*

## Rules

A Compiler can distinguish overload functions by their **signature**. A function's signature is made up of:

1. The function name,
2. The **number** of parameters,
3. the **type** of parameters

```C++
#include <iostream>
#include <string>

// Function 1: Takes an integer
void print(int i) {
    std::cout << "Printing Integer: " << i << std::endl;
}

// Function 2: Takes a string (Same name, different type)
void print(std::string s) {
    std::cout << "Printing String: " << s << std::endl;
}

// Function 3: Takes TWO integers (Same name, different count)
void print(int a, int b) {
    std::cout << "Printing Two Integers: " << a << " and " << b << std::endl;
}

int main() {
    print(10);          // Calls Function 1
    print("Hello");     // Calls Function 2
    print(5, 7);        // Calls Function 3
    return 0;
}
```

One thing to remember is that you **cannot** overload a function based **only** on return types, the compiler cannot figure out which one to call if you don't use the return value.

