10-04-2026 17:22

Tags: [[C++]]

Deep copies are a problem

Before modern C++, if you had a `std::vector<std::string>` that contained lots of user records and passed it onto a function and modified then returned it. Returning meant allocating a new block of memory and copy all records into a temporary variable within the function and then returning the values into the new variable receiving the result and then finally destroying the temporary vector: massive waste of CPU time and RAM.

## L and R Values

C++ distinguishes between data you want to keep using and temporary data that is about to die anyway.
It does this by categorising expressions into L and R values.

- **L-Value (Locator value)**: is something that occupies a persistent memory address. It has a name, you can use it on the left side of an equal sign:
	- `int x = 5` - `x` is the L value

- **R-Value (Read value):** A temporary value. It has no persistent memory address. It exists for a fleeing moment on the *right* side of an equals sign and then destroyed.
	- `5` is an r-value of the above example

## Stealing Resources

If the compiler knows that a value is an r-value there is no point in copying its details but rather its **pointers**.

This is what **Move Semantics** is.
An empty vector is made, and point its internal memory tracker to the old vector's data. Then the old vector's pointer is set to null.

```C++
std::string source = "Massive String Data...";

// Deep Copy: 'source' keeps its data, 'target1' gets a duplicate.
std::string target1 = source; 

// Move: 'target2' steals the data. 'source' is left empty/valid but unspecified.
std::string target2 = std::move(source);
```






