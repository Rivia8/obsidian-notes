17-04-2026 15:04

Tags: [[C++]]

![[Pasted image 20260417150438.png]]

# `if` / `switch` / `range-for` Initialisation

C++17 Features

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

C++17 Features

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

So instead of secretly modifying a reference, you should **explicitly** return a `std::pair`

```C++
#include <utility> // Where pair actually lives

std::pair<int, int> f1() {
    int val1 = 5;
    int val2 = 10;
    
    // You can use std::make_pair, but modern C++ allows you to 
    // just return a braced list, and it will figure it out!
    return {val1, val2}; 
}
```

This aligns with the C++ Core Guideline F.21 mentioned.

# Structured Bindings

C++17 Features

Accessing a data inside the pair used to be tedious. You had to use `.first` and `.second`.

```C++
std::pair<int, int> result = f1();
int x = result.first;
int y = result.second;
```

C++17 Introduced **Structured Bindings**.
It allowed to unpack a tuple, pair or struct directly into variables using square brackets `[]`.

```C++
// The auto keyword automatically figures out the types.
// The brackets [] unpack the pair into two brand new variables: ret1 and ret2.
auto [ret1, ret2] = f1();
```

