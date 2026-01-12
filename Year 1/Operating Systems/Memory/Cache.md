03-04-2025 18:11

Tags: [[Operating Systems]]

# Cache

A **cache** is a copy of a small subset of some large data data set and because it is small it is fast and convenient to get at.

A memory cache is a small, fast memory that is close to the processor.
In high performance machines, the cache may be comprised of two or more 'levels', the smaller levels are faster and closer to the processor, and bigger and further away are closer.

![[Pasted image 20250403182046.png#invert]]

Because L2 and L3 use physical addresses they will need translating.

Cache usually are self-managing but occasionally need software intervention which the operating system will handle.

Cache relies on **temporal** and **spatial** locality (memory addresses used frequently and memory addresses that are close together).

The operation that the cache goes through is that it intercepts outgoing requests to memory, if it recognises the location it retrieves it quickly, if not then then the operation proceeds as normal.

Caching not only occurs in Cache but also the [[Memory Management Unit (MMU)#TLB|TLB]], [[Virtual Memory]] and between RAM and hard-disks.

A shared-memory multiprocessor will have separate L1 caches for instructions and data (using virtual addresses). Further down, the cache hierarchy (the slower cache levels) the cores can share the cache:

![[Pasted image 20250403184428.png#invert]]



- - -

![[Pasted image 20250415144111.png]]

*In terms of general application of a cache, as in maybe DNS hosting, ISPs etc:*

So looking at the image, we can see that we can utilise the cache as a closer point to the 'stuff' it needs to reach, this reduces the 'cost' involved for searching. These 'costs' could be things like energy.

**Drawbacks:**

- Cache gets full: Need a policy for replacing things
- Cache goes stale: Need to know when to flush and put things that are actually needed

For the first point, we can have different cache **eviction** strategies:
- **LRU** (Least Recently Used)
- **Random**
- **Cyclic**

