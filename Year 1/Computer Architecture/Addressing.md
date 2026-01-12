01-11-2024 17:40

Status: #new 

Tags: [[Architecture]] [[RISC-V Instruction Set]]

# Addressing
## Addressing Mode
What is 'Addressing Mode'?
All memory instructions need to access a specific location - a specific address. It is the process through which the processor generates the 32-bit address.

There are multiple mechanisms in which different kinds of data have different layouts and so different ways to calculate the address. No processor supports all addressing modes (RISCV supports fewer than usual).

The modes in RISCV are:
- Absolute
- Register Indirect
- Base-Offset
- PC-Relative

### Absolute Addressing
Uses a fixed address directly specified in the instruction:
`lui x5, 0x1000` - Loads upper 20 bits of the immediate into register `x5`.
Instructions are are 32-bits and addresses are 32 bits.
Uses the pseudo-instructions: `lw, sw and la` which are all translated into pc-relative addressing.
This is good for accessing one specific thing.

### Base-Offset Addressing
Combines a base address from a register with an immediate offset specified in the instruction.
`lw rd, 0[rs1]`- loads the word from the memory address contained in `rs` (register source) into `rd` (register destination).
The immediate is 12-bit (-2,048 to +2,047 but -4,096 to +4095 for `jalr`)  

### PC-Relative Addressing
It is somewhat similar to base-offset, but the base address is the PC. The Program Counter (PC) is used as a reference point, adding an immediate offset to it.
`auipc rd, 0x1` - adds an upper immediate value to the PC and stores it in the rd.
This is good for jumps and branches since they tend to be local and so small offsets relative to the pc and therefore can be coded in few bits.
Furthermore the code can be relocatable as long as the relative offsets remain constant.

### Register Indirect Addressing
The full address is in a register. It is base-offset addressing with a zero-offset.
`lw rd, 0[rs]` - loads the word from the memory address contained in `rs` into `rd`.

![[Pasted image 20241101182323.png#invert]]
