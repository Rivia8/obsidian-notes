10-02-2026 13:07

Tags: [[C++]]

# Inheritance

Inheritance makes OOP much more powerful.

Look at these pieces of code:

```C++
#include “point.h”
class Shape{
private:
	int id;
	char* name;
	Point* points;
public:
	Shape(Point* points, int npoints);
	Shape(Point* points, int npoints, char* name);
	~Shape();
	void setName(char *name);
	char* getName() {return name;}
};
```


```C++
#include “point.h”
class Circle{
	private:
	int id;
	char* name;
	Point point;
	double r;

public:
	Circle(Point point, double r);
	Circle(Point point, double r, char* name);
	~Circle() {delete[] name;}
	void setName(char *name);
	char* getName() {return name;}
	double getArea();
	Point getCentre() {return point};
};
```

```C++
#include “point.h”
class Rectangle{
private:
	int id;
	char* name;
	Point points[4];
public:
	Rectangle(Point* points);
	Rectangle(Point* points, char* name);
	~Rectangle() {delete[] name;}
	void setName(char *name);
	char* getName() {return name;}
	double getArea();
	Point getCentre();
};
```

You can setup inheritance for these classes above to look like the following:

![[Pasted image 20260210131337.png#invert]]

You can see that the `class Circle` inherits the parent class `Shape` through the colon: `class childname : parentname`.

## Inheritance Quirks in C++

1. The child class will always call the base class's constructor, implicitly or explicitly.

2. The 'Diamond Problem' - also known as **Multiple Inheritance**

This is the most famous quirk. Unlike Java and C#, C++ allows a class to inherit from multiple **parents** at the same time.

If you have two classes, `B` and `C`, that inherit from `A` and then a final class `D` that inherits from *both* `B` and `C` you get a diamond shape.

This means that class `D` now contains two copies of Class `A` (one from `B` and one from `C`).

To fix this you use `virtual` keyword.

3. Object Slicing

In C++ objects are values (not references).
Assigning, a derived object to a base variable causes the compiler to 'slice off' the derived parts to make it fit into a smaller base variable.

4. Non-Virtual Destructor Trap

If you delete a `Derived` object through a `Base*` pointer, and the Base Destructor is not `virtual`, the  `Derived` destructor will never run.

5. Private inheritance

Inheritance implies an "Is-A" relationship (A Car **is a** Vehicle) but you also can inherit privately (using the `private` keyword) which changes the meaning to "implemented-in-terms-of" (**Has A**).

You are able to do **Composition** (holding a variable) but with the ability to override virtual functions.

6. Name Hiding (Not overriding)

In C++, scopes do not mix. Functions in a derived class hide all functions with the same name in the base class, *even if the parameters are different*.
