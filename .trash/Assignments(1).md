 14-10-2025 21:00

Tags: [[Verilog]]

# Assignments

Assignments define how signals are or variables are updated. They dictate the flow of data within the design.

![[Pasted image 20251015081613.png]]

## Blocking '=' 

A **blocking** assignment uses the operator `=`. 
It is called blocking because blocking assignments happen sequentially, so when you have a block of assignments, the first must occur first then the next.
Its similar in other language's variable assignments like in Python.

```Verilog
// Describing a simple logic chain
always @(*) begin
  // Use blocking assignments for combinational logic
  tmp = a & b;  // Step 1: This is calculated and assigned to tmp
  y = tmp | c; // Step 2: This uses the *new* value of tmp
end
```

Here are the lines of codes and the steps it takes:
1. Defines the `always` block,
2. `a & b` is evaluated and stored in `temp`,
3. now `tmp | c` is evaluated and stored in y,
 
## Non-Blocking '<='

A non-blocking assignment uses the operator `<=`, it is non-blocking because it doesn't block the execution of other statements. Instead it **schedules** an update to happen at the end of the current simulation step time:
All right-hand sides are read first, and then all left-hand sides are updated simultaneously.

## Continuous

This type of assignments are used to model combinatorial logic in a concise way. The expression on the right-hand side is continuously evaluated and the result is assigned to the left-hand side:

```Verilog
assign <variable> = <logical statement>

#actual example:

assign a = b && ( c || d);
assign q = (sel == 0) ? x : y;
```

**Note:** 
- Continuous assignments are only allowed on wire data types.
- Continuous assignments are performed in the body of the module, they are not performed in initial or always blocks.

Here is another example:

```Verilog
// The 'assign' keyword creates a continuous assignment
module mux (
  input  wire a, b, sel,
  output wire out
);

  // This is a permanent, concurrent rule.
  // If a, b, or sel changes, 'out' updates instantly.
  assign out = sel ? b : a;

endmodule
```

