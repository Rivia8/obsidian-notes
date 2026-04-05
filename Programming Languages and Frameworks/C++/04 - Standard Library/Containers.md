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
#include <map>

std::vector<int> data;
std::list<int> data;

std::map<int, int> translation;
```

`std::vector<T>`: This is the most common container. It is a variable-sized array that encapsulates a dynamically allocated heap array.
- It resizes itself automatically and allows for rapid random access

`std::array<T, k>`: A fixed-size array that requires you to specify both the type and the exact size at compile time, it operates as a safe, encapsulated stack array

