27-04-2026 13:05

Tags: [[Haskell]]

This is a functional programming answer to **interfaces** or **method overloading** seen in imperative and OOP languages.

A `class` in Haskell is not on object-orientated class, it is a contract or an interface. It defines a list of function signatures that a type *could* support.

```Haskell
class Descriptive a where
	desribe :: a -> String
```

This says "*To belong to the `Descriptive` club, a type `a` must provide a function called `desctibe` that turns it into a string*".

When it comes to the **implementation**, you can make specific types join the 'club' by writing an `instance`. This is where the ad-hoc "overloading" happens, you write different logic for different types:

```Haskell

instance Descriptive Bool where
	describe False = "Wouldn't bet on it!"
	describe True = "This actually holds!"
	
instance Descrptive Int where
	describe 1 = "The lonliest number"
	desrive _ = "A boring number"
```

`describe True` would bring up the `Bool` instance and `desribe 1` would bring the `Int` instance.

## Type Constraints

With Typeclasses you can write powerful generic functions that only accept types belonging to specific 'clubs'. 
You do this with `=>`, it acts as a filter or constraint on your type variables.

```Haskell
descrLen :: Descriptive a => a -> Int
descrLen x = length (describe x)
```

Usually the compiler wouldn't know whether the generic type `a` has a describe function. The constraint guarantees to the compiler *"I will only ever pass types into this function that have implemented `Descriptive` blueprint"*.

## Conditional Instances

If we want to describe a list of Booleans you need an instance of lists.
A list of functions `[a -> b]` can't be described, we only want to allows lists to be described *if* the items inside them can be described.
Haskell allows you to put a constraint on an instance itself:

```Haskell
instance (Descriptive b) => Descriptive [b] where
	describe [] = "Nothing left!"
	describe (x:xs) = (describe x) ++ ", then" ++ (describe xs)
```

_"**IF** the inner type `b` is Descriptive, **THEN** a list of `[b]` is automatically Descriptive too."_ It then uses recursion to call `describe` on the head (`x`) and the tail (`xs`).

## Custom Operations and Default Implementations

In Haskell, operators like `+`, `*` or `==` are standard functions whose names are made entirely of symbols, to define them you just wrap the symbols in parantheses:

```Haskell
class MyEq a where
	(===) :: a -> a -> Bool
	(/==) :: a -> a -> Bool
	
	-- a default implementation
	x /== y = not(x === y)
```

What's happening is that 'not equal' is just the opposite of equal and so the typeclass is automatically generated for `/==` (you only have to make the `===` Haskell does `/==` for you).

## Multiple Constraints

You aren't limited to one constraint, you can have multiple constraints e.g. if two things are equal AND It needs to print out their descriptions, you list both typeclasses in a tuple before the fat arrow:

```Haskell
ifEqD :: (MyEq a, Descriptive a) => a -> a -> a -> a -> String
ifEqD w x y z = if w === x then (describe y) else (describe z)
```

The compiler will strictly enforce that whatever type `a` is, it must have implemented both `===` and `desribe`.

## Built-in Typeclasses

In Haskell, the `print` function relies on the built-in `Show` typeclass. If a type isn't a member of the `show` 'club', Haskell simply refuses to print it.
You can manually add it:

```Haskell
data Pcolours = R | G | B

instance Show Pcolours where
  show R = "Red"
  show G = "Green"
  show B = "Blue"
```

