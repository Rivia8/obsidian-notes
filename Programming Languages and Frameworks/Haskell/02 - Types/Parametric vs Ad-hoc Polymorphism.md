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



# Ad-hoc Polymorphism

Often called *"Overloading"*

This is where the same function name could refer to a different function based on the input parameters.





