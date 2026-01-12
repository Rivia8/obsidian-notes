09-11-2024 17:19

Status: #new

Tags:  [[Computer Engineering]] [[3-Box Model of the Computer]]

# MU0
Manchester University has designed a simple processor design called the MU0.
MU0 in essence is the most simplest processor design you are likely to come across, both in terms of the complexity of the hardware design and the functionality of the CPU.

The Instruction set architecture (ISA) is an abstract view of what the processor does, it represents the programmer's view of the system, the size of the instructions, address and data buses and the instruction that it will execute. 

MU0 has a Von Neumann architecture: memory contains both instructions and data. MU0 operates on operands that are held in memory; consequently instructions specify the address where the data can be found.

The instruction decoding is very simple for MU0:
- the four most significant bits (bits 15:12) are the opcode, which specifies the operation required by the instruction,
- the remaining 12 bits (bits 11:0) is the address in memory where the operand can be found.
## Sequencing
Key steps in the execution of an instruction in the processor are sequenced to the clock.
The contents of the registers are updated simultaneously at the rising edge of the clock - depending on the whether the clock enable clock signals is asserted.
The frequency of the clock determines how quickly each instruction is executed and therefore how quickly the processor runs.
## The MUO ISA
The opcode specifies the instruction, although MU0 can support 16 possible operations, only 8 have been implemented, leaving room for further extension.

The ISA for MU0:
- Memory is 16 bits
- The internal Data paths are 16 bits wide
- The instructions are 16 bits wide
- The address space is 12 bits

The instructions have a fixed format:
- 4 bit opcode
- 12 bits operand address

It has two user visible registers
- The accumulator (ACC)
- Program Counter (PC)

It is a single address machine:
- One operand is specified in the instruction
- Other operands are implicit in the instruction

The memory used for MU0 has two control signals:
- `Ren` - goes high when data is to be read from a memory location.
- `Wen` - goes high when data is to be written to a memory location.
Ren and Wen are mutually exclusive - they cannot be high at the same time.

## MUO Instructions:
`LDA S`
The `LDA`instruction is used to copy the contents of a memory location, specified by the address, `S`, the instruction into the accumulator.

`STA S`
The `STA` instruction is used to copy the contents of the accumulator into the memory location, `S`, specified in the instruction.

`ADD S`
The `ADD` instruction is used to add operands:
- One operand can be found in the memory address, `S`, supplied in the instruction
- One operand comes from the accumulator

`SUB S` 
The `SUB` instruction is used to subtract to operands:
- One operand can be found in the memory address, `S`, supplied in the instruction
- One operand comes from the accumulator

`JMP S`
The `JMP` instruction is used to change the programme flow so that the processor jumps to another sequence of instructions located in memory defined by the start address `S`, supplied in the instruction. The branch is unconditional and always happens. Execution of the instruction results in the contents of the PC being overwritten with `S`.

`JGE S`
JGE is a conditional branch instruction. If the contents of the accumulator following previous instruction execution results in the value in the accumulator being greater than or equal to zero, then the PC is overwritten with the address, `S`, supplied in the instruction.

`JNE S`
`JNE` is a conditional branch instruction. If the contents of the accumulator following the previous instruction results in the value in the accumulator not being equal to zero, then the PC is overwritten with the address, S, supplied in the instruction.

`STP`
This simply halts the processor. In terms of the action it causes the FSM to remain in the execute state.
There is also an output from MU0 called Halted – this goes high when a STP instruction is executed.
![[Pasted image 20241109195414.png#invert]]

## MU0 Execution Steps
When executing an MU0 instruction, the following steps are followed:
- Fetch the instruction,
- Increment the PC,
- Decode the instruction,
- Fetch the operands,
- Perform the required operands,
- Perform the required operation,
- Write the result.

In the MU0 design we combine some of these steps so that there are only two stages since some of these steps takes longer than others: in the fetch instruction accessing memory takes a long time since memory is slow.

- fetch, which contains
	- fetch of the instruction from memory 
	- incrementing the PC
- execute/decode, which contains
	- decoding of the instruction
	- fetch the operands
	- performing the required operation
	- write the result

## Designing the MU0 Datapath
Here we will be looking at how data moves between the functional components (PC, IR, ACC and ALU) of the datapath as we execute and instruction (fetch and execute phases). 

![[Pasted image 20241218155454.png#invert]]

As with any other processor, the MU0 design has a hierarchy, where the design is partitioned into blocks, this allows for easier implementation of the design.
The datapath consists of the logical components and registers to enable the register transfer level (RTL) view of a sequential system to be realised.
The control consists of the finite state machine (FSM) that determines the state of the system, and the control signal decode logic that determines the status of the control signals to the datapath (from the control) that control the operation of the datapath depending on the phase (fetch, execute) and the current instruction.

![[Pasted image 20241218154523.png#invert]]
The datapath interacts with the outside world via the address, data in and data out buses.
Within the datapath we have the key functional components: the PC, IR, ACC, and ALU.

### Fetch
In fetch, we place the contents in the PC on the address bus and from memory the data will be placed into the 'Data in' bus to the IR. We also need to increment the PC, so we identify a path from the output of the PC to the input of the ALU. The ALU performs a +1 operation and we write the result back to the PC.
![[Pasted image 20241218155916.png#invert]]
### Execute
Now looking at the execute phase, first we will need to take an address from the IR (in the case of an arithmetic operation) and place it on the address bus - this is grabbing our operand address. However, looking at the diagram above, we can see that there is already a path to the address bus, so we need to select what gets connected to the address bus at one particular time.
So we are going to insert a multiplexer (a data selector). It will be a 2-to-1 12-bit MUX, it allows us to select between two 12-bit inputs depending on the status of a 1-bit control signal. If the control, signal is 0, then the output of the PC is connected to the address bus, otherwise if the control is 1, then the output of the IR is connected to the address bus.
The address goes out on the Address Bus and the operand comes in from memory on the Data In bus, which is then passed to one of the inputs of the ALU.
The other operand comes from the accumulator but from the fetch phase we've already used the other input to the ALU. So we need another multiplexer that collects two inputs from the PC and the ACC that goes to the ALU.
![[Pasted image 20241218160957.png#invert]]

### Branch Instructions
For the branch instructions (JMP, JGE, JNE) we have to write the address to the PC. But since we have already have a connection to the input of the PC we need another form of data selection. We could use another multiplexer but instead we will select which input goes to the input of the ALU from the IR (branch instructions) or Data In bus (arithmetic and LDA), using a 2-to-1 16 bit multiplexer.
Okay lets say we have a branch instruction coming from the IR, it will select that input (the multiplexer will have the appropriate control signal) and it will be passed to the ALU, which the ALU will then pass to the PC (the ALU has a passthrough function).
![[Pasted image 20241218163346.png#invert]]
### Flag logic and Control
The flag logic (N and Z) is also part of the Datapath. In addition we have a connection out from the datapath to the 'Control' - the instruction opcode, as the instruction needs to know what instruction is being executed.
![[Pasted image 20241218165956.png#invert]]


![[Pasted image 20241218164615.png#invert]]
![[Pasted image 20241218164630.png#invert]]
![[Pasted image 20241218164703.png#invert]]
![[Pasted image 20241218164714.png#invert]]
## Registers
Registers are sequential elements that store data, where the stored data is always available for readout at the output of the register.
Often the data to be stored comes from the output of a combinatorial circuit, for instance, the output of an ALU.
Registers are typically built with a series of flip-flops with common control signals, such as the clock and reset.
The register is an edge triggered device, which means that the data is only stored when there is a rising or falling edge observed on the clock input. 

An example of a 4 bit register:

![[Pasted image 20241218172826.png#invert|400]]

## Multiplexers
A [[Multiplexer]] is simple data selector. They have multi-bit control signal, `sel`, that determines which of the inputs will be connected to the output. The inputs can be single bits, or they could be buses. 

## ALU
The arithmetic logic unit, ALU, is the brains behind the processor datapath. It is the ALU that performs the operations by the instruction using the operands specified - such as arithmetic and logical operations.

The ALU is a purely combinatorial circuit, so no clock or reset signals and it does not contain any registers.

In the case of MU0 the ALU has two inputs, X and Y, which are both 16-bit buses. The ALU can implement a number of functions depending upon a control signal input and the 16-bit value is observed at the output, R.

The MU0 ALU has to perform 4 operations:
- R = X + 1
- R = X + Y
- R = X - Y
- R = Y
To select the operation it has a 2-bit control signal, called M.

### The Adder
At the heart of the ALU we have a 16-bit adder that takes two 16-bit values, along with a carry in, and generates 16-bit result along with a carry out. The main operation of the ALU is addition, where subtraction can be carried out via addition through making the addition a negative number.
![[Pasted image 20241218233554.png#invert|200]]

![[Pasted image 20241218233623.png#invert]]


### Critical Path
Any combinatorial logic circuit does not generate an output instantaneously, instead there is some finite delay until the output changes due to a change of the input. 
If you look at the ripple carry adder design above, you can see that the output of bit cannot be generated until the output from bit 1 is produced.

This delay is related to the number of components the signal has to propagate through - the '**Gate Delay**'. The more logic gates, the longer the delay. The measure of the maximum delay for the circuit is called the **critical path** and this limits the maximum operating speed of a circuit.

### Operations
In the case of **ADD**, it is quite straightforward:
We add the two inputs X and Y using our 16-bit adder design we have just explored

For **SUB**, we could add a negative value, i.e.:
X - Y = X + (-Y)
In order to generate the negative Y operand:
-Y = (Y') + 1 
Y is inverted as in for each bit 0 -> 1 and 1 -> 0 and we set the increment to 1.

For **Increment** we make the Y input 1 and perform an ADD.

For **Passthrough** we just set the carry in to 0.

![[Pasted image 20241218235632.png#invert|600]]
![[Pasted image 20241218235750.png#invert]]

#### Preconditioner
In order to set the Carry In to either 0 or 1, we have something called the **preconditioner**.

![[Pasted image 20241219000031.png#invert]]
The preconditioner is a circuit with an external control signal, that manipulates the data at the input in some way to give the desired value required by the ALU.

## Control Signals
We have already produced a datapath design, we now need to identify the control signals required to control the operation of the datapath. These signals will be set by the control block depending on the current state (fetch or execute) and the instruction being executed (in execute only). The control block is also responsible for decoding the instruction from the IR to determine what operation is required.

The signals are:
- Data out/X input Multiplexer, `X_sel`
- Address multiplexer, `Addr_sel`
- Y input multiplexer, `Y_sel`
- Program Counter, `PC_En`
- Instruction Register, `IR_En`
- Accumulator, `ACC_En`
- ALU, `M[1:0]`

We also have to consider the control of memory, where we can either perform data read or data write operations. For MU0 we have two mutually exclusive controls signals that are used to control memory:
- `Rr` - Memory read, goes high when a memory read is required.
- `Wr` - Memory write, goes high when a memory write is required.
The actual read/write operation is performed by the memory itself. However, we need to make sure that a valid address is placed on the address bus for both cases, and for read we read the data from the Data In bus an for write, we place the data on the Data Out bus.
![[Pasted image 20241219120505.png#invert]]

## Conditional Branches

The `JMP` instruction updates the program counter with the address proved in bits 11:0 of the instruction from the IR.

For `JGE` and `JNE`, these instructions conditionally update the PC based on the state of specific flags.

For these specific flags, we have a condition code register, also known as a **status register** or **flag register**. This is used to store the status of a number of flag bits for a processor. It contains information about the state of the result of a particular instruction.

This a dedicated register that the processor will have for these flag bits, which are updated when instructed to. In the case of the ARM processor, the mnemonic is appended with an 'S' (e.g. ADDS) to indicate that the condition code register should be updated as a result of the operation.

Common flags are:
- N: Negative Flag
- Z: Zero Flag
- V: Overflow Flag
- C: Carry flag

For the case of MU0 it does not have a status register, rather it just has two status flags that are continuously updated depending on the value stored in the accumulator. 

- N: Negative Flag - Will be 1 when the value held in the accumulator is negative, otherwise it will be 0.
- Z: Zero Flag - Will be 1 when the value held in the accumulator is zero, otherwise it will be 0.

So all instructions that change the contents of the accumulator will update the status flags.

## MUO Control Block

### Overview
The control block contains a finite state machine (FSM) that advanced the state based on the current instruction.
It also contains control signal decode logic that determines the state of control signals for the datapath components (registers, ALU, Multiplexers) based on the FSM's state and the instruction being executed.

Inputs:
- Clock (Clk): Global clock signal required for sequential operations
- Reset: Resets the FSM and control block
- Instruction Bits (IR\[15:12]): Instruction code fetched from the Instruction Register (IR), which guides the processor's behaviour.

Outputs:
- Control signals for the datapath (registers, multiplexers, ALU)
- Memory control signals, (e.g. read/write)

### Registers and their control signals:
Each register has:
- Clock Input (Clk): Driven externally to synchronise updates
- Reset Signal: Resets the register's contents
- Enable Signals:
	- **IR Enable (IR_En)**: Allows the IR to update its contents on a clock edge.
	- **PC Enable (PC_En)**: Allows the PC to update its contents on a clock edge.
	- **ACC Enable (Acc_En)**: Allows the accumulator to update its contents on a clock edge.

These enable signals are driven by the MU0 control block, which decides which register updates at any moment.

### Multiplexers and their control signals:
MUXs control the flow of data and determine sources for specific datapath components.
- **Address Bus MUX (AddrMux)**:
    - Controlled by `Addr_sel`.
    - Selects the source for the address bus:
        - `0`: Address from the PC.
        - `1`: Address from the IR.
- **ALU X Input MUX (XMUX)**:
    - Controlled by `X_sel`.
    - Selects the source for the ALU's **X input**:
        - `0`: From the Accumulator.
        - `1`: From the PC.
- **ALU Y Input MUX (YMUX)**:
    - Controlled by `Y_sel`.
    - Selects the source for the ALU's **Y input**:
        - `0`: From the Data In bus (external data from memory).
        - `1`: From the IR

![[Pasted image 20241219125201.png#invert|400]]
![[Pasted image 20241219125318.png#invert]]

So when we need to fetch or execute, we will to set the status of the control signals for that to occur.

# MU0 Enhancements

## Critical Path
Reminder: The critical path is the longest delay through a digital circuit and this limits the speed at which the circuit can be operated i.e. it limits the clock speed.
For a processor, the critical path will determine the maximum number of operations the processor can perform per second (often measured as MIPS), as well as the maximum clock speed.

The execution of an instruction takes two clock cycles, the first to fetch the instruction, the second to execute the instruction. The critical path limits the maximum speed of the clock depending on which of these actions takes the longest time.

![[Pasted image 20241219174618.png#invert|400]]
### Critical Path: Fetch phase
Two things happen in parallel: 
1. Instruction fetch, the processor reads the instruction from memory.
2. PC increment, the Program Counter is incremented.
The slower of these two actions determines the critical delay.
Since memory access is typically slower than arithmetic operation in the ALU, so the critical delay for the fetch phase is memory access time.

### Critical Path: Execute Phase
The actions during execution depends on the specific instruction being executed.
`LDA` : (Load Accumulator) Reads data from a memory address into the accumulator.
`ADD` or `SUB` : Fetches a value from memory, passes it through the ALU for addition/subtraction, and updates the accumulator. This means that the delay is the sum of the time it takes to read data from memory plus the time it takes to propagate through the ALU.

### Limitations
So we have found what limits the speed on MU0, that is the time it takes to perform a memory operation. 

The delay associated with the memory operation is limited by the memory used and as such cannot be optimised by any redesign of the processor.

So we will then look at how we can speed up the operation of the arithmetic logic unit.

## ALU
At the heart of the ALU we have a 16-bit ripple carry adder.
![[Pasted image 20241219184126.png#invert]]
We have a maximum delay of 3 gate delay, when A, B and Carry In all go high.
In essence for a 16 bit adder, we (2n+1)δ where δ is the delay per gate.
For a larger n, the delay becomes significant because each carry must ripple through every adder in sequence.

How do we improve this gate delay?

One way we could do this is to use a different design, one we might call the **Carry Look-Ahead Adder**.

### Carry Look-Ahead Adder
So instead of allowing the Carry to ripple through each bit, the CLA has logic that predicts the carry for every bit based on its inputs, allowing all operations to done in parallel.
There are three levels of logic to the design.
1. Generate the propagate, *p*, and generate, *g*, terms - the propagate term is the XOR of the two bits and the generate term is the AND of the two bits.
2. Generate the carry for each bit - takes the *p* and *g* terms and for each pair of bits and calculates the carry out from each bit, which will depend on the *p* and *g* terms of the pervious bits along the `Cin` to the adder.
3. Generate the sum for each bit which is just a simple XOR operation.

![[Pasted image 20241219185346.png#invert]]

Whilst the first and third blocks are relatively simple in design and have a constant delay of 1 gate delay regardless the number of bits, the generate carries block gets quite complex as the number of bits increases, resulting in more gate delays being introduced.

Because there is no dependency on the sum for each bit using the carry from the previous bit then a speed improvement is observed. The critical delay in this case is largely independent of the number of bits:

![[Pasted image 20241219204040.png#invert]]

### Parallelism
Parallelism refers to performing multiple operations or tasks simultaneously rather than sequentially. It is a key concept in improving performance and reducing execution time, and it can occur at different levels of hardware and system design.

The CLA (**Carry Look-Ahead Adder**) increases the number of gates but decreases the time to compute a result. This is achieved  because the computation of carries happens simultaneously for all bits using additional hardware.
But the design is more complex but the result is faster addition.

At the **Register Transfer Level (RTL)**, an example of parallelism is found in the **incrementing of the Program Counter (PC)** at the same time as the **instruction fetch**. These two tasks happen concurrently, which reduces the total execution time.

#### Pipelining
A common analogy is: Imagine having two separate washers and dryers, so you can simultaneously process **two independent loads of laundry**. This means that two loads can be at different stages of 'processing' at the same time - an example of parallelism. However, notice that our MU0 uses the same hardware for both fetching and executing instructions (e.g. the same ALU increments the PC and ADDs the data) and could not be pipelined without adding extra hardware; it is more a ‘washer/drier’ solution!

#### Multiple Issue
By adding extra hardware it is possible to execute more than one instruction at once. With two decoders and two ALUs, two instructions may be fetched and decoded together. This, potentially, doubles the processor speed for roughly twice the hardware cost.
Some times there may be issues as for example, if the first instruction was a `JMP` then the other instruction would be wasted anyway. Nevertheless attempting to issue two, four, or even more instructions together is quite common in high-performance processors. In this case the compiler will introduce code to enable dependencies to be removed, or extra hardware needs to be introduced (or both).

![[Pasted image 20241219211320.png#invert|400]]

## Functionality
MU0 only performs the arithmetic operations ADD and SUB, this somewhat limits its application. There is a hole in the instruction set (mnemonics 1XXX are not defined) so we could introduced additional instructions - we use a 4-bit opcode but are only using 3 of those bits so we could potentially use the other 8 for further functions