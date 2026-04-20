21-03-2026 13:28

Tags: [[2 - Tags/System Architecture]]

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

## Ideal Pipeline

The ideal pipeline is to have an increase throughput with little increase in cost.
How?:
- Repetition of **identical operations**.
- Repetition of **independent operations**
- **Uniformly partitionable sub operations**
	- Processing can be evenly divided into latency-uniform sub operations that do not share resources.

## None-Ideal Pipeline

- Non-identical operations
	- Forcing different instructions to go through the same stage pipe stages 
- Non-uniform sub operations
	- Need to force each stage to be controlled by the same clock. Can cause **internal fragmentation**.
- Dependent operations
	- Can cause pipeline stalls

## Deeper Pipelining

If slicing a processor into 5 stages make its 5 times faster, why can we not slice into 100 stages to make it 100 times faster.

Since the system clock only has to wait for the slowest stage to finish, a shorter stage means you can tick the clock much faster, so clock frequency ideally increases.

The problem with this:
- Splitting **requires** **more hardware**
- Becomes hard to have **uniform chunks**
- Each stage has **register delays** - the pipeline buffers themselves takes a tiny fraction of a nanosecond to open, save data and close, this can produce bottlenecks.
- Can generate **a lot of heat**

A deeper pipeline can make [[Handling Data Dependencies|data dependencies]] much worse:
- More forwarding
- More collisions
- Greater penalty for hazards - incorrect CPU branch guesses requires pipeline flushes, a pipeline with 4 stages is minor compared to one with 30 stages.

