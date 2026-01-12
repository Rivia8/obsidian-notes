13-12-2024 19:15

Status: #new 

Tags: [[Architecture]]

# Assemblers
## Role of an Assembler
An assembler is a software tool that translates assembly language code into machine code. Machine code is the set of binary instructions that a computer's central processing unit (CPU) can execute directly. Assembly language is a low-level programming language that uses mnemonics and labels to represent machine-level instructions, making it slightly more readable for humans.

The primary function is to convert assembly language code into machine code. This process involves several steps, including lexical analysis, parsing and code generation.

There are some overall steps that it might follow:
1. Strip out comments
2. Identify named constants, labels etc.
3. Identify instructions
4. Identify data or variable space to be located in memory
5. Assign an address to each instruction, data word etc.
6. Determine the values of all constants, labels etc.

# Simple Assembler
An assembler has to scan the text version of the program and operate upon it

Can it scan the program just once from start to finish and convert line by line to binary?
In very, very simple cases yes it can:

```R
li a1. 17 # -> E3A01011
li a2, 20 # -> E3A02014
add a0, a1, a2 # -> E0810002
```

This can only be done for sequences of instructions/data that can be individually converted to binary/hex form without reference to anything else.

But once the program starts to get a bit more complicated, the assembler can no longer translate the program in one pass.

Look at this:
![[Pasted image 20241213195201.png#invert]]

Single pass assembly is only possible if the program is a simple sequence of instructions with:
- No reference to data that is located later in the code (red)
- No branches forward (blue)
- No position-dependent pseudo instructions (green)

## Two-Pass Assembler
Look at this example:
![[Pasted image 20241213215659.png#invert]]
Here the assembler has to take two passes through the code.
Pass 1:
- Assign an address to each instruction or data
- Record any labels or names encountered with their numerical value in a 'Symbol Table'
- Check that each symbols is defined only once
Pass 2:
- Replace any labels or names with their values
- Convert each instruction to binary

### Difficulties with a Two-Pass Assembler:
Something that a two-pass assembler will find difficult is position-dependent pseudo-instructions, for an example:
`la` uses `PC` relative addressing to load an address:
`la a0, mystring` =
```R
auipc a0, offest[31:12]
addi a0, a0, offset[11:0]
```
The offset is calculated by the assembler and put in the instructions as a literal offset.

However, if the offset is greater than 12 bits, more instructions would be needed, which would change the address of the Data, requiring more passes.
This is because instructions like `addi` can handle immediate values  (offsets) up to 12 bits. This means that you cannot fit the entire offset in a single `addi` instruction. You would need additional instructions to handle the larger offset.
Adding more instructions to handle a larger offset means that the position of subsequent code (and data) in memory changes. This change affects the address calculation for other data and instruction, creating a cascading effect that requires the assembler to reprocess the code multiple times to resolve all addresses correctly.

### Summary for a Two-Pass Assembler
**First Pass:** The assembler scans the code to build a symbol table, recording the positions of all labels.
**Second Pass:** The assembler uses the symbol table to resolve addresses and generates the machine code.

**Position-Dependent Instructions**:
- Pseudo-Instructions like `la` are position-dependent because they rely on the relative position of the instruction and the label.
- The assembler must replace the pseudo-instructions with actual instructions (`auipc` and `addi`)

## Conversion of Text into Binary

The process of converting text to binary is not trivial.
It can be broken down into 4 phases:
1. Lexical (word) analysis:
	Convert sequences of characters into sequences of tokens
2. Syntactic (Structural analysis):
	Identify instructions, check they are valid
3. Semantic (meaning) analysis:
	Find the values of named entities
4. Binary code generation
	Generate final machine code

### Lexical Word Analysis
The assembler scans the line character by character. It identifies 'tokens', 'lexemes' or 'lexical units' by detecting spaces and other delimiting features in the language.

Tokens are the recognised units such as `start`. `andi`, `a0`, `a1`, `Mask` and delimiters like `,` and `;`.
Lexemes or Lexical units are the actual sequences of characters that match the tokens.

We can look at an example.

```R
Mask equ 0x0000000F
start andi a0, a1, Mask; Zero bits except LSN
```

```R
start andi a0 , a1 , Mask ; comment
```
- `start` : label
- `andi` : instruction
- `a0`, `a1`, `Mask` : Operands
- `,` : delimiters
- `; comment` : indicates the start of a comment, which is ignored in further analysis.

### Syntactical Analysis
This involves checking the structure of a line of code to ensure it conforms to the grammar rules of the programming language. In RISC-V assembly language, this includes identifying the different components of a line of code:
- Labels
- Operation Code (mnemonics)
- Operands (registers)
- Constants/Literals
- Addresses
- Comments
- Delimiters (, ;)

It also checks that the sequence of token types is legal: 
- That it satisfies the grammar of the language
- The sequence of tokens forma complete, legal instruction


### Semantical Analysis
This involves determining the meaning of the tokens and ensuring that they are used correctly according to the context of the program.

This phrase resolves thee values of symbols and variables:
```R
start  andi  a0  ,  a1  ,  Mask  ;  comment
```

Steps:
- Symbols: Identifying symbolic names `start` and `Mask` and determining their values.
- Symbol Table: Maintain a symbol table to store the addresses of labels and the values of constants.
	Value of `start`: The value of the label `start` is the address of the instruction. This value is stored in the symbol table.
	Value of `Mask`: `Mask` is defined elsewhere in the code. Its value is retrieved from the symbol table.
- Replacement: Replace symbolic names (like `Mask`) with their actual values from the symbol table in the final code.

### Code Generation
The assembler then converts assembly language instructions into machine code using the output of semantic and syntactical analysis. 

First the input from the **Semantic** and **Syntactical** analyses provide the necessary information to generate the correct machine code.

Then each component of an instruction (operation code, registers, constants) maps to a specific part of the binary code. The structure of the instruction set in RISC-V makes this mapping quite straightforward.

```R
start andi a0, a1, 0x0F ; Mask, leave the 4 least significant bits
```
![[Pasted image 20241214165658.png#invert]]
Looking at the table above, you can see that
- `andi`: Maps to opcode `E`
- `AL` : This is a specific part of the instruction encoding, represented by `20`.
- `a0`: Destination register, encoded as `1`.
- `a1`: Source register, encoded as `0`.
- `0x0000000F`: Immediate value, encoded as `00F`.
- Comment: Ignored by the assembler and not included in the binary code.

## Relocatable Code
Because one single program is not normally the only code running on a computer, multiple programs and processes need to be running simultaneously. Maybe in some very small cases where you have dedicated systems that only one program will be running but this is very rare.
Usually there is an OS and other programs that are running.

But how does the assembler know where the code will be placed in memory?

It does not. The resolution to this is that binary code is normally generated such that it can be located at any address ('relocatable'), much easier when addresses used in the code are not absolute (absolute addresses would have to be calculated and then placed into the code each time the code was loaded).

We have something called relative addresses. Addresses specified relative to the code location are relocatable.
RISC-V code implicitly generates relative addressing:
1. `la` generates PC-relative addresses
2. Branch instructions are PC-relative
3. `lw/sw` specify the address of the data as an offset from the pc

These all automatically generate relocatable code.
