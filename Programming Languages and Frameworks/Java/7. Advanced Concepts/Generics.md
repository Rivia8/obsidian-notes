26-05-2025 18:45

Tags: [[Java]]

# Generics

**Generics** allow you to specify the type of objects that a collection (or a class, interface or method) will work with.

Generics use `< >` (angle brackets) after a class or interface name:

```Java
// With Generics
List<String> stringList = new ArrayList<String>(); // This List will ONLY hold Strings
stringList.add("Apple");
stringList.add("Banana");
// stringList.add(123); // COMPILE-TIME ERROR! The compiler stops you here.

String fruit = stringList.get(0); // No cast needed! The compiler knows it's a String.

// What if you try to get something else?
// Integer number = stringList.get(0); // COMPILE-TIME ERROR!
```

**Type Parameters:**
These are placeholder types specified in the angle brackets, often single uppercase letters like `E` (for Element, common in Collections), `T` (for Type), `K` (for Key), `V` (for Value), `N` (for Number), etc.

**Type Arguments:**
When you use a generic class or method, you replace the type parameters with actual types.

Because the compiler knows the type of elements stored in a generic collection, you don't need to cast them when you retrieve them.

Generics shine in the **Java Collections Framework (JCF)**: all the interfaces and classes in the JCF (like `List`, `Set`, `Map`, `ArrayList`, `HashSet`, `HashMap`) are generic.

A generic type can be declared as an interface, a class, a generic type or a wild card.

Generics are needed to enforce type safety at compile time, when you have **raw lists** you can add items that belong to different classes or subclasses:

```Java
// You can hold multiple subclasses without generics, but it's not type-safe.
List rawList = new ArrayList();
rawList.add(new Dog()); // A subclass of Animal
rawList.add(new Cat()); // Another subclass of Animal

// The purpose of generics is to provide TYPE SAFETY.
List<Animal> safeList = new ArrayList<>();
safeList.add(new Dog());
safeList.add(new Cat());
// safeList.add("a string"); // This would now cause a COMPILE ERROR, which is the benefit.
```

You can create your own generic classes for any purpose like a `Box<T>` that can hold any type of item.
When you use generics with streams and call `.map()` or `.filter()` on a `Stream<String>` the compiler infers the resulting stream's type without you having to write it out explicitly, this is known as type inference.

## Generic Class

When we design a generic class, the generic type is declared with the the class and is known to the entire class (its fields, all its methods, etc).

```Java
public class Box<T> { // <T> is declared for the whole class
    private T content;
    public void setContent(T content) { this.content = content; }
    public T getContent() { return content; }
}
```

## Generic Methods

In generic methods, the generic type is declared with the method and is only known *within* that one method, this allows you have a generic method even inside a non-generic class.

If we had the signature:

```Java
public <E> boolean doSomething(GenericClass<E> gc){...}
```

We see that we have `<E>` which is the parameter type declaration, it says that "For this method only, I am declaring a new placeholder type that I will call E".

```Java
class Utilities {
    // This method is generic, but the Utilities class is not.
    // <T> declares a generic type 'T' for this method.
    public static <T> T getFirstElement(List<T> list) {
        if (list == null || list.isEmpty()) {
            return null;
        }
        return list.get(0);
    }
}

public class Main {
    public static void main(String[] args) {
        // Here, the compiler infers that T is a String
        List<String> names = List.of("Alice", "Bob");
        String firstName = Utilities.getFirstElement(names);
        System.out.println(firstName); // Prints "Alice"

        // Here, the compiler infers that T is an Integer
        List<Integer> numbers = List.of(10, 20, 30);
        Integer firstNumber = Utilities.getFirstElement(numbers);
        System.out.println(firstNumber); // Prints 10
    }
}
```