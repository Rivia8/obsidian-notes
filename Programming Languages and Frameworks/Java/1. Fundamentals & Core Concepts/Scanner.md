03-06-2025 01:48

Tags: [[Java]]

# Scanner 

The `Scanner` class is designed to break down, parse, the input into 'tokens'. By default it uses whitespace as delimiters to separate these tokens.

The `Scanner` utility is required to be imported into the file:

```Java
import java.util.Scanner;
```

It is necessary to create a new `Scanner` object in every method that uses the `Scanner` class.

```Java
Scanner scanner = new Scanner(System.in)
```

You pass the the input source (`System.in`) to its constructor.
Using `System.in` is specifically for **reading from the keyboard**.

You can also create a `Scanner` for:
- File: `Scanner fileScanner = new Scanner(new File("mydata.txt"))`
- Strings: `Scanner stringScanner = new Scanner("Hello 123 world")`

**Reading Strings:**

- `next()` : Reads a single word
- `nextLine()` : Reads an entire line (including whitespace) 

Example:
```Java
System.out.print("Enter your name: ");
String name = scanner.nextLine();
System.out.println("Your name is: " + name);
```

**Reading Numbers:**

- `nextInt()` : Reads an integer.
- `nextDouble()` : reads a floating-point number.
- `nextLong()`, `nextFloat()`, `nextShort()`: Reads other numeric types.

Example:
```Java
System.out.print("Enter your age: ");
int age = scanner.nextInt();
System.out.println("Your age is: " + age);
```

**Reading Characters:**

The `Scanner` class does not have a direct method for single characters, you can read a string and extract the first character.

```Java
System.out.print("Enter a character: ");
char character = scanner.next().charAt(0);
System.out.println("You entered: " + character);
```

**Custom Delimiters**

The way `Scanner` works is that it parses the input by separating the tokens that are separated with whitespace, so the string "Hello World" would have the tokens "Hello" and "World".

But you can also set custom delimiters, this is useful for parsing comma-separated values in .csv files.

```Java
Scanner csvScanner = new Scanner("apple, banana, orange");
csvScanner.useDelimiter(",");
while (csvScanner.hasNext()) { // Using the hasNext() method to check if there is a following word
	System.out.println(csvScanner.next());
}

// Output
// Apple
// Banana
// Orange

```

**The `hasNext()` feature**

We can use the `hasNext()` methods to check for input. Before attempting to read the input, we can check just to see if there is actually an input available for the desired type using `hasNext()` methods.

- `scanner.hasNext()`: Returns  `true` if there is another **token** in the input.
- `scanner.hasNextLine()`: Returns `true` if there is another line in the input.
- `scanner.hasNextInt()`: Returns `true` if the next token can be interpreted as an `int`.
	- This is similar for other types also.

**Closing `Scanner`**

We then have to close the `Scanner` object (failing to do so can lead to resource leaks):
```Java
scanner.close();
```






