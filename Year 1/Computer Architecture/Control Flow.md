12-10-2024 21:21

Status: #new

Tags: [[Architecture]] [[Week 2 Slides.pdf]] [[RISC-V Instruction Set]]

# Control Flow
So how does the processor know what to execute next? So when we looking at the fundamentals of our processor and the Von Neumann model, we know that programs are just another form of data and that each instruction has an address. 
The Program Counter (PC), is a special register that holds the address of the next instruction.
The PC is a key component in the [[FDE Cycle]]. The FDE cycle continues forever until we tell it to stop.

Understanding key points about how instructions flow in the CPU:
- Execution is serial: this means that instructions are processed one at a time
- There is also little flexibility: instructions cannot be repeated without copy pasting code, you cannot change what is executed, every time the program run the exact same operations will run.

**RISC-V Control Flow Instructions:**
There are special instructions that arbitrarily change which instruction is to be executed next, it effectively assigns a value to the PC, these are also known as a jump or branch instructions.

We will be looking at RISC-V's control flow instructions and that means that 
***jumps*** will be ***unconditional*** (will always change the PC),
and that ***branches*** will be ***conditional*** (will only change the pc given that a certain condition is true)

## Unconditional Control Flow:
*jal rad, lab*
- jal : jump and link
-so what does this code do?:
1. Jumps to lab: this instruction causes the program to jump to the address labelled lab, which is the start of a subroutine
2. Return address is saved: the address of the instruction immediately following jal (in this case is rad) is saved in the destination register, rd.

*jalr rd, rs1, imm*
- jalr: Jump and Link with Register
1.  Jump: The CPU will jump to the address stored in rs1 plus the immediate value imm.
2. Link: The return address (the address of the next instruction) is saved into rd.

These two pieces of code are very powerful and so more simple jump pseudo-instructions would be:

*j label:* jump to the label
 - 'j label' is the same as 'jal x0, label' - the 'x0' has no effect as x0 is always 0
*jr rsl*: jump to the address in the register
 - 'jr rsl' is the same as writing 'jalr x0, rs1. 0'

## Conditional Control Flow:
General Syntax:
*b {cond} rs1, rs2, label*
So what does this code do?
- b : Branch
- {cond} : Condition - this can be eq for equal, ne for not equal, it for less than etc
- rs1 : Source register 1
- rs2: Source Register 2
- label: target address to branch to
An example of a complete section of this code could be:
*beq rs1, rs2, label*: branch if rs1 is equal to rs2.
- what this does is that if rs1 is equal to rs2, PC will be updated to hold the address of label, if it is not then PC will be updated (PC = PC + 4)

**Zero Comparison Pseudo Instructions:**

| beqs | rs=0 | beq rs, x0, target |
| ---- | ---- | ------------------ |
| bnez | rs≠0 | bne rs, x0, target |
| bltz | rs<0 | blt rs, x0, target |
| blez | rs≤0 | ble x0, rs, target |
| bgtz | rs>0 | bgt x0, rs, target |
| bgez | rs≥0 | bge rs, x0, target |
This is why we have the register of x0 that always has the value of 0.

What are control flow needed for?:
- If-then-else statements
- Loops
- Functions/methods
- Complex logic operations
- Runtime checks 

## Conditional Statements:
### If - Else Statements
First Approach we have is nested ifs:
```R
lw t0, number

cmp0
	bnez t0, cmp2 #if t0 != 0 then branch
	li a0, '0'
	li a7, 0
	ecall 
	j end

cmp2
	li t1, 2
	bne t0, t1, cmp4 #if t0 != t1 then branch, where t1 = 2
	li a0, ‘2’
	li a7, 0
	ecall
	j end

cmp4
	li t1, 4 
	bne t0, t1, none #if t0 != t1, then branch, where t1 = 4
	li a0, '4'
	li a7, 0
	ecall 
	j end

none 
	li a0, '?' 
	li a7, 0
	ecall

end
	...

number defw 0

```

The code above does:

```R
if number == 0:
	print(‘0’)
elif number == 2:
	print(‘2’)
elif number == 4:
	print(‘4’)
else: 
	print(‘?’)
```

The problem with this is that a large nested if statement can have many cases so many tests are needed, it is slow and requires lots of code.

![[Pasted image 20241113150831.png#invert]]
The if-else method is simple and has a direct implementation. It can also handle non-numeric and sparse input variables without any memory overhead.
However, many comparisons and branch instructions are required to get to the last of the if-else statements. It also takes more time to execute if there are a large number of nested if-else statements.
### Switch
A better way we can do this sort of thing is with switch statements.

```R
switch var
	condition_1: #do something
	condition_2: #do something else
	condition_3: #do something else
	...
	condition_n: #do something else
	defaultL #any other case
	
```

We can also use switches with [[Tables]].
We use a table(list) holding the addresses of the pieces of code.
- The table has one word for each possible value of the variable,
- Each table entry is the address of the code to be executed for that value,
- Use the value of the variable to find the address in the table.

```R
lw a0, number
bltz a0, default #branch if a0 less than 0
lw a1, 4
bgt a0, a1, default

la a1,
table slli a0, a0, 2
add a1, a1, a0
jalr zero, 0[a1] #table + (number*4)


table defw case0 address = table + 0
	defw default ; address = table + 4
	defw case2 ; address = table + 8
	defw default ; address = table + 12 
	defw case4 ; address = table + 16
	defw default ; address = table + 20
```

Using the 'Address Table' method it takes less time to execute as compared to the direct "if-else" method., the numerical variable can be used to directly index the table and require few branch instructions.
However, table lookup is more complex when the input variable is non-numeric and memory footprint is very when if-else statements are sparsely placed.