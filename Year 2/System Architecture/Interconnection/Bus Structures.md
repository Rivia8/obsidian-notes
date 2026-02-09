09-02-2026 15:36

Tags: [[System Architecture]]

# Bus Structures

The classic computer architecture as *perceived* by the programmer is the [[Vonn Neumann Architecture]].
Essentially it has unified memory that holds both instructions and data.

The most common alternative is **Harvard Architecture**, where instructions and data are in separate address spaces.

![[Pasted image 20260209154840.png#invert]]

Harvard:
- Offers more flexibility, data and instructions words can be different sizes,
- Fetches can be made in parallel with data movement (overcomes the memory bottleneck)

Von Neumann:
- Simpler and convenient for programmers, 
- Available memory can be partitioned dynamically into code and data segments as is currently appropriate.
- Data and code can be interchanged.
- Most contemporary 'big' computers (x86, ARM) use Von Neumann architecture.
- Not all are purely Von Neuman, some contemporary embedded controllers (e.g. the AVR used in the Arduino controller boards) utilise Harvard Architecture.

## Harvard Architecture at the Cache Level

Most high performance use Von Neumann but they typically use Harvard-style at the cache level with separate buses. 
These connect different processor pipeline stages to parallel **caches**.

When an object code has been written it is usually necessary to provide some sort of **memory barrier** which ensures that the writes are complete before trying to read them.





