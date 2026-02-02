31-01-2026 07:25

Tags: [[C++]]

# What is C++

C is at the core of C++. 

There are 3 evolutionary stages on top of C:

1. Started at C with just classes in the 80s,
2. We then had templates and template library in the 90s (C++98 standard),
3. And then in 2011 (C++11) it incorporated things like compile-time evaluation and other functionalities. Many people think this as pivotal moment for the language.

C++ has a unique philosophy that makes it special for certain things.
- It firstly tries to be *pragmatic* - you choose the best approach that fits the problem bets.
- Its fast, it has zero-cost abstractions. If you don't use any abstractions, it is as fast as C.
- Statically checked so unfortunately allows misuse.
- **RAII** (Resource Acquisition Is Initialisation), philosophy that efficiently handles resources.

It does have some drawbacks, its quite complex and it has the possibility of being extremely dangerous. It has no garbage collection.

"A better language trying to get out"