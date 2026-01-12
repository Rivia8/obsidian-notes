01-11-2024 18:31

Status:

Tags: [[Architecture]] [[RISC-V Instruction Set]]

# Strings
In the RISCV ISA, strings are typically handled using a combination of instructions that operate on memory addresses and registers.

![[Pasted image 20241101183126.png#invert]]
## Memory Instructions:

RISCV provides instructions for loading and storing strings (sequences of characters) from and to memory.
`lb` and `sb` (load byte and store byte) are used to handle individual bytes of a string.
To process strings we have looping constructs, RISCV supports loop constructs through instructions like `loop` and conditional branches.

### String Length
![[Pasted image 20241101185723.png#invert]]

### String Find()
![[Pasted image 20241101185848.png#invert]]

See [[Week 5 Slides.pdf]] for more information for the above slides.





