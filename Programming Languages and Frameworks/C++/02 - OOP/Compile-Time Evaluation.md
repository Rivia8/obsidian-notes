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

This generates a massive amount of machine code, due to 