19-12-2024 21:18

Status:

Tags: [[Computer Engineering]] [[3-Box Model of the Computer]]

# Memory
When a computer program is operating it needs to keep its data somewhere. There may be some registers (such as the Accumulator in MU0) but these are very small in capacity.

The concept of a 'stored program' is attributed to John Von Neumann. Put simply it says: 'Instructions can be represented by numbers and stored in the same way as data'.
This has lead to the 'Von Neumann' Architecture which is followed by almost all modern computers where a single memory holds values which can be interpreted as data or as instructions by the processor.

Memory can hold instructions (programs), program data, as well as I/O information. To access memory, we have the address bus - this is the address in memory (a pointer to memory) where the read/write action will be performed. 

You can either have two data buses: a Data In bus for when data comes from memory into the PC, and a Data Out bus, for when data is being written from the PC to memory. We could combine these into a single bidirectional bus. 

You also have memory control signals - these are used to tell memory what operation is being performed using the address on the address bus - read or write.

Types of Memory:
- ROM : Read-Only-Memory
- RAM : Random-Access-Memory

The simplest memory device is a flip-flop ([[Year 1/Computer Engineering/Sequential Systems]]).

## Register
We can produce a register when we have multiple flip-flops together:
To build a register, we take the appropriate number of flip-flops, lets say 4 to implement a 4-bit register. We connect the clock signals to all four flip-flops together and connect all four clock enable signals together. So when CE is 1, all four flip-flops are enabled and a four bit value of the input, d\[3:0] is stored to the register (one bit per flip-flop) on the rising edge of the clock. So a four bit value is seen at the output, q\[3:0]. A reset signal going high will result in all four flip-flops being reset at the same time.
![[Pasted image 20241219215420.png#invert]]
## Memory Block
![[Pasted image 20241219215543.png#invert]]

If you look at the picture above, it contains all the signals you need for the memory block.
It is actually common practice to combine the input and output data buses and replace them with a single bidirectional data bus. Also, the read and write control signals can often be replaced with a single control line, R/W ,which is high for a data read and low for a data write.

*K addresses means we have $2^k$ memory locations*

How can we extend the use of a register to have multiple memory addresses.

![[Pasted image 20241219220415.png#invert]]
[[Decoder]]: First we have decoders, these decodes the binary address received on the address bus, it produces enable signals for each memory row. Each memory location corresponds to a specific row. In the image, a 2-bit address bus is used to address four rows (since $2^2 = 4$).
When a specific address (like 01, or 10) is provided the decoder activated the corresponding row by enabling it for a read or write operation.

### Tri-State Buffers
The **Tri-State Buffers** are logical devices that control when a specific memory location outputs its data onto the Data Out Bus.
The Tri-State Buffer has three states:
- **High (1):** Transmits a logical 1.
- **Low (0):** Transmits a logical 0.
- **High Impedance (Z):** Effectively disconnects from the circuit to avoid interference.

When the `read` control signal is high, the tri-state buffer corresponding to the selected address allows data from that memory row to pass onto the **Data Out Bus.**
![[Pasted image 20241219221657.png#invert]]
## Implementing Bidirectional Buses
![[Pasted image 20241219221756.png#invert]]
In order to enable bidirectional buses, we use the Tri-State Buffers.
They allow data to flow in one direction at a time.
In the image we have a 4-bit system:
If we have the control signal `En1 = 1` and `En2 = 0` then the data will go from Bus B to bus A, and if `En1 = 0` and `En2 = 1` then the data will flow from bus A to bus B.