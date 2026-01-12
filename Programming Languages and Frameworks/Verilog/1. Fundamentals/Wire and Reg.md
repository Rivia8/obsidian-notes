14-10-2025 21:24

Tags: [[Verilog]]

# Wire and Reg

A `wire` represents a physical connection and is used for **continuous** assignments, whereas a `reg` represents a storage element and is used for procedural assignments inside always blocks.

## Wire

The best way to think of wire is as an actual wire, it doesn't actually store anything on its own it drives the data away to another component.
Here is an example:

```Verilog
module and_gate(
	input wire a, 
	input wire b, 
	output wire c
);

	// 'y' is a wire continuously driven by the result of a & b
	assign y = a & b;

endmodule
```

## Reg

A `reg` (from register) represents a storage element. It holds a value until a new value is assigned to it.
One thing to note is that it does not always synthesise to a register -  depending on how the `always` block is written it can change what it represents.

`reg`s are used to model both sequential logic and combinatorial logic that is described procedurally.

## Implementation

- Inputs in `module` must be a net type, so always a `wire`
- Outputs can be either a `wire` or a `reg`


