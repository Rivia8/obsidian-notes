20-12-2024 11:44

Status:

Tags: [[Computer Engineering]] [[Memory]]

# Decoder


![[Pasted image 20241220114146.png#invert]]
A particular location in memory is identified by an address. We have to be able to translate this address to identify particular memory location so that data can be written to the correct memory location. The job of determining which memory location is required is performed using a decoder.

If a memory address is n-bits wide, then the decoder takes this and takes one of $2^n$ control lines high, depending on the address value.

The role of the decoder is to take an n-bit binary value and to decode it so that one of the $2^n$ output lines goes high depending on the binary value. The outputs from the decoder are mutually exclusive, so only one output can be high at any one time.

So essentially it 'decodes' the input value where it only allows one of the outputs to be high based on the input binary code, while the others remain low.

![[Pasted image 20241220120035.png#invert]]

The image shows how a decoder looks like (abstraction) alongside a table with corresponding values for the control signals.

The role of the enable signal is to control when the decoder is operational. When `En` is low, then the decoder is 'off', when it is high, the decoder is on and the appropriate output goes high for the address presented at the input.

It is often inconvenient and impractical to decode an entire address bus (for an example 64 bits).

A 6-to-64 decoder would be too big and so it could be divided into smaller chunks using multiple stages of decoders (2 5-to-32, 4 4-to-16... etc) this makes it more practical to manage large address spaces without needing a single massive decoder. But you will also ned an additional controller to select which of the output decoders is enabled at any particular time.

If we choose to use 8, 3-to-8 bit decoders for the 64 bit decoder, then we will need a 3-to-8 decoder to provide the enable lines to enable just one of the 16 output 2-to-4 decoders at any particular time.

![[Pasted image 20241220141150.png#invert|500]]

The image above illustrates how a 3-to-8 decoder is used as a controller.

## Address Decoding

### One Dimensional
Each location in memory is identified by a unique address. In order to access a memory location, we need to decode the address to find the appropriate location in memory.

One way to achieve this is to have the memory arranged in an array, (1 x $2^n$) with each memory location accessed via a control signal that is derived from the decoder. This is called a one dimensional memory scheme. The data bus is common to all memory locations.
![[Pasted image 20241220142440.png#invert]]
When a particular select line goes high, then a memory location is enabled, and data can either be written to, or read from that particular memory location.

For small memories, this approach is feasible, but it becomes impractical for larger memories due to the size and complexity of the required decoder.

### Two-Dimensional Arrays
Rather than arranging a memory as a (1 x $2^n$) array, we can arrange the memory in a n x n matrix, where each point in the matrix represents a memory location where a word is stored.
Here the n-bit address is split into two n/2-bit parts: one for the row decoder and one for the column decoder.
The combination of row and column select lines identifies a specific memory location.

For example, for a 4-bit addressing scheme:
- Split the 4-bit address into two 2-bit values
- Use a 2-to-4 decoder for the LSBs to select the column
- Use a 2-to-4 decoder for the MSBs to select the row
- The intersection of the selected row and column gives the targeted memory location.


![[Pasted image 20241220143737.png#invert]]

Consider a 256Mb memory . In a one dimensional scheme this would require a 28-to-268,435,456 decoder – which would be a very large and complex decoder. However, using a two-dimensional scheme this would require two 14-to-16,384 decoders to access a 16,384 x 16,384 memory array, which would overall be a much simpler circuit to implement.