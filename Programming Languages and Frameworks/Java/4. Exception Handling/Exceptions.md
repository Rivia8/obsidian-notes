05-05-2025 11:54

Tags: [[Java]]

# Exceptions

Programs should be written in a way that allow it to continue to function when unexpected issues arise. 
We need **exception handling** for this sort of thing.

An exception is an event that occurs during the life of a program which could cause that program to behave unreliably.
An event that can lead to an exception has its own pre-defined **exception class.**

So exceptions are objects.

When said event occurs the Java run-time environment determines that it has occurred and the object of said class is generated - this is known as **throwing** an exception.

The names of the classes are reflective of the type of error:
When an array is accessed with an illegal index an object of the `ArrayIndexOutOfBoundsException` is thrown.

The way these exceptions classes are structured are that they all inherit from the base class `Throwable` which is found in the `java.lang` package.

![[Pasted image 20250505125039.png#invert]]

Above you can see there are two subclasses of `Throwable`: `Error` and `Exception` the deal with `error` is that this describes internal system errors, and if these were to occur there isn't much to do apart from closing the program as gracefully as possible.

## Runtime and IO

From `Exception` we have: `IOException` and `RuntimeException`. 

**`RuntimeException`**
This deals with errors that arise form the logic of a program -i.e. a program that converts a string into number, when the strings contain non-numeric characters or accesses an array with an illegal index.


```Java
public class Example {
    public static void main(String[] args) {
        try {
            int[] nums = {1, 2, 3};
            System.out.println(nums[10]);  // Causes  ArrayIndexOutOfBoundsException
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Caught an exception: " + e);
        }
    }
}
```

**`IOException`**
This deals with external errors that could affect the program during input and output. These errors include keyboard locking or external file being corrupted.

## Checked Exceptions

These are forced checks that the compiler ***makes*** you handle or else the program won't be able to compile.
A clear example is with:

```Java
FileReader reader = new FileReader(fileName);
```

The above code will **NOT** compile due to the fact that currently it has no error handling.
One way will be with [[Handling Exceptions#Catching an Exception|try-catch blocks]] for specifically the `FileNotFoundException`

## Unchecked Exceptions

Unchecked exceptions are all the exceptions that fall under `RuntimeException`, this the main category that you will most likely interact with and these exceptions represent bugs or logical flaws in our code that we should fix, rather than catch.
The compiler ***does not*** force you to handle them.

Examples include:
- `NullPointerException`
- `IllegalArgumentException`
- `ArrayIndexOutOfBoundsException`
- any custom exception you create that `extends RuntimeException`

## Custom Exceptions

You can create custom exceptions by extending either `Exception` or `RuntimeException`.

1. Extending `Exception`:

	This would create a **checked** exception. For an example:

```Java
// The compiler will force you to handle this.
class MyCheckedException extends Exception {
    public MyCheckedException(String message) {
        super(message);
    }
}
```

2. Extending `RuntimeException`

```Java
// The compiler will NOT force you to handle this.
class MyUncheckedException extends RuntimeException {
    public MyUncheckedException(String message) {
        super(message);
    }
}
```

The purpose of a custom exception is to give a specific name to a problem.