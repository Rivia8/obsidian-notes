02-04-2026 17:05

Tags: [[C++]]

In the C++ Standard Library, a container is **a collection of data organised int a specific standard structure.**

They are built using [[Templates#Template Classes|Templated Classes]] which means you can pass the data type you want to store as a template parameter, ensuring that all the elements inside that specific container share the exact same type.

Different containers have different underlying implementation and trade-offs regarding memory and speed.

The library divides the containers into three main functional categories.

![[Pasted image 20260405134342.png#invert]]

## Sequence Containers

These store data linearly: one after another. You control exactly where elements are inserted.

```C++
#include <vector>
#include <list>

std::vector<int> data;
std::list<int> data;
```

`std::vector<T>`: This is the most common container. It is a variable-sized array that encapsulates a dynamically allocated heap array.
- It resizes itself automatically and allows for rapid random access

`std::array<T, k>`: A fixed-size array that requires you to specify both the type and the exact size at compile time, it operates as a safe, encapsulated stack array

```C++
#include <array>

std::array<int, 5> arr1; // Size = 5, {0, 0, 0, 0, 0}
std::array<int, 3> arr2{0, 1, 2}; // size = 3

arr2.push_back(6); // Not valid operation
arr1[2] = 1;
arr1.at(4) = 2; // same as arr1[4] = 2;
arr2.at(4) = 0; // exception
```

### Compared to C?

C-arrays are considerably more harmful than C++ arrays:

![[Pasted image 20260405143149.png#invert]]


```C++
#include <vector>
int* v = new int[initial_size]; // BAD: new considered harmful
fn1(v); // BAD: v is now just a pointer, no info about size is passed
delete[] v; // BAD: could leak memory
std::vector w(initial_size);
fn2(w); // w is still a vector, fn2 knows its size
// No delete, w manages its own memory
```

![[Pasted image 20260405143339.png#invert]]

## Associative Containers (Ordered)

These containers **automatically sort your data** as you insert it.

Because the data is kept in a specific order, typically managed by a binary search tree, the elements that are stored within them must be explicitly comparable.

Examples are:
- `std::set` - a collection of unique keys
- `std::map` - a collection of key-value pairs
- `std::multiset`
- `std::multimap`

## Unordered Associative Containers

These use hash maps rather than search trees.

*Because* they rely on hashing, the elements you insert must be "hashable" rather than just comparable.

They provide faster access times than their ordered counterparts but they require more space in memory to operate efficiently.

Examples are:
- `std::unordered_set`
- `std::unorderd_map`


## Common Interface

STL containers are abstracted through a consistent, common interface.
This means that you don't have to memorise a completely different set of functions for every data structure.

Capacity Checks: `empty()`, `size()`, and `max_size()`

Modifiers: `clear()`, `insert()`, `emplace()`, and `erase()`

[[Iterators]]: `begin()`, `end()`, `cbegin()` and `cend()` to traverse data