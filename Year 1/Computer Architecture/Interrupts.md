23-11-2024 16:27

Status: #new 

Tags: [[Architecture]] [[Week 9 Slides.pdf]]

# Input and Output: Interactions with Peripherals

## Peripherals
When we deal with computers, we communicate via 'peripheral' devices: keyboards and mice, touchscreens, speakers, etc.
In order to connect these devices, we use something called Port Mapping.

## Port Mapping and Memory Mapping
This refers to the process of assigning specific input and output (I/O) devices to particular ports or addresses in the system, allowing the CPU to address these devices efficiently.

In the context of RISC-V, port mapping can be managed through the use of an I/O Memory Management Unit (IOMMU) and specific I/O mapping tables.

Reading a keyboard:
```R
loop
	la a1, Status_Reg
	lb a0, o[a1]
	li a2, 0x80
	and a3, a2, a0 ; test ready bit
	beqz a3, loop ; if not ready, try again

	la a1. Data_Reg
	lb a0, 0[a1]
	...
	j loop

```

## Handshaking:
The processor is very fast (the clock speed being in the GHz range) and people type very slowly, the processor can read the keyboard many times before your finger comes off the key, so it would detect many keypresses.
So we need a simple handshaking protocol. Handshaking is a crucial process where it ensures that data is transferred properly.

There are both synchronous and asynchronous handshaking. 
- Synchronous uses a common clock to signal to coordinate data transfer, ensuring both the sender and receiver are synchronised.
- Asynchronous relies on control signals without a shared clock, allowing for communication at different speeds. 

## Polling:
Polling is another method that the CPU uses to manage communications with I/O devices. Instead of the I/O device notifying the CPU when it is ready, the CPU repeatedly checks the status of the device at regular intervals.

How it works:
1. Status register check: the CPU reads the status register of the I/O device to determine if it is ready to perform a read or write operation.
2. Action based on status: if the status register indicates that the device is ready, the CPU performs the necessary data transfer.
3. Looping: if the device is not ready, the CPU continues to check the status register in a loop until the device becomes ready.

This is not a perfect solution though, what can we do better?:
## Interrupts
These are signals sent to the CPU that temporarily halt the current executing program, allowing the CPU to execute a piece of code known as an interrupt handler or interrupt service routine (`ISR`).
What happens is:
1. An interrupt signal is sent to the CPU by an external device or internal event,
2. The CPU saves the context (the current state) of the running program, which includes the program counter (PC), registers, and other critical information.
3. The CPU jumps to the interrupt vector table, locates the appropriate ISR, and executes it.
4. After handling the interrupt, the CPU restores the previously saved context,
5. The CPU then resumes execution of the interrupted program from where it left off.

![[Pasted image 20241127142345.png#invert]]

### State Preservation:
This is crucial when handling interrupts to ensure that the original program can continue executing correctly after the ISR has completed.

1. **Program Counter (PC)**: The address of the instruction to be executed next.
2. **Registers**: All general-purpose registers, special-purpose registers, and status registers must be saved.
3. **Stack**: The stack pointer must be managed to avoid overwriting important data.

### How Does The Interrupt Occur:
The processor is not polling the device, instead the device has to get the processor's attention so it issues an "Interrupt ReQuest" (IRQ)
	**IRQ Interrupt Request** handling is a signal sent to the CPU by a hardware device or software to indicate that it needs immediate attention. This could be triggered by a variety of events, such as a keystroke on a keyboard. 
	There has to be a hardware connection.

![[Pasted image 20241127142756.png#invert]]
	if \<EN\> status register is enabled, it allows for the CPU to get an IRQ signal (look at the AND gate in the circuit above)

#### Considerations:
More than one device can interrupt, so more hardware is needed compared to that of the diagram above.
Look at [[Privileges]] to understand more...

# Summary:
- Polling: simple, but uses much CPU time 
- Interrupts: more complex, but use CPU only when needed 
- CPU has basic hardware to handle interrupts 
- More hardware is needed for multiple interrupt sources -
- Interrupt handler and ISRs must restore original state when they return
-  Interrupts are initiated by hardware, not by the user 
- The writer of the user code and/or the writer of the IRQ code do not know when the interrupt will occur
-  …it could happen anywhere in the user code
- So it’s vital that the IRQ code does not change anything at all in the user space
- Return to user code in exactly the state it was left in.

## Interrupts for multiple hardware
If there are multiple peripherals we need to be able to enable some devices to interrupt but not others and know which device has interrupted so we can execute appropriate code.
![[Pasted image 20241203202247.png#invert]]
Above we have a simple hardware implementation for handling multiple interrupts. It includes:
- **Multiple IRQ and IEn signals**: Each device has an IRQ (interrupt request) signal and an IEn (interrupt enable) signal.
	- `IRQ_0`, `IRQ_1` and `IRQ_8` are interrupt request signals from different devices.
	- `IEn_0`, `IEnn_1` and `IEn_0` are interrupt enable signals for the corresponding devices.
- **Combination Using Logic Gates**: The IRQ and IEn signals are combined using AND gates and an OR gate to generate a single IRQ signal that is sent to the processor. This logic ensures that only the enabled devices' interrupts are passed to the processor.
- **Memory Mapped Registers:**
	- `IEn` (Interrupt Enable) and `IRq` (Interrupt Request) are memory-mapped registers connected to the data bus.
	- The processor writes to the `IEn` register to enable interrupts from selected devices.
	- The processor reads from the `IRq` register to determine which device caused the interrupt and can clear it after handling the interrupt.

In RISC-V `IEn` = `mie`, `IRQ` = `mcause`- [[Privileges]]

### IRQ Handling (Multiple Sources)
The `IRQ_handler` code must
1. Protect any register it uses
2. Determine the interrupt source
3. Service the interrupt
4. Recover the protected registers
5. Return back to the main code
Each source of interrupt will have its own `ISR`.

### Interrupt Modes
**Direct Interrupt Mode**: Best suited for systems with a single (or a few) sources.
**Vectored Interrupt**: Best suited for systems with many interrupt sources.

It is selected using the `mtvec` register.
![[Pasted image 20241203205449.png#invert]]
The `BASE` field holds the address of the `ISR`, which is loaded by the `IRQ` handler, and the `MODE` defines whether you are on vectored or direct interrupts.

For **Vectored Interrupts**,  we use a table called **Interrupt Vector Table (IVT)**:
- It's in main memory.
- Holds the addresses of the `ISRs`
- Each device has an ID, which will be used as offset in the table, (the device ID is in the `mcause` register)
- The `BASE` field of `mtvec` will hold the base address of the table, by adding the device offset the correct `ISR` can be located.

- **Interrupt Occurrence**:
    - A device generates an interrupt signal to the CPU.
    - The CPU saves the current state and identifies the interrupt type using the `mcause` register.
- **ISR Address Calculation**:
    - The CPU reads the base address of the IVT from the `mtvec` register.
    - It then adds the Device ID (from `mcause`) to the base address to locate the specific ISR in the IVT.
- **ISR Execution**:
    - The CPU jumps to the address of the ISR obtained from the IVT.
    - The ISR handles the interrupt, performs the required actions, and then returns control to the main program.
- **Resuming Execution**:
    - After the ISR completes, the CPU restores the saved state and resumes normal execution of the main program.