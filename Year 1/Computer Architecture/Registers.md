01-10-2024 12:57

Status: #new 

Tags: [[Architecture]] [[Vonn Neumann Architecture]]

# Registers
In order to fix the problem of memory bottlenecking experienced looking at straight forward Von Neumann [[Three-Address Instructions]] computers, we have registers:
- Super fast memory locations inside the CPU
- Closely connected to the ALU
- Relatively small memory

Every architecture has at least a few registers. 

The inclusion of registers now means that we no longer need to completely rely on slow memory and now use fast registers. 
Instructions now do one thing and do it efficiently instead of having to negotiate with the bus.
### ***Load-store*** 
It is an architecture that is a way that we deal with registers. Here all operands are with registers, we keep the 3-address instructions for most operations like addition, but instead of instructions operating on natural addresses, they are operating on registers.
We have two more instructions with this in order for the memory to get to these registers and for it to be used.
**Load**: Instruction goes from memory into register
**Store**: Copies the register value to a memory location

## RISC-V Registers
![[Pasted image 20241001132608.png#invert]]

![[Pasted image 20241001132941.png#invert]]


