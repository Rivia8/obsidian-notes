23-12-2024 14:00

Status: #new

Tags: [[Computer Engineering]] [[3-Box Model of the Computer]]

# Input and Output

Remember from the 3-box model that we have:
![[Pasted image 20241223140137.png#invert]]

3 Boxes or Main elements.
- CPU: The brains.
- Memory: To hold instructions and data.
- Input/Output: To communicate to the outside world.

Connecting the three we have the system bus that is comprised of the Control, Address and Data buses.

I/O is the link between the combination of the CPU and memory of the outside world. There may be any number of devices for providing input or receiving output from the computer.

Digital transmissions uses a binary coding system and so have the same advantages that binary signals have inside the computer.
![[Pasted image 20241223140936.png#invert]]
Advantages to binary signals:
- Distinct signal levels.
- No intermediate states so it is easy to eliminate ambiguity.
- Easy to discriminate and reject noise.


A binary signal is representable by a voltage (high/low) current, light level (on/off) etc. With a single wire the voltage can only represent one bit at any given time. To send a large number of bits therefore requires some sequencing, separating different elements of the message in time.

**Serial Transmission:** Bits are sent one after another, sequentially, over a single wire. Suitable for long-distance communication and simpler wiring.
**Parallel Transmission:** Multiple bits are sent simultaneously over multiple wires. Faster data transfer but requires more words and is typically used for short distances.

### Speed:
Speed of light in a vacuum is $3 * 10^8$ m/s ~ 670,000,000 mph. Best case is nothing can travel faster than this. Signals on a PCB travel (at best) ~ 60% of this speed.
A signal of 1GHz has a period of 1ns/ $10^{-9}$ s.

This has set almost of an upper limit to the speed of a computer, probably will never be able to exceed it and most definitely not exceed the speed of light.


## Important Terms

1. **Latency**:
	The Latency is the time taken from sending a signal until it is received.

	It is measured in time, usually milliseconds (ms). Lower latency means quicker response times and faster performance.

2. **Bandwidth:**
	The bandwidth of a communication channel is the amount of information which can be sent in a given time. It is the capacity of the communication of the communication link.

	It is measured in rate, usually a form of bps - megabits per second Mbps.


![[Pasted image 20241223142507.png#invert]]

![[Pasted image 20241223150124.png#invert|400]]

## Balance
"A balanced computer system needs about 1 megabyte of main memory capacity and 1 Mbps of I/O per MIPS (millions of instructions per second) of CPU performance."

A CPU may be able to process information at an incredible rate, however, it would be a completely useless unless:
- It can get operands to work on, so we need some memory to hold instructions and operands
- Take input from something to control its operation (keyboard, mouse, disk)
- Output the results to something (disk or display)

