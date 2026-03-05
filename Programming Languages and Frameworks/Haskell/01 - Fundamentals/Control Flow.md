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

For Boolean conditions Haskell utilises Guards: they look like a pip character and act like a much cleaner `if/else if/else` chain:

```Haskell
checkAge :: Int -> String
checkAge age
	| age < 0 = "You havn't been born yet"
	| age < 18 = "You are a minor"
	| age >= 18 = "You are an adult"
	| otherwise = "invalid age"
```

The compiler reads the guards top to bottom and the first condition that evaluates to `True` get its corresponding expression returned.

## `where`

When you use guard expressions you often utilise the same calculated value against several different conditions. 
The `where` clause allows you to calculate that value exactly once.

If you had something like this:

```Haskell
-- The repetitive, inefficient way
bmiTell :: Float -> Float -> String
bmiTell weight height
    | weight / (height ^ 2) <= 18.5 = "Underweight"
    | weight / (height ^ 2) <= 25.0 = "Normal weight"
    | weight / (height ^ 2) <= 30.0 = "Overweight"
    | otherwise                     = "Obese"
```

It could be converted into something like:

```Haskell
-- The clean, functional way
bmiTell :: Float -> Float -> String
bmiTell weight height
    | bmi <= 18.5 = "Underweight"
    | bmi <= 25.0 = "Normal weight"
    | bmi <= 30.0 = "Overweight"
    | otherwise   = "Obese"
    where bmi = weight / (height ^ 2)
```

Where can be used for multiple variables, not just one:

```Haskell
cylinderSurfaceArea :: Float -> Float -> Float
cylinderSurfaceArea radius height = 
    topArea + sideArea
    where 
        piVal    = 3.14159
        topArea  = 2 * piVal * (radius ^ 2)
        sideArea = 2 * piVal * radius * height
```

Another thing to remember is that a `where` binding is strictly **local** to the specific function pattern it is attached to.

```Haskell
greet :: String -> String
-- Pattern 1
greet "Alice" = "Hello Alice! Your secret code is " ++ code
    where code = "xyz123" -- 'code' only exists for Alice

-- Pattern 2
greet name = "Hello " ++ name ++ "!" 
-- You CANNOT use 'code' here. It is out of scope.
```

## `let`

`let ... in` lets you define your variables *first* and *then* use them in the final expression.

```Haskell
cylinderSurfaceArea :: Float -> Float -> Float
cylinderSurfaceArea radius height =
	let piVal = 3.14159
		topArea = 2 * piVal * (radius ^ 2)
		sideArea = 2 * piVal * radius * height
	in topArea + sideArea
```

The syntax is always: `let <bindings> in <expression>`

