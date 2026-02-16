16-02-2026 13:52

Tags: [[System Architecture]]

# Cache Operation

In operation an incoming address, it is logically divided up into fields.

The middle of the address (the index) is taken and then we go to directly to that specific row in the cache array. It ignores the rest of the cache.

Once we're at that bit, the hardware reads the tag stored there, it compares this stored tag against the **tag** from your address;
- In a [[Caches#Direct Mapped Cache|Direct Mapped Cache]] the single tag at that index.
- In a [[Caches#Set Associative|Set Associative Cache]] it checks the tags of all 2 or 4 blocks in that set simultaneously.

Finally, we either get a hit or miss:
- **Hit**: The comparator circuit signals a match. The data is routed to the CPU/
- **Miss**: The cache reports a miss, the CPU must now go to main RAM (which is slow to fetch the data).


**The problem with fully-associative cache:**
Since there are no "index" and data can be anywhere (isn't fixed to select cache lines) 




