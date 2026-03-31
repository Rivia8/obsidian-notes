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
- Process a **different** instruction in each stage.

The **main** benefit is that more work can be done per unit time which leads to increased instruction processing throughput.

## Hardware Changes 

We need some hardware changes to **accommodate** the 'pipelined' process.

![[Pasted image 20260331141234.png#invert]]

Instead of direct connection between stages, you use extra buffers to hold the state of each stage.
- So once the 'fetch stage' finishes grabbing the first instruction, its held in a buffer whilst the 'fetch stage' then fetches the next instruction.
Clock buffers once per cycle.
- Every time the clock ticks, all the buffers buffer for a split-second, the data in stage 1 moves to the buffer for stage 2
If all stages are homogeneous  (the same propagation delay) clock speed is increased by 5x.



