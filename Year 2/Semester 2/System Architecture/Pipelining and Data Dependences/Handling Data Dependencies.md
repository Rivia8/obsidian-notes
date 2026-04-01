
01-04-2026 16:24

Tags: [[System Architecture]]

*Recall that there are 5 fundamental data dependencies:*

![[Data Dependencies#Ways of Handling flow Dependencies]]

# Detect and Wait

## Interlocking

This is a form of **detection**.
There is software based and hardware based.

"It is the detection of dependence between instructions in a pipelined processor to guarantee correct execution"

Software Interlocking: The hardware is dumb. If there is a data dependence, the compiler, must detect it before the program runs, and insert 'dummy' instructions (called NOPs - No Operations) to artificially space out the instructions and force a wait.
- Early processors, called **MIPs** - Microprocessors without (hardware) Interlocking of Pipelined Stage - had no hardware breaks (all done via software work).

Hardware Interlocking: The processor hardware is smart, the physical circuitry detects the crash about to happen and physically freezes the pipeline stages.

### Scoreboarding (Hardware implementation of Interlocking)

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

### Hardware Depedence 