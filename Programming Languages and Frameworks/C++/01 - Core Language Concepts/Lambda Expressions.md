09-04-2026 09:33

Tags: [[C++]]

You use these to pass functions into algorithms easily.

A lambda is a function without a name that you write directly inside the line of code.

Here is the anatomy of the C++ lambda:

```C++
[captures](parameters) -> return_type { body }
```

The capture clause is unique to C++, because lambdas are defined *inside* other functions, they don't automatically know about the local variables around them.
The `{ body }` is the actual code to execute.




