29-03-2026 18:48

Tags: [[C++]]

Generic programming centres around the idea of abstracting from concrete, efficient algorithms to obtain *generic* algorithms that can be combined with different data representations to produce a wide variety of useful software.

An example can be illustrated as follows, if you want to write a simple function that swaps the value of two variables, without generic programming, you have to write a new version of the function for every single data type.

Here we can see that if we would like to swap the value for an `int` we have to declare it and then we have to do the same for the `string`.
```C++
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swapString (std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}
```

![[Pasted image 20260329205810.png#invert]]

To make this generic we use [[Templates]]

# Generic Classes

Templates aren't just for functions, they are heavily used for classes too especially with data structures. If you want to build a `Box` that can hold any type of item, you make the whole class a template.