17-04-2026 15:04

Tags: [[C++]]

![[Pasted image 20260417150438.png]]

# `if` / `switch` / `range-for` Initialisation

Common annoyance in C++ is variable leakage. 
You often call a function just to check its status (like a `retcode`) and you only care about this variable during the `if` statement but historically it "leaked" into the rest of your function.


1. Leaky Way:

```C++
retcode c = bar();
if (c != SUCCESS) { return c; }
// 'c' is still alive down here, cluttering memory and the namespace!
```

2. Ugly Scope Block

```C++
{
    retcode c = bar();
    if (c != SUCCESS) { return c; }
} // 'c' is destroyed here.
```

Programmers used kinda useless curly braces around the code to force `c` to die.

3.  The Modern C++17 way.

```C++
if (retcode c = bar(); c != SUCCESS) {
    return c;
}
// 'c' does not exist here! The compiler will throw an error if you try to use it.
```

C++17 Declared the ability to declare a variable *inside* the `if` statement's condition, separated by a semicolon.

This same syntax can be used in `switch` statements and `range-for` loops to keep local environments clean.

# Returning Multiple Values

C and C++ were originally designed so that a function can only return **one** value.

If you needed a function to calculate and output two different integers, you had to use **"Out Parameters"**. You would pass a variable by reference (`&`) so the function could modify it.

```C++
// Returns val1, but secretly modifies other_val
int f1(int& other_val) {
    int val1, val2;
    // ... math ...
    other_val = val2; 
    return val1;
}
```

This is bad since it has unclear expectations and no agreed convention (programmers won't know whether a function will read or overwrite the variable).

The fix is to use `std::pair` and `std::tuple`.
Modern C++ bundles the data together.

- `std::pair<Type1, Type2>`: A simple container that holds exactly two values, they don't have to be the same type (e.g. `std::pair<int, std::string>)`.
- `std::tupler<Type1, Type2, ...>`: This is `pair`s big brother. It can hold as many elements as you want.

