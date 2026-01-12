14-10-2025 16:54

Tags: [[Verilog]]

# Combinatorial Logic

Combinatorial logic describes a circuit whose output depends **only** on the **current** value of its inputs and doesn't look at any historical values that it may have received in the past.

This is quite simple to imagine, think of things like logic gates and wires wired together and if anything changes the signal is sent and a new output is produced.
With combinatorial logic we produce circuits like logic gates (that sit between the registers).

Here is an example of a simple piece of combinatorial logic:

```Verilog
// This register is always on, but the value of 'q'
// only updates at the exact moment of a positive clock edge.
always @(posedge clk) begin
  q <= d; // The value of 'd' is sampled and stored in 'q'.
end
```

As you can see by the `<=` operator we usually use non-blocking assignments to model this
