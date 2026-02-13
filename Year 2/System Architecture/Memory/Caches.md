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

The way it works:
- You have a 16-bit architecture
- A cache line is 4 words, 4 * 16 / 8 = 8 bytes
- In the 16-bit tag the 3 LSBs are used for identifying which block the data is in.
- The remaining 13 bits are the Tag
	- i.e. `0x2002`: `0010 0000 0000 0010` the offset at the end points to byte 2
	- The tag is `0010 0000 0000 0`

In the lookup process, every **cache line's** tag is compared to the tag you're looking for. When the cache line corresponding to that tag is found, then the offset is used to find the specific byte.

**Advantages:**
This has the most efficient use of space. You will almost never get a cache miss unless the cache is too small.

**Disadvantages:**

- Extra Hardware:
	- If your cache has 1024 lines, you need 1024 **comparators** (the device that compares each **cache lines** tag to the tag you're looking for)
- Power:
	- Lots of comparators needs more power.
- Speed:
	- The electronics have to wait for the comparison result before they know *which* data to output, this can be slower than simpler caches that know exactly where to look.


### Direct Mapped Cache

