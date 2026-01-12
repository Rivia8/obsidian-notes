17-10-2025 18:22

Tags: [[C]]

# Enumeration

**Enumerations** are textual names that are mapped by the compiler to integer constants under the hood.
They are a special type that represent a group of constants, here is an example:

```C
enum level{
	LOW,
	MEIDUM,
	HIGH
}
```

To access an `enum` you must create a variable of it:

```C
enum level myEnum;
```

Any value (that is applicable) can be assigned to the `enum`:
`
```C
myEnum = HIGH;
```

As we said before under the hood an `enum` just holds integer values, this means that by default the first value will hold 0, the second 1 and the third 2 and so on. But we can change what `int` each value represents for a better application for a certain use case:

```C
enum level {
	LOW = 5,
	MEDIUM, // Now 6
	HIGH // Now 7
}
```

Now if we were to do:
```C
printf("%d", myEnum)
```

We would get an `int` of 7 instead of 2.

We can use [[Custom Types|typedefs]] (like we did for `structs`) in order to make instantiating one type of `enum` easier :

```C
// Without typedef  
enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};  
enum Day today = WED;  
  
// With typedef  
typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN} Day;  
Day today = WED;
```

