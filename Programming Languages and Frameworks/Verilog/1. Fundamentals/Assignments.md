18-10-2025 22:36

Tags: [[Verilog]]

# Assignments

The job of the module is to define the behaviour of the circuit/design - it must determine the value of any output signals.
Assignments essentially define how signals are or variables are updated. They dictate the flow of data within the design.

![[Pasted image 20241021194241.png#invert|800]]
The value of the output signals are changed by assigning values to them.

In Verilog there are 3 forms of assignment, each with their own properties:
- Continuous assignment,
- Blocking assignment, (a=b),
- Non-blocking assignment, (a<=b).
The assignment you use depends on the type of circuit you are defining and how you define it.

### Continuous Assignments:
These are used to model combinatorial logic in a concise way. The expression on the right-hand side is continuously evaluated and the result is assigned to the left-hand side, e.g.:

```
assign <variable> = <logical statement>

#actual example:

assign a = b && ( c || d);
assign q = (sel == 0) ? x : y;
```

1) 1. `assign a = b && (c || d);`
    - This line uses a continuous assignment to define `a`.
    - It means `a` will be `1` (true) if:
        - `b` is `1` **and** at least one of `c` or `d` is `1`.
    - If `b` is `0` or both `c` and `d` are `0`, then `a` will be `0`.

2)  1. `assign q = (sel == 0) ? x : y;`
    - This line also uses a continuous assignment but includes a ternary operator.
    - It means `q` will be set to `x` if `sel` is `0`; otherwise, `q` will be set to `y`.


**Important thing to note**: Continuous assignment is only allowed on wire data types - so in the examples above, a and q must be declared as wires for the assign to be valid.
Continuous assignments are performed in the body of a module. They are not performed in  initial or always blocks.

### Blocking Assignment:
Blocking assignments occur sequentially, where they start in order of top to bottom.

```
always @ (a or b) begin
    c = a + b;
    d = c + 1; // This uses the new value of c
end
```

1. `always @ (a or b)`
    
    - This `always` block is sensitive to changes in `a` or `b`. Whenever `a` or `b` changes, the code within the block will execute.
        
2. `c = a + b;`
    
    - This is a blocking assignment (`=`). It means that `c` will immediately take the value of `a + b` once this line is executed.
        
    - In Verilog, blocking assignments (`=`) execute sequentially within an `always` block. So the next line of code will not execute until this one is complete.
        
3. `d = c + 1;` 

	- This line also uses a blocking assignment. Here’s the crucial part: because of blocking behaviour, `d` will use the newly assigned value of `c` from the previous line. Thus, `d` will be `a + b + 1`.

Blocking assignments are used for assigning variables in test ('stimulus') files and describing complex combinatorial logic.

### Non-blocking Assignment:
These execute concurrently, allowing for simultaneous updates. These are commonly used for modelling synchronous (clocked) logic e.g.:
```
always @ (posedge clk) begin
    a <= b + c;   // Schedule a = b + c for the next time step
    d <= a + e;   // Schedule d = current value of a + e
end
```

![[Pasted image 20241103194331.png#invert|800]]

For non-blocking assignments, all right-hand side expressions are evaluated first, and the results are assigned to the left-hand side at the end of the block.


