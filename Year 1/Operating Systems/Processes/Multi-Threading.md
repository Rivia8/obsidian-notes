02-05-2025 22:32

Tags: [[Operating Systems]]

# Multi-Threading

**Multi-Threading** is the term that is applied both to running multiple [[Threads|threads]] and multiple [[Processes|processes]] at the same time.

The more accurate definition is that it's the ability for a **single process** to perform multiple **threads** at the same time.

Example:

Imagine a web browser:

- Thread 1: Renders the page
- Thread 2: Downloads images
- Thread 3: Runs JavaScript  
	All run "in parallel" (or interleaved) in the same process.
 

**Benefits:**

- It allows the program to be able to **decompose** the code into smaller pieces that are semi-independent (like the example above).
- Processors nowadays have been getting increasingly more cores, the 'average' now is 6c/12t, cores being complete processors, which allows the CPU to **actually** multi-task.

**Drawbacks:**

- One of the bigger drawbacks is that it is more **difficult for programmers**. "Traditional" programming is a lot easier since its more linear and sequential for multi-threading on the other hand programming in a way that lets the code run in an **unpredictable** order can get people confused.
- The code requires synchronisation with its complexity and contention between the threads. Pretty much, threads must sometimes all reach a certain point before they can move on or else something like **deadlocks** could occur.
