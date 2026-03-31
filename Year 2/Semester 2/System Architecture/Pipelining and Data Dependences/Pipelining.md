21-03-2026 13:28

Tags: [[System Architecture]]

# Recap:

![[Pasted image 20260321160635.png#invert|400]]

- ISA = [[Instruction Set Architectures]] 
- Microarchitecture = Specific Implementation of the ISA, not directly exposed to the programmer.
- The process of executing an instruction is called the **instruction cycle** or processing cycle

# Pipelining to Achieve Concurrency

Pipelining is the assembly line principle applied to executing software instructions.
Instead of waiting for one instruction to completely finish before starting the next one, the CPU breaks the execution down into smaller, distinct stages and overlaps them.

How we can do it:

When an instruction is using some resources in its processing phase, we can **process other instructions on idle resources** (doing things with components that are not in use).

- Divide the instruction processing cycle into distinct "stage" of processing,
- Make sure that are enough hardware resources,
- Process a **different**



