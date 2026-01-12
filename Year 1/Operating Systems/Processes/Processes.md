25-04-2025 13:15

Tags: [[Operating Systems]]

# Processes

For the Operating Systems unit, the details of machine code are not considered, we can think of instructions as lines of source code.

When it comes to the computers that we have, you notice that a typical OS will have multiple simultaneous processes, and most of these processes will be unaware of the other. Each process will have its own [[Processes#Context|context]], as in you can have the multiple of the same instance of the same application running without them interfering with each other.

A process will have its own **address space**.
The process could face different **status updates** where the **task scheduler** might cause it to be 'blocked' or 'pushed aside'.


## Unix Process Structure

In Unix-like systems, there is a hierarchy of process where each process has a [[Parent and Child Processes#Parent Processes|parent ]]process.

![[Pasted image 20250425195341.png#invert]]

- Processes are created using system calls like `fork()` or `clone()`
- Unix-like systems use tools like the **PCB**  ([[Processes#Process Control Block|Process Control Block]]) to manage processes.

You also have other process types that might occur: [[Zombie Process|zombie processes]], [[Daemon Processes|daemon processes]] and [[Orphan Process|orphan processes]].
## Context

The context is the environment that the process operates within, which includes its variables, and the resources which it 'owns'.
This will be kept in main memory.

There will be a [[Processes#Process Control Block|Process Control Block]] (PCB) associated with the process, this holds/points to information (process' identity, parent, priority etc.)

A simple one core, one thread processor, can only run one process at a time. When you say that it is running multiple processes at the same time what is really meant is that one is running for a 'short' time, then context switching to another and so on:

![[Pasted image 20250425214237.png#invert]]

### Context Switching

This is the process where the CPU **pauses one process** and **resumes another**, this is to continue the illusion of multi-tasking.

## Process Control Block

This essentially holds information about the process. It holds information about:
1. Process Identification - PID
2. Process State
3. CPU registers and Program Counter
4. Memory Management Information
5. I/O Status Information
6. Scheduling Information
7. Accounting and Resource Usage

![[Pasted image 20250425222024.png#invert]]

The PCB is a data structure, and is stored in **kernel memory.** 

---

Between the two concepts:

**PCB**: Static metadata about the process.
**Context**: Dynamic runtime state of the process, specifically related to the CPU.
