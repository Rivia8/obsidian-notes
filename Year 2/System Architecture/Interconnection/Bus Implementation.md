08-02-2026 16:34

Tags: [[System Architecture]]

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





