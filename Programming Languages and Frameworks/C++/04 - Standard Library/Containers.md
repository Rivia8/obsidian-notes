02-04-2026 17:05

Tags: [[C++]]

In the C++ Standard Library, a container is **a collection of data organised int a specific standard structure.**

They are built using [[Templates#Template Classes|Templated Classes]] which means you can pass the data type you want to store as a template parameter, ensuring that all the elements inside that specific container share the exact same type.

Different containers have different underlying implementation and trade-offs regarding memory and speed.

The library divides the containers into three main functional categories.

![[Pasted image 20260405134342.png#invert]]

# Sequence Containers

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

## Compared to C?

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

# Associative Containers

Can either be **ordered** or **unordered**. 

- For **ordered** elements have to be comparable, so they are kept in some order, like a **search tree**.
- For **unordered** elements have to be hashable, they are kept in a hashmap. They are faster but needs more space.

