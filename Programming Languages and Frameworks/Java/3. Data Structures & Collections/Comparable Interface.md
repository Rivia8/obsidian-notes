17-08-2025 12:40

Tags: [[Java]]

# Comparable Interface

The `Comparable` interface is used to define a single, "natural" ordering for objects of a class.
By implementing the interface, you are telling Java how to sort instances of your class by default (like when you use `Collections.sort()`)

You use the `java.util.Comparable()` import.

## The `compareTo` Method

The `Comparable` interface has only one method you need to implement: `compareTo()`. This method compares the current object (`this`) with another object of the same type.

The `compareTo(T otherObject)` method must return an `int` with the following meaning:
- Negative number (-1): `this` object comes before `otherObject`.
- Zero(0): `this` object is equal to `otherObject`.
- Positive number(1): `this` object comes after `otherObject`.

So a class implements `Comparable` to gain a `compareTo()` method.
You do this so you can change the 'default' order the object goes in (this is what is meant by natural ordering). You usually use built-in helper methods like `Integer.compare()` and `String`'s own `compareTo` methods.

You use the `java.util.Collections()` import to get the `sort()` method - its a static method.