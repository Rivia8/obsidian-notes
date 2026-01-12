05-01-2026 15:08

Tags: [[Processor Microarchitecture]]

# Timing and Clocking

## Performance

This is in reference to how different ways of doing things can affect performance metrics.

There are different performance metrics:
Power, area, speed.

Here is an example:

![[Pasted image 20260105151053.png#invert]]

There are two flip-flops with some logic gates in between.

Performance depends on clock frequency and number of clock cycles. A faster clock will often mean more cycles are needed.

$$ \text{time per task} = \text{clock period} \times \text{number of clock cycles per task} $$
$$ \text{performance} \approx 1 / \text{(time per task)} $$ 
Again **repeating** shortening the clock period (higher frequency) will mean that you can do **less** work in a single cycle, therefore requiring more cycles.

In order to measure performance, FLOPS is often used - Floating Point Operations per Second (TFLOPS).
In microprocessors, efficiency is often measured by **Cycles Per Instruction** (**CPI**). A standard scalar processor usually has a CPI > 1. Superscalar processors (doing multiples at once) can have a CPI < 1, often expressed as Instructions Per Cycle (IPC).

## Clocking

To make a system faster (reduce time), you try to reduce the cycle count by maximising parallelism (doing more thing at once), however, putting too much logic in one cycle increases the delay, forcing you to slow down the clock.

A **Propagation Delay** is the time between the input crossing the 50% voltage threshold and the output crossing the same 50% threshold.
The **edge speed** is the time it takes for a signal to transition from 10% to 90% of its final value - the signal slows down as it reaches the final voltage because the capacitive load is nearly full, reducing the current flow. This is why we measure to 90% and not 100%.
 
**Clocking Constraints:**
For Synchronous Systems, specific timing rules must be obeyed:
- **Setup Time (tSETUP​):** The data input (D) must arrive and be stable **before** the clock edge hits .
- **Hold Time (tHOLD​):** The data input (D) must remain stable for a short time **after** the clock edge .
- **Propagation Delay (tPD​):** The time it takes for the Flip-Flop to actually update its output (Q) after the clock edge

We can determine the minimum clock period and so the maximum frequency of the circuit as the **critical path** is the sum of these constraints.

$$T_{\text{min}}​=t_{\text{PD\_source}}​+t_{\text{logic\_delay}} +t_{\text{SETUP\_target}}​ + \text{Margins} \text{(Skew/Jitter)}$$
There are **violations** that can affect these results:

1. **Setup Violation:** The signal arrives too late (slows down the clock speed, period increases)
2. **Hold Violation:** The signal arrives too fast, if the new data races through the logic and reaches the next flip-flop before the old data is locked in, the circuit fails. This cannot be fixed by slowing the clock, you have to add delay buffers to slow down the signal.

## Timing Closure and STA

This is the look at the process of designers ensuring their chip actually runs at the target speed ("Timing Closure") and the tools to verify it.

**Static Timing Analysis:**
Simulation runs "virtual" data through the machine STA on the other hand, calculates delays mathematically for *every* possible path.
It finds out the critical path and reports **violations** (which we have described above).
It does this by breaking the design into combinatorial paths between Flip-Flops and calculates the delay for *every* possible path.
It is very fast and safe, but can be "pessimistic" by reporting errors on "false paths" that logic can never actually take.

**Simulation vs STA**:
**Simulation** is good for checking functionality, but hard to use for timing because you can't test every combination (a 32-bit adder has $2^{64}$ possible input states).
**STA** is good for timing verification because it covers 100% of paths instantly, but does *not* check if the logic function is correct.

If your design is *too* slow (setup violations), you can have two tiers of fixes:

1. **Miles Off** - You need architectural changes
- **Pipelining:** Cut long paths into shorter stages.
- **Parallelism:** Do more work in parallel to allow a slower clock.
- **Multi-cycle:** Allow 2+ cycles for complex ops .

2. **Close** - You can tweak the technology.
- **Drive Strength:** Use bigger gates (more power, faster).
- **Thresholds:** Use "High-Speed" (leaky) transistors for critical paths and "High-Threshold" (slow, low power) for others


## Clock Distribution

There is physical difficulty with getting the clock signal to thousands of Flip-flops at exactly the same time.

1. Clock Skew
The difference in arrival time of the clock edge at different flip-flops. A bit of skew is unavoidable, however if there is a big difference between flip-flop A and B then the timing math breaks.

2. Distribution Tree:
You cannot drive all flip-flops from a single wire, you need a clock **tree**, buffers are inserted at branching points to boost the signal strength.

3. Clock jitter
This is the random variation in the clock period due to noise or temperature. You have to leave a safety margin to account for this.

4. Reset Signals
Activating reset is easy, but **removing** reset is **dangerous**. If reset is removed at different times for different parts of the chip, because of skew, the system might wake up in an illegal state. To prevent this, resets are often synchronised so they release cleanly on a clock edge.

## Clock Domains

As systems grow in complexity, it becomes impractical to run the entire chip off a single signal. Instead, we have them partition the design into multiple **Clock Domains**, where each section runs at its own **independent frequency** or **phase.**

We use multiple clock domains since different parts of a system work best at different speeds. Interfaces like USB might not match the standards of the CPU. Its also easier doing it like this since making a clock signal that branches to many components **with zero-skew** is difficult.

## Crossing Clock Domains and Synchronisation

When a signal generated in one clock domain is read by a flip-flop in a different domain, you are **Crossing Clock Domains**.
This is **dangerous** for **Metastability,** since the two clocks are independent (asynchronous), a signal from Domain A might arrive at Domain B exactly when Domain B's clock is rising.
- This violates Setup and Hold times,
- We enter something called **Metastability** - this like a ball balanced on a hill, it is neither a logical 1 or 0.

You cannot prevent metastability when crossing domains, but it *can* be resolved before it does damage. This is via a **synchroniser**:
This is where we chain two or more flip-flops together in the same destination domain:
- **First Flip-Flop:** Captures the asynchronous input. If it violates setup/hold times, this flip-flop goes metastable (the "ball" is on the hill).
- **Wait One Cycle:** We give the first flip-flop an entire clock cycle to resolve (for the "ball" to roll down). The probability of it staying metastable for that long is very low.
- **Second Flip-Flop:** Samples the output of the first one. By now, the signal is stable (a clean '0' or '1'), so the second flip-flop captures valid data safe for the rest of the system.

This raises the idea of **reliability** vs **latency**: 
- If the chance of the first flip-flop failing is 1 in a million (10−6), adding a second flip-flop makes the chance of failure 1 in a trillion (10−12).
- Each flip-flop you add increases the delay (latency) of the signal by one clock cycle. You are trading speed for reliability

## Design Partitioning and Pipelining

As systems become bigger, you must break them down (**partition**) into smaller, manageable blocks.
Some bits are obvious - like partitioning ALUs from memories etc. For less obvious parts you rely on design experience or system software to test different arrangements before committing to hardware.

**Pipelining** is a specific form of partitioning used to increase performance , particularly in processors. 
It involves breaking down long, slow combinatorial logic path into shorter "stages" separated by registers (flip-flops).

**Throughput vs Latency:**
You increase *throughput* because you break down the logic into smaller chunks, each chunk will take less time to complete. This allows you to run the clock frequency higher since the time to complete a single specific task actually gets longer.

*Latency* **increases**, this is because you accept a slightly slower individual completion times to get a massive boost in the total volume of work done.

You need something called **Pipeline Balance**, this is because when it comes down to it the minimum clock period is determined by the *longest critical path*. There isn't any point speeding up a stage that is already fast, you need to identify and optimise the slowest stage to increase the overall clock speed. Often accessing memory is the bottleneck, designers must pipeline the memory access itself (splitting the read/write over multiple cycles) or fetch multiple words at once to hide the slowness.

## Future Trends

**Network on Chip (NoC):** Instead of using a shared bus (which bottlenecks performance), modern chips connect components using a switched network, similar to how the Internet works but on a microscopic scale.

**GALS (Globally Asynchronous, Locally Synchronous):** A hybrid approach where individual blocks have their own clocks (Synchronous) but communicate with each other asynchronously. This avoids the nightmare of distributing a single clock across a giant chip.

**Asynchronous Design:** Removing the clock entirely. This saves power (no clock tree burning energy) and avoids skew problems, but it is much harder to design and currently lacks good tool support.