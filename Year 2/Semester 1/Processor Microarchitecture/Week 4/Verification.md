26-11-2025 16:39

Tags: [[Processor Microarchitecture]]

# Verification

"Is there a perfect design?" 

*General Definiton:*
**VLSI Verification:** Verification is done **before** silicon development. It is done at time of product development for quality checking and bug fixing in design. There are different types of verification, like IP verification, RTL verification, timing verification etc. SoC verification is used as a broader term.

We use different techniques for different purposes when you perform Verification.

## Software Simulation

![[Pasted image 20251126165739.png#invert]]

## Hardware Emulation

Programmable devices are so large now that they can be used for simulation purposes, it is possible to synthesise large logic subsystems and load them into an FPGA. If we have a box that contains a lot of big FPGAs it may be possible to partition and load a whole chip description.
Pros of this is that it runs orders of magnitudes faster than software, and can boot an OS and run real applications.
Cons are that they are expensive, they have **low observability** which means that it is hard to see signals buried deep inside the FPGA logic. Finally, it takes hours to compile the design for the emulator.

![[Pasted image 20251127095655.png#invert]]
## Testing Techniques (Manufacturing)

VLSI chips are made on silicon wafers, defects can sometimes occur, and so their yield is not always 100%. Yield is affected by surface area, where bigger chips are more likely to be faulty.

![[Pasted image 20251127095857.png#invert]]

 
There are some production tests:
- **Probe Test** - this tests the unpackaged chip to avoid wasting packaging costs, it requires time and jig
- **Package Test** - this is easier to perform and discards more expensive, it is necessary since chips may be damaged during packaging

Occasionally the whole wafer processing my go wrong, the foundry will add test sites to the wafer and parametric tests made at certain stages.

**Test Coverage:** the proportion of the design which is tested, the requirements differ at different stages of the design and production:
Design-time: at RTL the designer should endeavour to test all the source code (with 100% branch coverage)
Circuit-level: the circuit is synthesised from the description and there is not a one-to-one correspondence of wires and HDL variables.
Production: the design is believed to work, but any component could be broken and it needs to be ensured that every wire can change logical state, checking for bridges is hard since it is layout dependent.

This is called **Design for Test (DfT)**, design techniques added to the chip specifically to make manufacturing tests possible.
**Controllability:** the ability to set internal nodes to a specific state from the outside pins, 
**Observability:** the ability to measure internal nodes from the outside pins.










