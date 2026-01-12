29-05-2025 17:12

Tags: [[Java]]

# Streams

When it comes to process large volumes of data, iterating through the all the items can be rather a slow process, and is not necessarily the most efficient way of doing things. 

Here is an example:

```Java
import java.util.ArrayList;
import java.util.List;

public class PreStreamExample {
    public static void main(String[] args) {
        List<String> names = new ArrayList<>();
        names.add("Alice");
        names.add("Bob");
        names.add("Charlie");
        names.add("David");
        names.add("Andrew");

        List<String> filteredAndTransformedNames = new ArrayList<>();

        // Problem: Find names starting with 'A' and convert to uppercase
        for (String name : names) { // External iteration
            if (name.startsWith("A")) { // Filter
                filteredAndTransformedNames.add(name.toUpperCase()); // Transform
            }
        }

        // Problem: Calculate sum of lengths
        int totalLength = 0;
        for (String name : names) { // Another loop for a different operation
            totalLength += name.length();
        }

        System.out.println("Filtered and Transformed (Pre-Stream): " + filteredAndTransformedNames);
        System.out.println("Total Length (Pre-Stream): " + totalLength);
    }
}
```


For this reason, in Java 8 we had a new API, the **stream API**.
The API provides classes, especially the `Stream` class that enables us to process collections by making use of modern machines.

**Streams** is a collection of items that is created in memory, and which ceases to exist once the processing is completed.
They are **not** data structures.
The thing with streams are that they remove the burden from the programmer to write verbose code for iteration and selection.

## How Streams Work

The stream API provides lots of operations which can be categorised into:

1. **Intermediate Operations**
	- These return **another** `Stream` object, allowing you to chain multiple operations:
	- `filter(Predicate<T> predicate)`: Selects elements that match a given condition,
	- `map(Function<T, R> mapper)`: Transforms each element into a new element of a potentially different type.
	- `flatMap(Function<T, Stream<R>> mapper)`: Transforms each element into a stream of elements, and then flattens these streams into a single stream. Useful for working with nested collections.
	- `distinct()`: Returns a stream with unique elements.
	- `sorted()` / `sorted(Comparator<T> comparator)`: Sorts the elements.
	- `limit(long maxSize)`: Truncates the stream to at most `maxSize` elements.
	- `skip(long n)`: Discards the first `n` elements.

2. **Terminal Operations**:
	- These operations produce a result, like a single value, collection etc.
	- A stream can only have **one** terminal operation, after the stream is "consumed" and cannot be used again:
	- `forEach(Consumer<T> action)`: Performs an action for each element.
	- `collect(Collector<T, A, R> collector)`: Gathers elements into a new collection (e.g., `toList()`, `toSet()`, `toMap()`).
	- `reduce(BinaryOperator<T> accumulator)` / `reduce(identity, accumulator)`: Combines elements into a single result (e.g., sum, product).
	- **`count()`:** Returns the number of elements in the stream.
	- `min(Comparator<T> comparator)` / `max(Comparator<T> comparator)`: Returns the minimum/maximum element.
	- **`findAny()` / `findFirst()`:** Returns an `Optional` containing an element from the stream.
	- `allMatch(Predicate<T> predicate)` / `anyMatch(Predicate<T> predicate)` / `noneMatch(Predicate<T> predicate)`: Checks if elements match a condition.


Let's redo the original example that performs iteration with streams:

```Java
import java.util.ArrayList;
import java.util.List;
import java.stream.Collectors; // Import for collectors

public class StreamExample {
	public static void main(String[] args){
		List<String> names = new ArrayList<>();
		names.add("Alice")
		names.add("Bob");
		names.add("Charlie");
		names.add("David"); 
		names.add("Andrew");

		// Using the Stream API: Find name starting with "A" and convert to uppercase.
		List<String> filteredAndTransformedNames = names.stream() // Get a stream for the list.
			.filter(name -> name.startsWith("A")) // Intermediate operation: filter
			.map(String::toUpperCase)             // Intermediate operation: map (method reference)
			.collect(Collectors.toList());        // Terminal operation: collect to a List

		// Use the Stream API: Calculate the sum of lengths.
		int totalLength = names.stream()
			.mapToINt(String::length) // Intermediate operation: map to an IntStream for primitive int
			.sum();                   // Terminal operation: sum all elements

		// Another example: Print names longer than 5 chars
		System.out.println("\nNames longer than 5 characters");
		names.stream()
			.filter(name -> name.length() > 5)
			.forEach(System.out::println); // Terminal operation: print each
	
	}

}
```

You can easily convert a sequential stream to a parallel stream by calling `parallelStream()` on a collection and the stream API handles the underlying thread management, allowing you to leverage multi-core processors with minimal effort.

You can also create a stream from scratch instead of using the `stream` method on an existing collection:

```Java
import java.util.stream.Stream;

public class StreamFromValues {
	public static void main(String[] args) {
		// Creating Stream from values
		Stream<String> colours = Stream.of("Purple", "Blue", "Red". "Yellow", "Green");

		// Filterin gthe list and displaying strings of length 5 or more:
		colours.filter(c -> c.length() >= 5).forEach(System.out::println);
	}
}
```

As you can see, the Stream API methods are taking in **[[Interfaces|functional interfaces]]** as arguments, and as so are using [[Lambda Expressions|lambda expressions]].  

Streams are processed "vertically" which means a single element passes through the entire pipeline before the next element is processed. 
Streams incorporate something called 'lazy' evaluation, meaning intermediate operations like `filter()` and `map()` only set up a "recipe" for the stream. No data is actually processed until a terminal operation like `collect()`, `forEach()` or `count()` is called.
By default streams are sequential,, and you must explicitly call `.parallel()` or `.parallelStream()` to enable parallel processing. 
The standard Java API runs on the CPU.\

## Method References as Lambda Expressions

For many stream methods, we can either use [[Lambda Expressions|lambda expressions]] or method references.
A **method reference** is just a shorthand for lambda expressions.
An easy example is: 
``` Java
.map(s -> s.toUpperCase)
```
which has the object reference form of:
```Java
.map(String::toUpperCase)
```

The reason these works is that lambda just calls one method.

**When it doesn't work:**
It does not work it involves more than just a single method call like a comparison:

```Java
.filter(s.length() > 5)
```
Since this example above involves a comparison `>` and not just a single method call we must use a lambda expression.