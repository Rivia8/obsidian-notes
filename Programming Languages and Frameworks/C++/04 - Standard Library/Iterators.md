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
	- Its important to remember tha 