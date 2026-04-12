12-04-2026 18:47

Tags: [[Distributed Systems]]

We look at multi-processing in order to alleviate the heavy bottleneck from [[Simple Processing|simple processing]].

![[Pasted image 20260412184949.png#invert]]

First we have to distinguish between **multi-tasking**, **multi-processing** and **Parallel Computing**.
These are two different concepts that are mistakenly used as synonyms.

## Multi-Tasking

This is what we commonly see with simple machines or single-core processors and is commonly seen [[Processes|within Operating Systems]] and how they deal with lots of processes running.

What happens is that the processor will switch very quickly between processes and gives them each a "time slice" (a few milliseconds of CPU time). Every time this happens, the CPU has to do something called [[Processes#Context Switching|Context Switch]] which is ensuring that the contents of the CPU remains consistent with each process when its their turn.

You then have different forms of [[Process Scheduling]] in order to make sure that each process gets its fair share of processor time or to make sure a certain criteria is met.

## Multi-Processing

**Multi-processing** is more of an addition to multi-tasking. This involves either **forking** or **threading** an existing process in order to create more processes.

### By Forking

Forking is done via an OS call. It causes two copies of itself to be active concurrently and the child process is given a copy of the parent's address space. 

The address spaces however are distinct and so whatever the child process does is completely safe. This makes this method extremely safe.

The drawback is that copying an entire memory space can be expensive.

### By Threading

Threading was invented as a lightweight alternative to forking.
Instead of cloning the entire program, threading on the other hand creates a new execution path within the *same* program.

Threads share the exact same address space.

This makes threading threading a lot **faster** and more **efficient** compared to forking they can also communicate instantly since they are utilising the same variables.

However, this is fundamentally unsafe, 


## Parallel Computing

This is what is known as **True Concurrency.**

