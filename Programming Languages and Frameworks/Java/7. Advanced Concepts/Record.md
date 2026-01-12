 28-05-2025 13:11

Tags: [[Java]]

# Record Type

The `record` type is a relatively new feature in Java, its used to reduce the boilerplate code needed for data-carrying classes.

Before when you needed to create a simple class to just hold data, you had to typically write a lot of repetitive code.

A `record` is a concise syntax for declaring data classes. It automatically generates the common methods that data classes typically need. Acting like a compact, immutable and transparent carrier of data.

When you declare a `record` such as:

```Java
public record Point(int x, int y) {}
```

The java compiler automatically generates the following:

- A public constructor: `Point(int x, int y)` that initialises all the components.
- Private `final` fields: One for each component declared in the record header (`private final int x;`, `private final int y;`). This makes records **immutable** by default, which is a great practise for data objects, especially in concurrent programming.
- **Public accessor methods**: For each component, named identically for the component (`x()`for x, `y()` for `y`).
- An `equals()` method,
- A `hashCode()` method to generate a hash code based on all components.
- A `toString()` method that provides a clear, concise string representation of the record and its component values.


Full Example:

```Java
// 1. Declare the record type - that's it!
public record ProductRecord(String name, double price, String category, boolean inStock) {}

public class RecordExample {
    public static void main(String[] args) {
        // 2. Instantiate a record object using the generated constructor
        ProductRecord laptop = new ProductRecord("Laptop Pro", 1200.00, "Electronics", true);
        ProductRecord book = new ProductRecord("Java Book", 45.50, "Books", true);
        ProductRecord mouse = new ProductRecord("Wireless Mouse", 25.00, "Electronics", false);

        // 3. Access components using the generated accessor methods
        System.out.println("Product Name: " + laptop.name()); // Notice it's .name() not .getName()
        System.out.println("Product Price: " + book.price());
        System.out.println("Mouse in stock? " + mouse.inStock());

        // 4. toString() is automatically provided
        System.out.println("\nLaptop Record: " + laptop);
        // Output: Laptop Record: ProductRecord[name=Laptop Pro, price=1200.0, category=Electronics, inStock=true]

        // 5. equals() and hashCode() are automatically provided (crucial for Set/Map)
        ProductRecord anotherLaptop = new ProductRecord("Laptop Pro", 1200.00, "Electronics", true);
        ProductRecord differentLaptop = new ProductRecord("Laptop Pro", 1300.00, "Electronics", true);

        System.out.println("\nLaptop equals anotherLaptop? " + laptop.equals(anotherLaptop));   // Output: true
        System.out.println("Laptop equals differentLaptop? " + laptop.equals(differentLaptop)); // Output: false

        // Demonstrate with a HashSet (relies on equals and hashCode)
        java.util.Set<ProductRecord> uniqueProducts = new java.util.HashSet<>();
        uniqueProducts.add(laptop);
        uniqueProducts.add(anotherLaptop); // This won't be added as it's equal to 'laptop'
        uniqueProducts.add(book);

        System.out.println("\nUnique Products in Set (expecting 2): " + uniqueProducts.size()); // Output: 2
        uniqueProducts.forEach(System.out::println);
    }
}
```

