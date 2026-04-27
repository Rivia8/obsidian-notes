20-04-2026 17:55

Tags: [[Haskell]]

Haskell *does* have a way of throwing a hard, program-crashing exception. It is a function simply called `error`.

```Haskell
unsafeDivide :: Float -> Float -> Float
unsafeDivide _ 0 = error "Fatal: Divide by Zero"
unsafeDivide x y = x / y
```

Using `error` is considered bad practice in **functional programming**. You only use it for absolute catastrophic failures where the program has reached an impossible state and has to die.
For standard control flow (like bad user input, missing files or empty lists) you should always return `Maybe` or `Either`.

## Maybe

This is used when a function *might* fail, the reason for the failure is so obvious that you don't need to attach a specific error message.

```Haskell
data Maybe a = Nothing | Just a
```

Here is an example of safe division:

```Haskell
safeDivide :: Float -> Float -> Maybe Float
safeDivide _ 0 = Nothing -- Failure Case
safeDivide x y = Just (x/y) -- Success case
```

The caller has to unpack it using **pattern matching**:

```Haskell
printResult :: Maybe Float -> String
printResult Nothing  = "Error: You tried to divide by zero!"
printResult (Just val) = "The answer is: " ++ show val
```

## Either

Sometimes "nothing" isn't enough information. If a function is trying to do something and *fails* but you want to know what exactly fails, you use the `Either` keyword.

```Haskell
data Either a b = Left a | Right b
```

- **`Right b`**: By convention, `Right` is used for the **correct/successful** result (since "right" means correct).
- **`Left a`**: By convention, `Left` is used for the **error**

Here is an example of a validation function:

```Haskell
validateAge :: Int -> Either String Int
validateAge 
	| age < 0 = Left "Error: Age cannot be negative"
	| age > 30 = Left "Error: Age is unrealistically high"
	| otherwise = Right age
```

As with `Maybe`, with `Either` you have to unpack it using pattern matching:

```Haskell
processAge :: Either String Int -> String
processAge (Left errorMsg) = "Registration failed - " ++ errorMsg
processAge (Right validAge) = "Successfully registered user with age " ++ show validAge
```

## The `Bottom` Value

In theoretical computer science, we need a way to describe a computation that never successfully finishes. This is called **Bottom**.

```Haskell
bottom = bottom
```


## Strict vs Non-Strict Functions

```Haskell
eInt :: Int
eInt = error "Hang on.."

f x = x + 3
```

If you ran `f eInt` the program will crash. This makes this **strict** since Haskell is physically forced to figure out what `x` is.

```Haskell
g x = 5
```

If you ran `g eInt` or `g bottom`, it prints out 5 and does not crash. The reason for this is because Haskell is **lazy**, it looks at the function definition and see that it just returns 5 and so it never actually needs to know what `x` is.

## Multiplication Quirk

Multiplying anything by zero is zero. So `0 * eInt` should be `0` since it doesn't need to evaluate `eInt`. 
But it ***does*** crash, this is because primitive instructions like `*` are strict in *both* arguments. The hardware multiplication instruction requires two actual numbers to be loaded into the processors registers, so Haskell is forced to evaluation the `eInt` to try and get a number, triggering the crash.

