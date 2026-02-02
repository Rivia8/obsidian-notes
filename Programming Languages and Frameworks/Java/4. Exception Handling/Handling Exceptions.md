05-05-2025 14:49

Tags: [[Java]]

# Handling Exceptions

When it comes to [[Programming Languages and Frameworks/Java/4. Exception Handling/Exceptions#Runtime and IO|exception errors]] we need to be able to **handle** them appropriately.
They should be implemented when:
- You expect a possible error,
- You want to prevent app crashes,
- You can offer recovery.

`IOException` is only thrown with `BufferedReader` and not the `Scanner` class.
## Claiming an Exception

The term **claiming an exception** refers to a given method having been marked to indicate that it will pass an exception object that it might generate.
So when we implement `throws IOException` means that the method *could* cause an I/O exception in the program.

First in order to do this, we import the `IOException` class:
```Java
import java.io.IOException;
```

Example:
```Java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

  
public class InputExample{
    public static void main(String[] args) throws IOException{
    
        // Sets up buffered reader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter Your Number: ");
        String input = reader.readLine();
        int number = Integer.parseInt(input);
        System.out.println("Your number is: " + number);
    }
}
```


When you utilise the `throw IOException` line for a method, it must be either handled using a `try-catch` or be claimed by passing it further up.

When you 'pass it further up'  ideally at one point it should be caught, if it is never caught, the thread in which the exception was thrown will terminate.

## Catching an Exception

One way we can do this is by using `try-catch` blocks that surround the code:

```Java
public void readFile(String path) {
    try {
        FileReader reader = new FileReader(path);
    } catch (IOException e) {
        System.out.println("Error reading file: " + e.getMessage());
    }
}
```

In this way we are dealing with the exception within the same method.

When you do have a `try` block three things can happen:
1. the instructions within the block execute successfully,
2. the exception occurs within the `try` block and a matching `catch` block is found for the exception,
3. no matching `catch` block is found for the `try` block and is thrown from the method.

Full Example:

```Java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class InputExample{
    public static void main(String[] args) {
        try {
            // Sets up buffered reader
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter Your Number: ");
            String input = reader.readLine();
            int number = Integer.parseInt(input);
            System.out.println("Your number is: " + number);

        } catch (IOException e) {
            System.out.println("error");
        } catch (NumberFormatException e) {
            System.out.println("error");
        }
    }
}
```

In a try-catch block you can also have a `finally` statement that is guaranteed to execute regardless of what happens in the `try` or `catch` blocks.
The main reason for the `finally` block is to ensure that crucial clean-up code is always executed to prevent resource leaks, like closing a file (`file.close()`) or closing a database connection (`connection.close()`).

Example:

```Java
public class FinallyExample {

    public static void main(String[] args) {
        System.out.println("--- Running test with valid index ---");
        testArray(0);

        System.out.println("\n--- Running test with invalid index ---");
        testArray(5);
    }

    public static void testArray(int index) {
        int[] numbers = {10, 20, 30};

        try {
            System.out.println("Entering the try block.");
            int result = numbers[index]; // This line might throw an exception
            System.out.println("Value at index " + index + " is: " + result);
            System.out.println("Leaving the try block.");

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Catching an exception: " + e.getMessage());

        } finally {
            // This block runs whether an exception was thrown or not.
            System.out.println("Executing the finally block. Cleanup complete.");
        }

        System.out.println("Continuing execution after the try-catch-finally block.");
    }
}
```

``` 
--- Running test with valid index ---
Entering the try block.
Value at index 0 is: 10
Leaving the try block.
Executing the finally block. Cleanup complete.
Continuing execution after the try-catch-finally block.

--- Running test with invalid index ---
Entering the try block.
Catching an exception: Index 5 out of bounds for length 3
Executing the finally block. Cleanup complete.
Continuing execution after the try-catch-finally block.
```


## Summary Between Claiming and Catching:

- **Claiming (`throws`)**: You're saying, _"I'm not dealing with this — someone else should."_ This passes the exception **up the call chain**.
- **Catching (`try-catch`)**: You're saying, _"I'll handle it here."_
- If **nobody catches it**, and it reaches the top (like `main()`), **the program will crash** with an uncaught exception error.
- So, ideally, you want to **catch exceptions at a point in the program where it makes sense to handle the error gracefully** (e.g., notify the user, log it, retry, etc.)

###  Analogy:

Think of it like hot potato — you're throwing the error around until someone _actually catches it_. If no one does, it "explodes" (crashes the program).
