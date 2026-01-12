23-12-2025 11:57

Tags: [[Processor Microarchitecture]]

# Scan Paths

As chips get larger, they become exponentially harder to test. **Scan Paths** are a design technique used to solve the complexity problem by turning internal memory elements into a tool for testing.

Testing a large circuit is difficult due to the vast number of possible "states" it can be in.
While not a strict mathematical law, it is suggested that complexity is roughly proportional to the cube of the size: $N^3$. If a block of size $N$ has complexity of $N^3$, splitting it into two smaller blocks of size $N/2$ reduces the total complexity significantly: 
$$ 2 * (N/2)^3 = N^3 / 4$$

A scan path is a mechanism that modifies the hardware design to improve **Controllability** and **Observability**.

## How it Works:

The design tools automatically replace "normal" flip-flops (memory units) in the circuit with **Scan Flip-Flops**. 

These special flip-flops are connected in a serial chain, effectively turning the circuit's registers into one giant shift register.

In normal mode, the flip-flops behave normally, storing data for the processor.
In **scan** mode, the clock is stopped and data can now be "scanned in" (shifted in serially) to set the state of the system, or "scanned out" to read the current state.

**Advantages:**

- Uses **Serial Access** so it requires very few I/O pins on the chip.
- It allows access to deep buried logic that would otherwise be invisible.

**Disadvantages:**

- Shifting data in and out one bit at a time, is very slow especially for long chains.

## Boundary Scan

A **Boundary Scan** is one that specifically "surrounds" an IP block (like a processor or memory controller). It allows you to 'freeze' the function of a block, read the state of its peripheral pins or force new values onto those pins.