06-02-2025 20:13

Status:

Tags: [[Java]]

# Object-Orientated Programming
Object-orientated languages such as Java and C++ enable us to create types that store many pieces of data and also to define within these types the methods by which we could process that data.  These types are what as known as **classes.**
## Differences Between a Class and an Object
A class is a blueprint for creating objects. It defines the data and behaviour (methods) that the objects created from the class will have.

```Java
public class Car {
    // Attributes
    String color;
    String model;

    // Method
    void drive() {
        System.out.println("The car is driving.");
    }
}
```

An **object** is an instance of a class. It is created based on the class and has its on sets of attributes and methods as defined by the class.

```Java
public class Main {
    public static void main(String[] args) {
        // Creating an object of the Car class
        Car myCar = new Car();
        myCar.color = "Red";
        myCar.model = "Tesla Model S";
        myCar.drive(); // Calls the drive method
    }
}
```

In this example, `myCar` is an object of the `Car` class.
The attributes are `color` and `model` and can perform methods `drive` as defined by the class.


