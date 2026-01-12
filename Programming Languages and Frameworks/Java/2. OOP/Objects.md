06-02-2025 20:13

Tags: [[Java]]

## Objects

To use the methods of a class, you need to create an **Object** of that class - the object is an instance of that class.

So let's say we have an `Oblong` class (a class about rectangles). With the class we will now be able to make declarations like:

```Java
Oblong myOblong;
```

This is similar to a declaration of a variable of a primitive type, like `int`, but now we have declared a variable `myOblong` as a type of `Oblong` - so we have basically created a new type, `Oblong`.
But you have to remember that this has only created a reference to the object, we have only created a variable that holds a reference to an object, no actual object has been created yet.

In order to **instantiate** an object, you use a **constructor**. 
```Java
myOblong = new Oblong();
```

The constructor is a method that always has the same name as the class. It reserves some space in the computer's memory just big enough to hold the required object. 

Let's look at another example:
```Java
public class Vehicle {
    // Constructor
    public Vehicle() {
        System.out.println("Vehicle created!");
    }

    // Method
    public void startEngine() {
        System.out.println("Engine started.");
    }

    public static void main(String[] args) {
        Vehicle myCar;               // Step 1: Declaring a reference
        myCar = new Vehicle();       // Step 2: Creating an object
        myCar.startEngine();         // Using the object to call a method
    }
}
```

1. `Vehicle myCar` Declares a reference of type Vehicle. At this point `myCar` is just a placeholder and doesn't point to any actual `Vehicle` object.
2. `myCar = new Vehicle()` creates a new `Vehicle` object and assigns the reference `myCar` to point to this object. The `new` keyword calls the constructor of the `Vehicle` class, which in this case, prints "Vehicle Created".
3. After the object is created, you can use it to call methods or access its fields.

Let's look at a more sophisticated example:

```Java
public class Vehicle {
    private String brand;

    // Constructor
    public Vehicle(String brand) {
        this.brand = brand;
        System.out.println("Vehicle created: " + brand);
    }

    // Method
    public void startEngine() {
        System.out.println(brand + " engine started.");
    }

    public static void main(String[] args) {
        Vehicle myCar = new Vehicle("Toyota"); // Passing "Toyota" to constructor
        myCar.startEngine();                   // Outputs: Toyota engine started.
    }
}
```

The example above is what is known as a parameterised constructor. 

When it comes to constructors, we don't always need to define them, Java will assign a default constructor for the object. Furthermore, we can have constructors that have no parameters and instead define a no-argument constructor.

When we have a user-defined constructor declared, the default constructor becomes unavailable to be used, so it then requires explicit declaration of the default constructor to use it:

```Java
public Vehicle()
{
}
```

One cool thing you can do is have multiple constructors, also known as constructor overloading. This is similar to we have seen in [[Programming Languages and Frameworks/Java/2. OOP/Methods|Methods]] for method overloading and is extremely similar to that, where depending on the parameters used to initialise the object, it changes the constructor used and so loads different values in said parameters:

```Java
public class Example {
    private int value;
    private String text;

    // No-argument constructor
    public Example() {
        this.value = 0;
        this.text = "Default";
    }

    // Parameterized constructor
    public Example(int value) {
        this.value = value;
        this.text = "Default";
    }

    // Another parameterized constructor
    public Example(int value, String text) {
        this.value = value;
        this.text = text;
    }
}

Example obj1 = new Example();              // Calls the no-argument constructor
Example obj2 = new Example(42);            // Calls the parameterized constructor
Example obj3 = new Example(42, "Hello");   // Calls the other parameterized constructor
```


One thing to note is that constructors have **no** return types, if a class has two 'constructors' as in they both have the same name as the class, but one of them has a return type, the one with the return type will be treated as a method by the compiler.
