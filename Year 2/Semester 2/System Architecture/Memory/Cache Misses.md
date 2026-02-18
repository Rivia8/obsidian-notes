
18-02-2026 14:36

Tags: [[System Architecture]]

# Cache - Action on Miss

There are three different types of cache 'misses':

1. **Compulsory Miss:** This occurs when a cache is first filled (the cache will start off empty until there is data in the cache, for there to be data in the cache misses are needed)
2. **Capacity Miss**: This is in reference to the working set (the set of items which are 'in-uses' over a period of time). If the working set exceeds the size of cache, it cannot all be cached.
3. **Conflict Miss**: Conflict misses can occur when a cache has *limited* *associativity*.

*Higher Associativity is desirable in small caches, a small cache will have fewer cache lines (in each set) and so the probability of a conflict is greater. To reduce the probability of a conflict you would increase the associativity.*




