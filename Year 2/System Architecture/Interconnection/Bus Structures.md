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


![[Pasted image 20260209164742.png#invert|200]]

Most high performance use Von Neumann but they typically use Harvard-style at the cache level with separate buses. 
These connect different processor pipeline stages to parallel **caches**.
This allows the CPU to do two things at once, it can fetch an instruction from the I-Cache whilst *simultaneously* writing a variable to the D-Cache. This double the bandwidth at the most critical part of the pipeline.

Because the I-Cache and the D-Cache are physically separate, they do not automatically sync with each other instantly.
The problem with this is that if you are executing **self-modifying code**, they take the code and write **new** machine code *while* the program is running. The CPU then writes this new data into the **D-Cache**. The problem with this is that the I-Cache might still be holding a copy of the *old* memory at the address, or it simply doesn't know that the D-Cache has new information.

The solution to the above problem is **Memory Barriers and Flushing:**
When a JIT compiler finishes writing new code, it cannot just jump to it. Cleaning must be performed:
1. **Memory Barrier:** this forces the CPU to finish all current writes to the D-Cache (ensure the new code is actually saved)
2. **Cache Flush:** It sends a signal to the **I-Cache** saying "hey the data at Address X has changed".
3. **Reload:** The next time the CPU tries to execute code at address X, the I-Cache sees it is invalid, reaches out to main memory to get the fresh version and everything works correctly.

In standard processors, we have **Symmetric Multi-Processing (SMP)** -  we have many cores that act as standalone CPUs:

![[Pasted image 20260209173624.png#invert]]

Each is a fully capable processor.

You can have different arrangements for different processors:

![[Pasted image 20260209174131.png#invert]]

Above is the example of a DSP (Digital Signal Processor).
DSPs perform matrix multiplication and so they need to read pairs of operands at high speeds (2 or more buses for efficiency).