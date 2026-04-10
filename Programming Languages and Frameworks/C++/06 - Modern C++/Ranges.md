09-04-2026 09:51

Tags: [[C++]]

Before, if you wanted to sort a vector, you'd have to pass two separate iterators to define the boundaries of the data:

```C++
std::sort(numbers.begin(), numbers.end());
```

A **Range** is a concept that represents an iterable sequence of elements: anything that provides `begin()` and `end()` is considered a range.





