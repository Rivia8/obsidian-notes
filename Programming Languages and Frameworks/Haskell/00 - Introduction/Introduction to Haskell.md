28-02-2026 22:09

Tags: [[Haskell]]

Haskell involves the deep end of functional programming.

It is quite different from languages like C++, Haskell is **purely functional**, **statically typed** and a **lazy** programming language.
You define things through the use of mathematical expressions ([[Declarative Programming]])

In other programming languages, variables are **mutable** which means that you can *mutate* the state of `x` in memory. However, in Haskell, variables are **immutable**. Once `x` is 5, it is 5 forever.
There are also no `for` loops or `whilke` loops because those require a **counter variable** that changes state. Instead **recursion** is used and high-order functions.

Example:

```C++
std::vector<int> numbers = {1, 2, 3, 4, 5};
for (int i = 0; i < numbers.size(); i++) {
    numbers[i] = numbers[i] * 2; // Mutating state step-by-step
}
```

```Haskell
numbers = [1, 2, 3, 4, 5]
doubledNumbers = map (*2) numbers
```

The goal of functional programming is to:

- Treat functions like any other data


- Reason about them like mathematical functions
	 if $f(x) = g(x)$ for all $x$ then $f = g$

	 let $x = f10$ and in $x + x + x = f10 + f10 + f10$, in a regular programming language, there will be differences with how its executed and changes with execution order, whether they are being copied etc. But in functional programming we want the above statement to be true **as much as possible.**



