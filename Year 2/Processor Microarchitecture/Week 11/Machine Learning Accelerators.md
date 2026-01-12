08-01-2026 15:52

Tags: [[Processor Microarchitecture]]

# Machine Learning Accelerators

Moore's law is slowing and the era of getting "free" speedups for general purpose CPUs every two years is ending

However, the demand for computing power has increased, driving by Machine Learning (ML) breakthroughs like ChatGPT. To handle these breakthroughs we need specialised hardware.

**Tensors and Matrix Multiplication:**
To understand the hardware needs, we need to understand the workload. Neural Networks function by processing **Tensors**.

A **Tensor** is a generalised matrix.
- Rank 0 = Scalar (single number)
- Rank 1 = Vector (1D array)
- Rank 2 = Matrix (2D grid)
- Rank 3 = 3D Tensor (Cube of numbers) .

Neural Network inference involves passing data through a layer of neurons. Mathematically this is simply a massive amount of **Multiplication and Addition: $y = Wx + b$**. Efficiently executing these millions of multiply-accumulate operations is the primary goal of modern AI hardware.

CPU is a generalist machine where its designed for flexibility, it can run operating systems, word processors or rocket controls etc. But because it is general purpose, it doesn't know what calculation comes next, it must read an instruction, fetch data from memory, calculate and write it back for *every single **operation***.

GPUs improve on CPU by using massive parallelism (in this regard). Instead of a few ALUs, a GPU might have 2,500 - 5,000 ALUs, allowing thousands of calculations simultaneously. While faster at this task, GPUs are still general machines, and still have the same issue when it comes to these tasks - it must access shared memory or registers to store intermediate results. This high memory access creates a significant energy footprint and requires complex wiring.

The solution leads to Google's **TPU** **(Tensor Processing Unit)**. The TPU discards general-purpose flexibility to solve the Von Neumann bottleneck. The TPU is domain specific for Matrix Multiplication in neural networks. Since the hardware *knows* the workload is always matrix math, it doesn't need to fetch instructions or access memory for every step. Instead of independent ALUs, the TPU uses a **Systolic Array**. This allows data to flow directly from one ALU to the next without going back to memory, drastically reducing power consumption and increasing speed.


**Systolic Array:**
In a **Systolic Array**, data flows through a grid of ALUs like blood pumping through a heart (hence systolic).


The way it works:
Weights or parameters are loaded into the grid first and held stationary. Input data flows in from the left. 
![[Pasted image 20260108201423.png#invert]]
Multipliers perform their calculation, adding it to the passing sum, and pass the result to the next neighbour instantly. During this massive wave of calculation, **no memory access is required**.

The TPU v1 has a 256 x 256 grid, meaning 65,546 ALUs working in parallel.

**TPU v1 Spec and Floorplan:**

![[Pasted image 20260108201530.png#invert]]

In a CPU/GPU complex control logic (branch prediction, out-of-order execution) takes up huge space. In the TPU, control logic is <2% of the chip. This is because matrix math is deterministic and doesn't need complex scheduling logic.
This also has cost benefit since the TPU die itself is half the size of a comparable CPU/GPU - smaller chips mean you can print more per wafer, reducing cost by roughly 8x.


**The usage of bfloat16:**
To go faster, Google realised they didn't need the insane precision that came with the standard 32-bit Floating Point (FP32). This is because Machine Learning models are "fuzzy", they don't need perfect accuracy and just need the right "range". So Google created a custom format called **bfloat16** (**Brain Floating Point**). 

- It cuts the 23-bit Mantissa down to just 7 bits,. 
- It keeps the 8-bit exponent the same as FP32. What this means is that you can swap FP32 for bfloat16 easily without the numbers overflowing.

Microsoft also has **MSFP-12** which shares one exponent across a whole block of numbers to compress data even further.


---

After TPUs there can be more 'Specialisation' that is a lot more exotic.

**Mortal Computation:** Geoff Hinton suggested at merging hardware and software so completely that code can't run on a different chip (analogue computing).

**IBM NorthPole:** A new architecture that puts memory inside the computing core to totally eliminate the Von Neumann Bottleneck.

**Quantum Supremacy:** Google's Sycamore chip performing calculations impossible for classical machines.