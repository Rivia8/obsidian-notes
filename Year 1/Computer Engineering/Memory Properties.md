20-12-2024 17:25

Status: #new 

Tags: [[Computer Engineering]] [[Memory]]

# Memory Properties
There are a number of storage devices that are come under the 'Memory' category.
## Memory Hierarchy
When it comes to memory design, there is a fundamental challenge that involves balancing three competing factor:
1. Capacity (Density of Storage)
2. Speed (Access Time)
3. Cost (Price per Bit of Storage)

Typically, these factors work against each other - you can't optimise all three simultaneously without compromising at least one. This has led to the development of a memory hierarchy where different technologies are used at different levels to achieve the best possible balance.

![[Pasted image 20241220172852.png#invert|500]]


## Register Bank
A register bank, sometimes called a register file, is the fastest and most accessible form of storage in a computer system.
- It is located directly within the CPU
- Provides the fastest possible access times compared to any other memory type
- Typically accessible within a single CPU clock cycle

- Unlike MU0's single accumulator, modern processors have multiple registers
- Common configurations include:
    - ARM processors: 16 registers
    - MIPS processors: 32 registers
    - Other architectures may have different numbers

In the memory hierarchy, registers represent "Level 0" - the closest and fastest storage to the CPU's processing units. This makes them crucial for program performance, as operations using registers are significantly faster than those requiring access to any other type of memory, including cache. 

### Purpose and Usage:
1. Temporary Storage:
    - Holds operands (values to be processed)
    - Stores immediate results from calculations
    - Keeps frequently accessed variables
    - Maintains program counters and status information
2. Direct Addressing:
    - Registers are addressed differently from main memory
    - In ARM, for example, "R7" refers to Register 7, which is distinct from memory address 7
    - This separate addressing scheme allows for faster access

## Caches
The concept of cache memory is based on two important observations:
1. Programs typically spend 90% of their time using only 10% of their code (locality principle)
2. Larger memories tend to be slower than smaller ones

Cache memory works on two types of locality:
1. Spatial Locality: If a program accesses one memory location, it's likely to access nearby locations soon
2. Temporal Locality: If a program accesses a memory location, it's likely to access it again soon

Cache Operations:
1. When the CPU needs data/instructions, it first checks the cache
2. If the data is found (cache hit), it is retrieve quickly
3. If the data is not found (cache miss), it is fetched from main memory
4. When fetching from main memory, nearby data is often also cached (prefetching)

### Cache Hierarchy
Modern systems often implement multiple levels of cache:
- L1 Cache: Integrated Directly on the CPU chip, smallest but fastest
- L2 Cache: Larger but slightly slower, may be on or off the CPU chip
- L3 Cache: Even larger but slower, becoming more common in high-performance systems

### Cache Hit Rate
The **cache hit rate** is a measure of the percentage of accesses that result in the information being found in the cache.

If we assume that an access to memory takes a conservative 10ns, but an access to cache takes 2ns, then depending on the cache hit rate we can improve the average access time.

- With 50% hit rate: Average access time = (0.5 × 10ns) + (0.5 × 2ns) = 6ns
- With 75% hit rate: Average access time = (0.25 × 10ns) + (0.75 × 2ns) = 4ns