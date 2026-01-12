21-12-2024 15:54

Status:

Tags: [[Computer Engineering]] [[Memory]]

# Memory Structure
In semiconductor memories, the basic element is the memory cell. Regardless of the technology, all memory cells share the same characteristics:
- They have two stable states representing the storage of a binary 0 or 1
- Data can be written to the cell 
- Data can be read from the cell.

The cell must have control signals to determine its operation, to allow data to be written and to allow data to be read. Often these cells are arranged within an array of identical cells so the control signals are used to access (or address) individual, or groups, of cells.
![[Pasted image 20241221160648.png#invert]]
The control signal have a specific purpose:
- The Select is used to select a memory cell for reading or writing data
- The Control is sued to determine whether the operation is a read or write

## Static RAM (SRAM)
The SRAM memory cell is constructed using the sane logic elements used to construct the processor. As such, it is fast memory and tends to be used within the processor, **usually for implementing cache memory**.

The memory cell is constructed from transistors to form a flip-flop (outside course unit so it is just a black box for now). The SRAM cell is volatile; as such the stored data will be lost when the power is removed. 

To access SRAM, there are two complementary bit lines that are attached to two transistors that act as switches which have an address select line attached to them.
![[Pasted image 20241221162213.png#invert|400]]
In order to **Write** data:
	Storing a '0',
		The select line goes high - 1
		The bit line on the left goes to 0,
		and the bit line on the right (inverse bit line) goes to 1
		That results a 0 being stored
	Storing a '1',
		The select line goes high - 1
		The bit line on the left goes to 1, 
		and the inverse bit line goes to 0,
		Results a 1 being stored
![[Pasted image 20241221162629.png#invert]]

To **Read** data:
	You take the address select line high and the read value on the Bit Line (or the complementary value on the bit line). 
	For more detail, when the Select line goes high, the state of the flip-flop will cause one of the Bit Lines to discharge slightly, depending on the stored value,
	A sense amplifier will determine the difference to a full logic level, which is then read as the output data.

## Dynamic RAM (DRAM)
DRAM has been the semiconductor memory of choice since the 1970s, mainly because it is a very simple memory cell that can be made very small and hence dense.

![[Pasted image 20241221165645.png#invert|400]]

Each DRAM cell consists of a capacitor and a transistor. The capacitor can be either charged or discharged, representing binary 1 or 0.
Data is accessed by activating the transistor, which connects the capacitor to a bit line for reading or writing.
Since capacitors leak charge over time, each cell needs to be periodically refreshed by reading and re-writing data.

To **Write** data:
	Writing a '1':
		A voltage is applied to the corresponding Bit line
		The corresponding word line is taken high to switch on the transistor
		This charges the capacitor
		Resulting in a '1' being stored
	Writing a '0':
		The capacitor needs to be discharged
		The word line is taken high to switch on the transistor
		The bit line is set to a low voltage
		With the transistor on, the storage capacitor discharges
		The word line is then driven low to turn off the transistor
		This maintains the stored capacitor's charge of 0

![[Pasted image 20241221170933.png#invert|400]]

To **Read** data:
	The word line is taken high,
	Therefore the transistor is switched on,
	and connects the capacitor to the Bit Line
	A sense amplifier is used to compare the voltage
	This determines whether a '0' or '1' is stored.
![[Pasted image 20241221171451.png#invert|400]]
Read operations are 'destructive' and therefore any data which are read must be rewritten afterwards. The use of capacitors is not ideal since it requires them to be refreshed (around every 64ms), hence the name *Dynamic* RAM.

In actual practice, the memory cells are arranged in a matrix. With the word line common for the cells in a word. Taking the word line high allows the word to be read/written in parallel.

An example for a 2-bit address line, 4 bit-memory array is shown:
![[Pasted image 20241221171859.png#invert]]

To read from the array, the Word Line goes high, switching on the transistors, the capacitors are then discharged down the bit lines (if they are charged if not then nothing happens), a Sense Amplifier senses whether a current is flowing and this determines the stored data values. 

To write it follows the same process, but the decoder selects appropriate word lines in the array to go high, the transistors are activated and the corresponding bit lines either have a high or low voltage to either charge or discharge the capacitor.

### SDRAM: Synchronous DRAM
Early DRAM was asynchronous in its operation: control signals from the CPU are used to make requests to the memory, which responds as soon as it can. 
Modern DRAM is **synchronous**, this means the memory responds to the clock depending on the status of the control signal.

DDR was then an update of the SDRAM design. In SDRAM data is read once per clock cycle, however, in DDR SDRAM two words of data can be read during each clock cycle - once on the rising edge, once at the falling edge.
This gave it its name: **Double Data Rate RAM**.

The first generation of DDR RAM, DDR1, was able to fetch data on both clock edges, allowing it to double the data rate for a given clock frequency.

There have been further generations: DDR2, DDR3, DDR4 and DDR5 the most latest. Each generation of DDR has evolved in a similar way to the CPU, they all have reduced voltages to make them more power efficient and some other things like latency, burst length, data strobe etc.