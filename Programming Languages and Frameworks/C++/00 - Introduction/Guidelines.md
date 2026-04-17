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

## Style Guides

**Style Guides** are about **consistency**.

They are heavily restrictive and sometimes make arbitrary choices (like always use 2 spaces for indentation or class names must start with a capital letter).

Large organisations use them so that code written by thousands of different engineers all look it was written by one person. **Google C++ Style Guide** and **Bloomberg's standards** as prime examples.

## Professional Ecosystem

Writing good C++ means utilising the surrounding ecosystem of tools. Even with modern C++ the classic C tools are still very relevant.

- **Memory Checkers:** tools like **Valgrind** and **Sanitizers** run your code and watch for memory leaks or accessing arrays out of bounds

- **Unit Testing:** Professional C++ relies heavily on testing frameworks like **Google Test (GTest)**, **Boost.Test** and **Catch2** to verify that individual functions behave correctly.




