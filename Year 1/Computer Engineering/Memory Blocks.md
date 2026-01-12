22-12-2024 14:51

Status: #new

Tags: [[Computer Engineering]] [[Memory]]

# Memory Blocks
We have seen that typically memory chips come in fixed sizes, the SRAM example we looked at offers 1Mb (20-bit address) 8-bit wide memory. However, CPUs often have a larger data-width than 8 bits (64 bits in modern systems). 
In order to increase the width of the memory, we use multiple memory blocks in parallel.

## Parallel Memory Configuration

### Increasing Memory Width

To increase memory width, multiple memory blocks are used in parallel.
All the memory blocks share the same address bus, they have a **common address bus**. This means that the same address is sent to all blocks.
The data bus is split among the memory blocks through a **split data bus**. Each block handles a portion of the data.

![[Pasted image 20241222155548.png#invert]]

In the example shown above, we have two 1Mb x 8bit memory blocks which are used to implement a 1M x 16-bit memory. Both memory blocks share the same 16-bit address bus to access memory locations.

*This diagram however is inaccurate for the fact that we need at least a 20bit address to store all 1M address locations.*

**Split Data Bus:**
	One memory block handles the most significant byte (8 bits)
	The other memory block handles the least significant byte (8 bits)

This configuration still allows for only 1Mb of memory, but at a 16-bit memory width. The total unique addressable space is the same, but each addressable space can now store 16-bits or 2 byte of data so the total **data** has doubled but not addressable memory.

The enable signals (`En`) and the read/write signals (`Rd/Wr`) are common to both so they perform it together. 

### Increasing Memory Depth

So what if we need more memory locations for a particular application?

So lets say we have a 1Mb x 8-bit memory block that requires 20 address lines we have a CPU with a 24-bit address bus and an 8-bit data bus.

The problem is that the CPU has a 24-bit address bus, allowing to to address up to 16Mb. But only using one 1Mb x 8-bit memory block means that it restricts us to using only 1Mb. Only the least significant of the 20 address bits are used, resulting in a 1Mb memory address range.
The reason for the use of only 20 address bits out of the 24-bit address bus, is because for a 1Mb memory block, only 20 bits are needed to address all of the 1Mb locations.

![[Pasted image 20241222190011.png#invert]]

Using two 1Mb x 8-Bit memory blocks allows us to extend the memory to 2Mb by using address bit 20, A\[20], to control which memory block is enabled.

CE1 - enables bank 1
CE2 - enables bank 2

Both memory blocks share the same 20-bit address bus A\[19:0].
The higher address bits A\[20] and above, are used to select the memory block.
Each memory block has its own 8-bit data bus, but they are effectively combined to create a larger addressable memory space.

We can connect CE1 to A\[20] and CE2 to the inverse of A\[20].
This allows for one memory block to be on and the other to be off to prevent reading and writing from both.

### Combining the Two
![[Pasted image 20241222193219.png#invert]]

Here we have two rows of 1Mb memory blocks, there is a 24-bit address space from the CPU.
We assign the first 21 for address spacing A\[21:0] , and bit A\[21] is the enable bit where it is inversed for the bottom row in order to make access between the two rows mutually exclusive.
	it is inaccurately labelled on the diagram once again, we need 21 bits to store 2Mb of address locations.

This gives us 2mb of addressable memory locations that are 32 bits wide.

# Memory Map
As far as programs are concerned, they have access to one continuous memory space. However, portions of the code are decoded to have enable signals to have access to banks of memory.

![[Pasted image 20241222210058.png#invert]]

The memory map, shows many of the basic properties found in real systems. The memory is roughly divided into areas with different functions.
Areas may contain different types of memory or different technologies that run at different speeds. For example the I/O area may be designed to cycle more slowly (i.e. more clock cycles) than the RAM.
Peripheral devices are usually byte-wide so not all bits in the word will be defined.


