
01-04-2026 16:24

Tags: [[System Architecture]]

*Recall that there are 5 fundamental data dependencies:*

![[Data Dependencies#Ways of Handling flow Dependencies]]

# Detect and Wait

## Interlocking

This is a form of **detection**.
There is software based and hardware based.

"It is the detection of dependence between instructions in a pipelined processor to guarantee correct execution"

Software Interlocking: The hardware is dumb. If there is a data dependence software, the compiler, must detect it before the program runs, and insert 'dummy' instructions (called NOPs - No Operations) to artificially space out the instructions and force a wait.
- Early processors, called **MIPs** - Microprocessors without (hardware) Interlocking of Pipelined Stage - had no hardware breaks (all done via software work).

Hardware Interlocking: The processor hardware is smart, the physical circuitry detects the crash about to happen and physically freezes the pipeline stages.

### Scoreboarding 

*Hardware*

**Scoreboarding** is a specific algorithm on allowing the silicon to physically 'detect' the problem.
*Its like an occupancy sign on a bathroom door*

Every register (`r1`, `r2` etc) gets an extra wire (bit) attached to it.
When instruction 1 enters the pipeline and says "I am going to calculate a new value for `r3`", the hardware flips `r3`'s bit to invalid (occupied).
When instruction 2 enters the pipeline and wants to read `r3` it looks at the bit and sees 'invalid'.
This causes the hardware to trigger an  **interlock**, stalling instruction in the decode stage until instruction 1 finishes and flips the sign back to **valid**.

**Advantage:**
- Simple 1 bit register

**Disadvantages:**
- Need to stall for all types of dependencies
- Other techniques do not stall on false dependencies

### Combinational Dependence Check Logic 

*Hardware*

[[Handling Data Dependencies#Scoreboarding (Hardware implementation of Interlocking)|The above]] is considered 'dumb' since it will stall even if the dependence is fake - WAR or WAR dependencies.

Instead we have **Combinational Dependence Check**, which is smarter.
Instead of looking at a bit, the **Decode Stage** has complex logic circuits (wires) that  look "downstream" into the Execute, Memory and "Write-Back" stages. 

**Advantage:**
- Only stalls for **RAW** flow dependencies.

**Disadvantages:**
- Logic is much more complex,
- Logic becomes a lot more complex as the pipeline becomes deeper.

### Compiler - Inserting NOPs

*Software*

We can use the compiler to **reorder instructions**. 
This only works if we can find something **useful** to do or otherwise NOPs are inserted.

![[Pasted image 20260402103756.png#invert]]

If you look above, the second instruction is pushed until the 4th clock cycle.

### Compiler - Instruction Reordering

*Software*

This is the fix for the above's wasteful cycles

This is what modern compilers do, the compiler looks at the entire program and says: "Are there any other instructions later in the code that have absolutely nothing do with `r1`" and if there are it places it between the current and dependent instruction.

# Detect and Data Forwarding/Bypassing

To fix the problem with [[Handling Data Dependencies#Stalling the Dependent Instruction|the above]], we can add additional dependence check logic and data forwarding paths (i.e. buses) to supply the producer's value to the consumer right after the value becomes available.

Pretty much, since the next instruction (the one causing the dependence) requires the value from the **current** instruction, instead of going through the whole Write-Back stage, we just send the data straight to the next instruction.

# Detect and Eliminate

This entirely happens in software.

Instead of building complex hardware to detect and stall, the compiler 'fixes' the code before it runs.

This can occur in two ways, **Instruction Reordering** or Inserting **NOPs**.

## Stalling the Dependent Instruction/Inserting NOPs

`ADD r1, r2, r3`
`SUB r5, r1, r4`

**Stalling** would mean freezing instruction 2 in the decode stage and waiting for instruction 1 to finish.
There is a crucial part, you cannot write to a register and read from it in the exact same clock cycle. Because of this, instruction 2 has to wait for instruction 1 to completely finish its Write-Back stage (Cycle 5). Instruction 2 can finally read the register on Cycle 6.

What this does is creates a massive 3-Cycle **Bubble**.

## Instruction Reordering

This is the ideal fix. 

The compiler looks ahead at the code and tries to reorder instructions.
- If it sees `Instruction 1` (calculates `R1`) and `Instruction 2` (needs `R1`), it knows putting them back-to-back will cause a crash.
- So, the compiler searches your program for _completely unrelated_ instructions (let's call them `Instruction A` and `Instruction B`).
- It physically moves `A` and `B` to sit _between_ `Instruction 1` and `Instruction 2`.
- **The Result:** From the hardware's perspective, the dependency has been "eliminated". By the time `Instruction 2` finally enters the pipeline, enough clock cycles have naturally passed (while the CPU worked on `A` and `B`) that the data in `R1` is ready and waiting.