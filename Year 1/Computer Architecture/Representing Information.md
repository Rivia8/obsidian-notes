15-10-2024 09:25

Status: #new

Tags: [[Architecture]]  [[Computer Engineering]] [[Week 2 Slides.pdf]]

# Representing Information
## Intro to binary representation
How do we think about computers?
There are multiple levels of abstraction:
- Physics → Electrons and holes flow through semiconductors\
- Electronics → Voltages, transistors, memory cells
- Computational → 0s and 1s, Binary numbers, Operators

At a basic computational level, all information is composed of bits: 0s and 1s.
Algorithms handle all different kinds of information.

For an example:
Looking at a traffic light there are 4 possible values:
Red, Red + Amber, Green and Amber and so we need bit values to represent these states:
- n bits can count $2^n$ things:
	- *2 bits can count 4* things
	- 00 01 10 11
- Then there are 4! (24) ways to map these 4 values to the 4 states of the traffic light.
Looking at the example there are many ways to map n bits to N things.

## Number Representation
### Integers:
To represent integers it is relatively easy: 
sets of bits → natively treated as base-2 numbers
more bits → better range
fewer bits → less storage

The RISC-V architecture uses three built in data types:
8-bits (byte), 16-bits (half-word), 32-bits (word)

### Decimal to Binary:
2110 to binary:
- 21 / 2 = 10 remainder 1 → 1 
- 10 / 2 = 5 remainder 0 → 01 
- 5 / 2 = 2 remainder 1 → 101 
- 2 / 2 = 1 remainder 0 → 0101 
- 1 / 2 = 0 remainder 1 → 10101 

10101 = 24 + 22 + 20 = 16 + 4 + 1 = 21

### Negative Numbers:
Base-2 numbers are positive, so we use two's complement to display negative numbers.

![[Pasted image 20241015122456.png#invert]] 

![[Pasted image 20241015122548.png#invert]]
![[Pasted image 20241015122913.png#invert]]
So how do we know how to interpret whether a binary number is signed or unsigned using 2's complement? Without context, you'd never know if a binary number is signed or unsigned.

### Character Representation:
When looking at the alphabet, there are 26 letters from A-Z (another 26 for a-z, lowercase letters) and 10 numbers of 0-9. There are 17 symbols and 2 more for space and newline.
This in total leads to over 81 characters.
So how do we display these 81 characters?:
- n bits = $\log_{2}81$ ≈ 6.34
	- 7 bits can represent all the characters that we use, $2^7 = 128$, is enough. 

#### ASCII
This is an early 7-bit standard - 128 English and American characters.
It stands for the 'American Standard Code for Information Interchange'
- A is represented by 100 0001
- B is represented by 100 0010
-  Z is represented by 101 101
- a is represented by 110 000\
- b is represented by 110 0010
- z is represented by 111 1010
- 0 is represented by 011 0000
- 9 is represented by 011 1001
You can see there is a 32 bit difference between 'A' and 'a', the same with 'Z' and 'z' (32 bit difference between the capital and non-capital letters - capital having 32 less bits)

#### Other Character sets:
What about non-Americans?
ISO-8859 is a family for alphabets and abjads:
- 8 Bits → 256 values
- 128 for ASCII + 128 for extra characters for a specific script
However, this was an improvement but a bit would have a lot of different interpretations depending on the ISO script.

#### Unicode:
UTF-8 (Unicode or ISO10646).
This is a superset of ASCII, it uses 4 bytes → 32 bits →  $2^{32}$ characters → > 4 billion characters.
If the 8th > bit of a character is 0 its most likely an ASCII character since ASCII operates with only 7 bits.

#### Strings:
These are characters in memory that are sequenced (in consecutive memory locations)
![[Pasted image 20241015143234.png#invert]]   
 
### Extending Numbers:
In base-2:
1000  =  0000 1000

In two's complement:
1000 = -8 (4 bit two's complement)
0000 1000 = 8 (8 bit two's complement)
1111 1000 = -8 (8 bit two's complement)
- in 2's complement 1000 = 1111 1000 = 1111 1111 1000 (all equal to -8)

So to extend a negative value with two's complement you add 1's and for positive numbers add 0's.

![[Pasted image 20241015131052.png#invert]]

## Boolean 
![[Pasted image 20241119134354.png#invert]]
![[Pasted image 20241120164151.png#invert]]
### Boolean Examples:

```assembly
#assuming t0 = 1 (true) and t1 = 0 (false)

and t2, t0, t1

#t2 = t0 & t1 : t2 will be 0 (false)
```

```assembly
# Assuming t0 = 1 (true) and t1 = 0 (false)

or t2, t0, t1

# t2 = t0 | t1 -> t2 will be 1 (true)
```

```assembly
# Assuming t0, t1, and t3 have some values
and t2, t0, t1  # t2 = t0 & t1
or t4, t2, t3   # t4 = t2 | t3
# t4 now contains the result of (t0 & t1) | t3
```
### Lazy Evaluation
Lazy evaluation is a strategy used where the evaluation of an expression is delayed until the value is actually needed. Lazy evaluation can be applied in if-then-else constructs, where the condition is evaluated first and only the relevant branch is executed.

### Bitwise Logic
Sometimes (maybe in IO or control applications), we have to operate logically on individual bits.
In some applications it is useful for individual bits to have different functions, e.g.:
- Displays, instrumentation, control etc..
An example could be this 7-segment display:
![[Pasted image 20241120164436.png#invert]]

