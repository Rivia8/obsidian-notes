22-03-2025 22:35

Tags: [[Java]]

# Strings 

Strings are used for storing text.
This variable type is an [[Objects|object]] so it has various methods.

In order to get a string from the keyboard you should use the next method of the `Scanner`.

The `String` class has a number of interesting and useful methods.

## String Comparison:

```Java
public class StringExample {
    public static void main(String[] args) {
        String str1 = "Java";
        String str2 = "java";
        
        System.out.println("Equals: " + str1.equals(str2));  // False
        System.out.println("Equals Ignore Case: " + str1.equalsIgnoreCase(str2)); // True
    }
}
```
*Output:* `False`  `True`

## String Length

```Java
public class StringExample {
    public static void main(String[] args) {
        String message = "Hello, World!";
        System.out.println("Length of the string: " + message.length());
    }
}
```
*Output:* `Length of the string: 13`

## Convert Case

```Java
public class StringExample {
    public static void main(String[] args) {
        String message = "Hello, World!";
        
        System.out.println("Uppercase: " + message.toUpperCase());
        System.out.println("Lowercase: " + message.toLowerCase());
    }
}
```
*Output:* `Uppercase: HELLO, WORLD!` `Lowercase: hello, world!`

## Splitting Strings

```Java
public class StringExample {
    public static void main(String[] args) {
        String message = "Java,Python,C++,JavaScript";
        
        String[] languages = message.split(",");
        for (String language : languages) {
            System.out.println(language);
        }
    }
}
```
*Output*: `Java` `Python` `C++` `JavaScript`

## Trim Whitespaces

```Java
public class StringExample {
    public static void main(String[] args) {
        String message = "   Hello, World!   ";
        
        System.out.println("Trimmed String: '" + message.trim() + "'");
    }
}
```
*Output:* `Trimmed String: 'Hello, World!'`

##
- - - 

There are a lot more `String` methods, the ones above are just some.



