18-11-2025 13:21

Tags: [[Processor Microarchitecture]]

# Design Flow: Behavioural

CAD Tools are the specific software instruments used to execute the steps within the behavioural design flow.
The **behavioural design flow** is a methodology or process, while "CAD Tools" are the means to perform the process.


Once the architecture is decided, **the behavioural design flow begin**.


![[Pasted image 20251118132259.png#invert|600]]

The behavioural design models the logic of the system, this can be:
- A high level description,
- An RTL Design


As you can see from the diagram you either start with a **Verilog** design or a **Schematic**.
*A **Schematic** is drawing the circuit visually using symbols (gates, flip-flops, block) and wires.*
These are two main ways to capture the design intent, these then feed into an **Abstract Netlist**, which is a standardised list of components and connections that represents the entire circuit.



## Behavioural Design Development

The behavioural or function design development is a design created using a HDL description or a schematic entry tool. This is what is mentioned above and is what we are familiar with.
These are then simulated according to some input stimulus file, the circuit and stimulus will be combined in a **simulation** by interpreting or compiling the code and running it. This can generate a trace file of selected signals which indicate show and when they change.
It is good to choose unique and interesting subset of the signals for tracing to limit the size of the generated files  - writing large files will slow down the simulation as it will choke on disc/network bandwidth.

With the generated trace file of selected signals, we use a **Waveform viewer** that is a tool that imports the trace file and visualises the signals, it allows the user to zoom, scroll and search for specific events for debugging.

In terms of checking the results we can use **automated testing** which is the most efficient method to automate the comparison. The **test harness** can compare the results against some **expected results** on the fly.
This makes **regression testing** easy. Regression testing is running a suite of tests to ensure that a new "fix" hasn't broken a previously working feature. A good practice is to temporarily break the design to ensure that the test harness effectively reports the error, a test that never fails might be a broken test.

# Design Flow: Synthesis

![[Pasted image 20251118153443.png#invert|800]]
Synthesis is the process of translating an abstract, functional design (usually a netlist or HDL code) into a physical implementation using components from a specific technology.

Looking at the diagram you can see that the synthesis tools takes three main inputs, the **abstract netlist** (the output from the behavioural design phase), the **library** (collection of standard cells like AND gates, OR gates, flip-flops etc) and **constraints** (a wish list of requirements the design must meet).

## Constraints

When changing a functional design into a physical one there is a wish list, these are expressed as constraints on the synthesiser and place and route tools:

- Clock period,

For almost all logic blocks there will be a clock period, into which the gate (and wire) delays must fit.

- Floorplan/pinout

You need to be able to place individual devices, some of these components/devices will correspond top bigger functional blocks. 
*In EDA (Electronic Design Automation): The **floorplan** of an integrated circuit is a schematic representation of tentative placement of its major functional blocks.*

Floor planning takes some of the geometrical constraints in a design, example are:

	• bonding pads for off-chip connections are normally located at the circumference of the chip
	• line drivers (amplifier circuit to drive transmission lines) often have to be located as close to
	bonding pads as possible
	• chip area is therefore in some cases given a minimum area in order to fit in the required
	number of pads
	• areas are clustered in order to limit data paths thus frequently featuring defined structures
	such as cache RAM, multiplier, barrel shifter, line driver and arithmetic logic unit
	• purchased intellectual property blocks (IP-blocks), such as a processor core, come in
	predefined area blocks
	• some IP-blocks come with legal limitations such as permitting no routing of signals directly
	above the block.


- Area/Density

It is desirable to use all the chip area for useful gates - it is expensive to build a bigger chip than necessary. But if everything is too packed in tightly then there won't be enough space to enlarge cells or insert buffers. A typical starting point would be at 70% utilisation.

- Power

Power dissipation is a major issue and there may be a peak power constraint for a chip or block. Power concerns are typically from self-heating and battery life. $P = E/t$ so power is also proportional to how often the node switches.

# Design Flow: Layout

![[Pasted image 20251118181014.png#invert|800]]
Above mentioned are some layout tools:

**Layout Editor:**

This is for polygon pushing - drawing the features which will actually appear as wires, transistor-parts etc.
Layout editors give a plan-view of the chip surface with the various layers depicted by different colours/shading patterns.
Layout editing will be closely coupled with DRC (Design Rule Check).
When the layout is believed complete it can be extracted.

**Extractor**:

This is the next step after the layout editor, it will identify transistors, and follow wires to find their interconnection, resulting in a schematic-like representation of what is actually present.

![[Pasted image 20251118182111.png#invert|400]]

The extractor will also capture the sizes of the components and the various load capacitances.

**Place and Route:**

P&R are separate operations but generally treated together.
**Place**ment is the location of components and **route**r will interconnect the cells with wires.
When it comes to P&R there are some important considerations, i.e. placement density.

**Buffer Insertion:**

The wiring from the router will slow down switching edges, sometimes unacceptably. To fix this the driving gates can be swapped with cells with a greater drive strength

**Logical Equivalence Checking:**

It is good to check that the circuit implemented correctly has the functions you originally designed. An equivalence checker is a separate tool which compares the synthesised netlist to the original RTL and highlights possible differences.

## Placement

Once you have a cell netlist, we have to place the primitives of the netlist on the target device.
The inputs are the cell netlist and constraints, the tool roughly allocates large areas for major blocks like the ALU or memory controller. This follows external constraints (like pin positions).
For ASICs these components are standard cells, for FPGAs they are look-up tables (LUTs).

There is an optimisation technique called **Simulated Annealing** -  a method that is inspired by how metals are cooled to make them stronger.

The Pathfinder algorithm solves this through repeated, optimized attempts:

- **Initial Route:** The algorithm starts by treating each signal path (called a "net") individually. It uses a shortest path algorithm (like Dijkstra's) to find the fastest way to connect each net. This results in many **collisions** where nets share the same wire segments.
- **Cost Update:** After all nets are routed, the tool reviews the collisions. Any wire segment that was used by multiple nets has its **cost** (or resistance) **increased**. Popular, congested wires become more expensive.
- **Re-Route & Negotiation:** The entire routing process is run again. Because the previously congested wires are now more expensive, the nets that used them are forced to search for alternative, less crowded paths.
- **Critical Net Discount:** To ensure the circuit meets the required speed, nets that are **critical** (those with very little "slack"—the time remaining before the next clock edge) are given a **discount** on the cost function. This ensures the most time-sensitive signals get priority access to the fastest wires.



## Routing

The industry standard when it comes to routing is the **Pathfinder Algorithm**, routing is the process of drawing the millions of connecting wires between all the components that were placed in the previous step (placement).



# Design Flow: Final Checks

![[Pasted image 20251118183925.png#invert|800]]


# Post-Layout Tools

**DRC: Design Rule Check**
This checks that all the polygons all obey the necessary max/min widths and clearances. If standard cells, placement and routers all work it should be okay, you may need metal fill on some tracking layers to keep chip surface planar.

**ERC: Electrical Rule Check**
Checks on the power supply, voltage drips and signal integrity.

**LVS: Layout Versus Schematic**
Does the resultant layout match the intended netlist - if it was automated it should and check if there was any hand intervention.

# Tolerances

The chip must work with a range of PVT:
- Process Variation
- Voltage (Operative Voltage)
+-10% 
- Temperature (Chip Temperature)
Temperature ranges may be 0°C-100°C

You have characterised ac hip under some 'typical' conditions but does it run and meet spec under variation?

