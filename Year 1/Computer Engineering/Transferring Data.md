25-12-2024 00:11

Status: #new

Tags: [[Computer Engineering]] [[Input and Output]]

# Transferring Data
The CPU may talk to the I/O to see if there is any data to receive or send it data. The I/O may then respond, and the resulting data may then be stored to memory for later processing. 
So how do we govern the transfer of data?

## Program Control
In this way of transferring data:
The I/O device transfers bytes of data one at a time when they become available. 

![[Pasted image 20241224233556.png#invert]]

- The I/O will place some information on the I/O bus (and using the handshaking protocol) will result the Ready and Acknowledge signals going high.
- The Flag F indicates that we have some data in the interface from some peripheral.
- The CPU will place the address of the Status Register on to the address bus, it will read from that register, and it knows that some data is needed to be read from the data register
- It places the address of the Data Register on the address bus, initiating a memory read.

In laments terms, the CPU is checking the status register, for the necessary Flag to read from the Data Register that contains information from the I/O.

It can be visualised in this flowchart:
![[Pasted image 20241224235444.png#invert]]

This whole process is a form of **polling** where we are checking for if the device is ready to be read from.

## Polling
Polling is an important technique the CPU utilises by the CPU to regularly check the status of each connected peripheral device to determine if it needs to perform an I/O operation.
![[Pasted image 20241224235850.png#invert]]

The CPU in turn addresses each peripheral device. It sends a request to each device asking if it has any information to send or if it needs any data.
Each peripheral device responds to the CPU's query, indicating whether it has data or not.
This process is repeated at regular intervals, ensuring that each device is periodically checked.
The interval depends on the system's requirements and the speed of the peripherals.

Polling is quite simple and straightforward to implement. The CPU simply loops through a list of devices and checks their status. The CPU also has direct control over the timing and sequence of the checks, ensuring that no device is overlooked.

However, the polling of each device takes processor time away from doing other things and also places a continuous load on the CPU. This can be particularly taxing on the CPU.

## Hardware Interrupts
We have seen the problems with polling, one way to not waste the CPU's resources is to use interrupts - where the peripheral through a control signal 'interrupts' what the CPU is doing to give it attention.

A processor may have a number of interrupt lines that are connected to peripherals requiring immediate attention, such as hard drives and less urgent ones like keyboards.

![[Pasted image 20241225001455.png#invert]]

There are both hardware and software interrupts and they are both self explanatory. But in the case of software interrupts, action is taken according to when the programmer wants it to happen However, in the case of hardware interrupts the programmer has no idea when an interrupt will occur.

### What Happens?

When the interrupt is serviced, the processor is seconded to run a different 'thread'. The Interrupt Service Routine **(ISR)** is called at random positions in the user's code. At the time of the interrupt any or all of the processor's registers may be holding important information that needs to be restored. **It is essential that the state of the CPU before the interrupt is restored.**

![[Pasted image 20241225003010.png#invert|300]]
![[Pasted image 20241225002704.png#invert]]
	The Interrupt Service Routine (ISR) is a block of code dedicated to handling interrupts for these peripherals.
	As you can see the even the PC is restored to prevent any issues with the ongoing thread.
#### Vectored and Non-Vectored Interrupts
Vectored interrupts the interrupting device also provides an address in memory where the appropriate ISR can be found. This allows the CPU to immediately jump to the specific ISR without the need for additional steps to determine which ISR to execute.
The CPU does this by using the interrupt vector provided by the interrupting device to lookup the address of the ISR in the **Interrupt Vector Table (IVT)**, which is a table in memory that contains the addresses of all the ISRs. The CPU immediately jumps to the ISR address obtained from the IVT and executes the ISR.

For non-vectored interrupts the same ISR is ran no matter what peripheral device initiates it. However, the CPU must perform some polling of the devices - the CPU polls the status registers of all potential interrupting devices to determine which device caused the interrupt.

### Implementation
Here we have a simple system.
![[Pasted image 20241225005558.png#invert]]
The interrupt is provided to the CPU via a dedicated **interrupt request line**.

Looking at the bar above the IRQ, it is an active-low request system, so if either of those peripherals take the interrupt line low, this results the CPU identifying an interrupt request.
As you can see interrupt registers, this is an example of non-vectored interrupts.
The CPU in turn will check each peripheral's interrupt register, to find which peripheral threw the interrupt.
The problem with this approach is that it takes time to poll through each device, however it is still an improvement over regular polling to interact with devices.

#### Priority
So how do install priority for these interrupts, because looking at the image above, no matter what peripheral 2 does, peripheral 1's interrupt register will be checked first to see if it had interrupted.

There are many ways to implement interrupt priority, 
- Software - choosing the order in which devices are polled
- Interrupt controller with several interrupt
- Daisy chaining 
- A combination of these

![[Pasted image 20241225011528.png#invert]]

Here they are daisy chained. Instead of looking for the IRQ to go low, it is for it to go high (as shown by the absent bar above the IRQ label going towards the CPU).
The CPU sends an interrupt acknowledge signal that trickles down from peripheral 1 to peripheral 3 until it finds the peripheral that initiated the request.

#### Another Example (Vectored Interrupt)
![[Pasted image 20241225013425.png#invert]]
Here we have 4 devices that are providing an active-high interrupt, with increasing priority going from 0 to 3 (3 has the highest priority). The devices are latched to a register, that is then latched to an AND gate that goes to a priority encoder.
There are also mask registers that are on the other input of the AND gate for each corresponding peripheral register.

The mask register allows us to disable the interrupts for specific devices by setting the corresponding mask register to 0 - if Mask Register 3 is 0, regardless if there is an interrupt at device 3, causing the Interrupt Register to have 1 bit, it will not make the I3 signal high at the priority encoder.

Whenever an interrupt goes high, the IRQ signal will go high, causing an interrupt at the processor. Also, the priority encoder will outputs a 2-bit value (there are 4 devices so 2-bits are enough) that forms part of an 8-bit address to the corresponding Interrupt Service Routine for that peripheral device.

![[Pasted image 20241225014258.png#invert]]
The image above showcases the outputs for different scenarios of interrupts.

## Direct Memory Access (DMA)
Interrupts offer a clear speed advantage and efficiency compared to just polling, but they still use processing time (even Vectored Interrupts). **Direct Memory Access** (DMA) allows a peripheral to directly access memory, removing the need for the CPU to be involved with data transfers.

![[Pasted image 20241225015211.png#invert]]

DMA is primarily used for high bandwidth transfers - such as transfers from a disc. 
	An example is the display output for a typical workstation. A frame buffer contains more than 1Mpixels (depends on resolution), and each pixel possibly has a 32-bit representation. The display is refreshed at 70Hz, the required bandwidth will therefore be ~300M/Bs.

![[Pasted image 20241225015355.png#invert]]
How DMA works:
- The DMA controller is initialised by the CPU - source/destination addresses, amount of data transfers and transfer directions are handled (written to the DMA's control registers).
- The peripheral device sends a DMA request to the DMA controller.
- The DMA controller asks the CPU and gets permission which once the DMA controller gets the permission, it transfers the data.

There are three ways for transferring the blocks of data:

**Burst Mode:** The DMA controller transfers a block of data in one continuous burst, gaining control of the system buses for the duration. This mode is fast but the CPU no longer has access to the system bus causing delays.

**Cycle Mode:** The DMA controller transfers a single byte or word of data at a time, interleaving its transfers with CPU operation.

**Transparent Mode:** DMA transfers are performed when the CPU is not using the bus. This ensures that the CPU is never interrupted but can result in slower data transfers.. 

