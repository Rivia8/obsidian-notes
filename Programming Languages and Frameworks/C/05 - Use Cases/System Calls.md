19-11-2025 12:46

Tags: [[C]] [[Operating Systems]]

# System Calls

When a user space task is executing on the processor, the CPU state of this task consists in the value present in the processor registers.

![[syscall-detailed1.svg#invert|800]]

We have general purpose registers used for computations, but also special-purpose ones such as stack and instruction pointers.

When running user programs the CPU is in **user mode**, 
When a system call is issued `syscall`, the CPU switches to **supervisor** mode, also known as kernel mode. When the CPU is in kernel mode, it can do privileged operations (all operations that is supported by the CPU).
The CPU also does some things in terms of the stack:

1. The CPU jumps to a predefined *system call handler* in the kernel which switches to the kernel stack

2. The kernel starts by saving the application state by pushing all registers on the kernel stack.

3. The kernel determines which system call is invoked and starts processing it. When it has been processes the kernel restores the task state by popping all registers from the kernel stack.

4. And then the user space execution resumes at the next instruction following the system call invocation instruction.






