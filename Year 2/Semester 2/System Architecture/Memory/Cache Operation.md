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
Since there are no "index" and data can be anywhere (isn't fixed to select cache lines) you would have to read every single line (using the method above) this is very slow and will use a lot of energy.

In order to fix this there is a slower two step process that utilises **CAM**.

## Content Addressable Memory **CAM**

This is a special type of hardware.

First recap RAM:
- Input: An address
- Output: The Data
You already have the address, you just go there to get the data

**CAM** is associative memory.
- Input: The Tag
- Output: The address
Here you have **less** information, and so you're getting data about where the data is.

The **Process:**
1. **CAM Search** - The Cache Controller sends the **Address Tag** into the CAM array. The CAM searches all entries in parallel (instantly). If the tag is found it outputs a "Match Line" signal.
2. That "Match Line" signal is then used as a simple address to read the actual data RAM. It extracts the data from line #3 and sends it to the CPU.

This is efficient (in time) because CAM hardware checks all items in a single clock cycle, $O(1)$, the only drawback is the amount of transistors and electricity to perform the operation.

![[Pasted image 20260216150027.png#invert]]




