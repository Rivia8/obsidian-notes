27-11-2024 15:48

Status: #new 

Tags: [[Architecture]] [[Interrupts]] [[DMA]]

# Privileges
RISC-V has 3 Privilege Modes:
- User Mode (U-Mode)
- Supervisor Mode (S-Mode)
- Machine Mode (M-Mode)

Each mode supports various levels of software execution in order to enhance security and performance. 

## User Mode:
This is the least privileged mode, designed for running application-level code. It has restricted access to certain system resources and cannot directly perform operations that could affect the system's stability.

## Supervisor Mode:
This has a higher privilege level than user mode, it's used for running operating system kernels and system-level software. It has access to control registers and the ability to handle system calls and interrupts.

## Machine Mode:
This has the highest privilege level, and it is intended for low-level hardware control. Machine Mode has unrestricted access to the entire system including all memory and I/O devices. It is usually used for Firmware, Bootloaders, and Low-Level Hardware Initialisation.

## Control and Status Registers
Theses are additional set of registers to expose CPU status and allow configuration, they are available in Machine Mode and can be controlled using dedicated instructions (*CSR* instructions).

The Registers Include:
- **'mstatus'** : Holds global interrupt state, including interrupt enable
- **'mcause'** : Holds the cause of the interrupt i.e. which type of interrupt occurred
- **'mtvec'** : Machine Trap-Vector Base Address Register, hold information to address the ISR to execute
- **'mie'** : Machine Interrupt Enabler Register, enables or disables individual machine-level interrupts.
- **'mip'** : Holds a list of pending interrupts, i.e. not serviced yet.
- **'mepc'** : Machine Execute Programme Counter, holds the saved PC.
- **'mscratch'** :  Holds one word of data for temporary storage.

Since the CSR registers cannot be accessed when in lower level privilege modes, how do we do interrupts when it comes to privileges?
Whenever there is a hardware interrupt, the processor changes modes from User Mode to Machine Mode. 
There is a Memory Management Unit (MMU) - Hardware between the processor and the memory which only allows access to some regions of the memory map when the processor is in specific modes.
Machine mode may be able to directly access hardware, user mode cannot.

How does the MMU know what mode the processor is in?
• 'mstatus' register,
• MPP field (User 00, Supervisor 01, Machine 11),
• When IRQ occurs mode is changed to Machine mode,
• The MMU can see the mode bits and enable access.

## OS Considerations:
- **User Space in Memory**:
    - Users are allocated specific memory spaces called "user space".
    - Users cannot access the memory space of the OS or other users, ensuring isolation and security.

- **Access to Peripherals**
    - Users need to use peripherals like keyboards, network interfaces, and storage devices.
    - Direct access to hardware is prohibited to maintain system stability and security.
    - Users interact with hardware through controlled interfaces provided by the OS, such as file stores and network services.

- **Utilities and Containment**:
    - The OS provides utilities and services to users, such as file systems, networking, and process management.
    - The Memory Management Unit (MMU) ensures users are contained within their allocated memory spaces.
    - Direct Memory Access (DMA) and hardware access are limited and controlled by the OS.

## How can user access hardware?
- **Using the OS for Hardware Access**:
    - Users request the OS to perform hardware operations.
    - This is typically done through system calls.
- **System Calls (**`ecall`**)**:
    - The `ecall` instruction is used by user programs to request services from the OS.
    - When a user executes `ecall`, an integer `n` specifies the requested service or operation.
- **Handling** `ecall`:
    - Similar to an Interrupt Request (IRQ), but initiated by the user rather than by hardware.
    - When `ecall` executes, the following occurs:
        - The processor switches to a higher privilege mode (Machine or Supervisor mode).
        - The OS handles the request by executing the appropriate routine.
        - After completing the service, the OS returns control to the user mode and resumes execution at the next user instruction.
