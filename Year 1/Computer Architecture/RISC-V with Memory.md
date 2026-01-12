15-10-2024 18:44

Status: #new 

Tags: [[RISC-V Instruction Set]] [[Week 3 Slides.pdf]] [[Architecture]]

# RISC-V with Memory
## Data:
**Sizes:**
The default data size is 32-bits (word)
- Internally everything is 32 bits
- Allows processing large numbers in a single step
Memory is byte addressable. This might seem inefficient, but this allows for fine-grained access so that individual bytes can be read, written or manipulated without needing to access to larger blocks of data. Furthermore, many data types only operate with single bytes/bits so having to always operate with 32 bits will use too much memory for simple applications.

**Registers**:
When you access a register, you access its entire width of 32 bits, not individual bytes within it. This is different from memory, which is byte-addressable, meaning that each byte in memory has its own address.
You can still load single bytes but they will be extended (with 0's no to affect the value)

![[Pasted image 20241015190826.png#invert]]
## Endianness
This refers to how data is stored in memory, particularly the order in which bytes are arranged when storing multi-byte data types like integers or floating point numbers.
So if we store 4 bytes in a register (since the default is 32 bits) and memory is byte addressable (8 bits) how do we 
There are two types of Endianness:
### Little Endian 
Here the least significant byte (LSB) is stored first (at the lowest address)
For the 32-bit integer 0x12345678 (this is hex representation), this is what would be stored:

| Address | 0    | 1    | 2    | 3    |
| ------- | ---- | ---- | ---- | ---- |
| Value   | 0x78 | 0x56 | 0x34 | 0x12 |

### Big Endian
For BE the most significant byte (MSB) is stored first (at the lowest address).
So for the same 32-bit integer:

| Address | 0    | 1    | 2    | 3    |
| ------- | ---- | ---- | ---- | ---- |
| Value   | 0x12 | 0x34 | 0x56 | 0x78 |

### Does this matter?
When looking at data interchange (transferring data between systems) the way data is stored and read must be consistent. If not it might misinterpret the data if is not in the right format.
In a system the lowest addressed bytes is the first to be processed and so the whether the data is in the lowest addressed does matter.
Though it is less important on strictly 32/64 bit processors since all bytes are loaded at once.

RISC-V, including the implementation used in Bennett, is little endian by default. This means that 32-bit data values are stored with the LSB at the lowest memory address. RISC-V however is flexible in the fact that it can indeed be changed.
Most modern architectures use little endian, it is hard to find big endian outside of low-level network communication.