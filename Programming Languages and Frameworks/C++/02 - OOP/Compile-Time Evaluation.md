16-04-2026 18:52

Tags: [[C++]]

**Compile-Time Evaluation** is the process of shifting computational work **away** from the moment your program is running (runtime) and forcing the compiler to do the math while it is building the executable.

In performance-critical application like software/computer science, the ultimate optimisation is entirely eliminating work. If a value can be known before the program ever touches a user's machine,  the compiler will calculate it once and simply hard-code the final answer into the binary.

The magic keyword `constexpr` explicitly tells the compiler to evaluate something at compile-time.
- For variables, it guarantees that the variable is read-only (`const`) **AND** its value is definitely calculated before the program runs.
- For Functions it says: "if you feed this function arguments that are known at compile-time, it will return a compile-time constant."

Look at this example that can be done via 'Runtime' or 'Compile' time solutions:

```C++
auto cube = [](int x) {return x * x * x;};
std::vector<int> v(cube(3)); 
std::iota(v.begin(), v.end(), 0);
return v[fibonacci(8)];
```

This generates a massive amount of machine code, due to `std::vector` and `fibonacci(8)`.
- `std::vector` relies on dynamic memory allocation (`new`) which must happen at runtime on the heap
- `fibonacci(8)` is evaluated at runtime, meaning the CPU physically pushes and pops frames onto the call stack to execute the recursive `fibonacci` function every single time the program runs.


```C++
constexpr int fibonacci(int num) { ... }

std::array<int, cube(3)> v;
```
To make this ***faster***, we can make `fibonacci` with `constexpr` and switch to using a `std::array` (a `std::array` lives on the stack and requires its size to be known at compile-time).
When the program is compiled, the compiler sees `cube(3)` and calculates 27. It sees `fibonacci(8)` and runs the recursion during compilation. This causes the machine code to be a lot smaller and instead of recursive calls and heap allocations, the final machine code just returns a pre-calculated value `move eax, 21`.

## Rules of `constexpr`

You cannot evaluate absolutely everything at compile-time.
`constexpr` only works with **Literal Types**.

- It works with things like standard numbers (`int`, `float`), pointers, enums and simple classes where the destructors are trivial.
- It **doesn't** work with anything that requires dynamic heap allocation (like `std::vector` or `std::string`) or virtual functions.


## Replacing C-Macros

There's a crucial C++ guideline, ES.31: **Don't use macros for constants or functions**.

In C, developers used `#define MAX_SIZE 100` or `#define CUBE(x) (x*x*x)` to force compile-time text replacement.
`constexpr` completely replaces this dangerous practice and it gives you the exact same zero-overhead performance as a macro, but with full C++ type-safety and debugging support.

