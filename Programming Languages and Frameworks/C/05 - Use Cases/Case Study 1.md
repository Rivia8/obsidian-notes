19-11-2025 13:37

Tags: [[C]] [[Operating Systems]] 

# Case Study 1

Here we will look at [[Context Switching]] and [[System Calls]] within the Linux operating system.

The Linux is the most widespread OS kernel (whilst although holding a small market share in the desktop market).
It is open source so you can see the source code yourself.

# System Calls and Entering the Kernel

We first look at the `nanosleep` system call, it involves both a [[System Calls|system call]] and [[Context Switching|context switching]]. 

When we get the `nanosleep` call, an exception is raised and the user space program's execution is interrupted. The CPU switches to supervisor mode, and jumps to a predefined piece of kernel code, the **system call entry point**. 
The kernel has the entry point defined as the label `entry_SYSCALL_64` in an assembly file.

The assembly code starts by saving the user stack pointer in a 'scratch' space and switching the stack pointer register to a kernel stack, the reason for this is that sharing a stack between a user and kernel space would be unsafe.

Next the registers of Task A are pushed to the kernel stack (so it can be restored later).

After that the system call entry point is going to jump to a function in C code, this function takes 2 arguments. The first parameter is a pointer to a data structure of type `pt_regs`, this contains the state of the CPU that was just pushed to the stack. The second is the identifier for the system call being invoked: in the case of `nanosleep` it will be 35.

*See [here](https://olivierpierre.github.io/comp26020/22-os-kernel-case-study.html)* since it is quite complicated and hard to understand.
