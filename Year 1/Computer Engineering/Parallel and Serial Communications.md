24-12-2024 16:06

Status: #new 

Tags: [[Computer Engineering]] [[Input and Output]]

# Parallel and Serial Communications
'Communications' involves sending a signal over a physical medium. As digital computer are primarily electronic this medium is frequently a metal wire. Wires are convenient to interface and cheap at the small scale such as on-chip or on a PCB. 

## **Parallel Communications**
This involves sending several bits of data at the same time. This requires the use of more data channels (wires) and is therefore more likely to impose a higher cost.
![[Pasted image 20241224163650.png#invert|500]]

As you can see there are multiple data lines. Data is transmitted over multiple wires or channels at the same time. each wire carries one bit of the data, so an 8-bit parallel communication would use 8 data lines.

Parallel interfacing is very easy at the computer end. A parallel output is simply a latch that the processor can write to - a parallel input is a buffer which allows an external set of bits to reach the CPU. For simple parallel interfaces this is all that is required and software can provide any required control.

In principle, increasing the number of wires increases the number of bits per second which can cross the interface. When communicating at a distance this is often offset because some of the cost saving in going to serial interconnection can be reinvested in fancy interfaces which increase the bit or 'symbol' rate.
	The CPU's own bus connection with memory require very high bandwidth and maybe not be feasible by going serially. In high performance processors, a common technique is to improve data bus bandwidth is to double or quadruple the the bus width.

Downside of parallel communication is that the signals are susceptible to noise and interference which limits the rate at which data can be transmitted.
## Strobing
Strobing refers to a technique used to synchronise data transfer between components.

Strobing involves sending a periodic signal, often called a 'strobe signal' or 'strobe pulse', to indicate when data should be read or written. This helps to ensure that data is transferred at the correct time, avoiding errors caused by timing mismatches.
Only one control signal is required and this can be set either by the source (transmitter) or destination (receiver) unit depending on which unit initiates the transfer.

The strobe signal is typically a clock-like signal that oscillates at a regular interval. It can be a separate signal line in parallel with data lines, or it can be embedded within the data signal.
The strobe signal acts as a timing reference, indicating the exact moment when data on the bus is valid and should be read or written.

![[Pasted image 20241224160841.png#invert]]
In the example above, the source initiates the data transfer. 
The disadvantages of this method have to do with the lack of acknowledgment from the destination unit relating to the reception of data - the source does not know whether the data was properly received. 
A way to overcome this drawback is by using another control signal, resulting in **handshaking communication**.

## Handshaking
Handshaking is often used as a way of the transmitting and receiving devices to synchronise the transfer of data. 
	A classic example was the parallel printer port interface that was found on old PCs for connecting a printer.


![[Pasted image 20241224162616.png#invert]]

1. The source places data on the Data Bus,
2. The source takes the Request Signal high,
3. After a short period the Destination responds by taking the acknowledge signal high,
4. The Source sees that the acknowledge signal is high, and takes the Request signal low, causing the Acknowledge Signal to be low and so data is taken off the data bus. 

## **Serial Communications**
When you have wires, they can have to go long distances, as the distances gets longer and the cost goes up; it is likely that the wires need connectors at intervals, again increasing the cost.
Instead of communicating a 32-bit word along 32 wires, it can be **serialised** and sent as 32 messages each one bit long.
This is ideal for long distances as it minimises issues related to signal degradation and crosstalk between wires.
![[Pasted image 20241224192438.png#invert]]

When serialising signal it is important to observe a known convention as to which bit is transmitted first. This is looking at 'little endian' and 'big endian' once again. Little endian (LSB first) is more common.
When sending a series of data separated only in time it is essential that both parties agree on how time is delineated so that the receiver knows when to sample the incoming signal.

How do we synchronise this? 
There are start and stop bits to frame the data.
The transmitter and receiver operate independently, with the data transfer being governed by predetermined timing, this is known as the **baud rate**. Knowing the baud rate and recognising when the start bit is set, the receiver knows when to sample the transmitted signal in order to recover the transmitted data.

In serial communications data is often transmitted with an extra 'Parity' bit added to the original data. The role of the parity bit is to enable simple error detection to be performed and determine whether some data has been transmitted in error or not.

![[Pasted image 20241224201143.png#invert]]

**Odd Parity**
	If the data being sent has an even number of 1s, then the parity bit is set to 1 to give an add number of 1s in the transmitted data. If the data being sent has an odd number of 1s, then the parity bit is set to 0 to give an odd number of 1s in the transmitted data.
**Even Parity**
	If the data being sent has an even number of 1s, then the parity bit is set to 0 to give an even number of 1s in the transmitted data. If the data being sent has an odd number of 1s, then the parity bit is set to 1 to give an even number of 1s in the transmitted data.

Like the baud rate, the transmitter and receiver must both know beforehand what type of parity, odd or even is being used.

## Universal Serial Bus (USB)
The creation of the Universal Serial Bus (USB) was to have a standardised port to allow the plethora of peripherals that were being developed.

The USB provides a standard socket that you can plug any supported device into and it would instantly become available for use by the PC.
The standard allows up to 127 devices to be connected and allows for 'hot-swapping' of devices, which means devices can be plugged and unplugged without having to reboot the computer.

![[Pasted image 20241224204301.png#invert]]

**Host**
A USB system consists of a host 'master'. This is usually integrated into the computer's motherboard.
It manages the communication between the computer (host) and the connected and the connected USB devices.

**Root Hub**
The Root Hub is part of the host controller and serves as the primary connection point for all USB devices. 
It provides a central hub through which the host controller communicates with multiple USB devices.

**USB Hubs**
USB hubs can be connected to the root hub or other hubs to expand the number of available USB ports.
Hubs distribute data and power to multiple devices.

**USB Devices**
Each device has a unique identifier and communicates with the host through specific protocols.

Here are the standards that have been implemented.
![[Pasted image 20241224205854.png#invert]]
USB has four wires: two wires provide power and ground so that slave devices can be powered, then we have two **twisted** signal wires referred to as D+ and D- . 
The waveforms transmitted on these two wires are the inverse of each other, so if one is high, the other is low and vice versa.
![[Pasted image 20241224210314.png#invert]]
When receiving the signal, we look at the difference between the signals on these two wires, using a differential approach that helps reduces noise common to the both signals wires and hence improve the reliability of the transmitted data.

If D+ is greater than D- by more than 200mV or more, then a 1 has been transmitted. If D+ is less than D- by 200mV or more, then a 0 is being transmitted.

### USB Encoding of Data
In USB data is encoded for transmission using **Non-Return-to-Zero Inverted (NRZI) encoding** (in USB 1 and 2).

The data is encoded to ensure that there are regular transitions in the transmitted data, which allows the data to be recovered more efficiently and (more importantly) helps to regenerate the clock.

![[Pasted image 20241224212213.png#invert]]

But to to avoid long sequences of '1's which would result in synchronisation issues, there is '**bit stuffing**', after six consecutive '1's, a '0' is inserted to ensure there are enough transitions in the data stream to maintain synchronisation. 

![[Pasted image 20241224212708.png#invert]]
	We need transitions in order for the receiver's clock to be synchronised. A regular transition of 1's would not allow any transitions to occur and so cause the synchronisation to go out of sync and drift, bit stuffing prevents that.

### USB Packets
When communicating using USB, it involves the exchange of **packets** of information. Within these packets there is information that will control the exchange of data, hold the actual data itself and include error detection information to check that the received data is valid.
![[Pasted image 20241224213203.png#invert]]

**SYNC**: This is mandatory, and always occurs at the start of the packet. This synchronises the clock of the receiver with the transmitted data.
**PID**: Used to identify the type of packet that is being sent. It is an 8-bit value.
**CRC**: For error checking
**EOP**: Specific data pattern to signify the end of the packet.




