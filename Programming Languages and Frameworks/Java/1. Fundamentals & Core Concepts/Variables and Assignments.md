28-01-2025 12:19

Tags: [[Java]]

# Variables and Assignments

Variables are containers of information.

When it comes to variables in Java they need to be defined specifically - it involves the declaration of the variable type, naming the variable, and then assigning it a value.

Look at this **Example:**
```Java
int age;     // Declaration  
age = 25;    // Assignment
```

You can do both in one line:
```Java
int age =  25;
```

For a string variable:
```Java
String name = "Alice";
```

- Java is statically typed, so the type of a variable must be explicitly declared and cannot change.
- Variables in Java must be declared before they are used.
- The assignment operator (`=`) assigns the value on its right to the variable on its left.

If there are any Type Errors, they will be raised during Compile Time since Java is Statically Typed.

Also Java does **NOT** appoint default values for local variables if they aren't assigned a value, but for attributes java assigned them default values:
- Numeric primitives get 0 or 0.00,
- Boolean gets false,
- Char gets the null character `'\u0000'`,
- Object references get null.
This is to prevent bugs forces the code to be more robust.




