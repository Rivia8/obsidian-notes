07-03-2026 22:33

Tags: [[Haskell]]

Haskell is both **statically** and **strongly** typed. 

# Types

Declaring a type is quite simple:

```Haskell
f :: Int -> Int
fx = x + 1
```

If we explicitly declare that input of the function is something else, it would cause an error:

```Haskell
main = print(f(10::Double))
-- Error, since 'f' is expecting an Int and not a Double
```


## Primitives
### Int, Integer and Integral

We have seen that we have `Int` and `Double` in Haskell but since it's a more mathematical language, we also have **Integer** and **Integral**.

**Int** is a type that represents 64 bits (depends on the machine) of signed Integers.'

**Integer** is a type of arbitrary precision integers, it has no upper and lower bound.

**Integral** is a type class whose instances are integer types.

### Bool

Represents boolean logic. The values are `True` and `False`.

### Char

A single Unicode character, denoted by a single quotes (e.g., 'a', 'b')

## Collections

Unlike C++ where you have things like `std::vector`, `std::array` and `std::list`, Haskell relies heavily on two fundamental collection types.

### Lists

A list is a collection of items that must be of all the same type - ***homogenous***. 
*Syntax*: `[1, 2, 3]` or `['a', 'b', 'c']`

Haskell here relies on a singly-linked list, not a contiguous arrays. What this means is that adding to the front of a list is an instant $O(1)$ but getting the 100th element requires walking through the first 99 elements, $O(n)$.

A list of integers is written as `[Int]`

### Tuples

A tuple is a collection of items that can be different types - ***Heterogenous***. But it has a fixed size.
*Syntax*: `(5, "Hello)` or `('A'. True, 3.14)`

They are perfect for returning multiple values from a function without needing to define a custom `struct` or `class`.

A tuple holding an integer and a boolean is written as `(Int, Bool)`

## Strings

This is just a **Type Synonym** for a list of characters: `[Char]`.

`"Hello"` is translated by the compiler into `['H', 'e', 'l', 'l', 'o']`

## Nothing Type

In Haskell, every function has to return something, a value must be returned. If there is no meaningful data to return (usually when doing IO like printing to the screen), it returns the Unit type, written as `()`.

It is a tuple with zero elements and it has exactly one value which is also written as `()`.