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



