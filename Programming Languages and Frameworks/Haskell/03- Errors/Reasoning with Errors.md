22-04-2026 10:46

Tags: [[Haskell]]

## Does Order Matter?

$$A + B = B + A$$
If we were to test this with errors:

```Haskell
error "left!" + error "right!"
error "right!" + error "left!"
```

If the compiler reads left-to-right, the first one crashes and prints left, whilst the second prints right. This would break the commutative law of addition since the output changed.

This isn't the case however, in Haskell, if an expression results in an error (or an infinite loop), its "value" isn't a single string like "left!". Its value is the mathematically abstract set of all possible errors that could happen depending on how the compiler decides to evaluate it.
**Theoretically** commutativity still holds.

## Short Circuiting (Deliberately Non-Commutative)

```Haskell
eInt :: Int
eInt = error "Hang on.."

stimes 0 _ = 0
stimes x y = x * y
```

If you run ``0 `stimes` eInt``, the program survives and returns `0`. Due to lazy evaluation, Haskell assigns `eInt` to the wildcard `_` and never actually evaluates it. So the error is completely ignored.

However, if you run ``eInt `stimes` 0`` the program *will* crash. Haskell tries to match the first pattern, which requires checking if the first argument is a `0`. Because the first argument is `eInt`, merely looking at it to check its value triggers the crash.

Unlike standard addition `+` the custom function is **fundamentally non-commutative**. The order of the arguments completely changes the outcome of the program (survival vs crashing).

The standard boolean `&&` (AND) operator works exactly the same way.
- `False && eBool` survives (and returns `False`). Once again Haskell "short-circuits": and skips reading the second argument entirely.
- `eBool && False` **crashes** because Haskell *must* evaluate the first argument right away to see if its True or False.


