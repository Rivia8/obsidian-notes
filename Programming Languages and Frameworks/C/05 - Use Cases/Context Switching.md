19-11-2025 13:02

Tags: [[C]] [[Operating Systems]]

# Context Switching

*This is assuming a single core processor, since a multi-core processor will be able to perform and execute programs concurrently.*

Each task has its own code and stack, context switching can only occur **by the kernel**.
If we have a **system call** or **hardware interrupt** it may invoke a context switch.

![[switch-detailed1.svg#invert|500]]

When this occurs the CPU will be in supervisor mode and the instr. pointer will point to the kernel code:

![[switch-detailed2.svg#invert|500]]
Usually the OS will check if there is a task ready with a higher priority, if we assume task B is ready, and its priority is higher than the currently running task, the scheduler will run that instead.

**In order to preserve the state of the task that was mid-way through the completion, a context switch operation needs to be started by saving the state of the task getting scheduled *out* of the CPU, by putting it in the corresponding kernel stack (Task A's KStack).**

We now need to try doing task B, in order to do so we need to retrieve Task B's register saved states from *its* corresponding place within the stack and **pop** it to the registers then the execution of B can resume (the kernel returns to user space).


