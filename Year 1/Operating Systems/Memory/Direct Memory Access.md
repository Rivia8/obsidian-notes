15-04-2025 14:12

Tags: [[Operating Systems]]

# Direct Memory Access (DMA)

*This has already been looked at in [[Transferring Data#Direct Memory Access (DMA)|Computer Engineering]] but is going to be discussed again for Operating Systems.*

Some processes that the need computing are repetitive and tedious especially for things regarding input and output.
The CPU can do these 'tedious' tasks but it is inefficient:
- Can spend many idle intervals waiting for the next byte,
- Energy-efficiency maybe poor,
- Time could be spent doing more 'complex' tasks.

To do this we employ the use of a piece of hardware known as the **DMA** controller. 
It is essentially a simple processor that moves data and counts how much it has done.

![[Pasted image 20250415142234.png#invert]]


