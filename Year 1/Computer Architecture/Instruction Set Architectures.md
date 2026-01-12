17-12-2024 16:29

Status: #new 

Tags: [[Architecture]]

# Instruction Set Architectures
An ISA is a part of the computer architecture that defines the set of instructions that a processor can execute. It is essentially the interface between software and hardware.

The ISA specifies how the instructions a CPU can perform, how these instructions are represented in binary form, the registers available, and how data is managed.

Typically, instruction set architectures (ISAs) are classified based on the type of internal storage in a processor. This internal storage could be a stack, an accumulator or a set of registers.

Operands may be named explicitly or implicitly:
- The operands in a stack architecture are defined implicitly on the top of the stack
- In an accumulator architecture one operand is implicitly the accumulator.
- The general-purpose register architectures have only explicit operands - either registers or memory locations

![[Pasted image 20241217163748.png#invert]]

## Stack Based ISA
![[Pasted image 20241217163819.png#invert]]
Operands are implicitly stored at the top of a stack. This simplifies the instruction set and can lead to shorter instructions. But can be less efficient due to frequent stack manipulation.

## Accumulator Based ISA
![[Pasted image 20241217164452.png#invert]]
Uses a single accumulator register for arithmetic and logic operations. One operand is typically stored in the accumulator, and other operand can be a register, memory location, or immediate value.
## Register-Memory Based ISA
![[Pasted image 20241217164520.png#invert]]
This allows operands to be in both registers and memory. Instructions can directly operate on memory locations. This means that it can have complex instructions since they need to handle both register and memory operands.

## Load-Store Based ISA
![[Pasted image 20241217164544.png#invert]]
This only allows operands in registers for arithmetic and logical operations. Instructions only operate on registers; separate load and store instructions are used for memory access. Simpler instruction set and potentially faster execution due to the uniform handling of operands.

(*[[Week 11 Slides.pdf]] Page 25*)

## CISC and RISC
Typically, the design of a processor can be classified as:
- Complex Instruction Set Computing (CISC) Architecture
- Reduced Instruction Set Computing (RISC) Architecture

CISC based processors have the ability to execute complex operations using single or fewer instructions.
RISC based processors only use simple instructions that can be executed within one clock cycle.

![[Pasted image 20241217171409.png#invert]]

![[Pasted image 20241217171433.png#invert]]
![[Pasted image 20241217171506.png#invert]]
