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
2. The **data memory**:  holds a copy of a *subset* of the larger storage space.


