11-02-2025 18:23

Tags: [[Java]]

# Classes

Now from looking at classes briefly in [[Object-Orientated Programming]] and in [[Objects]], we know that classes consist of:
- A set of **attributes**
- A set of **methods**

When designing a class it can be useful to start off by using a diagrammatic notation - the usual way it is done is by using the **UML - Unified Modelling Language**.

## UML Notation

In this notation it simply suggests that we represent a class with a box that is divided into three sections:

1. Provides the name of the class
2. Lists the attributes the class
3. Lists the methods of the class

![[Pasted image 20250211183148.png#invert]]
The minus signs illustrate a **private** method/attribute where a positive sign means **public**.
This achieves something called encapsulation.

In UML notation `static` methods are written with an underline:

![[Pasted image 20250213132202.png#invert]]
## Encapsulation

The technique of **encapsulation** is is making attributes (data about the object) accessible only to the methods of the same class, this feature has allowed OOP to become mainstream.

![[Pasted image 20250211184024.png#invert]]
The figure above nicely illustrates this

So in an ideal setup, you would not be able to access the attributes of the class from the main method of another class, instead you can call a method of the class to view the attributes. Classes are defined like this to prevent inadvertent changes by anyone - **data is kept secure**.

## Constructing Classes

When it comes to creating classes we first have the **attributes**:

```Java
public class Car {
    // Attributes
    private String brand;
    private String model;
    private int year;
...

```

Looking at the attributes, we can see that they are declared outside any method, and they have the additional word of '`private`' ('`public`') before it, this declares the **scope** of the variable.
Attributes of a class are accessible to **all** methods within it.

The first 'method' that needs to be defined is the constructor. Remember from looking at [[Objects]] that the constructor has the same name as the class and it has no return type.

```Java
public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
```

The constructor is declared as `public`, this is because we need it to be accessible from the outside so that they can be called by methods of other classes.

### Static Modifier

If we want a variable that is constant for all instances of the classes, we can use the `static` modifier to hold for an attribute.
There is only copy of the `static` variable, regardless of how many instances of the class are created.

And if we want to have a method to access this attribute without reference to a specific object, we can have `static` methods.

### Initialising Attributes

Java does not give an initial value to local variables, but it does always initialise attributes:
- Numerical attributes such as `int` and `double` are initialised to zero,
- `boolean` attributes are initialised to `false`,
- Objects are initialised to `null` and,
- Character attributes are given an initial Unicode value of zero.

Despite this it is good practice always to give an initial value to your attributes.

