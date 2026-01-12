08-10-2024 10:58

Status: #new

Tags: [[Computer Engineering]] 

# Binary Adders
How do we implement a circuit to perform binary arithmetic.
The basic building block is the half adder, which takes two inputs and generates a sum and a carry, from which we can derive a truth table:

![[Pasted image 20241008134321.png|400]]



![[Pasted image 20241008130651.png#invert]]

![[Pasted image 20241008134412.png]]

**The Half Adder:**
Looking at the truth table above and the logic gates, we can see that when we add two 1's it results into a 0 with a carry of 1. The disadvantage here is that there could be a carry of 1 from the previous bit calculation, which the half adder will not take into account. This is why we need the full adder.

**The Full Adder:**
The full adder is a circuit that takes two binary values, plus an input carry, and produces a sum and a carry out. Such a circuit is called the full adder.
![[Pasted image 20241008132753.png#invert]]

![[Pasted image 20241008132934.png#invert]]

**Multi-bit Adders**:
The full adder is a 1-bit adder, to do anything meaningful we need to be able to add many bits. This can be performed using a parallel adder, where the carry out from one bit is fed to the carry in of the next.
![[Pasted image 20241008133101.png#invert]]

**Buses**:
A bus is a collection of signals, grouped together for convenience: address bus, data bus...
![[Pasted image 20241008135329.png#invert]]
In the lab, you will see these named according to two different conventions:
- busname <31:0>
- busname \[31:0]

