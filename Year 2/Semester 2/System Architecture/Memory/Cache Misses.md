
18-02-2026 14:36

Tags: [[System Architecture]]

# Cache - Action on Miss

There are three different types of cache 'misses':

1. **Compulsory Miss:** This occurs when a cache is first filled (the cache will start off empty until there is data in the cache, for there to be data in the cache misses are needed)
2. **Capacity Miss**: This is in reference to the working set (the set of items which are 'in-uses' over a period of time). If the working set exceeds the size of cache, it cannot all be cached.
3. **Conflict Miss**: Conflict misses can occur when a cache has *limited* *associativity*.

*Higher Associativity is desirable in small caches, a small cache will have fewer cache lines (in each set) and so the probability of a conflict is greater. To reduce the probability of a conflict you would increase the associativity.*

## Choosing a Line

When a cache miss has occurred a check is made that the requested address *can* be cached (some addresses should not be considered for caching).
In a [[Caches#Direct Mapped Cache|Direct Mapped Cache]], there isn't a choice but in cache architectures with more associativity, there *is*. When there is a choice, the first choice may be a place which is current *invalid*. 

There may be an instance where all candidate lines are valid and there is a *capacity miss* (all cache lines are full) so we need an **eviction strategy**:

### Cyclic Replacement

Uses a simple rotating hardware pointer, i.e. you evict the data in Slot 0, then Slot 1, then slot 2, looping back to the start when it reaches the end. 
There can be significant performance degradation if you're constantly looping through 3 variables but your cache set only holds 2.

### Random Replacement

Rolls a hardware die (usually a fast pseudorandom number generator) and picks a random cache line to overwrite.
This avoids the problem of getting stuck in a loop that can be experienced with cyclic replacement. The performance degradation is smooth and predictable too.

### LRU - Least Recently Used

This keeps track of when you last touched a piece of data. It is based on the assumption that if something hasn't been used in a while, it is not likely to needed again. 
This can still suffer from pattern issues. The main disadvantage is that it requires more state (storage) to be kept and it can be quite complicated to implement.

### Fetching the Line

Whilst picking a cache line with the above process, it may be possible to be fetching the new line in parallel. It is important to start this early to reduce *latency*.
Whilst the fetch is taking place, the processor is **stalled** (in the basic case) and so losing performance - the latency impact can be serious.

In something like a page fault, the delay is millions of cycles but with a cache miss is just a few hundred cycles so it cannot just swap out the processes via software (like in a page fault), so instead of the OS doing it in software, modern CPUs use hardware thread switching.

## Cache Prefetching

One of the ways of avoiding the penalty caused by cache misses, is to reduce the number of cache misses. This can be done by **speculation** - predicting and fetching lines before they might be wanted.

**Instruction Prefetching:** If you are on line 10, it fetches line 11, 12 and 13. But the problem is that if on average the code branches every 7 instructions, the CPU might prefetch a bunch of instructions but hit an `if` statement that jumps somewhere else leading to all that prefetched data to be thrown away.

**Hardware Data Prefetching:**  many instruction sets (like x86 or ARM) give the programmer a specific `prefetch` command. You put this inside a loop to tell the CPU to perform a 'dummy' read. This adds extra instructions but hides the massive 200-cycle RAM delay.

**Data-Orientated Design**: If you organise your structs and arrays so that data accessed together is stored next to each other in memory, you maximise spatial locality.

## Flushing

Every so often there is a need to **flush** a cache (invalidate its contents). The most common reason is probably a *context switch* where the translation of *virtual addresses* is redefined. This means that the virtual-addressed cache has to be dumped.

## Write Allocation

If a **write miss** occurs, it is a good idea to fetch and cache the line which contains the data.

### Which Architecture is the Best?

