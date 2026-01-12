01-10-2024 21:59

Status: #new

Tags: [[Architecture]] [[Vonn Neumann Architecture]] 

# RISC-V Instruction Set
Looking at what RISC-V is:
- Open standard ISA: free to use, no hidden information and is extensible
- Designed from scratch for efficiency and simplicity
- Base instruction sets + extensions
- In COMP15111 we use RV32IM
- Three groups of instructions: **Data Operations** (performs calculations on registers), **Memory Operations** (moves data between memory and registers) and **Control Flow Operations** (makes decisions to control execution).

## ABI Naming Convention
![[Pasted image 20241106190657.png#invert]]

Looking at the table above, we see that the registers from x0 to x31 can have different names with designated functions/descriptions.
The ABI defines rules for the use of each register which prevents compatibility issues and improves program readability.


## Representation
### RISC-V Assembly

![[Pasted image 20241001221617.png#invert]]
![[RISC-V Assembly Example]]

Source operands can be:
Registers,
Intermediate: constant numbers encoded in the instruction itself,
The instruction type specifies the input operands,
Destination operands are always registers.

![[Pasted image 20241001223525.png#invert]]
#### Terminology:
`rd` is the register destination, where data will be loaded into
`rs` is the source register containing the base register
`imm` is an immediate offset value 
`label` a symbolic name used for addressing memory locations
`td`


![[Pasted image 20241001223603.png#invert]]


**Pseudo-Instructions:**
These instructions are not actually in the instruction set, but they can be used in an assembly program. The assembler automatically translates them into one or more real instructions and it can simplify common tasks without making the instruction set large.

## RISC-V Extras:
### Environment Calls:
In real computing systems, user programs typically run with restricted privileges to ensure that they don't interfere with system-level operations or other processes. On the other hand, system code (like an OS) runs with full privileges. 
Restricting user code prevents it from performing operations that might destabilise the system.

Since user code is restricted, how can a user program request privileged operations? This is done through system calls:
- The OS implements privileged operations (e.g., file access, memory allocation) in a secure manner.
- The system exposes a **controlled interface** to user programs through **system calls**. This interface is well-defined and restricted to ensure that only approved operations are allowed.
- To request a privileged operation, the user program needs a mechanism to **switch from user mode to a privileged (kernel) mode**. The hardware provides instructions to perform this switch.

Different architectures have different use specific instructions to transition from user mode to system mode:
- `int`in x86
- `svc` in ARM
- **`ecall`** in RISC-V
	- In **RISC-V**, the **`ecall` instruction** (Environment Call) is used for system calls. When a user program executes an `ecall`, the control is passed to the OS, which performs the privileged operation.
 
![[Pasted image 20241018120147.png#invert]]

![[Pasted image 20241018120052.png#invert]]
## Pseudo-Instructions:
They are not part of the instruction set. They are _not_ part of the ISA but are convenient shortcuts that the assembler translates into real instructions, for an example:
- `li x1, 100` (load immediate value `100` into `x1`)
	- RISC-V doesn’t have a single instruction to load a 32-bit immediate value directly, so **`li`** will be translated by the assembler into **multiple instructions** like:
		- `lui x1, 0x0` (load upper immediate)
		- `addi x1, x1, 100` (add immediate to lower part)

- `nop` (no operation — this expands into `addi x0, x0, 0`, a real instruction that does nothing)

Pseudo-code is different to Pseudo-instructions where pseudo-code is an abstraction for high level languages, whereas Pseudo-instructions are are shortcuts used in assembly code to simplify programming, but they do not directly correspond to machine instructions. 

![[Pasted image 20241018122539.png#invert]]
## Assembler Directives:
These control how the assembler operates. They provide 'guidance' or 'metadata' for the assembly process, such as defining data, allocating memory or specifying alignment. They play a critical role in organizing assembly programs and managing memory, but they don't generate executable machine code like normal assembly instructions.

![[Pasted image 20241018123738.png#invert]]
![[Pasted image 20241018124220.png#invert]]
![[Pasted image 20241018124237.png#invert]]

## Memory Instructions
![[Pasted image 20241029131414.png#invert]]
	in the syntax `lw rd, imm[rs]` the data of a word will be loaded into register rd and the memory address is calculated by adding the immediate value (imm) to the contents of register 'rs'.
### The Memory Wall
Loading and storing is slow, 'The Memory Wall' refers to the performance bottleneck created by the difference in speed between the CPU and memory. 
- Loading and storing is slow
- Reading from registers is quick
![[Pasted image 20241029133629.png#invert]]
### Optimisation
![[Pasted image 20241029150810.png#invert]]

Variables have 'Value Liveness', where they will be stored in a register for a certain period of time. If a variable is 'alive' for a long time the register cannot be used for the same amount of time:
![[Pasted image 20241029152631.png#invert]]

![[Pasted image 20241029181825.png#invert]]
**SUMMARY:** 
There are three goals in order to have effective code:
- Minimise instructions
- Minimise memory access
- Minimise register use
The problem with these goals is that they can be conflicting but generally reducing memory use is the most critical one (due to the hindrance posed by 'The Memory Wall').
We can also reorder statements in order to optimise the code

## Control Statements
See [[Year 1/Computer Architecture/Control Flow]] for extra information
### IF vs Branch
Branch:
- Program executes something else when true,
- Program executes following piece of code when false.
IF:
- Following piece of code executes when true,
- Following code does not execute when false.

![[Pasted image 20241029134510.png#invert]]
Look at [[Week 4 Slides.pdf]] to see all the versions of control statements.

## Loops
These are critical for performance:
- They're everywhere,
- Small sequences are executed repeatedly and small changes have massive effect.
They are hardware tuned for making loop-y code faster (software needs to match what the hardware is tuned for)

![[Pasted image 20241031151854.png#invert]]
![[Pasted image 20241031152909.png#invert]]

- In the original version, the loop condition (`bge`) is checked at the start, so if `a` is initially greater than or equal to `b`, the loop body won’t execute at all.
- In the optimized version, the loop condition (`blt`) is checked at the end, ensuring that the loop body will execute at least once. This optimization can be beneficial when the loop is expected to run at least once and saves an instruction for cases where repeated checking at the start is not necessary.

![[Pasted image 20241031163701.png#invert]]
- The duplicated load and condition-checking instructions in `prestart` allow the main loop to skip the initial check after the first iteration.
- This reduces the loop overhead by avoiding an initial comparison in each iteration after the first, which can improve performance slightly.
- This version optimizes for faster looping at the cost of some **code duplication**.
- While it slightly improves efficiency by reducing branch checks within the loop, it increases the instruction footprint due to duplication, which may affect cache usage and memory efficiency.

Check [[Week 4 Slides.pdf]] for more information.

## Shift Operations
![[Pasted image 20241102232125.png#invert]]

![[Pasted image 20241102232139.png#invert]]
When you shift binary by either left or right, you are essentially multiply it or dividing by $2^n$ amount.
![[Pasted image 20241102232308.png#invert]]
![[Pasted image 20241102232316.png#invert]]
Shifting left is multiplication by 2 if the result fits in the register, if it is signed or not is irrelevant.
However, shifting numbers to the right, if it is signed or not matters.

![[Pasted image 20241102232507.png#invert]]
![[Pasted image 20241102233033.png#invert]]
Shifting is cheaper than multiplication so we can use shifting for table lookups rather than multiplication in order for them to work.