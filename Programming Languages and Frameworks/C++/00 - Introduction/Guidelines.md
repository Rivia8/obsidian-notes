17-04-2026 16:13

Tags: [[C++]]


The C++ Core Guidelines are a collaborative, living document created by the founders of C++ to help developers write modern safe code.

## Automated Enforcment

The C++ core guidelines are vast so help is needed to enforce them.

**Linters** and static analysis tools come in.

### Clang-Tidy

`clang-tidy` is a popular command-line tool that rads your code and flags violations automatically.

It catches things like using raw C-style arrays instead of `std::array`, using magic numbers and leaving global variables non-const.

Furthermore `clang-tidy` isn't just one check it has a suite of tests for a variety of things:

- `modernize`: Tells you when you can replace old code with new C++11/14/17 features.
- `bugprone`: Spots patterns that usually lead to crashes.
- `performance`: Flags slow code (like accidental deep copies






