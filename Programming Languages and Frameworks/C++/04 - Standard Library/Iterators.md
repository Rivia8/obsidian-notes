02-04-2026 17:05

Tags: [[C++]]


![[Pasted image 20260405202607.png#invert|500]]

Iterators are considered a "crucial glue" within the C++ standard library.

## What is an Iterator?

(Conceptually) They are generalised pointers.

While a traditional C-pointer points to a raw memory location, an iterator is a smart C++ object designed to act exactly like a pointer but safely within the bounds of a specific container.

Since they mimic s