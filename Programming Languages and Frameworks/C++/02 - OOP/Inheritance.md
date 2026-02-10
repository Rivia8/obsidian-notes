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

The base class object is kind of p