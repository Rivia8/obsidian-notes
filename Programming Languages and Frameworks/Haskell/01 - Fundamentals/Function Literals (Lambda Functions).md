04-03-2026 14:44

Tags: [[Haskell]]



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

Another example is with the higher-order function `filter` alongside lambda to keep only the numbers greater than 10:

```Haskell
bigNumbers = filter (\x -> x > 10) [5, 12, 8, 20]
-- Result: [12, 10]
```
