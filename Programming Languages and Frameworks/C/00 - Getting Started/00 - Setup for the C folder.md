06-10-2025 12:39

Tags: [[C]]

# 00 - Setup for the C folder

### The Folder Structure

I recommend numbering the main folders to keep them in a logical learning order.

```
📁 C Programming/
├── 00 - Getting Started/
├── 01 - Core Language Concepts/
├── 02 - Memory & Pointers/
├── 03 - Composite Data Types/
├── 04 - The Build Process & I-O/
└── 99 - Code Snippets & Projects/
```

---

### Breakdown of Each Folder

Here’s what you should put inside each folder. Each bullet point can be a separate note (`.md` file).

---

### ## 🗂️ `00 - Getting Started`

This folder is for the initial setup and your very first steps.

- **`Why Learn C.md`**: Your personal goals and key advantages of the language.
    
- **`Setting up a C Compiler (GCC).md`**: How to install and verify your compiler.
    
- **`My First Program (Hello, World).md`**: The code, a line-by-line explanation, and how to compile and run it.
    

---

### ## 🗂️ `01 - Core Language Concepts`

This is for the fundamental building blocks of the C language.

- **`Basic Syntax & Structure.md`**: Note on `main()`, semicolons, comments, and code blocks.
    
- **`Variables & Data Types.md`**: Covers `int`, `char`, `float`, `double`, and qualifiers like `short`, `long`, `unsigned`.
    
- **`Constants & Literals.md`**: How to define unchanging values.
    
- **`Operators.md`**: Notes on arithmetic (`+`, `-`), relational (`==`, `>`), logical (`&&`, `||`), and bitwise (`&`, `|`) operators.
    
- **`Control Flow.md`**: A note covering `if`/`else`, `switch`, `for` loops, `while` loops, `break`, and `continue`.
    
- **`Functions.md`**: How to declare, define, and call functions. Include notes on parameters and return values.
    

---

### ## 🗂️ `02 - Memory & Pointers`

This is the most critical (and often trickiest) part of C. Giving it its own dedicated folder is a good idea.

- **`What is Memory (Stack vs Heap).md`**: A high-level overview.
    
- **`Pointers.md`**: The core note. Explain what a pointer is (an address), how to declare it (`*`), get an address (`&`), and dereference it (`*`).
    
- **`Pointer Arithmetic.md`**: How to perform math on pointers.
    
- **`Arrays.md`**: How to declare arrays and the strong relationship they have with pointers in C.
    
- **`Strings.md`**: Explaining that C strings are just null-terminated character arrays.
    
- **`Dynamic Memory Allocation.md`**: A note on `malloc()`, `calloc()`, and `free()`.
    

---

### ## 🗂️ `03 - Composite Data Types`

For ways to group data into more complex structures.

- **`Structs.md`**: How to create your own custom data types.
    
- **`Enums.md`**: For creating sets of named integer constants.
    
- **`Unions.md`**: A brief note on this less common type.
    

---

### ## 🗂️ `04 - The Build Process & I-O`

How your code becomes a program and interacts with the outside world.

- **`The C Preprocessor.md`**: Explaining `#include` and `#define`.
    
- **`Header vs Source Files (.h vs .c).md`**: How to organise a multi-file project.
    
- **`File I-O.md`**: Notes on `FILE *`, `fopen()`, `fprintf()`, `fscanf()`, and `fclose()`.





