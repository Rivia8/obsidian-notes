04-03-2026 14:13

Tags: [[Haskell]]

# `case .. of` Expression

The `case` expression allows [[Pattern Matching]] at the function definition level. The `case` expression allows you to do the exact same pattern matching *anywhere* in the middle of your code.

It evaluates an expression, checks it against a list of patterns from top to bottom and executes the code foe the first pattern that matches

```Haskell
describeList :: [int] -> String
describeList xs = "This List is " ++ case xs of
	[] -> "Empty containing Nothing"
	[x] -> "A singleton list with one item"
	_ -> "a longer list"
```

- \[] Matches an empty list
- \[x] Matches a list with exactly one element
- _ is a the 'wildcard' or a default catch-all (like `default :` in a C++ switch)

# `if ... then .. else` Expression

This is traditional logic, the only difference with Haskell is that the `else` is strictly mandatory (since every expression in Haskell *must* evaluate to a value, you cannot have an `if` without an `else`).

```Haskell
checkNumber :: Int -> String
checkNumber n = 
    if n > 10 
    then "Greater than 10" 
    else "10 or less"
```

# Guards `|`

Pattern matching and `case` is great for checking the shape of data, it isn't great at checking *math* or logic.

For Boolean 