04-11-2024 15:07

Status: #new

Tags: [[Computer Engineering]]

# 3-Box Model of the Computer
The 3-Box model includes:
- The Processor
- Memory
- Input/ Output or IO

Keep in mind the Amdahl/ Case Rule which states that a balanced computer system needs about 1 megabyte of main memory capacity and 1 megabit per second of I/O per MIPS (million instructions per second) of CPU performance.

## Extra Detail:
### CPU
The CPU is a sequential system, it contains a data path and a control block. The control block contains a finite state machine (FSM) that controls the operation of the data path, and thus the operation of the processor.
The data path contains registers , the contents of which, along with data stored in memory, determines the state of the processor.

The state of the system is determined by: 
- data held in locations in memory
- data held in registers in the processor itself
- input provided to the processor from the I/O
### IO
On their own, the processor and memory are not much use, IO allows us to interact and have feedback from the processor and memory.
In order for the CPU to communicate with an IO device, some form of interface is required that converts the signals from a form the CPU understands to a form the peripheral devices can understand.

### Buses
Previously a 'bus' has been described as a collection of signals with the same function, representing something collectively. The processor communicates with the rest of the system using its bus, which consists of signals comprising the address, data, and control. 

The **Address Bus** is an output from the processor and specifies the memory or IO location.
The **Data Bus** is commonly bidirectional and carries information to or from the address.
The **Control Bus** specifies which way and when the data flows.



