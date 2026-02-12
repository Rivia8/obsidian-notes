11-02-2026 13:51

Tags: [[System Architecture]]

# Caches

Caches speed up a spatially subset of access. Meaning they accelerate memory access. 
Another way of thinking about it is that *cache misses* have a performance penalty.

Every memory access can be thought of as one cycle plus a further penalty for each access which is discovered to miss.

$$\text{Average Cycle Time} = 1 + \text{miss rate} \times \text{miss penalty} $$
From this equation we can see that the performance will be ***significantly*** impaired if the miss rate is also high.

## Architecture

There are two main components:

1. The **tag**: identifies *which* elements are currently stored.
2. The **data memory**: holds a copy of a *subset* of the larger storage space.


![[Pasted image 20260212194012.png#invert]]

One tag can span across a block of adjacent addresses, this makes use of **spatial locality**.
The block is known as **cache line**.

There is also data such as ***validity*** which indicates if there is a copy there or not.

There are different names for cache architectures but mainly there are two approaches: **high associativity** and **low associativity**.

### Fully Associative Cache

This is the most flexible type of cache.
The main rule: Any block of memory can be stored in **any** line of the cache.

