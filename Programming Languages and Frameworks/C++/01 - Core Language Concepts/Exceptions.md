02-02-2026 12:04

Tags: [[C++]]

# Exceptions

C++ introduces exceptions. In C, error handling is typically done by returning special values (like -1 or `NULL`) or setting a global flag like `errno`.

It has three keywords:

1. `throw`: Signals that an error has occurred. 
2. `try`: A block of code where you expect exceptions might happne,
3. `catch`: A block of code that executes *only* if a specific exception is thrown inside the try block


Example of a 'Division by zero' catch:


```C++
#include <iostream>
#include <stdexcept> // Contains standard exception types

double divide(double a, double b) {
    if (b == 0) {
        // We detect the error and "throw" it up the chain
        throw std::runtime_error("Division by zero error!");
    }
    return a / b;
}

int main() {
    try {
        // The "Happy Path" - we assume everything works
        double result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    } 
    catch (const std::runtime_error& e) {
        // The "Error Path" - we catch the specific error
        std::cerr << "Caught an error: " << e.what() << std::endl;
    }
    
    std::cout << "Program continues..." << std::endl;
    return 0;
}
```

Key difference between C and C++ is if you look and see that `divide()` doesn't return an error code, it returns a double. If it fails, it bypasses the `return` statement entirely and jumps to the `catch` block in `main`.

When a function `throws` an `exception` 9 

