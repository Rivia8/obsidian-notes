29-03-2026 20:58

Tags: [[C++]]

To create or make something generic, we use the `template` keyword. We tell the compiler that we will be giving it a placeholder type and that you'll tell the real type later. 
By convention we normally make this placeholder type `T` for type.

```C++
template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
```

- `template <typename T>` this part declares that function is generic, you *could* also do `template <class T>`.
- `T` acts as a blank variable for the data type itself.

```C++
int x = 5, y = 10;
swap<int>(x, y;

std::string s1 = "hello", s2 = "world".;
swap<std::strin>(s1, s2);
```


# Template Classes

Templates aren't just for functions, they are heavily used for classes too especially with data structures. If you want to build a `Box` that can hold any type of item, you make the whole class a template.

Similarly to how you use the [[templates|template]] keyword for functions you do the same thing with classes:

```C++
#include <string>
#include <iostream>

template <typename T>
class Box {
private:
    T contents;
public:
    Box(T item) : contents(item) {} // Constructor using initialization list!
    
    T getContents() {
        return contents;
    }
};

int main() {
    Box<int> intBox(42);
    Box<std::string> stringBox("Treasure");

   std::cout << "hello";
}
```


# Template Functions

A generic function utilises the [[Templates|template]] keyword to introduce its *own* generic type variable right above its definition. The compiler generates a new version of the function for *every* data type you pass into it.

```C++
template <typename T>
T findMax(T a T b){
	return (a > b) ? a : b;
}

int main() {
	findMax<int>(5, 10); // Generates an int version
	findMax<float>(5.5f, 2.1f); // Generates a float version
}
```

## Template Alias

We use **Template Type Alias** in order to shorten long-winded template names.

This is done utilising the `using` keyword. This lets you create a generic "nickname" for a complex type.