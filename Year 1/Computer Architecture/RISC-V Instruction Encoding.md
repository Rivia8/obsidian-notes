16-10-2024 11:17

Status: #new 

Tags: [[Architecture]] [[RISC-V Instruction Set]] [[Week 3 Slides.pdf]]

# RISC-V Instruction Encoding

Assembly is a textual representation of the program that is easy to remember, read and write (a way for humans to understand machine code better), but it is not easy for the processor to read.
for an example if we look at: *sub x1, x2, x3* it is 15 bytes in ASCII, 3.75 times more storage than a 32-bit instruction.

The actual program is a sequence of bytes, each instruction is 32-bits of machine code.
![[Pasted image 20241016112741.png#invert]]
Looking at the picture above there are several points to be understood,
Every instruction in RISC-V is 32 bits long, and the bits are divided into fields, each field hols a specific piece of information. These fields can vary in length, depending on the instruction type. For an example:

The B-Type instruction, `beq x1, x2, offset` is translated into `0000000 01010 01001 000 00000 1100011`. 

## Opcode:
The first 7 bits (bits\[6-0] )of every RISC-V instruction are called the **opcode**, the opcode identifies the type of instruction that is being executed, *load, store, branch etc..*. and it also dictates which format the (R-Type, I-Type, etc) that will be used to decode the instruction.
It has a limit of $2^7$ (128) unique instructions, 

## Instruction Formats:
- R-Type (Register Type): : Includes fields like `rs1`, `rs2` (source registers), `rd` (destination register), `funct3`, and `funct7` which are used to define specific operations.
- I-Type (Immediate type): Used for instructions involving immediate values, like loads. It includes fields like `imm[11:0]` (immediate value) along with registers.
- S-Type Immediate type): Used for instructions involving immediate values, like loads. It includes fields like `imm[11:0]` (immediate value) along with registers.
- B-Type (Branch type): This has a near identical layout, only difference is with the immediate bits, the immediate value is relative to PC: target = PC + immediate. The immediate encodes bits `[12:1]` instead of bits `[11:0]`.
- 
- U-Type (Upper Immediate type): Used for instructions like `LUI` (load upper immediate) and includes a large immediate value in `imm[31:12]`.
- J-type (Jump types): For the immediate it has 20 bits, that is split across multiple parts, used for jump instructions like *jal*. Has the same layout as the U-type. target = PC + immediate.

The term `imm` refers to an immediate value, this refers to a constant value embedded directly in the instruction itself, instead of being stored in a register.
For an example:
```
addi x3, x1, 5
```
The value 5 is the immediate value as it is embedded directly in the instruction as part of the `imm` field.


The table: 
![[Pasted image 20241016114216.png#invert]] 
The table enlarged above provides a breakdown of the base opcode map that is used in the RISC-V instruction set. Specifically, it shows how combinations of **inst\[6:5]** and **inst\[4:2]** (the bits from the instruction) map to different types of instructions.

Examples:
- **inst\[6:5] = 00, inst\[4:2] = 000 (first row, first column)**:
    
    - This corresponds to a **LOAD** instruction. The `LOAD` instruction is used to load data from memory into a register.
- **inst\[6:5] = 01, inst\[4:2] = 000 (second row, first column)**:
    
    - This corresponds to a **STORE** instruction. The `STORE` instruction is used to store data from a register into memory.
- **inst\[6:5] = 10, inst\[4:2] = 000 (third row, first column)**:
    
    - This refers to **MADD** (Multiply-Add). It performs a multiplication and adds the result to another register.
- **inst\[6:5] = 11, inst\[4:2] = 000 (fourth row, first column)**:
    
    - This corresponds to a **BRANCH** instruction. It is used to control the flow of the program by making conditional jumps.

For all instructions all register arguments are 5 bits, $2^5$ = 32, 32 different values to correspond to the 32 different registers in RISC-V. This allows uniformity in the architecture and simplifies the instruction encoding, making it easier for the hardware to process instructions efficiently.



















