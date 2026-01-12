30-09-2024 11:27

Status: #new

Tags: [[Computer Engineering]] 

# Boolean Algebra
Boolean algebra uses Boolean functions.
## Boolean Functions
Logic functions have binary inputs and binary outputs, i.e. the inputs and the outputs are either 0 (false) or 1 (true).
Some of these functions are AND, OR and NOT.

One way to express logical functions are through truth tables. These are way to tabulate the inputs and outputs that can be expressed through these logical functions, they can either be expressed through 'True and False's' or a more suitable way would be through 0's and 1's. 
![[Pasted image 20240930125652.png]]
![[Pasted image 20240930125634.png]]

Two more Boolean functions are worthy of their own names:
NAND: which is AND with the results inverted 
NOR: which is OR with the results inverted 

Another useful Boolean logic function is the Exclusive-OR gate (EXOR, XOR)
The XOR or EXOR function is the same as the OR function, however, it excluded the cases when both inputs are true, hence the name 'Exclusive OR function'. A way to understand this function more is to understand that this function goes 'High' when the two inputs are different. ![[Pasted image 20240930114550.png]]
![[Pasted image 20240930114753.png]]

^check notes for Booleans laws.

## De Morgan's Theorem
It is a very useful relationship that allows us to recast Boolean expressions in different forms.
![[Pasted image 20241008110337.png#invert]]

# Logic Gates
Logic gates are physical (can be virtual) ways to implement Boolean functions in digital circuits. 
In essence, logic gates are the physical representation and hardware of Boolean functions which utilises Boolean algebra to simplify and optimise the logic which in turn helps to reduce the number of logic gates needed.
![[Pasted image 20240930123022.png]]
In order to represent these logic gates, symbols are used in order to display these.
