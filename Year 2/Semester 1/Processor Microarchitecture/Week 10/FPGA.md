08-01-2026 13:39

Tags: [[Processor Microarchitecture]]

# FPGAs

An FPGA is a chip (ASIC - Application-Specific Integrated Circuit) that can be programmed to mimic *any* other digital circuit. It is a "target technology" like an ASIC but also a "processing device" like a CPU.

In terms of the **Fabric**, the chip is a regular grid of three main primitives:

1. **Look-up Tables (LUTs):** Small memories that act as Truth Tables to implement boolean logic. An $N$-input LUT can implement any boolean function of $N$ inputs.
2. **Switch Matrices:** These are for routing by having a vast network of multiplexers that connect the LUTs together.
3. **Flip-Flops:** This is for storing states for sequential logic.

One of the key comparison points of FPGAs is the concept of **cost:**
FPGAs are generic, they are less efficient than a chip built for a purpose (ASIC).

Compared to an ASIC, FPGA is:
- ~100x larger.
- ~4x slower
- ~10x less efficient (power)

In order to close this gap, modern FPGAs include **Dedicated Hard Blocks**, for common expensive structures such as Multipliers (DSP Blocks) and RAM blocks. Using these are much faster and cheaper than building them out of LUTs.

**Compute Paradigms: CPU vs GPU vs FPGA:**

| **Architecture** | **Paradigm**            | **Bottleneck/Characteristic**                                                                                                                          |
| ---------------- | ----------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **CPU**          | **Von Neumann**         | **Fetch/Decode Bottleneck:** Spends huge energy/time fetching instructions and moving data across a shared bus.                                        |
| **GPU**          | **SIMD (Vector)**       | **Memory Bandwidth:** Efficient for parallel tasks but requires massive global shared memory throughput.                                               |
| **FPGA**         | **Dataflow (Pipeline)** | **No Instructions:** There is no "fetch-decode" cycle. The structure of the hardware _is_ the algorithm. Data streams through a pipeline of operators. |
There are some key advantages of the FPGA workflow:
1. It has **Deep Pipelining**, what this means is that while a CPU must finish a loop iteration before starting the next, an FPGA pipeline can start a new operation **every single clock cycle**.
2. It also has the advantage of **customisation**: you can tailor the machine to the problem, rather than tailoring the problem to the machine (CPU/GPU).

---

**Here is a look at some examples:**

**Multiplexers:** FPGAs are *physically* built using multiplexers (for routing), but they are surprisingly inefficient at implementing multiplexers in user logic (using LUTs).

**String Matching ASCII Characters:** Instead of comparing characters sequentially like you would do so in a CPU style configuration, FPGAs use LUTs as **CAMs** (Content Addressable Memory). A LUT is programmed to output `1` only if the input bits match a specific character (e.g. 'H'). This allows massive parallel string search (e.g. Gene Sequencing).

**Polynomials ($Ax^3 + Bx^2 ...$):** This can be implemented using the dedicated DSP blocks (multiply-adders) in a cascade. This forms a pipeline where a new $x$ value enters and a new $f(x)$ result exits every cycle.


---

When it comes to **Economics and Energy** because FGPAs run at lower clock speeds and lack the "overhead" of instruction fetch/decode, they are often more energy-efficient than GPUs for specific tasks (e.g. Baidu Search algorithms). You can also program an FPGA to act like a CPU (a "Soft Core"). This is useful for running sequential control code alongside hardware accelerators.


