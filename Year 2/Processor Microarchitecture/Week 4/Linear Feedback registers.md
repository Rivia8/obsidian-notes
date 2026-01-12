12-12-2025 14:24

Tags: [[Processor Microarchitecture]]

# Linear Feedback registers

**LFSRS** generate pseudo random sequences and can be used to for test pattern generation. These can be made in different ways.

![[Pasted image 20251212142612.png#invert]]

As you can see its made of a series of flip-flops connected in a chain. The output of the last flipflop is fed back to the input of the first flip-flop but is modified by tapping outputs from some intermediate flip-flops and XORing them together.

An LSFR cycles through a sequence of states, with the right configuration, it can generate a "maximal length sequence", which looks random but repeats after $2^n - 1$ cycles (where $n$ is the number of bits).

LSFRs are a important in **Built-In Self-Test (BIST)** strategies because they are simple hardware structures that can perform two complex tasks.

1. Test Pattern Generation,

Instead of storing thousands of specific test inputs in a large, expensive ROM, an LFSR generates a stream of pseudo-random patterns to feed into the Device Under Test (DUT).

2. Built-in Self Test

To test a complex chip, you need lots of test patterns, storing these patterns requires hug ROMs but LSFRs allow a chip to test *itself* with very little extra hardware.

An FPGA can detect its own 'broken parts' and 'heal' itself by moving logic around. Instead of throwing away a chip because one of the areas are broken it works around it. Due to process variations, some parts of the chip might be slower than others, the system scans the FPGA to find these bad spots, and if a module is placed in a bad spot where it fails, the system places it in a different spot, the system then uses the LSFR to generate test patterns to check if a specific spot on the FPGA works, if the CRC checksum of the output is wrong, the system knows that the location is defective and moves the module elsewhere.









