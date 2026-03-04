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

What we have used above is what is known as a **Function Literal**.

## Function Literals

```Haskell

doubleIt :: Int -> Int
doubleIt x = x * 2

myList = [1,2,3,4]

doubledList = map doubleIt myList
-- Result: [2, 4, 6, 8]
```

In Haskell a function literal is known as a **Lambda** or an **Anonymous Function.**
Its a throwaway function without a name that you can define on the spot.

The way you define it is as follows:

```Haskell
\x -> x * 2

\x y -> x + y
```

The real usage is combining it with functions:

```Haskell
myList = [1, 2, 3, 4]

doubledList = map (\x -> x * 2) myList
```