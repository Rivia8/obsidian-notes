08-01-2026 13:39

Tags: [[Processor Microarchitecture]]

# GPUs

CPU and GPU architecture contrast heavily.

**CPU's Philosophy**: they have a Latency Orientated philosophy where they are designed to minimise the time taken to complete a single task. It uses large caches and complex control logic to ensure that one thread runs as fast as possible.

**GPU Philosophy:** these have a **Throughput Orientated** philosophy. What this means is that they are designed to maximise the volume of work done in a set time, it tolerates long delays (latency) for individual tasks as long as the total number of completed tasks (like pixel rendered) is high.

**An Analogy:**
- **CPU:** Good for generating the logic of a game frame (*Frame 0, Frame 1, Frame 2...*) sequentially and quickly.
- **GPU:** Good for rendering the millions of pixels within those frames. It might take milliseconds to get the data back (high latency), but it processes millions of pixels in parallel.


When it comes to architecture, there are vast differences between CPUs and GPUs:

| **Feature**       | **CPU Allocation**                                                                                       | **GPU Allocation**                                                                          |
| ----------------- | -------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| **Control Logic** | **Huge:** Complex branch prediction and out-of-order execution logic to keep one thread moving fast5555. | **Tiny:** Simple control shared across many ALUs. It assumes threads run in groups (SIMT)6. |
| **Cache**         | **Huge:** Up to 50% of the chip. Needed to hide memory latency for a single thread7777.                  | **Tiny/None:** GPUs don't rely on caches to hide latency (see section 3 below)8888.         |
| **ALUs (Cores)**  | **Few:** (e.g., 4-16 powerful cores)9.                                                                   | **Massive:** (e.g., thousands of simpler execution units)10101010.                          |

![[Pasted image 20260108135354.png#invert]]


In order to mitigate the affect of latency (since they don't use large caches), they utilise **massive multithreading**.
A GPU might have 10,000 threads active at once, where context switching on a CPU is expensive, on a GPU, context switching is **free** (happens in 1 cycle). So let's say Thread A needs to fetch some data from memory (which takes hundreds of cycles), the GPU instantly pauses Thread A and runs Thread B. By the time it cycles through threads B, C, D... Thread A's data has arrived. This results in the memory latency being hidden by the sheer volume of other work being done.

| **Feature**        | **CPU**                           | **GPU**                                   |
| ------------------ | --------------------------------- | ----------------------------------------- |
| **Goal**           | Low Latency (Speed for 1 task) 18 | High Throughput (Volume of tasks) 19      |
| **Cores**          | Few, Complex (Sequential) 20      | Many, Simple (Parallel) 21                |
| **Threads**        | Tens per core 22                  | Thousands per chip 23                     |
| **Caches**         | Large (to hide latency) 24        | Small/None (Latency hidden by threads) 25 |
| **Context Switch** | Expensive (Save/Restore state)    | Free (Hardware supported) 26              |
| **Best For**       | OS, branching logic, I/O 27       | Graphics, Matrices, Deep Learning 28      |