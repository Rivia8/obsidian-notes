30-11-2024 20:37

Status:

Tags: [[Architecture]] [[Interrupts]] [[Privileges]]

# DMA: Direct Memory Access

## Loading Storing Blocks of Data
What if a peripheral needs to move a large amount of data?
Like loading a file from a disk into memory:
- It needs to reserve a big enough block of memory for the data, 
- Initialise to the start address of the target memory block
- Repeat:
	- Disk drive interrupts, provides a byte,
	- ISR gets the byte,
	- Puts it in memory, 
	- Increments the memory address,
	- Returns from interrupt to user code,
(Uses interrupts to the CPU for each byte of DATA)
This isn't very efficient, as for a large file there will be huge CPU overhead.
So what can happen instead.
## DMA
DMA is a more efficient method of data transfer.
- **DMA Controller**: A DMA controller take over the data and address bus
- **Direct Transfer**: The DMA controller transfers data directly to/from memory without involving the CPU
- **Processor Independence**: The CPU can perform other tasks while the DMA controller handles the data transfer
This is overall a much faster method since the CPU is not involved in handling each byte, and is much more efficient, the CPU is free to execute other tasks, improving overall system performance. 
However, during DMA operations, the CPU cannot access the memory being used by the DMA controller, which might temporarily halt some tasks. 

![[Pasted image 20241203151217.png#invert]]

DMA Sequence
1. Peripheral requests DMA transfer
2. DMA controller requests DMA from CPU
3. CPU grants DMA when ready
4. Bus switch1 (CPU) disabled
5. Bus switches 2 and 3 (DMA controller and peripheral) enabled
6. DMA controller grants DMA transfer

## DMA Modes
### Burst Transfer:
Data is transferred in one continuous sequence, this mode is efficient for large data transfers but can make the CPU inactive for longer periods since it relinquishes control of the bus to the DMA controller.

### Cycle Stealing Mode:
In cycle stealing mode, the DMA controller takes control of the system bus to transfer one byte of data at a time. After transferring each byte, it returns control of the bus to the CPU. This mode allows the CPU to perform other tasks between data transfers, making it more efficient for small data transfers.

### Transparent Mode
In this mode, the DMA controller transfers data only when the CPU is not using the system bus, this mode minimises the impact on CPU performance since the CPU can continue executing instructions while the DMA controller transfers data during idle periods. 
Here transfer is the slowest but the CPU never stops executing.


