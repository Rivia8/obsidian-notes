04-03-2026 13:44

Tags: [[Haskell]]

# Defining Values

Haskell is an [[Imperative Programming|Imperative Language]] so you define variables that can change. In Haskell, you define **names** bound to **expressions**. Because they can never change and these are called "values" rather than "names".

```Haskell

-- Comment in Haskell

piValue = 3.14519
greeting = "Hello World"
meaningOfLife = 42
```

`meaningOfLife` is defined as 42 and it is 42 forever, and it cannot be overwritten later in the file.

# Defining Functions

This is where syntax can look drastically different, to define a function you write the function name followed by its parameters (separated by spaces) an equal signs and then the body.

```Haskell
-- A function that adds two numbers
add x y = x + y

-- A function that squares a number
square n = n * n
```

In order you would do:

```Haskell
add 5 10
square 4
```

*You don't need parentheses*







