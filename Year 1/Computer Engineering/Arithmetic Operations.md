08-10-2024 11:11

Status: #new

Tags:  [[Maths]] [[Computer Engineering]] 

# Arithmetic Operations
## Number Representation:
Digital circuits are used to perform arithmetic operations, they are built using transistors that are characterised by two states, 0 and 1.
We naturally work in decimal or base-10.

**Converting from Decimal to Binary (and Vice Versa):**
One way is by dividing the number by 2 and remembering the remainder. For an example if we look at the number 13:

![[Pasted image 20241008112823.png#invert]]

If we want to convert from binary to decimal, we can associate each digit with a power of two:

![[Pasted image 20241008113023.png#invert]]

**Binary Addition:**
Two n-bit binary numbers can be added by treating each pair of individual bits in turn (from the lsb to the msb) by summing the two bits and taking into account in the sum and forwarding the carry to the following bit.

**Binary Subtraction:**
We perform subtraction by "adding" a negative number.
$$A - B = A + (-B)$$
In order to represent a negative number in binary we use 2's complement.
This is where the msb indicates whether the binary number is positive or negative.

**2's Complement Notation**:

![[Pasted image 20241008114915.png#invert]]

Key points about the notation:
- The representation of POSITIVE numbers remains UNCHANGED
- Less positive values are available as half the positive integer values are lost to allow us to represent the negative values.
- The most significant bit (i.e. the leftmost bit) indicates the sign

Two find the 2's complement of a number:
- First: invert all the bits (0 -> 1)
- Then: add 1 to the least significant bit (propagating carry as needed)
