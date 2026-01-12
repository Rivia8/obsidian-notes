06-11-2024 19:17

Status:

Tags: [[Architecture]] [[RISC-V Instruction Set]] [[Week 7 Slides.pdf]]

# Methods
In python a method call is an invocation of a function that is associated with an object.
It allows you to declare functions or methods in one place and recall it so you do not have to keep on rewriting the same code. 
The function use parameters and return values etc.

But how do we apply this to RISCV:
It is quite easy to do this in RISCV by simulating it with functions and registers.
The method needs input parameters: the information from the calling code to be used by the method.
The method needs to be able to return a value: information from the method back to the calling code.

In RISCV we use `jal` to the jump the function:
```R
jal ra, func
...
jalr zero, ra, 0 
;return to the caller
```

## Limitations:
If the methods need to use more registers, it must save the current values of those registers before using them and restore them after the method call.
A temporary space, typically in data memory, is used to store the register values.
![[Pasted image 20241106192801.png#invert]]
Here the value that was being held in `s0` was placed into memory for 'safekeeping' until is retrieved after the function that had to use the register.

**What if a method calls another method?**
if a method calls another method it may cause complications in order to jump back to the original code.
In order to prevent this we can use a temporary space to store the return address:

![[Pasted image 20241106194446.png#invert]]

However, this does not fix everything, 
The number of arguments is limited by the number of registers (`a0-a7`),
- What if we need more arguments?
Methods also can call themselves in a recursive way
- Where do we store all these return addresses?

This all points to the fact we need an alternative to save and store registers.
The solution to all this is a **STACK**.

## Stack
A stack is like a pile of books, you can add anything on top 'push' and you can remove anything from the top 'pop'.
It is a data structure that follows the Last In, First Out (LIFO) principle. Think of it like a stack of plates: you add (push) plates on top and remove (pop) plates from the top.
It typically goes from a higher memory address to a lower one, adding to it decreases the address and removing from it increases the address.

`sp` register points to the top, decrease the `sp` to push, increase to pop.

Lets say we want to do the following:
- Push `t0`
- Push `t1`
- Pop `t0`
- Pop `t1`
We would do:
```R
sw t0, 4[sp] ;push t0
sw t1, 0[sp] ;push t1 
lw t0, 0[sp] ;pop t0
lw t1, 4[sp] ;pop t1
```

However, this has swapped the values of `t0` and `t1` since we popped whatever was pushed at the top last and returned that into `t0`.

The correct order would be:
```R
sw t0, 4[sp] ;push t0
sw t1, 0[sp] ;push t1
lw t1, 0[sp] ;pop t1
lw t0, 4[sp] ;pop t0
```
Looking at `sw t0, 4[sp]` the offset causes the stack to 'grow upwards' by 4. 

![[Pasted image 20241106202042.png#invert]]
Look at [[Week 7 Slides.pdf]] for more information

### Caller and Callee Saved Registers
When a function (caller) calls another function (callee), it needs to ensure that any data it is using is not overwritten by the callee. There are two ways it can do this:

1. Caller Saved Registers:
	The caller saves the values of the registers it needs to use after the callee returns.
	Before calling the callee, the caller pushes its data onto the stack. After the callee returns, the caller pops the data back from the stack.

2. Callee Saved Registers:
	The callee saves any registers it intends to use.
	Upon entry, the callee pushes the values of any registers it will use onto the stack. Before returning it pops these values back.


