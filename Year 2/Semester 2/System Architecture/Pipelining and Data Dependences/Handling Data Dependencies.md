
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

Every 



