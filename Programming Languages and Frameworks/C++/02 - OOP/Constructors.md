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

There is a better way to initialise object and this is through an initialisation list.


