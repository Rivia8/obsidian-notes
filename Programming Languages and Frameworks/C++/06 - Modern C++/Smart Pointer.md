10-04-2026 18:04

Tags: [[C++]]

In older C++ if you allocated a memory on the heap using `new` , you were responsible for calling `delete` to free it. If you forgot or the program crashed before reaching the `delete` statement, the memory was lost forever (aka a memory leak).

A smart pointer is a template class that wraps around a raw pointer. 
It acts exactly like a normal pointer (you can use `*` and `->`) but it automatically deletes the memory it points to when it goes out of scope.

C++ has three main types of smart pointers.

## Loner `std::unique_ptr<T>`

This is most common and fastest smart pointer.




