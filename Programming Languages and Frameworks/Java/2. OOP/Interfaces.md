25-05-2025 19:32

Tags: [[Java]]

# Interfaces

**Interfaces** is a blueprint of a class. It defines a contract for what a class can do or should do. 
If a class signs an interface, it makes a promise to provide a specific methods.

Pretty much an interface defines a set of methods that a client expects to be available and so any class that implements the interface **promises to provide those methods.**

**Example:**

Instantiate vehicle interface:
```Java
public interface Vehicle {
    void start();
    void stop();
    void accelerate(int speedIncrease);
    void brake(int speedDecrease);
}
```

Instantiating a car class:
```Java
public class Car implements Vehicle {
    // Must provide implementations for start(), stop(), accelerate(), brake()
    @Override
    public void start() {
        System.out.println("Car engine starts with a roar.");
    }
    @Override
    public void stop() {
        System.out.println("Car comes to a smooth stop.");
    }
    @Override
    public void accelerate(int speedIncrease) {
        System.out.println("Car accelerates by " + speedIncrease + " mph.");
    }
    @Override
    public void brake(int speedDecrease) {
        System.out.println("Car brakes by " + speedDecrease + " mph.");
    }
}

public class Motorcycle implements Vehicle {
    // Must provide implementations for start(), stop(), accelerate(), brake()
    @Override
    public void start() {
        System.out.println("Motorcycle kicks to life.");
    }
    @Override
    public void stop() {
        System.out.println("Motorcycle coasts to a halt.");
    }
    @Override
    public void accelerate(int speedIncrease) {
        System.out.println("Motorcycle revs up by " + speedIncrease + " mph.");
    }
    @Override
    public void brake(int speedDecrease) {
        System.out.println("Motorcycle slows down by " + speedDecrease + " mph.");
    }
}
```

Now, you can write code that operates on _any_ `Vehicle`, without knowing its specific type:

```Java
public class Driver {
    public void operate(Vehicle v) {
        v.start();
        v.accelerate(50);
        v.brake(20);
        v.stop();
    }

    public static void main(String[] args) {
        Driver driver = new Driver();
        Car myCar = new Car();
        Motorcycle myBike = new Motorcycle();

        driver.operate(myCar);    // Operates the Car
        System.out.println("---");
        driver.operate(myBike);   // Operates the Motorcycle
    }
}
```

In the example above, `v` is a reference variable, this means that `v` can hold a reference to any object whose class implements the `Vehicle` interface.

You can use [[Programming Languages and Frameworks/Java/7. Advanced Concepts/Lambda Expressions|lambda expressions]] to send the code for a particular method to another method which works quite nicely for interfaces.

The reason for interfaces is that it allows you to achieve **abstraction**, **polymorphism**, and **loose coupling**.
Technically you could just create methods without interfaces, but it misses these crucial design features.

In Java, a single class can `implement` multiple interfaces, this allows the class to inherit the required behaviours (or "contracts") from several different sources:

``` Java
// Interface 1: Defines the capability of printing
interface Printable {
    void print(String document);
}

// Interface 2: Defines the capability of scanning
interface Scannable {
    void scan(String document);
}

// This class "inherits" from TWO interfaces.
// It promises to fulfill both the Printable and Scannable contracts.
class MultiFunctionPrinter implements Printable, Scannable {

    // Must provide an implementation for the method from Printable
    @Override
    public void print(String document) {
        System.out.println("Printing: " + document);
    }

    // Must also provide an implementation for the method from Scannable
    @Override
    public void scan(String document) {
        System.out.println("Scanning: " + document);
    }
}

public class Office {
    public static void main(String[] args) {
        // Create one object that has both capabilities.
        MultiFunctionPrinter myOfficeMachine = new MultiFunctionPrinter();

        // We can call both methods on the same object.
        myOfficeMachine.print("My Report.docx");
        myOfficeMachine.scan("An Invoice.pdf");
        
        System.out.println("---");

        // --- Demonstrating Polymorphism ---
        // We can treat the same object as just a Printable device.
        Printable printer = myOfficeMachine;
        printer.print("Just printing this.pdf");
        // printer.scan(...); // This would cause a COMPILE ERROR because the 'printer' reference only knows about Printable methods.
    }
}
```

## Abstract classes v Interfaces

You might think that an interface is kind of useless as you can pretty much do the same thing with something like abstract classes, but that is not the case!

Interfaces makes it so that it gives a class the **capabilities** of itself without being related to it.
For an example, a class `Animal{}` can implement the interface `Printable{}` without having the need to `extend` the class and becoming a subclass. 
Furthermore, a class can extend from **one** parent class, but can `implement` *many* interfaces, so the class `Animal{}` can implement `Amphibian{}` **and** `Printable{}` (even though the latter makes no sense).

- An **`abstract`** defines an **identity** (what an object is and so what it needs to feature).
- An **`interface`** defines a capability.

## Functional Interfaces

**Functional interfaces** are interfaces with only **one** abstract method. This is to ensure the compiler can unambiguously map a lambda's signature to the interface's abstract method.

It has the `@FunctionalInterface` annotation to let the compiler know (it is not mandatory).