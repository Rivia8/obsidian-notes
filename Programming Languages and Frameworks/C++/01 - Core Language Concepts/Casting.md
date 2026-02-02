02-02-2026 11:44

Tags: [[C++]]

# Casting

In C++ there are different ways to cast with different casting operators.

Casting is converting a variable from one data type to another.


1. `static_cast`

This is the standard casting which is the most prevalent. It is used for compile-time checks of standard conversions.

- Used for `int` to `float`, `char` to `int` or pointer conversions *where the inheritance hierarchy is known*.
- It ensures that types are compatible and **will fail** if you try to cast two totally unrelated pointers.

```C++
double pi = 3.14159
int i = static_cast<int>(pi);
```

2. `dynamic_cast`

This is the 'Safe Inheritance Cast'

This is a unique C++ feature and only works with **polymorphism** (classes with virtual functions). This checks at **runtime** if the cast is valid.

```C++
class Base { virtual void func() {} };
class Derived : public Base { };

Base* basePtr = new Base();
// This returns nullptr because basePtr is NOT actually a Derived object
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

if (derivedPtr) {
    // Safe to use
}
```

3. `const_cast` 

This is the only cast that can remove the `const` property from a variable.

```C++
void printLegacy(char* str); // Old function, forgot 'const'

const char* myText = "Hello";
printLegacy(const_cast<char*>(myText)); // Temporarily strips const
```

4. `reinterpret_cast`

This is the most dangerous cast.

- This is used for low-level systems programming, hardware access or converting integers to pointers.
- This has zero safety checks and is just a bit-reinterpretation.

```C++
int a = 65;
// Treats the memory address of 'a' as a char pointer
char* ptr = reinterpret_cast<char*>(&a);
```


**Summary:**

| **Cast Type**      | **Checked When?** | **Purpose**                     | **C Equivalent**  |
| ------------------ | ----------------- | ------------------------------- | ----------------- |
| `static_cast`      | Compile Time      | Converting compatible types.    | `(int)x` (mostly) |
| `dynamic_cast`     | **Run Time**      | Safe navigation of inheritance. | None              |
| `const_cast`       | Compile Time      | Removing `const`.               | `(char*)constStr` |
| `reinterpret_cast` | Compile Time      | Re-labeling bits (Unsafe).      | `(int*)ptr`       |