25-05-2025 18:53

Tags: [[Java]]

# List

This is an **ordered** collection of items where it maintains the insertion order. It allows duplicate items and you access items by their integer index.

# ArrayList

When it came to creating arrays they have fixed sizes that are determined (they have an upper limit) which can be a problem when we want them to be dynamic.

An `ArrayList` is the solution since it's a **resizable-array** implementation of the `List` interface.

Technically an `ArrayList` is a regular array but once it gets full it just copies its contents into a larger array, since its an 'implementation of the `list` interface' it adheres to the contract defined by the `List` interface meaning it provides methods like `add()`,`get()`, `remove()` etc.

The `List` interface specifies the methods required to process an ordered list of objects. There are two implementations provided for the `List` interface in the JCF:

1. ArrayList
2. [[LinkedList]] (but also implements Queue)

All classes in the JCF are in the `java.util` package, so to use the `ArrayList` class we require the following `import` statement:

```Java
import java.util.ArrayList;
```

To instantiate an a `ArrayList` we would do:

```Java
List<String> myList = new ArrayList<>();
```

But we can create an `ArrayList` that has a pre-allocated internal array of a specific size. This is for performance optimisation to prevent the list from having to resize itself multiple times:
```Java
List<String> names = new ArrayList<>(100);
```

We can create an `ArrayList` from another collection:
```Java
Set<String> uniqueNames = Set.of("Alice", "Bob")

// Creates a new ArrayList by copying the elements from the set.
List<String> nameList = new ArrayList<>(uniqueNames);
```

And the oldest method of creating an `ArrayList` is as follows:

```Java
List<String> uniqueNames = List.of("Alice", "Bob");

List<String> names = new ArrayList<>(fixedList);
```

## Characteristics

1. Ordered Collection:
	- Elements maintain their insertion order,
	- Elements can be accessed by their index starting from 0,
	- Methods like `get(index)`, `set(index, element)`, `add(index, element)` are available.
2. Allows `null` elements.
3. `ArrayLists` are not synchronised, meaning it is **not thread-safe**.
	- Multiple threads accessing and modifying an `ArrayList` concurrently it can cause unpredictable behaviour.

## Usage

You use this when:
- You need frequent random access,
- Your are primarily adding elements to the end of the list
- The number of insertions/deletions in the middle of the list is minimal,
- You don't need thread-safety.





