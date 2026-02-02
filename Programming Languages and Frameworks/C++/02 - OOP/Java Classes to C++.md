02-02-2026 20:27

Tags: [[C++]] [[Java]]

# Java Classes to C++

Both Java and C++ are OOP giants. 

Java's syntax is actually modelled after C++ to make it familiar to developers. 

Both support:

- Classes and Objects: Both use `class` as a blueprint and instantiate objects

- Encapsulation: Both use `public`, `private` and `protected` to hide data.

- Inheritance: Both allow classes to derive form other classes to reuse code

- Polymorphism: Both allow you to treat a child object as a parent object and override methods.


Here are two examples:

```C++
class Circle{

public:
	double x, y, r;

...

	double getArea() {
		return 3.14 * r * r;
	}
};
```

```Java
class Circle{

	double x, y, r;

	public double getArea() {
		return 3.14 * this.r * this.r;
	}
}
```


## Key Differences

In C++ when you 'create' an object, as in when you do something like `Circle c1;` it creates this object in the stack and once you are outside the function that was used to create the object, the object is deleted. 

In Java, if you were to do the same thing: `Circle c1;`, this just creates an object reference until you do `c1 = new Circle()` which then creates the object in the heap. 

![[Pasted image 20260202204545.png#invert]]

You can actually create objects in C++ using `new` too.

![[Pasted image 20260202205344.png#invert]]

