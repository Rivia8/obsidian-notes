27-04-2026 10:09

Tags: [[Haskell]]

# Parametric Polymorphism

This is similar to C++'s generic code using `template <typename T>`. In Haskell, you do the same thing using **type variables** (usually uses lowercase letters like `a`, `b`, `c`)

```Haskell
f :: a -> Bool
f _  = True
```

This is parametric polymorphism since the function `f` takes an argument of type `a` and returns a `Bool`. Because the function never actually looks at the data (it uses the wildcard `_` to ignore it) and just returns `True`, it can accept *any* type.

When you write `f :: a -> Bool`, Haskell implicitly puts an invisible `forall a` at the very front of the signature. It reads as "*for all possible types `a` I can turn it into a `Bool`*"/ 

Looking at another function:

```Haskell
g :: (b -> Bool) -> Bool
g h = (h 7) && (h False)
```

`(b -> Bool)` is a single argument, its saying that the first argument of `g` is a function itself, `h` and `h` will take an input `b` (that can be anything) and will output a boolean.
`-> Bool` after taking `h` as an argument, the main function `g` will return a bool.

`g h = (h 7) && (h False)` is the body of the function, it takes `h 7` and `h False` and `&&` (ands) them together.

Although logically this should work since `b` indicates that the input of `h` can be anything, it will cause a compile error. The reason for this is because of two things:

1. `b` can only be *one* thing. When `h 7` occurs, `b` is an `Int` and when it is called again it is expected for `b` to be an `Int` again and *not* a `Bool`.
2. The *caller* decides `b` not `g`, because `b` is a lowercase letter it means "for all types", it means the ***caller*** of the function, `h` gets to decide what type to pass in.


And another:

```Haskell
p :: (a, a)
p = (1,1)
```

`p :: (a,a)` is a promise that "*I am a pair of absolutely **any** type you want"* but `1,1` is strictly a pair of numbers. If a programmer asks `p` to be a pair of `String` it fails. 
You essentially cannot hard code specific values into a universally quantifiable variable.
# Ad-hoc Polymorphism

Often called *"Overloading"*

This is where the same function name could refer to a different function based on the input parameters.
Ad-Hoc polymorphism is achieved through **Typeclasses**.

```Haskell
length :: [a] -> int -- Parametric

sum :: Num a => [a] -> a -- ad-hoc
```

The `sum` signature uses a specific Typeclass `num` so it knows how to do the math.



