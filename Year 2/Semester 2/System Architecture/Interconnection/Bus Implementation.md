08-02-2026 16:34

Tags: [[2 - Tags/System Architecture]]

# Bus: Implementation

If we have a 64-bit processor, we *could* have:

- The 61 MSBs as the addresses,
- The 3 LSBs are the ways to distinguish between the 'chunks of data'

Since we have a 64-bit machine, the CPU can access 8 bytes at a time, the LSBs signify which byte we want to access. 
What this means is that when we access a memory address, sometimes we want to access a specific byte within the 64 bits, and the 3 LSBs allow us to do so.

$3 ~\text{bits} =  2^3 = 8$ and there are $8$ bytes within $64$ bits.

There are two important metrics:

**Latency:** the *delay* from starting an operation to perceiving the result
**Bandwidth:** The rate at which data can be moved
**Read Latency:** is the time from wanting some data and receiving the data.


Reducing Latency:
Not much can be done generally for read latency, architecturally caching would do so. For Write latency, it can be alleviated by write buffering.

Improving Bandwidth:
You can make the bus wider. It does increase the number of wires considerably which can become a be a problem for the pinout process (sometimes its desirable to have a thinner data bus where speed matters more than data width, things like I/O devices). One bus implementation can be converted into another by what is usually called a bus **bridge**:
![[Pasted image 20260209153350.png#invert]]

We can have different architectures present within a system, [[Harvard Architecture]] can be seen above. We can also see multiple buses with bridges.

On-chip and often on PCB where it is feasible it is normal to use **parallel** buses with many wires. For more distant expansions, **serial** buses (same info but sequenced in time) is preferred (e.g. PCIE Express, USB).

## IO Spaces

These are interfaces from the outside world. They are mediated by **peripherals**.

Typically peripherals will have a number of specialised registers which are used to monitor and control external qualities. 

These registers are often **memory mapped**, they have unique addresses in the overall address space. Most I/O peripherals only have a small number of associated registers.
