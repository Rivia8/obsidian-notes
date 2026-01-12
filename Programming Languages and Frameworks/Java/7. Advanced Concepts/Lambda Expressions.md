26-05-2025 12:07

Tags: [[Java]]

# Lambda Expressions

**Before** lambda expressions were a thing, if you wanted to pass a piece of behaviour as an argument to another method, you had to:

- Define an [[Interfaces|interface]] with a single abstract method,
- Create a separate anonymous inner class that implements that interface and provides the implementation for the abstract method,
- Instantiate that anonymous inner class and pass it around.

But we **now** use lambda expressions in order to solve this problem:
Syntax:

```Java
(parameters) -> { body }
```

- `parameters`: The input parameters required by the abstract method of the functional interface.
- `->`: The "arrow" operator, which separates the parameters from the body.
- `body`: The implementation of the method. This can be a single expression or a block of statements.

So pretty much lambda expressions can be used to send a block of code to any method that expects a **functional interface** as a parameter, where a **functional interface** is an interface that contains only ***one*** abstract method.

The way lambda expressions work is by passing **functional interfaces** as a parameter.