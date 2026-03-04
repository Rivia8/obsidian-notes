04-03-2026 14:14

Tags:

This is where you pass a function as a parameter of another function.

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

addConstB =

```




