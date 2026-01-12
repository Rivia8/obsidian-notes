30-04-2025 19:28

Tags: [[Operating Systems]]

# Threads

A thread is almost a component of a process.
They are similar to processes and are sometimes called 'lightweight processes', they belong **within** processes.
The simple model is to have one thread in each process **but** to prevent the idea of a thread to being useless, any process could have multiple threads.
Threads will share their [[Processes#Context|Context]] but will also have some private data space such as processor registers and their own stack.

![[Pasted image 20250430193358.png#invert]]

Threads within the same process share access to resources such as peripherals devices and files. They also share the a virtual memory map.

The way to make a distinction between threads and processes:
- A process is like a container
- A thread is like a worker inside of a container

When you have an instance of a program in execution:
It has:
- Its own **memory space**,
- its own **resources**,
- At least one **thread** (the main one).

The process can be thought as a self-contained mini-computer that runs the program and protects it from others.

 A **thread** is:
 - A path of execution within a process,
 - It shares the process's memory and resources,
 - Has its own program counter, register set, and stack (so it knows where it's at and what it's doing).

| Feature       | Process                                  | Thread                                                          |
| ------------- | ---------------------------------------- | --------------------------------------------------------------- |
| Memory        | Has its **own memory space**             | **Shares memory** with other threads in the same process        |
| Communication | Hard (requires IPC)                      | Easy (same memory)                                              |
| Overhead      | High (creation, switching, isolation)    | Low                                                             |
| Failure       | One crashing process won’t affect others | One bad thread can crash the process                            |
| Example       | Chrome tab or VS Code window             | Tab rendering, network fetch, or spell check all run as threads |

**Game Dev Analogy:**

- The game app is a process, i.e. **Terraria.exe**
- Inside it:
	- One thread handles rendering the **graphics**,
	- Another thread plays **audio**,
	- Another handles **input**,
	- **They all work together but have different paths of execution**


## Thread Management

Threads may be managed by the operating system scheduler **or** by a separate scheduler in the application.

Thread management by the user typically allows for faster thread switching (since there is no need for system calls) and the scheduling can be tailored to the application.
The problem with this is that **cooperative scheduling** may need to be utilised which relies on the threads being **well-behaved**.
A disadvantage to managing threads at **user-level** is that it requires its own management software for creating, tracking, switching, synchronising and destroying threads (which can be in the form of a library).


**Pre-emptive V Cooperative**

| Type        | Description                                 | Who decides when to switch |
| ----------- | ------------------------------------------- | -------------------------- |
| Preemptive  | OS interrupts a thread to switch to another | OS Scheduler               |
| Cooperative | Threads voluntarily yield control           | The thread itself          |

