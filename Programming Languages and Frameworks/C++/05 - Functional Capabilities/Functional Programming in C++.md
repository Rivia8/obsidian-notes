06-04-2026 21:51

Tags: [[C++]]

C++ is **not** a functional language, by default it is an **imperative language** where you constantly write step-by-step instructions that constantly change the state of the machine.

[[Declarative Programming#Declarative **Functional** Programming|Functional Programming is a different paradigm]]. In C++ you would have to adopt those philosophies:
- Functions as first-class citizens (treating functions like variables)
- **Immutability** (avoiding changing data after its created, you use `const` heavily)
- **Pure Functions** (functions don't have side effects)

The reason for doing this in C++ is that it makes your code highly **predictable**.

In order to execute this properly you use [[Programming Languages and Frameworks/C++/01 - Core Language Concepts/Lambda Expressions|Lambda Expressions]]. 




