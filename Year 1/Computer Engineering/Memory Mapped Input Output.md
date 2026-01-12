23-12-2024 17:13

Status: #new 

Tags: [[Computer Engineering]] [[Memory]] [[Input and Output]]

# Memory Mapped Input Output
Any discussion of I/O can be very broad as it can encompass three main areas:
- The design of the interface circuit that provides the bridge between the processor and the peripheral
- The communication strategy - the strategy by which data is moved in and out of the computer
- The I/O device - the peripheral - interacts with the real world.

I/O devices are often memory mapped, so as for the CPU is concerned, they are seen as a simple extension of memory. 
Sending data to an I/O device is simply a case of writing data to the memory location associated with the I/O device. 

## Interface
The interface is the bridge between the CPU and the I/O device. The interface takes the data from the CPU and converts it to a form that the peripheral can interpret. In some cases the interface can be some **complex hardware including its own processor**.

The interface must contain the necessary logic to decode the contents of the address bus in order to determine whether the CPU is communicating with the peripheral by placing addressing on the address bus.

![[Pasted image 20241223191233.png#invert]]
**Functions the interface carries out:**
- **Address decoding**: Translates addresses from the system bus to specific peripheral addresses, ensures that data is routed to the correct peripheral device.
- **Bus controller**: Manages the data transfer between the system bus and peripheral bus, ensures data integrity and proper timing for read and write operations.
- **Data buffers**: Temporarily hold data during transfer between the system bus and peripheral bus.
- **Interrupt Handling**: Manages interrupt signals from peripheral devices to the CPU, it allows peripherals to notify the CPU of events requiring attention.

## Memory Mapped I/O
It is common for different areas of the memory address space to be associated with different types of memory. ROM and RAM are different physical devices but appear as contiguous memory to the CPU due to the system bus interfacing. This abstraction simplifies the CPU's view of memory, even though the physical hardware is different.

Remember what was mentioned at the start, the CPU sees the I/O just as an extension to  main memory.

![[Pasted image 20241223191904.png#invert]]

As you can see in the image above, there are a range of addresses dedicated to I/O.
The I/O devices are not physically located within memory. Instead, the address, data and control buses (system bus) are made available to the interface circuit, which decodes the address on the address bus to determine if an operation requires access to the I/O device.

![[Pasted image 20241223194006.png#invert]]

So the address and data buses are connected to the peripherals the same way as memory. This way, if a memory address associated with a particular I/O device is placed on the address bus, then the appropriate action can take place.
I/O can have special control lines to control the flow of data.

![[Pasted image 20241223194205.png#invert]]
Within the interface we have something called the address decoder. This looks for a particular address to be placed on the address bus, if that address is seen the Enable Signal goes high then it can be used to connect the interface to the data bus.

The interface often converts the data to a form the way the peripheral can understand. 

![[Pasted image 20241223194815.png#invert]]
Here the n-bits that are coming in parallel are being serialised and sent down the communication channel. 

![[Pasted image 20241223201054.png#invert]]
Looking at the image:
When we see the FFF address, the decoder's output will go high and enables the register. Whatever data is on the Data Bus will attach to the register. If the data for example was 0024 (16-bit) the LEDs will turn on like that in the picture.

![[Pasted image 20241223203115.png#invert]]

Looking at the image above:
The processor design has an 8-bit data and address buses.
(Here we have a peripheral that reads from C0 - 10100000 in binary). 
The address bus will decode the address and make the enable signal goes high. The input is connected via tri-state buffers to the data bus. The tri-state buffers are only enabled when the appropriate address has been decoded. The buffers isolate the peripheral from the data bus unless the correct address is decoded.
The switch is connected to bit 7 of the address C0.
If the switch is pressed then 10000000 will be read, otherwise it will be 00000000.

![[Pasted image 20241223204853.png#invert]]
An I/O device will often have more than one memory location associated with its operation. 
It is common for there to be:
- A memory location associated with the data movement to/from the peripheral
- A memory location associated with the status information/control for the peripheral

Any status information could be used to indicate the readiness of the peripheral to receive data, or whether data is ready for the CPU to read.

**Complex Example:**
![[Pasted image 20241223205405.png#invert]]
	The blue represents the interface, with the CPU and I/O device either side.
	The interface forms a bridge between the CPU and the I/O Device.

The interface contains:
- Data registers - these are also known as ports, which are used to transmit data to and from the I/O device.
- A control register, which receives data from the CPU and controls the operation of the interface/device, i.e. places it in a particular operating mode.
- A control register, which receives data from the CPU and controls the operation of the interface/device, i.e. places it in a particular operating mode.

A timing and control block is used to decode data from the CPU and identify which port register data needs transferring from/to.