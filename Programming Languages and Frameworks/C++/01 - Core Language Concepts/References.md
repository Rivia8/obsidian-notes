02-02-2026 10:48

Tags: [[C++]]

# References

A reference is an alias. This feature doesn't exist in **C**. With references you are not creating a new variable (are not declaring an area in memory) you instead create a new handle for an existing variable.

```C++
int main() {
    int a = 10;
    int& ref = a; // 'ref' is now a reference (alias) to 'a'

    ref = 20;     // Changing 'ref' changes 'a'
    // 'a' is now 20
}
```

One of the distinguishing features about references is that it **cannot** reference `NULL`. This makes it safe and easy since you don't have to check for it.

| **Feature**        | **C Pointers**                        | **C++ References**                                    |
| ------------------ | ------------------------------------- | ----------------------------------------------------- |
| **Declaration**    | `int* ptr = &a;`                      | `int& ref = a;`                                       |
| **Dereferencing**  | Must use `*ptr` to get value.         | Used like a normal variable (`ref`).                  |
| **Nullability**    | Can be `NULL` (dangerous!).           | Cannot be null. Must refer to an object.              |
| **Reassignment**   | Can point to different variables.     | Cannot be reseated (always points to the same thing). |
| **Initialization** | Can be declared without initializing. | **Must** be initialized when declared.                |


## Pass to Functions

This the most common use case. In C, you have to deal with addresses and dereferencing which is tedious and awkward:

```C
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
// Called as: swap(&a, &b);
```

In C++ you can swap by Reference:

```C++
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
// Called as: swap(a, b);
```

## Passing Large Structures

Pass by Reference is very good at doing this.

If you have a very large object:

```C++
struct Image {
	int pixels{1000000}; // 4 MB of data
};
```


If you pass this 'by value' the CPU will have to pause the program, allocate a new 4 MB of memory and copy every single pixel **one by one** into the function.

"The Slow way:"
```C
//The Slow Way (Pass-by-Value)
void processImage(Image img) { 
    // 'img' is a brand new 4MB clone.
    // We wasted time copying it just to look at it.
}
```

Instead, you could reference to avoid the copy. This is a risk where you could change the original copy but we can avoid that by using the `const` modifier:

```C++
void processImage(const Image& img) {
    // 1. No Copy: 'img' is just an alias (fast!)
    // 2. Safe: 'const' prevents us from changing the pixels.
    
    // int x = img.pixels[0]; // Allowed (Reading)
    // img.pixels[0] = 255;   // ERROR! Compiler stops you.
}
```