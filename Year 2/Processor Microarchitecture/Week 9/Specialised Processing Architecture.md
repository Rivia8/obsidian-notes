06-01-2026 10:13

Tags: [[Processor Microarchitecture]]

# Specialised Processing Architecture

Standard "General Purpose" processors operate on the *Fetch-Decode-Execute* cycle are optimised for integer arithmetic and logical operations. This makes them quite flexible but for certain tasks it makes them highly inefficient:
- Numeric Processing - High-precision floating-point arithmetic or vector processing,
- Cryptography - Requires abnormal bit manipulations and transpositions that standard ALUs handle slowly.
- Digital Signal Processing - Requires real time processing of data streams and fast multiplications
- Graphics: Highly parallelisable tasks

There is an 'evolution' hardware that is described by Moore's law. But as general-purpose processors become faster, they tend to "assimilate" specialised functions.

The typical evolution path is:

- **Hardware (ASIC):** Fixed function, very fast, but completely inflexible.
- **Custom Processor:** Specialized Instruction Set Architecture (ISA); offers some flexibility.
- **ISA Extensions:** General processors add specific instructions (e.g., MMX/SSE) to handle specialized tasks.
- **Hardware Extensions:** Adding coprocessors or dedicated hardware blocks to a general CPU.

There are some programming challenges where programming specialised architectures can be difficult because they often have irregular instruction sets or require managing explicit parallelism. Instead of writing raw code, developers often rely on APIs (like OpenGL or DirectX) or hand-optimised libraries to bridge the gap between standard code and specialised hardware.

DSPs are a prime example of specialised architecture emerging around 1980.
Early DSPs were excellent at mathematical code but horrible for general purpose compute. In modern day systems, general purpose CPUs have adopted many DSP features, but dedicated DSPs still exist for high performance mathematics.

## Coprocessors

A coprocessor is a processing unit that is distinct from the main CPU and is not historically part of the basic Instruction Set Architecture (ISA). It is designed to offload specific tasks, such as floating-point math or system control, from the main processor.

How it works:
The coprocessor will monitor instructions, it sits on the bus and monitors the instruction stream fetched by the main CPU. If it recognises an instruction intended for it (by a specific ID field) it executed it in coordination with the CPU. If the coprocessor does not recognise the instruction the main CPU treats it as an "Illegal instruction" and triggers an exception. This allows the Operating System to intervene and emulate the missing hardware in software.

There is an example of ARM's coprocessor interface, where ARM supports 16 coprocessors identified by a 4-bit field in the instruction. There are three main classes of operation: Data Processing (CDP), Register Transfer (MRC/MCR) and Load/Store (LDC/STC).

## Digital Signal Processors (DSPs)

DSPs are specialised processors designed to perform a specific subset of computing tasks, like filtering, audio processing, or Fast Fourier Transforms (FTT) - efficiently.

The most fundamental operation in signal processing is the Dot Product (multiplying two numbers and adding up the results) which is used for digital filters:
$$\text{Result} = \sum(\text{data}[i] \times \text{coeff}[i])$$
- A general CPU takes several cycles to load, multiplay, add and loop. A DSP uses specialised hardware to do this in a single cycle using **VLIW** (Very Long Instruction Word) commands and hardware loop counters.

![[Pasted image 20260106133201.png#invert]]

To achieve this DSPs differ from standard CPUs in several ways, 
- They use **Harvard Architecture** which has separate memory buses for data and instructions, this allows for parallel access.
- In standard CPUs, adding two large numbers might overflow (wrap around to be a negative number) which can cause glitches. DSPs have hardware to saturate or clip the value to the maximum representable number.
- There is  **zero-overhead** loops as the **hardware** manages the loop counters, so there are no cycles wasted on "decrement" and "branch" instructions.
- They have **specialised addressing**, what this means is that they support unusual memory access patterns, such as bit-reversed addressing required for FFT algorithms.
- They have **very wide Accumulators** to prevent overflowing during long summation sequences.

## Superscalar Extensions

Multimedia (audio and video) has become more dominant and engineers realised that using 32-bit integer path for simple 8-bit or 16-bit data (like pixel colours or audio samples) was wasteful.

To solve this they introduced **SIMD** **(Single Instruction, Multiple Data)** extensions.

Instead of processing one value per cycle, the processor "packs" multiple small values into a single register and processes them all at once: *A single 32-bit register can hold four 8-bit values or two 16-bit values*.

This requires only minor changes to the existing Arithmetic Logic Unit (ALU). The hardware simply adds "gates" to prevent the carry bit from propagating from one small packed value to the next. 
Examples: **Intel:** MMX and SSE (Streaming SIMD Extensions), **ARM:** ISA v6 extensions and NEON.

There is also ARM's VFP unit. Unlike True parallel SIMD, the VFP processes vectors serially through a single functional unit, making it slower than the fully parallel approach of NEON

## NEON

![[Pasted image 20260106140612.png#invert]]

NEON is ARM's advanced implementation of the "Superscalar Extension" concept. It is a dedicated hardware engine designed to accelerate multimedia and signal processing.

**Registers:** It has a massive register file, comprising 32 x 64 bit registers, which can be combined and viewed as 16 x 128 bit vector registers,
**Data Types:** It can handle vectors of 8, 16, 32 or 64-bit integers, as well as 32-bit floating point numbers.
**Deep pipeline:** NEON operates as a separate, deep pipeline that sits behind the main integer pipeline.

How it works:
1. The main integer pipeline handles the 'admin' work like fetching data and passes the instruction to NEON.
2. NEON instructions execute later, the MAIN CPU doesn't wait for them, unless it specifically needs the result back.
3. Since NEON is a separate unit, moving results back from NEON registers to the main CPU registers can be slow, optimally you can keep the data inside NEON for as long as possible.

There has been research into CPU interlays to replace fixed units like NEON. They are small FPGA fabrics inside processors. This allows the hardware to be reconfigured at runtime to suit specific applications.

## GPUs

**Graphics Processing Units** are like DSPs in the way that they are designed for a specific thing. They originally were used for graphics but are now used for general massively parallel tasks.

They are **latency tolerant** which means that unlike CPUs, they do not prioritise low latency for a single task, as long as the total bandwidth (volume of data) is high, they tolerate delays well.
They have **massive threading**.
They excel when the same operation is performed **En Masse**. 
Data is rarely reused immediately, so GPUs generally lack large caches compared to CPUs. Instead, they rely on fetching blocks via DMA.
There is minimal hardware interlocking, the software (drivers and compiler) is responsible for synchronisation and memory coherency.

**NVidia Style Architecture:**
![[Pasted image 20260106141650.png#invert]]

We can see that the chip is composed of many identical blocks, these are called "Stream Multiprocessors". 
GPUs use something called **Hardware Thread Scheduling**, Context Switching is effectively free. Also, if a thread stalls waiting for memory, the hardware instantly switches to another thread that is ready to run. This hides the memory latency without needing complex cache hierarchies.
For **resources** they have massive register files partitioned among threads. Threads share local memory blocks.
They have **Special Function Units (SFUs)** that are dedicated hardware for math functions like `sin`, `cos`, `log` and `exp`.

There are various programming models to utilise the GPUs functionality:
**APIs:** Traditionally programmed via abstract APIs like **OpenGL** or **DirectX**.
**GPGPU (General Purpose GPU):** Using GPUs for non-graphics tasks like bioinformatics (DNA sequencing)
**OpenCL:** An open standard framework that allows code to run across heterogeneous systems (mixing CPUs, GPUs, and DSPs). It anticipates a future where processors "sleep" or turn off when their specific specialty isn't needed

## VLIW vs Superscalar

Both these architectures aim to break the "one instruction per cycle" limit but they solve scheduling problems differently.

**VLIW (Very Long Instruction Word).**
Here the compiler does the work, it groups multiple instructions into one "Very Long" word to be executed in parallel.

**Pros**: simplifies hardware because there is no need for complex runtime schedulers or dependency checkers.
**Cons:** 
- There are **Static Scheduling Limitations**, the compiler cannot predict dynamic events (like cache misses or variable loop counts) as well as hardware can.
- This can lead to **Code Bloat** where if the "Very Long" word isn't fully utilised, it must insert NOPs (No Operations), wasting memory fetch bandwidth.
- Furthermore, code is tightly tied to the specific hardware, if you change the hardware you must recompile (**Compatibility**).

**Superscalar:**
Here the hardware does the work, the processor fetches a stream of sequential instructions and decides at *runtime* which ones can be executed in parallel.

**Pros:** It has more efficient use of memory (no need for padding with NOPs) and better handling of runtime surprises

**Cons:** it requires **serious** hardware complexity and consumes more power and area to handle the dependency checking and reordering on the fly,

## Transport Triggered Architecture

This is a unique architecture where the program doesn't specify "add registers A and B" instead it specifies data movements. 
Functional units (Adders, Multipliers) have addressable "ports". The control unit moves data to these ports and the arrival of data triggers the operation.