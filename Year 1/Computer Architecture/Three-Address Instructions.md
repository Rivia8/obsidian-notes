01-10-2024 12:22

Status: #new 

Tags: [[Architecture]] [[Vonn Neumann Architecture]]

# Three-Address Instructions
Its called three-address instructions as three addresses are utilised 
The steps are:
- Copies the input values from two memory locations into the processor, **Source Operands**
- Performs some operation
- Copies the result back from the processor into a third memory location ,**Destination Operand**
- The instruction combines the operation and three operands

![[Pasted image 20241001122614.png#invert]]

More complex operations will result a three-address computer needed a sequence of instructions in order to carry it out:

![[Pasted image 20241001123146.png#invert]]

However, this will cause something called a **memory bottleneck**, this is due to processors being too fast for memory, memories are designed to be big and cheap.
Memories and buses typically allow only one action at a time.
This means that much of computer architecture is a about avoiding Von Neumann bottlenecks.

**Memory Cost of 3-Address Instructions:**
Each 3-address instruction requires at least 3 memory cycles but in practice it's at least 4 memory cycles as the instruction lives in memory. The instruction is read in memory and memory is much slower than the processor, most of the program time is spent on memory.

This causes an inefficiency when look at more complex operations where more instructions are needed to be read from memory and so more time is spent.
This means that straightforward Von Neumann machines are inefficient.
