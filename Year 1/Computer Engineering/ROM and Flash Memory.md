21-12-2024 21:49

Status:

Tags: [[Computer Engineering]]

# ROM: Read Only Memory
ROMs are usually random-access memory devices. They use similar integrated circuit (IC) technology to RAMs, with lower cost/bit than RAM.

Properties:
- Read-only which means their contents cannot be corrupted by accidents such as bugs or maybe crashes
- They are non-volatile, they retain their information when power is removed

They can be used for:
- 'Bootstrap' programs, like BIOS systems
- 'Fixed' operating system and application code
- Logic functions (e.g. microcode, fine state machine)

![[Pasted image 20241221215942.png#invert]]
## Programmable Read Only Memory Devices
The three types of 'programmable' ROM all allow data to be written to non-volatile memory cells.

### PROM: Programmable ROM
As the name suggests, PROMs are 'Programmable', in that data can be written to them permanently after manufacture.
Specialist programming equipment is needed for this, as well as being an expert in PROM programming.
Once a PROM is programmed then it cannot be erased/overwritten.

### EPROM: Erasable Programmable ROM
EPROMs are erasable and programming devices. They use arrays of floating gates to store data are erased by exposing the IC to ultraviolet light. They are a technology now in decline.

### EEPROM or $E^2PROM$: Electrically Erasable Programmable ROM
EEPROMs are probably one of the most popular ROM technologies on the market, and are used in a variety of applications such in computer BIOS, hardware firmware etc.
like EPROM, EEPROM uses a floating gate transistor to store information.
EEPROM differs from RAM in that they require considerable time to alter a location (writes take ~100x the read time).


# Flash
Flash memory is a type of non-volatile storage technology that can be electronically erased and reprogrammed. It is widely used in various devices for storing data and code that needs to be retained when power is turned off.

Key Properties:
- **Non-Volatile:** Retains data even when the power is turned off.
- **Reprogrammable:** Can be electronically erased and written to multiple times.
- **Solid-State:** Has no moving parts, which makes it durable and reliable.

## Floating Gate Transistors
A floating gate transistor is a special type of transistor used primarily in non-volatile memory technologies like EEPROM and flash memory.

A floating transistor is a modified MOFSET (Metal-Oxide-Semiconductor Field-Effect Transistor) consists of a gate, source, and drain. The gate controls the flow of current between the source and drain.

![[Pasted image 20241222013725.png#invert|400]]

The floating gate transistor has an additional layer, known as the floating gate, situated between the control gate and the transistor's channel.
This gate is used to control conduction between the source and the drain.

Writing:
	If a voltage is applied to the gate, then a charge accumulates at the gate that helps form a conduction region (strong electric field). Electrons are injected onto the flowing gate through a process called the Fowler-Nordheim tunnelling or hot-electron injection.
	Once on the floating gate, the electrons are trapped there because of the insulating oxide layers.

Reading:
	Apply a reference voltage to the gate and apply a voltage across the source and drain. If we sense the current flows, then we can determine if a '1' or '0' is stored.

## SLC v MLC v TLC
By varying the threshold voltage applied we can potentially store more than one bit to a single cell. 

### SLC: Single-Level Cell 
In this design, each cell holds one bit of data, so there are two states, 0 or 1. This arrangement is used in high performance systems as it offers the greatest reliability. 

### MLC: Multi-Level Cell
Each cell holds two bits of data, so there four possible states. This arrangement is less expensive compared to SLC, as you can store more in the same area - used in high end consumer and enterprise application.

### TLC: Triple Level Cell
Each cell holds three bits of data, so there are eight possible states. Low cost due to the ability to store large amounts of data compared to other approached .However, due to the need to be able to differentiate between more recorded levels can be less reliable.

### QLC: Quad Level Cell
Quad-level cell – four bits of data – 16 possible states. Used in low end consumer devices – USB drives etc.

### Overview:
Going down the list, adding more bits to be stored as you can see is cheaper to produce since it is more densely packed and so on. However, endurance decreases as well as being more prone to errors.
Cheap flash devices like USB sticks have data encoding controllers that have error correcting software (that is redundant if using something like SLC) to prevent issues.
Multi-level cells are more susceptible to the problem of wear-out which results in the potential loss of data.