18-02-2025 13:57

Tags: [[Operating Systems]]

# Memory Mapping

Computer memory is a physical storage medium where it holds one data item per location.
A running process uses an address to specify a location to **load** data from ore **store** data to memory.

Each process has its own, independent set of addresses it wants to use. It's like each program having its own separate notebook to work in, without seeing what other programs are writing.

When multiple programs run simultaneously, it is imperative that they do not accidentally access or modify each other's data in memory. 

It is possible to to resolve this issue by manually assigning each process its own memory ranges (with careful compilation and programming) it would just be extremely impractical. 
**Virtual Memory** solves this.

## Virtual Memory Solution

Each process can use any virtual address and there can be many overlaps in values. 

In a virtual memory solution, a process address is referred to as a 'virtual address' which is then translated to a physical address so that each physical location has a single correspondence with a process-plus-virtual-address combination.

### Implementation:

We **could** do this by having four times as much physical memory than the virtual address could reach, then concatenate the process number {0, 1, 2, 3} and the virtual address.

![[Pasted image 20250218142932.png#invert]]

The way this works is that each process has its own address space of 1024 (0-1023) address spaces, the physical memory is 4x bigger and so the **translation** works by concatenating the process number and the virtual address.

e.g.

- If Process 0 uses virtual address 42, it maps to physical address 42
- If Process 1 uses virtual address 42, it maps to physical address 1024+42 = 1066
- If Process 2 uses virtual address 42, it maps to physical address 2048+42 = 2090

You would have base and limit registers that would indicate where in physical memory the process would start and the limit register would indicate how much the memory the process can use.

This is a **poor** solution though, since it requires having 4 times as much physical memory as the total virtual address space, which is expensive and wasteful.

## Memory Allocation Strategies

![[Pasted image 20250224154713.png]]

If you look at the image, you can see that an appropriate memory space needs to be found, for Process 9, but where should it be placed in this instance.

There are key allocation strategies that can be implemented:

**First Fit**: Assign the first available space that is large enough, this is fast for the process but may impact system performance later.

**Best Fit:** Find the smallest hole that is largest enough, this requires complex algorithms requiring evaluation of all available spaces.

**Worse Fit:** Find the largest available hole, this has a counter-intuitive name but can be beneficial in some cases.

## Memory Fragmentation Problems

This occurs in memory management as processes are allocated memory and then release it over time. 

### External Fragmentation

This happens when there is enough total free memory for a request but its split into lots of non-contiguous block.

### Internal Fragmentation

This occurs when memory is allocated in fixed-size blocks, and the process doesn't use all the memory within its allocated block - the allocated block is larger than what is actually being used.

## Address Translation

**Virtual Memory** addresses is simply a memory a process uses, which does not directly correspond to the address that it is using within memory.
When a program runs it **thinks** that it is using an address space like 0x1004 or 0x1000 but it is not rather these addresses exist in its virtual address space, an illusion created by the operating system that makes each process believe it has its own complete memory range.

When the program tries to access a virtual address, the CPU translates that virtual address into an actual physical address RAM with help with the MMU (Memory Management Unit).

The translation happens through mapping tables called 'page tables' that are maintained by the operating system.

![[Pasted image 20250218210343.png#invert]]
In this example the page sizes are much smaller than in actual implementations.

If you look at the example above, the virtual address of 99 (remember that memory addresses are usually in hex) is translated to the physical address 19 (hex).

The way **paging** works is that the most significant bits of the virtual address, identify the page number that virtual address belongs. The OS looks up the corresponding page within memory to that virtual page (looking up at the table we can see that virtual page 4 translates to physical page 0). The OS now knows that virtual address' with the MSB equalling to 4 map to page 0 in physical address. The LSBs will then be the same between the virtual memory addresses and the physical addresses.


## Shared Memory

What we can see is that **shared memory** allows multiple processes to access the same physical memory via different virtual addresses, which is useful for:
- Shared Libraries
- Read-only data sharing
- Interprocess Communication

**Interprocess Communication**: is where a process can exchange data through shared memory. 
**Shared Libraries:** A single copy of frequently used routines are shared with any process that needs them.

What memory mapping enforces is processes do not have access to memory that it isn't allowed to, where they are enforced via the **page table** where the bits will indicate the **access types**, **privilege levels** and **faults** (improper access attempts can cause a fault).

### Libraries

**Libraries** are pre-written chunks of codes (functions, classes, routines) that developers can reuse to avoid rewriting common functionality.

You can have:

1. Static Libraries: These are linked to your program at compile time, the needed parts become part of the **executable** file. This allows for self-contained binary but large executables.
2. Dynamic Libraries: These are linked at runtime and are stored as separate files (`.dll` in Windows and `.so` in Linux), multiple programs can share the same loaded instance in memory. This means it has smaller binaries, and is easier to update but is slightly more complex to manage.

You can have **Reentrant** and **Relocatable** routines/code.

**Reentrant:** Can be safely interrupted and re-entered before the previous execution is complete, and does not rely on global state - it uses local variables only. If a dynamic library is shared by multiple processes or even multiple threads in one process, it needs to be reentrant to avoid data corruption.

**Relocatable:** This is position-dependent so it can be loaded at any address in memory without requiring modification and uses relative addresses rather than absolute addresses. When an OS loads a dynamic library, it might not know where in memory it will go, so relocatable libraries avoid clashes and simplify memory management.

| Concept      | Meaning                                           | Importance in Libraries                             |
| ------------ | ------------------------------------------------- | --------------------------------------------------- |
| Reentrant    | Safe to use by multiple threads/processes at once | Ensures no crashes or conflicts during shared use   |
| Relocatable  | Can be placed anywhere in memory without issue    | Allows sharing and dynamic loading with flexibility |
| Static Libs  | Linked at compile time, copied into binary        | Simpler, but larger and less flexible               |
| Dynamic Libs | Linked at runtime, shared among processes         | Efficient, updatable, but more complex to manage    |



