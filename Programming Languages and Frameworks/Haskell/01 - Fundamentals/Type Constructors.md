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
- `Maybe` is the type constructor.
- `Maybe` itself isn't a concrete type but is rather a function *for* types. It takes a type variable `a` as an argument and spits out a concrete type.

`Nothing | Just a`
- This side lives in the value level that was discussed before.
- These are the actual functions that are used to build the data in memory. The `|` means or.
- `Just` is a data constructor that takes exactly one argument of type `a`.


### Types with Multiple Fields

This is similar to structs, if a type only has one way to be built, the Type Constructor and the Data Constructor are given the exact same name. This is done by convention and they are **different** things:

```Haskell
data Person = Person String Int

-- Type level, tells that the function takes a Person and returns a String
getName :: Person -> String

-- Value level, pattern match on the data constructor to extract the name 
getName (Person name age) = name

alice :: Person
alice = Person "Alice" 20
```

Looking at the constructor, `data Person = Person String Int`, the `Person` on the left is the Type Constructor and the `Person` on the right is the data constructor.

### Recursion

Algebraic datatypes can incorporate **recursion.** 
Since Haskell is like mathematics we can incorporate recursion quite nicely.

```Haskell
data MyList a = Empty | Append a (MyList a)
```

- `Append` is a data constructor that takes two arguments `a` and `MyList a`

Haskell sees the following as the same thing:

```Haskell
sugarList = [1,2,3]
realList = 1 : 2 : 3 : []
```

## Haskell's List Type

Haskell has its own List already predefined.

```Haskell

myIntHead :: [Int] -> Maybe Int
myIntHead [] = Nothing
myIntHead x xs

```