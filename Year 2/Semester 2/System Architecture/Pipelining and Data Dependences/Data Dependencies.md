31-03-2026 15:09

Tags: [[2 - Tags/System Architecture]]

When an instruction relies on another, it breaks the flow of the pipeline and this is known as "non-ideal pipeline" and the interruptions are called "Dependencies" or "Hazards".

Dependencies dictate ordering requirements between instructions.

There are three types of dependencies:
- Data Dependence
- Control Dependence
- Resource Dependence

## Data Dependence

There are three types of data dependencies:

![[Pasted image 20260401133228.png#invert]]

1. **Flow Dependence** or RAW (Read-After-Write)
	- Flow dependence always needs to be obeyed because they constitute true dependence on a value.
2. **Anti Dependence** or WAR (Write-After-Read)
	- Instruction 1 needs to read the original value of `r1` and if instruction 2 somehow races agead in the pipeline and overwrites `r1` too early, Instruction 1 will accidentally read the new value instead of the old value it was supposed to get.
3. **Output-Dependence** or WAW (Write-After-Write)
	- This happens when two different instructions are trying to write their final answers into the exact same registers.
- Anti and Output dependence exist due to a limited number of architectural registers.

Because Anti and Output dependencies are 'false', they are easier to handle.

## Ways of Handling flow Dependencies:

There are [[Handling Data Dependencies|5 fundamental ways]] of handling flow dependencies:
1. **Detect and Wait** until value is available in register file.
2. **Detect and forward/bypass** data to dependent instruction
3. **Detect and Eliminate** the dependence at the software level
	- No need for hardware to detect dependence
4. **Predict** the needed value(s), execute "**speculatively**" and **verify**
5. **Do something else** (fine-grained multi threading)
	- No need to detect





