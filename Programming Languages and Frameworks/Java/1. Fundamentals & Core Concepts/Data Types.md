03-06-2025 01:47

Tags: [[Java]]

# Data Types

In Java, variables are categorised into two main types; **Primitives** and **Object**(/reference) Types.
## Primitive Types
These are the most basic data type. They hold simple values and are not objects. Java has eight primitive data types.

1. **Byte**: 8-bit integer (e.g., `byte b = 10;`)
2. **Short**: 16-bit integer (e.g., `short s = 1000;`)
3. **int**: 32-bit integer (e.g., `int i = 123456;`)
4. **long**: 64-bit integer (e.g., `long l = 123456789L;`)
5. **float**: Single-precision 32-bit floating point (e.g., `float f = 1.23f;`)
6. **double**: Double-precision 64-bit floating point (e.g., `double d = 1.234567;`)
7. **char**: Single 16-bit Unicode character (e.g., `char c = 'A';`)
8. **Boolean**: Represents `true` or `false` (e.g., `boolean bool = true;`)

### Type Casting

Type casting is the process of assigning a value of one primitive data type to another type.

There are primarily two types of casting:

1. **Widening** casting (Automatic):
`byte` -> `short` -> `char` -> `int` -> `long` -> `float` -> `double`

```Java
int myInt = 10;
double myDouble = myInt; // Automatic conversion from int to double
System.out.println(myDouble); // Prints 10.0
```

2. **Narrowing** casting (Manual):
`double` -> `float` -> `long` -> `int` -> `char` -> `short` -> `byte`

A key point to remember is that narrowing casting must be done  by placing the type in the parentheses in front of the value.
`
```Java
double myDouble = 9.78;
int myInt = (int) myDouble; // Manual cast from double to int
System.out.println(myInt); // Prints 9 (the .78 is lost)
```

## Reference/Object Types
Reference types are used to refer to objects. They store the memory address of the object not the object itself. All non-primitive types are reference types, including arrays, classes and interfaces.

So what this essentially means that, an object can be instantiated with a variable name:

```Java
StringBuilder sb1 = new StringBuilder("hello");
```

And then another variable can point to the *same* object:

```Java
StringBuilder sb2 = sb1;
```

This is because initially `sb1` holds an address pointing to the `StringBuilder` object and when `sb2 = sb1;` is called it copies the address of the object to `sb2` and so they point to one single `StringBuilder` in the heap.
This means that any change that to the object `sb1` points to will also occur to `sb2`.

An object variable can also hold a special value: `null`. 

### Object Reference Casting
This doesn't change the object itself, but rather changes the type of the **reference** pointing to it, allowing it to access different methods.

1. **Upcasting** (Automatic):
This is where you cast from a subclass to a more general superclass or [[Interfaces|interface]]. This is completely safe and happens **automatically**.

For an example:

```Java
// A Dog is-an Animal, so this is safe and automatic.
Dog myDog = new Dog();
Animal myAnimal = myDog;
```

Now the `myAnimal` reference can only be used to call methods defined in the `Animal` class, even though the actual object is a `Dog`.

2. **Downcasting** (Manual):
Casting from a superclass reference back to its original, more specific to a subclass type. This *can* be unsafe since you can get a `ClassCastException` at runtime if the object isn't actually an instance of the target type. It must be done **manually** with parentheses `()` and should always be checked with `instanceof`.

For an example:

```Java
// We must check if the Animal is actually a Dog before casting.
if (myAnimal instanceof Dog) {
    // Manually cast the Animal reference back to a Dog reference.
    Dog myDog = (Dog) myAnimal;

    // Now we can call Dog-specific methods again.
    myDog.wagTail();
}
```

## Key Differences

1. The first key difference is **memory allocation**, Primitive Types are stored directly in the memory location associated with the variable. Reference types store the memory address of the actual data.
2. Primitive types have **default values** (e.g., `0` for numeric types, `false` for `boolean`, `\u0000` for `char`). Reference types default to `null`.
3. Primitive types do not have methods. Reference types (objects) can have methods and fields.

