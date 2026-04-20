20-04-2026 17:55

Tags: [[Haskell]]

Haskell *does* have a way of throwing a hard, program-crashing exception. It is a function simply called `error`.

```Haskell
unsafeDivide :: Float -> Float -> Float
unsafeDivide _ 0 = error "Fatal: Divide by Zero"
unsafeDivide x y = x / y
```


asadsdas

