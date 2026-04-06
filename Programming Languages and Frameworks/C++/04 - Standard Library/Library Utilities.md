06-04-2026 19:13

Tags: [[C++]]

Library Utilities in C++ isn't as big as other languages like Java or Python.

It only adds utilities that are universally needed and are highly optimised.


## `std::string` and `std::string_view`

Text manipulation in C was notoriously dangerous because it relied on raw arrays of characters and manual memory management. C++ solves this with `std::string` and `std::string_view` that are distinct.

### `std::string`

This encapsulates C-Style string into a safe, dynamically resizing container, its very similar to `std::verctor<char>`. 
When you create a `std::string`, it *owns* the data in memory and it comes with many built-in methods.

### `std::string_view`

This was introduced in modern C++, it acts a read-only "handle" that points to existing string data.
Its similar to `std::span`.

The reason for this is that it allows you pass a lightweight pointer and a size integer, which allows you to look at strings incredibly fast without copying them.

## `std-format`

For a very long time, formatting strings in C++ was unsafe by using C-style `printf` or it was really verbose chaining endless `<<` operations.

- Instead of: `std::cout << "Hello " << name << ", your score is " << score << "\n";`
- You can write: `std::cout << std::format("Hello {}, your score is {}\n", name, score);`.

## IO Streams

This is the ecosystem that C++ uses to move data in and out of the program.
There are 3 specific headers that all share the exact same `<<` output and `>>` input interface. 