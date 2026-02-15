05-01-2026 15:08

Tags: [[Processor Microarchitecture]]

# Microarchitectural Structures

There are lots of different structures used when designing ASICs.

![[Pasted image 20260105181351.png#invert]]

One type of structure can have different 'choices' like the multiplier can be different depending on factors like hardware budget, latency etc.

**Register File:**
AKA Register Bank, depends on many things. A small file may fit comfortably in D-type flip-flops, a large may be better in RAM. Another influence will be the number of simultaneous reads and writes which can be performed. This will also be influenced by both the ISA and the implementation

**Priority Encoder:**


## Adders

**Ripple Carry Adder:**
This mimics how a human would do addition. You add the LSBs and if there is a carry it moves to the next bit. 
This looks like a chain of full adders connected in line and the Carry-out of one feeds the Carry-In of the next.
It is small and cheap but is slow $O(N)$ delay because the MSB cannot be calculated until the carry has "rippled" all the way from the LSB.

**Carry Look-Ahead Adder:**
Instead of waiting for the carry to ripple, this adder "looks ahead" to predict if a carry will be generated.
The way it works is that it classifies bit pairs into three categories:
- **Generate (G):** Inputs are `1` and `1`. A carry is definitely generated (1+1=10).
- **Propagate (P):** Inputs are `0` and `1`. If a carry comes in, it will be passed on (1+0+Cin​=10).
- **Kill (K):** Inputs are `0` and `0`. No carry will be generated.
Its much faster, roughly $O(logN)$ because it calculates in parallel groups, but it requires significantly more complex hardware gates.

**Carry-Select Adder:**
This does the work twice, for the upper half of the bits, it builds two separate adders, one assuming that the carry-in is 0, the other assumes its 1.
Once the real carry arrives from the lower half, a simple multiplexer selects the correct result immediately.
This is very fast but high hardware cost.

**Carry-Save Adder:**
It does not propagate the carry at all. It outputs two results: a "sum" a "carry" for each bit position. The carry is saved to be added in the next clock cycle or stage. 
This is ideal for summing many numbers rapidly, such as inside a multiplier.

## Multipliers

Binary Multiplication is essentially a series of shifts and adds.

**Array Multiplier:**
This generates "partial products", where you multiply the input by each single but of the other number and then sum them up. Unlike a human doing math one line at a time, this hardware can evaluate multiple partial products simultaneously using a grid (array) of adders.
You do this by tiling smaller, pre-optimised multiplier blocks (e.g. using 4x4 blocks to build larger ones).

**Booth's Multiplier:**
A long string of 1's requires many addition operations. Booth's algorithm recodes strings of 1's into a subtraction and an addition.
practical version used in modern chips. It scans 3 bits at a time (representing 2 bits of the multiplier) to perform operations like +1×, +2×, or −1× the input. This halves the number of partial products needed, speeding up the calculation.

## Multi-Operand Adders

When adding more than two numbers together, standard adders are inefficient because the carry signal has to propagate through every bit.

**The Carry-Save Adder:**
This is a technique used to speed up the summation of multiple inputs. So instead of resolving the carry immediately, the CSA saves the "carry" for a later stage.
It takes 3 inputs and produces 2 outputs.
It acts like a parallel set of Full Adders where the carry-out of one bit is passed to the next stage rather than the rippling to the neighbour immediately.
This approach is *very* fast because the "ripple" delay is postponed. To get the final result, you only need one standard adder (like a Ripple Carry or Look-ahead) at the very end to combine the final Sum and carry Vectors.

## Shifters

These move bits left or right (and in doing so either divides by a power of 2 or multiplies by a power of 2).

**One Place Shifter**:
This shifts data by exactly one place - multiplies/divides by 2.
You implement this by having a simple multiplexers to select whether a bit position  receives data from its left or right neighbour or itself.

**Shift Register:**
This can shift multiple places, but does so one bit at time.
It is cheap in terms of hardware but slow, shifting 8 places requires 8 clock cycles.

**Barrel Shifter:**
This is for high performance, this can shift or rotate a word by an arbitrary number of places in a single clock cycle. This is expensive to build as it requires wide multiplexers and extensive cross-wiring, which occupies significant chip area.
Its often built using stages of small 2:1 multiplexers, each stage shifts by a power of two e.g. to shift by 5 places, the logic activates the shift by 1 and shift by 4 stages.
This can be optimised by a 32-bit barrel shifter not implementing a "right rotate" and so to do a right shifts by 8 bits it could just do a left rotate by 24 bits ($32 - 8 = 24$).

## FIFOs

A FIFO is a First-In First-Out buffer or queue. data words are inserted and will appear *in the same order as they came in*.
It is primarily used to bridge two functional blocks that operate at different rates.

**The Pipeline Approach**:
This acts like a physical queue of people. Data enters at one end and "shuffles" forward through flip-flops whenever the space ahead is empty.
This suffers from poor performance, if the pipeline is full, data can only move when the item at the very front leaves. It has high latency because data must physically traverse every stage.

**The Circular Buffer Approach:** (efficient)
Instead of moving the data, we move *pointers*. The data stays in one memory location until it is overwritten.
You have the **Tall Pointer** that points to where the next data word will be written, it increments after every write. You also have the **Head Pointer** that points to the data ready to be read. It increments after every read.
The benefits of this is that it is energy efficient, data is not constantly shifting/toggling flip-flops, saving power. It is also **low latency** as from an empty state, a new input is immediately available at the output on the next clock cycle.

This approach is used for:
1. **Burst Handling:** If an upstream block produces a sudden "burst" of data the FIFO holds it so the downstream block can process it gradually.
2. **Hardware Stacks:** Similar to FIFOs (but FILO), used for storing procedure return addresses or nesting interrupts.

## RAM

**RAM** (Random Access Memory) is also used heavily as small embedded blocks inside processors.

**Structure and Characteristics:**
Definition: A dense electronic structure optimised to store many bits in a small space.
Density: It uses SRAM (Static RAM) cells which require only 6 transistors per bit - its more compact than flip-flops.
Interface: It usually follows a synchronous model, you supply an address at the start of a cycle, and the data appears after the clock edge.
Parameters: RAM is defined by its **width** (bits per word) and the **Address Length** ($N$ bits address $2^N$ words).

There are diverse uses for RAM, beyond storing variables.

- **Embedded Buffers:** Storing large data packets from interfaces like USB or Ethernet (acting as a large FIFO).
- **Lookup Tables**
	- Routing Tables
	- TLBs
	- Branch Prediction Tables (Branch Target Buffers)
- **Logic Functions** in FPGAs where they are used to implement logic gates. For example, a RAM can act as a truth table to calculate any function of its input.

**Multi-Port RAM:** Standard RAM usually performs one action (read or write) per cycle. **Multi-port RAM** allows simultaneous reads and write sat different addresses, but it is expensive and consumes significantly more silicone area.


## Prefetching

Processors are faster than memory. So if the processor always waits on memory then the system will be slow.
Prefetching tries to ensure that there is always an instruction to be fetched from memory every single cycle, it will spend most of its time stalling.
Prefetching tries to ensure there is always an instruction ready to issue to be executed by the system by buffering words fetched from the instruction memory.
**Variable instruction lengths** allow ISAs like x86 (where instructions vary in length) to have the buffer "smooth out" the flow, allowing the processor to assemble a complete instruction every cycle even if the memory fetch didn't perfectly align.
There is a risk because prefetching is **speculative**, the system guesses what will be needed soon, this can lead to the buffer holding the wrong word and will need to be discarded and so will waste time and power.

Therefore, to make prefetching effective, the processor must guess where the code is going to go before it has even decoded the current instruction.
You have **simple prediction**, this is guessing that the program will continue sequentially onwards, PC +1.
You have **invariant prediction,** if an instruction at a specific address caused a jump last time, it will likely jump to the same place next time.
And finally you have **sophisticated prediction,** modern predictors keep a history of past behaviour to follow patterns. *(the handout mentions that this is a complex topic).*

**Branch Target Buffer (BTB)**:
The hardware will use this BTB to instantly know that the current Program Counter (PC) address corresponds to a branch instruction that needs to jump. The BTB acts like a cache that sits in parallel with the PC incrementor.
1. The current PC address is sent to the BTB,
2. If the BTB finds a "match"  (meaning this address is a known branch), it immediately outputs the **Target Address** (where the branch goes).
3. This target address is substituted into the PC for the next cycle, effectively "predicting" the jump.


## CAM vs RAM

The BTB relies on a specialised type of memory called **CAM (Content Addressable Memory)** to perform these instant checks.

**RAM (Random Access Memory)**:
Standard behaviour, you provide an address and it gives you data.
The way RAM interacts with the BTB is that the target address is stored in RAM (the destination we want to jump to).

**CAM (Content Addressable Memory):**
This has reverse behaviour, you provide the data (which is the PC's current value) and it tells you if that data exists and where it is.
CAM compares the input against *every* stored entry in parallel. A search takes a single clock cycle (quite fast).
But CAM is quite costly in terms of hardware: It requires comparison logic (XOR and OR gates) at every single bit position. Physically, a CAM cell is roughly **twice the size of a standard SRAM** cell.

The flow of the CAM operation takes the following flow:
- **PC Output:** The processor outputs the current address.
- **Parallel Check:** The address goes to the **Instruction Memory** (to fetch the code) AND to the **BTB's CAM** (to check for branches) simultaneously.
- **CAM Hit:** If the CAM recognizes the address, it signals a "Hit" and the BTB's RAM provides the jump target.
- **Next Cycle:** The processor fetches from the jump target instead of just `PC + 1`.