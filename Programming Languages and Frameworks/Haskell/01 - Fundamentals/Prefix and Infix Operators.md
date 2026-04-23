22-04-2026 14:24

Tags: [[Haskell]]

```Haskell
f 0 _ = 0
f x y = x * y
```

There are two ways to apply a function, **Prefix** and **Infix**

## Prefix

**Prefix**: The standard way you write a function in almost all programming languages:

```Haskell
f 0 x
```

## Infix

**Infix**: This is the way we write mathematical operators, the function (operator) sits *in between* its two arguments:

```Haskell
0 + x
```


Haskell has built in syntactic sugar, any function that takes two arguments can be used as an infix operator by wrapping its name in back-ticks (\`\`)

These two are the exact same:

```Haskell
f x y
x `f` y
```


We also have a *reverse* version:

```Haskell
x + y
(+) x y -- these two are the same

f x y
(f) x y -- same here
```

