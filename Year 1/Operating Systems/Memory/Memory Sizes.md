18-02-2025 13:22

Tags: [[Operating Systems]]

# Memory Sizes

## Virtual Memory

When it comes to the address spaces that can be allocated for virtual memory, it is determined by the **architecture** of the CPU, for example, a 32-bit architecture can address up to 4 Gb of Memory ($2^{32}$), while a 64-bit architecture can address a much, much larger space.

- 16-bit: ~65,000 addresses,
- 32-bit: ~4 billion addresses,
- 64-bit: ~1.8 $\times$ 10$^{19}$ addresses.

Where having larger address spaces introduces complexity in memory mapping and management.

After this the operating system then dictates how virtual memory is managed where different OS's have varying limits on the size of the virtual memory space they can handle.

## Physical Memory

This is dictated by the actual physical hardware that is installed in the system. The amount that is installed is influenced by a variety of factors like technological factors, economic factors etc.



![[Pasted image 20250218132445.png#invert]]


