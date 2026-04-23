22-04-2026 11:14

Tags: [[Haskell]]

Haskell doesn't calculate the value of a variable *until* the exact moment you look at it (lazy evaluation). This means that you can mathematically define a list that goes on *forever*.  As long as you only ever look at a finite piece of it, the program will run perfectly without crashing or running out of memory.

## Lists: Spine vs Components

A list in Haskell is a recursive structure:

```Haskell
data MyIntList = Emp | Cons Int (MyIntList)
```

```Haskell
v1 = Cons 10 (Const eInt Emp)

v2 = Const 11 (error "Hi!")
```

`v1` is an 'intact box' that contains 10 that points to another box that contains an error throwing variable.
`v2` is similar but instead of a variable that contains an error it *is* an error - the spine itself is an error.

```Haskell
myhead :: MyIntList -> Maybe Int
myhead Emp = Nothing
myhead (Cons x xs) = Just x
```

`myHead` only needs to open the first box to get the first number. It can survive both `v1` and `v2` because the first box is perfectly fine in both cases. It is **non-strict in the tail**.

`mylen` needs to walk down the chain of boxes to count them. It doesn't care what is _inside_ the boxes. It survives `v1` (countin

g 2 boxes and ignoring the error inside the second one). It crashes on `v2` because it tries to follow the chain and hits the error instead of a box. It is **strict in the spine, non-strict in the components**.

## Using `take`

The built-in function `take n` grabs the first `n` elements of a list and throws the rest away.

```Haskell
take 2 (1 : 2 : error "hi!")
```

Because of lazy evaluation, `take 2` only opens the first two 'boxes' so it gets `1` and `2` and stops.

### Infinite Lists

Since `take` doesn't care what happens after it stops counting you can give it a list that never ends:

```Haskell
ones = 1 : ones
```


In C++ a recursive definition like this would cause a Stack Overflow or an infinite loop crashing the computer. In Haskell, it just creates a 'recipe'.
It says: "if anyone asks, I am a 1, followed by another one of me", if you run `take 5 ones` Haskell follows the recipe exactly 5 times and then stops, printing `[1, 1, 1, 1, 1]`.

#### Real World Powers

You can define algorithms like the Sieve of Eratosthenes

- Start with an infinite list of numbers from 2 onwards: `[2, 3, 4, 5, 6, 7...]`
    
- The first number (`2`) is prime. Keep it.
    
- Filter out every multiple of `2` from the rest of the infinite list.
    
- The new first number (`3`) is prime. Keep it.
    
- Filter out every multiple of `3` from the rest of the list.

Here is a piece of Haskell that solves it:

```Haskell
sieve (x:xs) = x : [v | v <- xs, v `mod` x /= 0]
primes = sieve [2..]
```

When you run `take 10 primes` Haskell lazily turns the gears of this infinite sieve just enough to spit out the first 10 primes and then halts the math.