04-03-2026 14:14

Tags: [[Haskell]]

This is where you pass a function as a parameter of another function.

This can be done since functions are treated as "first-class citizens" just like an `Int` or a `String`, you can pass them around.

```Haskell

-- Here we have defined addConst
addConst :: Int -> Int -> Int
addConst n m = n + m

addThree = addConst 3

-- To output a result
main = print (addConstB 7)
-- prints 10
```

You can write this **explicitly** so that it returns a function

```Haskell
addConstB n = \m -> n

-- To evaluate this:
main = print (addConstB 3 7)
-- results in the same answer as above
```






