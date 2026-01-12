29-03-2025 22:29

Tags: [[Java]]

# Wrapper Classes and Autoboxing

Some methods, especially in Java's API and collections (like `ArrayList`, `HashMap`, etc.), only work with objects - not primitive types. 

**Wrapper Classes** solve this. Think of them like a 'box' or 'wrapper' that wraps around a primitive value (like `int` or `double`) and turns it into an object.

For example:

```Java
int primitveValue = 42;
Integer wrappedValue = Integer.ValueOf(primitiveValue);
```

Usually the `Wrapper` class' name is the type's name itself but with a capital first letter. 
## Autoboxing and Unboxing

**Autoboxing** is simply the automatic conversion of a primitive type into its corresponding wrapper class. You do not need to explicitly wrap it - it happens automatically. Example:

```Java
int primitiveInt = 10;
Integer wrappedInt = primitiveInt; // Autoboxing happens here!
```

**Unboxing** is the reverse process, where a wrapper class object is converted back into a primitive type. Java handles this for you automatically when needed.

```Java
Integer wrappedInt = 10;
int primitveInt = wrappedInt;
```

- - -

**Full example:**

```Java
import java.util.ArrayList;

public class ProductRatingTracker {

    public static void main(String[] args) {
        // Step 1: Create a list to store ratings (ArrayList works with objects)
        ArrayList<Double> productRatings = new ArrayList<>(); // Wrapper class Double is used
        
        // Step 2: Add ratings (autoboxing occurs here)
        productRatings.add(4.5); // Primitive double automatically converted to Double
        productRatings.add(3.8);
        productRatings.add(5.0);
        productRatings.add(4.2);

        // Step 3: Calculate the average rating
        double totalRating = 0; // Primitive double to hold the total
        for (Double rating : productRatings) {
            totalRating += rating; // Unboxing: Double to primitive double
        }
        double averageRating = totalRating / productRatings.size();
        
        // Step 4: Check if the product is "Highly Rated" (boolean example)
        Boolean isHighlyRated = averageRating >= 4.0; // Autoboxing: primitive boolean to Boolean

        // Step 5: Display the result
        System.out.println("Product Ratings: " + productRatings);
        System.out.println("Average Rating: " + averageRating);
        System.out.println("Is the product highly rated? " + isHighlyRated);
    }
}
```

Output:

```
Product Ratings: [4.5, 3.8, 5.0, 4.2]
Average Rating: 4.375
Is the product highly rated? true
```