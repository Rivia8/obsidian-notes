02-02-2026 21:12

Tags: [[C++]]

# Constructors

Like in Java the constructor is a special method. 

The name is its class name, it doesn't have a return type or value and its called automatically when we create the object.

We use the `this` keyword to prevent ambiguity when assigning variables within the constructor.

```C++
public:
	Circle(double x, double y, double r) {
		
		this->x = x;
		this->y = y;
		this->r = r;
	
	}
```

There is a **better way** to initialise object and this is through an initialisation list.
This gives values to member variables before the object is "officially created".
It has less boilerplate and can initialise const, refs and the base class.

```C++
...
public:
	Circle(double x, double y, double r):
		x{x}, y{x}, r{r} {};
```

Using an initialisation list is faster and technically better since the compiler has less work to do. With the initialisation list, the compiler calls the copy constructor directly, it builds the object with its fields immediately and needs to temporary object. Without it, the compiler will need to call the default constructor for the class but then once the assignment operator runs it allocates *new* memory and copies `n` into it.
