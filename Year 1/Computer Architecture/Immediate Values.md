18-10-2024 10:43

Status:

Tags: [[Architecture]] [[RISC-V Instruction Encoding]] 

# Immediate Values:
Immediate values are literals (like numbers or characters),
They could be labels (symbolic names corresponding to memory addresses)

Regardless of their type immediate values end up being transformed into a number, that number is then encoded in the immediate field of the instruction.

Two groups of encoded immediate values:
- I/S/B - Type → 12 bits
- U/J - Type → 20 bits

![[Pasted image 20241018111053.png#invert]]
- This limitation (the trade-off) balances between using fewer instruction bits and being able to work with larger values. For larger values, multiple instructions might be needed.

![[Pasted image 20241018111108.png#invert]]
- The understanding for the 'Multiplied by 2' is due to  RISC-V instructions being word-aligned (i.e., each instruction is 4 bytes), the offset is multiplied by 2. This means the branch offset represents **word offsets** and gives a range of **-4096 to 4095**.
- It has a small range but most conditional branches (like loops) are local, meaning they jump within the same function, so this is sufficient.

![[Pasted image 20241018111118.png#invert]]
![[Pasted image 20241018111142.png#invert]]
![[Pasted image 20241018111154.png#invert]]
