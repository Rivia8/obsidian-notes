04-03-2026 14:02

Tags: [[Haskell]]

Haskell has really strong, static typing. The compiler is smart enough to guess the types (type inference), it is considered best practise to write out the **Type Signature** above every function you define.

*It acts as documentation and a strict contract.*

We use the special operator of `::` which translates to "**has the type of**"

```Haskell
-- Greeting has the type of String
greeting :: String
greeting = "Hello World"

-- Square takes an Int and returns an Int
square :: Int -> Int
square n = n * n*

```





