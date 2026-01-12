22-12-2024 21:08

Status: #new

Tags: [[Computer Engineering]] [[Architecture]]

# Harvard Architecture
The Harvard Architecture logically separates memory storage and pathways for instructions and data: it separates the fetching of instructions from data reads and writes (e.g. 'load' and 'store'). However, its real purpose is to increase memory bandwidth.

Bandwidth is the quantity of data (number of bits) which can be transferred in a given time. 

*The term 'Harvard Architecture' is normally used for stored program computers that separate instructions and data buses. This separation may apply to the entire memory architecture*

Separate buses for instructions and data memory means that parallel access to instructions and data can occur, reducing bottlenecks.

![[Pasted image 20241222213759.png#invert]]


## Disadvantages of the Harvard Architecture
- Available memory is pre-divided into code and data areas; in a Von Neumann machine the memory can be allocated differently according to the needs of a particular program - there is less flexibility.
- It is hard/impossible for the code to modify itself (can make loading programs difficult).
- More wiring (pins etc.) is needed