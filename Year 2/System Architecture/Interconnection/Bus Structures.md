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
- Simpler and convenient for programmers, available memory can be partitioned dynamically into code and data segments as is currently appropriate.
- 

