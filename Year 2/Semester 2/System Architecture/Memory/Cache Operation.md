16-02-2026 13:52

Tags: [[System Architecture]]

# Cache Operation

In operation an incoming address, it is logically divided up into fields.

The middle of the address (the index) is taken and then we go to directly to that specific row in the cache array. It ignores the rest of the cache.

In a [[Caches#Direct Mapped Cache|Direct Mapped Cache]] the single tag at that index.
In a [[Caches#Set Associative|Set Associative Cache]] it checks the tags of all 2 or 4 blocks in that set simultaneously.







