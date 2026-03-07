07-03-2026 22:33

Tags: [[Haskell]]

Haskell is both **statically** and **strongly** typed. 

# Types

Declaring a type is quite simple:

```Haskell
f :: Int -> Int
fx = x + 1


```

# Type Inference

Haskell's type inference is global and bidirectional, the compiler treats the code like a giant Sudoku puzzle. It looks at how a value is created, but it looks at **how that value is used later on** to deduce the only mathematically possible type.






