04-03-2026 14:01

Tags: [[Haskell]]

Pattern Matching or **defining by shape** is how Haskell allows you to define the *same* function multiple times, specifying different behaviours depending on the exact value or "shape" of the input.

The compiler reads functions from top to bottom.

This can be though of to be similar to that of **polymorphism** in other programming langauges.

```Haskell
isZero :: Int -> Bool

isZero 0 = True
isZero n = False
```







