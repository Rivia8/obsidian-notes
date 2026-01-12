30-09-2024 20:39

Status: #new

Tags: [[Architecture]] 

# Basic Machine Model
## The 2-Box Machine Model
![[Pasted image 20240930204007.png#invert]]
**Memory**
On the LHS we see the memory, the memory is made up of lots of storage units - locations. 
These locations hold one piece of information, the information can be in the form of instructions or data and each location has a unique address - this address identifies that storage location.
Each memory location groups together multiple bits. 

Memory Sizes:
1 bit -> Smallest piece of information
4 bits -> 1 nibble, this can be represented with 1 hex digit
8 bits -> 1 byte, Main memory is byte addressable *where each memory byte is a separate location with its own address*

RISC-V are 32-bit processors.

**Bus**
It is a "Complicated set of wires" where the CPU specifies what is read and written
