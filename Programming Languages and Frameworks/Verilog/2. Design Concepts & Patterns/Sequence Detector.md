19-10-2025 23:29

Tags: [[Verilog]]

# Sequence Detector

The sequence detector has one input, X, and a single output, Z. A stream of 0s and 1s o the input X (at a rate determined by an external clock) is tested and when the pattern that we want to find is observed then output Z goes high and is 0 otherwise.

![[Pasted image 20251019233203.png#invert|800]]

## Moore Design

We can have [[Synchronous Paradigm#Moore and Mealy Machine|Moore design]] for this:

![[Pasted image 20251019233320.png#invert|800]]

We now need to [[Sequential Systems#The Design Process|design the sequential system]] and so we have to first produce the state transition table:

![[Pasted image 20251019233731.png#invert|600]]

We then look at whether its a Mealy or Moore machine *(for this example its a Moore Machine but the picture below shows a Mealy Machine)*

![[Pasted image 20251019233935.png#invert]]

Here we define each element with its own `always` block (the combinatorial logic's sensitivity list being an asterisk, `*`).

We then need to define internal variables to hold the next and current state variables.

**Verilog Implementation of a Moore Design:**

```Verilog
module sequence (input wire X, clk, rst, output reg Z);

reg [1:0] current_state, next_state;

// Next state logic
always @ (*)
	case (current_state)
		2'b00: if (X == 1) next_state = 2'b01;
			else next_state = 2'b00;
		2'b01: if (X == 1) next_state = 2'b01;
			else next_state = 2'b00;
		2'b10: if (X == 1) next_state = 2'b11;
			else next_state = 2'b00;
		2'b11: next_state = 2'b00;
		default: next_state = 2'b00;
	endcase

// State assignment
always @ (posedge clk, posedge rst)
	if (rst == 1)
		current_state <= 2'b00;
	else 
		current_state <= next_state;

// Output assignment
always @ (*)
	if (current_state == 2'b11)
		Z = 1;
	else
		Z = 0;

endmodule
```

## Mealy Design

In terms of the Mealy design for this simple sequence detector we would have the SM chart:

![[Pasted image 20251019235123.png#invert|800]]
We have one fewer state as we have an Output Conditional Box.

Verilog implementation of the Mealy design:

```Verilog
module sequence (input wire X, clk, rst, output reg Z);

reg [1:0] current_state, next_state;

// Next state logic
always @ (*)
	case (current_state)
		2'b00: if (X == 1) next_state = 2'b01;
			else next_state = 2'b00;
		2'b01: if (X == 1) next_state = 2'b00;
			else next_state = 2'b10;
		default: next_state = 2'b00;
	endcase

// State assignment
always @ (posedge clk, posedge rst)
	if (rst == 1)
		current_state <= 2'b00;
	else 
		current_state <= next_state;

// Output assignment
always @ (*)
	if ((current_state == 2'b10) && (X == 1))
		Z = 1;
	else
		Z = 0;

endmodule
```

