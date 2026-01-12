13-03-2025 22:20

Tags: [[Operating Systems]]

# Memory Management Unit

An **MMU** (Memory Management Unit) is the hardware system which performs both virtual memory mapping and privilege checks to keep user processes separated from the operating system. It also helps to prevent caching of 'volatile' memory regions (such as areas containing I/O peripherals).

The inputs that the MMU takes are:

- a **virtual** memory address
- an operation (read/write), maybe transfer size
- and, the processor privilege information.

The outputs that the MMU produces are:

- a physical address
- cachability (information)

*or*

- a rejection (memory fault)
	- no physical memory mapped to the requested page
	- illegal operation 
	- privilege violation

A typical MMU in a virtual memory system will use a paging system.

## Architecture

This shows a typical 'MMU' in situ.

![[Pasted image 20250402151932.png#invert]]

Here it shows how the MMU performs address translation - virtual to physical - using a **TLB (Translation Look-aside Buffer)** lookup.

### TLB

The TLB is a specialised cache within the MMU that stored recently used address translations.
This means that when the MMU needs to translate a virtual address, it first checks the TLB, if it gets a TLB hit then it quickly retrieves the address and continues working, if it gets a TLB miss then MMU consults the page table in **memory** - the page table is stored in memory. 

*[TLB operations](https://www.youtube.com/watch?v=95QpHJX55bM)*

![[Pasted image 20250402204941.png#invert]]

The image above describes the process of what happens in an address translation.
### Locality

Locality is the tendency of programs retrieving the same memory location based on its **space** or **time**.

**Spatial Locality:** When a program accesses a memory address, it is likely to access nearby addresses in the same page.

**Temporal Locality:** Pages that are accessed often are likely to stay in physical memory and the TLB for faster access

