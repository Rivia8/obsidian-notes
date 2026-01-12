13-03-2025 13:06

Tags: [[Operating Systems]]

# Paging

We already know that memory is a large equal-sized storage space, where a memory location is defined by a hexadecimal address location that stores bytes of data.

Using a [[Virtual Memory|virtual memory]] system will divide its memory into pages. Where a page is a **fixed size** block of memory. The principle is that any page can be mapped into any page frame, invisibly by the user.

## Page-Lookup

This has already been seen in [[Memory Mapping#Address Translation|memory mapping]] but it's quite a simple process where a program's memory space (its notepad) uses virtual addresses whereby the MSB of the virtual address signify its page in the virtual memory and the LSB is the offset, the page table will hold the page that the page in virtual memory will correspond to and will apply the offset to point to physical memory.

The look-up is all done by MMU hardware so this can all run as part of a user's application process. If a virtual page is not resident in physical memory, a fault will be triggered (a page fault).

## Page Faults
A page fault is a type of memory fault: a hardware-level exception which causes an **operating system** call.
This usually occurs when a virtual address fails to be translated into a physical address - usually because the page is not present in physical **memory**.
The exception handler must determine that this is a page fault and not some other form of memory fault.

If this type of fault occurs then something called **Page Swapping** must happen.

### Page Swapping
The OS has to find a page frame for the desired page, this can be anywhere in the physical RAM for a memory mapped system.

If there is a free frame available, the page can be directly loaded into that frame.

**Swapping Out a Page:**

If there are no free frames available, the OS must free up a frame by swapping out a current resident page to the swap space, the OS does this by using a replacement algorithm (e.g. LRU, FIFO) to select the victim page.
The selected victim page is written to the swap space and the page table is updated to reflect that the page is now on disk.

**Swapping in the Required Page:**

The missing page is then read from the swap space into the newly freed frame in physical memory.
The page table is then updated to map the virtual address of the missing page to the new physical memory.

### Restart

The process then can resume execution from the point where the page fault occurred. The paging process is it not visible to the application code, which is an advantage, the only 'visible' part is the slowing down that the user will face, so 'running out' of RAM will result in a lot of paging and a noticeable slowdown of overall execution speed.

### Minor Page Faults

These occur when a process tries to access a virtual page that is not currently mapped to a physical page in RAM, but the required page is already in memory and accessible without needing to read it from disk. These are generally less disruptive than major page faults because they do not involve I/O operations.

## Hierarchal Page Tables

Basic page tables are inefficient for large address spaces:
If we have 4Kb as a reasonable page size, we have 4000-bytes that can be represented with $2^{12}$ bits, leaving $2^{20}$ bits to represent the pages. This is a lot of pages and a lot of entries in the page table which takes up a lot of space. Often to prevent this, the page tables are subdivided into a tree structure.       

![[Pasted image 20250404002154.png#invert]]

Here are visualisations on how this works:

![[Pasted image 20250404002249.png#invert]]

The higher level pages are created on demand.

This might look overcomplicated and slow to implement, but this isn't coded and compiled in C but rather is hardwired in the MMU.


## Inverted Page Tables

When we have regular page tables, what happens is that each process has its own page lookup table. Where the table has its own mapping for each page to a frame in the physical memory.

For inverted page table however, instead of having a page table for each process, the entire system shares a single inverted page table. Where it has one entry for each physical frame of memory.