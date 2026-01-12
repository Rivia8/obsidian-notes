05-11-2024 14:17

Tags: [[Computer Engineering]]

# Register Transfer Level

Register is the name given to a number of flip-flops acting together to hold a single coherent value, which is a number of bits wide, i.e. 16-bits, such as:
- A state value
- A numerical value
- A computer instruction
- A colour

Transfer refers to the need to move values between registers, possibly:
- Applying some operation - such as old, compare, etc - in the process
- Maybe predicating operations on some conditions

But what does the term, 'Register Transfer Level' mean?
RTL refers to an abstraction level that is used in digital circuit design, that describes a system's operation in terms of the data flow between registers and the logical operations performed on that data.
RTL is a critical level of abstraction in hardware description languages (HDLs) like Verilog and VHDL.

The reason we use RTL is because designing complex things like a processor would be extremely tedious and difficult to do so in a level abstraction that is too low like *transistor-level design* or *logic-level design*.

## Register

A register is a sequential component that can store multiple bits.
A basic register can be built from D-type flip-flops - for example a 32 bit register would contain 32 D-Type flip-flops.

A clock is normally free-running but it may not be desirable for the register to change every cycle. Usually, therefore, there will be a clock enable (CE) input, which is also common to the flip-flops in one register. Different clock enables control different registers, whereas the clock will typically be the same signal in all the registers in the system. Thus, the clock enable can be used to determine WHEN the flip-flop is updated – this is extremely important in complex designs.

## RTL Design

The RTL arrangement of registers/logic looks something like this:
![[Pasted image 20241105144208.png#invert]]
In the RTL view data flows through an arrangement of registers and combinatorial logic

The job of the registers is to store the data whilst the combinatorial logic applies some logical function function to (i.e. operates on) the data held in the register.

**The Control Block** is essential for managing the data path. It sends control signals based on the system's current state and input signals to dictate how data is handled.

The RTL design follows a two-step process: capture the desired behaviour, and then convert that behaviour to a circuit. 
Behaviour is captured using a finite state machine (FSM), which is then converted to a controller/datapath architecture. 