01-11-2024 18:59

Status: #new 

Tags: [[Architecture]] [[RISC-V Instruction Set]] 

# Tables
In RISCV, tables are typically used to organise and manage data efficiently.

## Colours and Colour Lookup
![[Pasted image 20241101213310.png#invert]]
![[Pasted image 20241101213658.png#invert]]
![[Pasted image 20241101213813.png#invert]]


^ The code above has the goal to map a 4-bit colour ID stored in `x10` to a specific colour value.
`x10` is already loaded with a 4-bit colour ID, it is then compared with `x1` which first has 0 loaded.
`x1` is incremented by 1 in each instance and is compared with `x10`, once it has found a match with a corresponding ID in `x1`, `x10` is set to the colour value associated with that ID in `x1`.  
![[Pasted image 20241101214537.png#invert]]
![[Pasted image 20241101214735.png#invert]]
^ This example demonstrates a table lookup approach for colour matching in RISCV, which is more efficient than the previous approach that used conditional branching.
A memory table is initialised as 'table' in memory, with each entry being a 4-byte word. Each word contains 24-bit colour value.
Each colour in the colour table is organised sequentially in memory.
In the Table Lookup above, the part `mul x2, x10, x2` multiplies the colour ID by 4, this finds the byte offset for that colour (how far the colour is into the colour table). The offset is then added to the memory address of the table that is in x1: `add x1, x1, x2`.
This means that `x1` now has the memory address that points at the location of the colour in the table.

See [[Week 5 Slides.pdf]] for more examples.