21-03-2026 13:28

Tags: [[System Architecture]]

# Recap:

![[Pasted image 20260321160635.png#invert|400]]

- ISA = [[Instruction Set Architectures]] 
- Microarchitecture = Specific Implementation of the ISA, not directly exposed to the programmer.
- The process of executing an instruction is called the **instruction cycle** or processing cycle

# Pipelining

The Instruction Processing Cycle is a simple repetitive fetch-execute cycle.

Pipelining is the assembly line principle applied to executing software instructions.
Instead of waiting for one instruction to completely finish before starting the next one, the CPU breaks the execution down into smaller, distinct stages and overlaps them.

The two parts of the cycle can be subdivided:

1. **Fetch**: the CPU grabs the next instruction from memory and loads it into the IR. The PC is incremented.
2. **Decode**: the CPU identifies the instruction by **decoding** the contents of the IR. The control signals are generated to process the identified instruction in later phases of the instruction cycle. Source operands are obtained from register file needed to process the instruction.
3. **Execute**: instruction is executed.
4. **Memory**: this either reads data from memory or writes a result to the designated location.
5. **Write**-**back**: the write-back phase writes the result to the designated register.

The **worst case** data path is when the CPU has to go through all these phases:
![[Pasted image 20260321162436.png#invert]]Most logic circuits are driven by a clock signal:
![[Pasted image 20260321162629.png#invert]]
In very a basic instruction processing engine, each instruction takes a single clock cycle to execute (single-cycle processor).
Only [[Combinatorial Logic|Combinational Logic]] is used to implement instruction execution. This means that to calculate the next state, only the current inputs are considered.

The microacrhi