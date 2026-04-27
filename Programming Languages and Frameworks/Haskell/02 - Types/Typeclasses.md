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
You do this with `=>`. 



