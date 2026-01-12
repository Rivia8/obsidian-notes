24-10-2025 18:06

Tags: [[C]]

# Pointers

A **pointer** is simply a variable that holds an address, possible the address of another variable. We can declare a pointer by indicating the type of the pointed variable, followed by `*`, and then the name of the pointer.

```C
int v = 42;
int *ptr = &v
```

So here we have created an `integer` pointer called '`ptr`' that holds the address of the `integer` `v`.
Lets say for instance that `v` was stored at the memory address 0x1000, this means that `ptr = 0x1000` after we call that instantiate the pointer.
Now we have two variables, `ptr` that is held at some other memory address that holds the address 0x1000 and `v` which is **at** the memory address 0x1000 and holds the value of 42.

## Dereferencing Pointers

The `*` operator is kind of the opposite to the `&` operator, this is because the `*` operator makes it so that we get the value 
**from** the address held in the pointer.
From the example above if we were to perform the operation:
```C
printf("pointed value: %d\n", *ptr);
```

Instead of:

```C
pritnf("pointed value: %lx\n", ptr);
```

We would get the value of 42.

