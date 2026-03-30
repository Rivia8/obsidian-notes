30-03-2026 21:24

Tags: [[System Architecture]]

The Instruction Processing Cycle is a simple repetitive fetch-execute cycle.

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

**Microarchitectural Model**:
![[Pasted image 20260321164051.png#invert]]

Above is the diagram of a highly abstracted single-cycle microarchitecture.
- Each instruction takes a single clock cycle
- All state updates made at the end of an instruction's execution.

What determines the Cycle Time of the Processor?:
- The slowest instruction determines the clock cycle time
- Other instructions have "slack"

## Performance Analysis

The clock has to wait for the instruction to finish entirely before it can tick again. This means that the clock time must be set in order to accommodate the **slowest instruction** in the entire system.
This means that even *if* an instruction is fast, like `ADD` that finishes in 6ns, because the slowest instruction `LOAD` takes 10ns, there is 4ns **SLACK**.

In a Single-Cycle processor, only **one** instruction is in the system at a time. So when the instruction is in the decode phase, the ALU is turned off. When the instruction is in the "Execute" phase (using the ALU), the Instruction Memory and Data Memory are turned off.

## Performance Analysis

Execution time of a single instruction:
$$\text{CPI(Clocks Per Instruction)} \times \text{Clock Cycle Time}$$
Execution time of an entire program:
$$\text{No. of Instr} \times \text{Average CPI} \times \text{Clock Cycle Time}$$
# The Solution

This is where the methods of [[Pipelining]] come into consideration.