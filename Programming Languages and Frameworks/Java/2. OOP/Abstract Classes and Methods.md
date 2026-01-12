25-03-2025 22:36

Tags: [[Java]] [[Classes]]

# Abstract Classes

Abstract classes act as a basis for other classes or subclasses. 
This is good for when you want to enforce the use of subclasses.

It is like a blueprint or a template for other classes. It provides some functionality and leaves other parts (abstract methods) for its child classes to fill in:

- The abstract class sets rules: "If you're inheriting from me, you **must** implement these abstract methods in your own way"
- The child class adds specific behaviour.

Let's look at an analogy:

Imagine company designing vehicles.  They create a blueprint (abstract class) called **Vehicle**. Every vehicle (child classes like Car or Bicycle) needs to have certain features like `startEngine` or `stop`. But different vehicles will implement these differently.

**Example:**

Abstract Class:

```Java
abstract class Vehicle {
    // Abstract method (no implementation, child classes must implement it)
    abstract void startEngine();

    // Concrete method (common behavior for all vehicles)
    public void stop() {
        System.out.println("Vehicle stopped.");
    }
}
```

Subclass:

```Java
class Car extends Vehicle {
    @Override
    void startEngine() {
        System.out.println("Car engine started.");
    }
}
```

Subclass:

```Java
class Bicycle extends Vehicle {
    @Override
    void startEngine() {
        System.out.println("Bicycle doesn't have an engine, but let's get pedaling!");
    }
}
```

Main Class:

```Java
public class Main {
    public static void main(String[] args) {
        Vehicle myCar = new Car();
        myCar.startEngine(); // Outputs: Car engine started.
        myCar.stop();        // Outputs: Vehicle stopped.

        Vehicle myBike = new Bicycle();
        myBike.startEngine(); // Outputs: Bicycle doesn't have an engine, but let's get pedaling!
        myBike.stop();         // Outputs: Vehicle stopped.
    }
}
```

# Abstract Methods

An **abstract** method in Java is a method that is declared without an implementation (i.e. it has no body). It is meant to be overridden and implemented by subclasses to define a common interface or behaviour that must be implemented by all subclasses.

**Example:**

```Java
abstract class Animal {
    // Abstract method (must be implemented by subclasses)
    abstract void makeSound();

    // Concrete method (common for all animals)
    public void sleep() {
        System.out.println("This animal is sleeping.");
    }
}
```

Subclass implementing Abstract Methods:

```Java
abstract class Animal {
    // Abstract method (must be implemented by subclasses)
    abstract void makeSound();

    // Concrete method (common for all animals)
    public void sleep() {
        System.out.println("This animal is sleeping.");
    }
}
```

Using the class:

```Java
public class Main {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        myDog.makeSound(); // Outputs: Woof! Woof!
        myDog.sleep();     // Outputs: This animal is sleeping.

        Animal myCat = new Cat();
        myCat.makeSound(); // Outputs: Meow!
        myCat.sleep();     // Outputs: This animal is sleeping.
    }
}
```

