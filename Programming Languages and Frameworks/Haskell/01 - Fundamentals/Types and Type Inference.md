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

## Int, Integer and Integral

We have seen that we have `Int` and `Double` in Haskell but since it's a more mathematical language, we also have **Integer** and **Integral**.

**Int** is a type that represents 64 bits (depends on the machine) of signed Integers.
**Integer** is a type of arbitrary precision integers, it has no upper and lower bound.
**Integral** is a type class whose instances are integer types.

## Bool





# Type Inference

Haskell's type inference is global and bidirectional, the compiler treats the code like a giant Sudoku puzzle. It looks at how a value is created, but it looks at **how that value is used later on** to deduce the only mathematically possible type.






