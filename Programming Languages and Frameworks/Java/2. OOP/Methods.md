08-02-2025 11:19

Status:

Tags: [[Java]] 

# Methods
Methods allow us to call the same piece of code multiple tines without having to re-write the code again and again. 

Example:
```Java
static void displayMessage()
{ 
System.out.println("Please note that all information supplied is confidential"); System.out.println("No personal details will be shared with any third party");
}
```

The body of the method is contained between the two curly brackets.
The first line that declares the method, is called the method **header**.

## Method Header and Modifiers
In the example we see three different words. These words dictate, to a degree, how the method works with the rest of the code.

1. **Access Modifiers:**
- `public`: The method is accessible from any other class.
- `protected`: The method is accessible within the same package and by subclasses.
- `private`: The method is accessible only within the same class.
- (default, no keyword): The method is accessible within the same package, also known as **package-private**

2. **Non-Access Modifiers:**
- `static`: The method belongs to the class, rather than an instance of the class. It can be called without creating an object of the class.
- `final`: The method cannot be overridden by subclasses.
- `abstract`: The method is declared without an implementation (must be overridden in a subclass).
- `synchronized`: The method can only be accessed by one thread at a time.
- `native`: The method is implemented in native code using JNI (Java Native Interface).

3. **Return Type:**
- `void`: The method does not return a value.
- Any primitive data type (e.g., `int`, `float`, `double`, `char`, etc.): Specifies the type of value the method returns.
- Any object type (e.g., `String`, `Object`, `List`, etc.): Specifies the type of object the method returns.

4. **Method Name and Parameters:**
- Then we have the method name which follows the Java naming convention (e.g. `displayMessage`)
- The parenthesis holds a comma separated list of input characters where each parameter consists of a type and a name, (e.g. `int x`, `String name`).

## Method Properties
Let's look at this example:
```Java
static double addTax(double priceIn, double taxIn) { 
	return priceIn * (1 + taxIn/100); 
}
```

From just looking at the header we can distinguish that:
- No access modifier = the method is accessible within the same package
- `static` = the method belongs to the class
- `double` = returns a primitive datatype - double
- Parameters = contains two parameters that are both of 'double' datatypes

In this example we have, a `return` call. The word `return` in a method serves two very important functions. First it ends the method - as soon as the program encounters the word, the method terminates, and control of the program jumps back to the calling method. Secondly, it is that it sends back a value. In this case it sends back the result of the calculation: `priceIn * (1 + taxIn/100)`.

This means that if the method is of type `void` you do not need a `return` instruction - the method simply terminates once the last instruction is executed.

## Instance Methods vs Static Methods

These are two challenging concepts that are tricky to understand.

A static method is a method that belongs to the class and can be called **without** creating the object of the class the method belongs to.

An instance method is one that **belongs** to an object and **requires** and object to be made of that class to use said instance method.

## Method Overloading
This is a feature that allows a method to have more than one function with the same name, but with different parameter lists. 

Method overloading is what is known as *polymorphism* (it means having many forms). 

```Java
public class OverloadExample {

    // Method with one integer parameter
    public int add(int a) {
        return a + a;
    }

    // Method with two integer parameters
    public int add(int a, int b) {
        return a + b;
    }

    // Method with three integer parameters
    public int add(int a, int b, int c) {
        return a + b + c;
    }

    // Method with two double parameters
    public double add(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        OverloadExample example = new OverloadExample();
        
        // Calling different overloaded methods
        System.out.println(example.add(5));        // Calls the first method
        System.out.println(example.add(5, 10));    // Calls the second method
        System.out.println(example.add(1, 2, 3));  // Calls the third method
        System.out.println(example.add(5.5, 7.5)); // Calls the fourth method
    }
}
```

Looking at the example above, you can see that when you change the number of parameters of the same method that is being called, it will call a different method.