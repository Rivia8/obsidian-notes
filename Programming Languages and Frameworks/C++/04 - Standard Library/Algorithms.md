02-04-2026 17:05

Tags: [[C++]]

Algorithms are the 'processing engine'.

Instead of every container having its own built-in `.find()` or `.sort()` method method, C++ provides over 100 generic algorithms that sit outside the data structure and interact with them *through* their iterators.
Because they rely on a common [[Iterators|iterator interface]] (`begin()` and `end()`), a single algorithm can work on `std::vector` and `std::list` or even a custom container you build.

There are over 100+ algorithms in 12 categories.
- Non-modifying sequence operations
- Modifying sequence operations
- *others*

## Use Case

You can do this yourself in most cases but why use the standard algorithms?

- **Concise code**: it takes one line instead of five
- **Optimised implementation**: The C++ developers have highly optimised the functions under the hood
- **Lower the chance of Error**: Writing fewer loops means making fewer "off-by-one" index errors
- **Clearer intention:** When another programmer reads `std::find`, they instantly know exactly what the lines of code achieve.



