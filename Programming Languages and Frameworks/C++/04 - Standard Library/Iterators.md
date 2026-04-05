02-04-2026 17:05

Tags: [[C++]]


![[Pasted image 20260405202607.png#invert|500]]

Iterators are considered a "crucial glue" within the C++ standard library.

## What is an Iterator?

(Conceptually) They are generalised pointers.

While a traditional [[Pointers|C Pointer]] points to a raw memory location, an iterator is a smart C++ object designed to act exactly like a pointer but safely within the bounds of a specific container.

Since they mimic pointers, they share the same semantics:
- Accessing data you deference them using `*` or `->`
- To move around you step forward or backward using `++` and `--`
- Some iterators (like those for vectors) allow pointer arithmetic, `+` and `-`

C++ achieves this illusion by using operator overloading, it defines exactly what `++` means for a contiguous array versus a scattered linked list. This is abstracted away so you can write **generic** code that works across all containers without worrying about their internal memory layout.

## Boundaries

To traverse [[Containers]], you need to know where it starts and ends, iterators define this standard using two standard methods:

- `begin()`: An iterator that points to the very first element in the container
- `end()`: An iterator pointing to the memory space *just* past the last element
	- Its important to remember that `end()` does **not** point to the final item, but rather points just past the last element. With this, we do `it != last` rather than `it <= last`.


## The Evolution of the Loop

- Originally you had to explicitly type out the long type name every time: `std::vecotr<int>::iterator it = c1.begin()`
- `Auto` was introduced in C++11. Since the compiler already knows what `c1.begin()` returns, you can let it deduce the type by simply writing `auto it = c1.begin()`.
- In modern C++, standard traversal is done through syntactic sugar that hides the iterators entirely which is similar to Java or Python, you can just write `for (auto& elem : c1)`

## C++20 Ranges

This is a modern 'upgrade'
Instead of passing two separate iterators(`begin` and `end`) into an algorithm to define a target block of data, a Range combines them into one thing.
Instead of writing: `find(c1.begin(), c1.end(), 0)` you can simply pass the entire container directly: `find(c1, 0)`.

# Why do we use Iterators over c\[] like a Normal Array

if you have a `std::vector`, you can have standard index loop.
**But** the solution with iterators works with **any** of the containers, so it works with `std::set` or `std::list`.
This is because `std::vector` has elements stored contiguously in memory, but other containers, like `std::set` or `std::list`  use different implementations, they use linked lists and binary trees respectively and so 