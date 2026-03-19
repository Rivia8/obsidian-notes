14-03-2026 07:34

Tags: [[Introduction to Haskell]]

In Haskell, the word constructor, is split completely into two different concepts, **Type Constructors** and **Data Constructors.**

There are two concepts that you need to be familiar with: **Types** vs **Values**.
- The Type Level is the universe of blueprints (`Int`, `String`, `Bool`). These only exist at compile-time to ensure that the logic is sound.
- The Value Level is the universe of actual data in memory (`5`, `"Hello"`, `True`), these exist when the program is running.

## Custom Type

To create a custom type, you use the `data` keyword. The most famous type in Haskell: `Maybe`.

```Haskell
data Maybe a = Nothing | Just a
```

`data Maybe a`
- `Maybe` is the type constructor
- `Maybe` itself isn't a concrete type but is rather a function *for* types. It takes a type variable `a` as an argument and spits out a concrete type.

`Nothing | Just a`
- This side lives in the value level that was discussed before
- 



