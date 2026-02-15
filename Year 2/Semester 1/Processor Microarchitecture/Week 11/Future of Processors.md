08-01-2026 16:01

Tags: [[Processor Microarchitecture]]

# Future of Processors

**Limits to Moore's Law:**
Moore's Law describes the doubling of transistors every 18-24 months but there are barriers to this in 4 areas:

1. Design Limits:
There is a growing gap between the massive number of transistors we can manufacture and our ability to actually design useful logic with them. And because custom logic is hard to design, much of the transistor budget is now spent on "repetitive" structures that are easier to generate automatically, such as huge blocks of **memory** or multiple identical **Processor** **Cores**.

2. Physical Limits:
We are hitting the hard limit of nature, the **atom**. An atom is roughly 0.1nm in radius. A 22nm transistor gate is only about 100 atoms wide. The insulation (dielectric) layers are now only a few atoms thick.

3. Manufacturing Limits:
Chips are printed using light by a process called **photolithography**. The current standard uses light with a wavelength of 193nm to print features that are 22nm small. This is difficult.
There are some alternative methods like **E-Beam / Ion Beam**. These can draw small features but they work like "handwriting", what this means is that they work serially and not parallel (like printing) - essentially too slow for mass production. **Mechanical Stamping** was researched but failed because the material kept sticking to the stamps (called the "Gecko" effect).

4. Economic Limits:
As chips get smaller, the machinery becomes exponentially more expensive. If the cost of making the transistor smaller rises faster than the benefit gained from it, shrinking becomes uneconomic and stops.

**The ITRS - International Technology Roadmap for Semiconductors:**
This is a set of documents produced by global experts that attempts to predict the future of semiconductor technology. It is considered the definitive source for forecasts on what should be technologically possible and when:
- System Drivers and Design,
- Test Equipment,
- Emerging Materials,
- Lithography (printing techniques),
- Metrology (measuring things at the nano scale).

![[Pasted image 20260108162141.png#invert]]

**Power:**

**Power Consumption** in future technologies is a critical topic because power is now the limiting factor in high-performance ICs.

Why do we need to control power? There are two fundamental reasons we must control power dissipation: **Battery Life** (essential for mobile devices) and **Cooling** (energy lost as heat must be removed. If a chip gets too hot, it fails or melts.


---

Power loss can be categorised into 2: **Dynamic (active switching)** and **Static (leakage)**

1. **Dynamic Dissipation:**
This occurs when the processor is actually doing work. 
Every time a gate switches, it charges or discharges a capacitive load ($C$). 
The energy dissipates per cycle is: 
$$ E = C \cdot V^2 $$
We have the formula:
$$ P = \alpha \cdot f \cdot C \cdot V^2 $$
- $\alpha$: Activity factor (how often the node switches).
- $f$: Clock frequency
- $C$: Capacitance
- $V$: Supply Voltage

Obviously according to the formula the most effective way to save power is by reducing the voltage (since it is squared). 

[[Issues with CMOS Circuits#Total Power Dissipation|Crowbar Current (Short Circuit)]]: When a logic gate switches, there is a brief moment where both the PMOS (top) and NMOS (bottom) transistors are partially "on". This creates a direct short circuit from power to ground, wasting energy.


2. **Static Dissipation (leakage)**
This occurs when the processor is **idle**.
Transistors are never perfectly "off", they are just "mostly off": as transistors get smaller and supply voltages drop, current leaks through the channel even when closed.
Furthermore, the insulation layer (the oxide) between the Gate and the Channel is now so thin (a few atoms) that electrons can "quantum tunnel" right through it.


---

There are various techniques for **Power Control:**

There is **clock gating**. Turning off the clock signal to parts of the chip that are not currently working. This stops them from switching (Dynamic Power = 0).
We can also have **Glitch** **Reduction**. A "Glitch" is a useless switch caused by signals arriving at different times (logic races). Designing circuits to align signals prevents this waste.
Instead of letting long buses "Flap About" (switch randomly) when unused, their values are latched (held steady).
Lastly, if the computer is idle, we can slow down the clock ($f$), and **lower the  voltage $V$**. This is because $P \propto V^2$, this saves massive amounts of power.

In terms of power for memory, memory is unique in the sense that because it is dense and rarely switches (mostly static power).
The problem is that you cannot "power gate" or turn off a standard RAM block or it will lose data. The solution to this is lowering voltage to the bare minimum required to *hold* the state (this is called the *retention voltage*). You must ramp the voltage back up before reading or writing.


---

**Variation**:

As we shrink transistors down to 10nm or 7nm, we stop dealing with "bulk" materials and start dealing with individual atoms. This introduces randomness that creates significant manufacturing headaches.

**What Cause Variation?**:

1. **Rough Edges**: When printing a line that is only a few atoms wide, "Rough Edges" become significant. A variation of a few atoms might mean the wire is 87% effective in one spot and 73% in another.
2. **Doping Fluctuations:** To make a semiconductor work, we inject "dopant" atoms (impurities) into the silicon. In the past we used to inject millions, now only a hundred or so. Statistical variation means that one transistor might get 90 atoms and its neighbour 110, this creates a massive performance difference.

(So as transistors get smaller they become more random and therefore some are *slower*. A standard synchronous Clock must therefore run at the speed of the ***slowest*** possible transistor. **Self-timed** circuits do not have a global clock, they run as fast the specific silicon allows and so they tolerate transistor variation more effectively.)

**What is the Impact?:**

What this now means is that you can no longer guarantee that every transistor on a chip has the same drive strength or switching speed. Manufacturers allow a "Bell Curve". Most transistors are near the average, but some are much faster (or slower) and some are much 'leakier'.
As processes get harder to control, the "spread" increases.
Manufacturers aim for 6$\sigma$ (meaning 99.9999998% of transistors work). Of course there are billions of transistors so even a few percent not working will mean a lot.

Because you don't know exactly how fast your transistors are, you must add larger "safety margins" to the clock frequency. You have to run the chip slower than its theoretical max just to be safe.

---

**3D on One Chip**

This is the true "3D" technology. Instead of just wiring the edges of a stacked chips, we drill holes straight through the silicon to connect them vertically.

**Through-Silicon Vias (TSVs)**
Vertical electrical connections (Vias) that pass completely through a silicon wafer. To do this you must grind the silicon wafer down until it is paper-thin, from around ~300$\mu$ to ~50$\mu$. We then use "Deep Reactive-Ion Etching" to cut vertical holes. Finally, we use **metallisation** to fill the holes with metal copper.

**The Challenge:**
While 3D TSVs offer massive bandwidth (especially for RAM), they are difficult to implement.
1. **Heat Dissipation**: if you stack three hot CPU cores on top of each other, the middle one has nowhere to dissipate its heat to.
2. There is also **mechanical stress**. Grinding wafers to 50 microns makes them incredibly fragile and prone to cracking.
3. Finally, you must **align** the millions of microscopic bumps on Chip A to perfectly with Chip B.

![[Pasted image 20260108191541.png#invert]]


---

**Exotic Stuff:**

**Neuromorphic Computing:**
This is a **non** Von Neumann architecture. Instead of traditional fetch-decode cycles which has the Von Neumann bottleneck, these chips mimic biological neurons and synapses.


