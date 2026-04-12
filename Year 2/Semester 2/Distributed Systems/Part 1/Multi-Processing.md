12-04-2026 18:47

Tags: [[Distributed Systems]]

We look at multi-processing in order to alleviate the heavy bottleneck from [[Simple Processing|simple processing]].

![[Pasted image 20260412184949.png#invert]]

First we have to distinguish between **multi-tasking** and **multi-processing**.
These are two different concepts that are mistakenly used as synonyms.

## Multi-Tasking

This is what we commonly see with simple machines or single-core processors and is commonly seen [[Processes|within Operating Systems]] and how they deal with lots of processes running.

What happens is that the processor will switch very quickly between processes and gives them each a "time slice" (a few milliseconds of CPU time). Every time this happens, the CPU has to do something called [[Processes#Context Switching|Context Switch]] which is ensuring that the contents of the CPU remains consistent with each process when its their turn.

## Multi-Processing

This is what is known as **True Concurrency.**
