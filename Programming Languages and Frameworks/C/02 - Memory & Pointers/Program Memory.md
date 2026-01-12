24-10-2025 17:45

Tags: [[C]]

# Program Memory

An understanding of memory in needed to fully grasp the concept of [[Pointers]]

All the data manipulated by a program is present somewhere in memory. 
The area of memory that is accessible for the program to read, write and execute is called the **address space**.

You can visualise the address space as a very large array of contiguous bytes:

![[memory.svg#invert]]
Each byte has an index into this array, named an address. Addresses range from 0 to the maximum addressable byte. On x86-64 the kernel configures virtual memory from addresses 0 to 128 TB to be accessible by each program.

## Addresses: Variable Addressing

Since code executed and data manipulated by the program reside in memory. Each variable has an address which is the first byte of location in memory.
We can get the address of a variable in C with the `&` operator. 

Look at the following example:

```C
int glob = 12;
char string[] = "abcd";

typedef struct {
    int member1;
    float member2;
} mystruct;

int main(int argc, char **argv) {
    mystruct ms = {1, 2.0};
    // With modern processors an address is a 64 bits value, so we need the
    // right format specifier: `%lu` or `%lx` if we want to print in hexadecimal
    printf("ms address is: 0x%lx, glob address is 0x%lx\n", &ms, &glob);
    return 0;
}
```

An address in a 64 bit architecture is 64 bits, so 8 bytes, meaning that it would be a `long` type.
Looking at the `struct` defined we have to variables:
1. an `int` (2 bytes minimum),
2. a `float` (2 bytes minimum), 

We also have the `string` within the `printf` statement.

If you look at the `printf` statement itself you can see that we are printing the address with the `l` type (long) and an `x`, the `x` specifies we want the the output to be in hexadecimal.

We can portray all this in memory:

![[layout.svg#invert]]

