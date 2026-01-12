15-10-2025 08:09

Tags: [[Verilog]]

## Tasks

Most programming languages have things like functions and procedures that are used to break up code into more easy to manage parts.
We can use these parts as reusable code.

In Verilog we already have [[Modules|modules]] to partition the design but with **tasks** we can create more relocatable and reusable chunks of code that can be called within the module.

![[Pasted image 20251015081722.png#invert]]

- Tasks can have any number of inputs and outputs
- They can call other tasks or functions
- Can be used to model both combinatorial and sequential logic
- They have input and output parameters and they work on the input parameters to produce some new output on the output parameters

## Functions

Function is similar to a task but only input parameters are passed to it and it returns a single output value

- Functions can have any number of inputs
- They can return a single result which by default is a single bit
- They reside within a module
- They work on the inputs passed by the input parameters to produce an output

![[Pasted image 20251015083107.png#invert]]




