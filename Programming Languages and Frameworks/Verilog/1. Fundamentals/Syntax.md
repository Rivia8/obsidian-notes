14-10-2025 14:46

Tags: [[2 - Tags/Verilog|Verilog]]

# Syntax


![[Pasted image 20241017111820.png#invert|800]]

As in other programming languages, you must define the type of a variable being assigned a value:
- Wire - declares the default connection between components - a `net wire` is the default type.
- Reg - which declares something which may be a register but may just be a simple wire connection, this can be somewhat confusing and takes some getting used to.

![[Pasted image 20241017112436.png#invert|800]]
![[Pasted image 20241017112536.png#invert|800]]
As in other programming languages. Verilog has a number of operators that can be used.
![[Pasted image 20241017113009.png#invert|800]] 
How do you make decisions in code?
You use control statements, in Verilog we use the If else statement.


![[Pasted image 20241017113254.png#invert|800]]
![[Pasted image 20241017113519.png#invert|800]]



## Always Block

We use always blocks to describe assignments that occur when something happens, such as a variable (or variables) changing, or with respect to some timing (a clock edge).
The `always` block starts with the keyword `always` followed by a sensitivity list, which dictates when the block should execute.
Inside the block, you define the logic that should execute when the conditions in the sensitivity list are met.

For combinatorial logic, the block executes whenever any signal in the sensitivity list changes, updating outputs based on current inputs.
For sequential logic, the block typically triggers on clock edges, updating state variables (like flip-flops or registers) based on the clock's edge.

**Example of combinatorial logic:**
```
always @ (a or b) begin
    c = a & b;  // AND operation between a and b
end
```
	This block updates c whenever a or b changes

**Example of Sequential Logic:**
```
always @ (posedge clk) begin
    q <= d;  // Capture the value of d at the rising edge of clk
end
```
	This block updates q with the value of d at the rising edge of the clock signal clk.

### The Sensitivity List:
This is a crucial component of the `always` block that determines when the block should execute. It specifies the signals or events that the `always` block is sensitive to.
- The sensitivity list is enclosed in parentheses following the `@` symbol, such as `@(posedge clk)` or `@(a or b)`.
- Signal Changes: The always block runs whenever any signal in the list changes. For example, @(a or b) means the block executes when either a or b changes.
- Clock Edges: The block can be triggered by clock edges, such as `@(posedge clk)` for the rising edge or` @(negedge clk)` for the falling edge of the clock signal.
![[Pasted image 20241103193303.png#invert|800]]
General coding guidelines:
- When modelling combinatorial logic use continuous assignments or blocking assignments - a quick reminder is that combinatorial logic refers to logic that doesn't depend on a clock; its output is a direct function of its inputs.
- When modelling sequential systems, flip-flops, registers, etc., non-blocking assignments
- if a design contains both combinatorial and sequential in the same `always` block then use non-blocking assignments.
- Never mix blocking and non-blocking assignments in the same always block.
## Case Statements
The case statement is useful when operation is determined by a number of options, and it can be use to replace a long list of `if ... else ` statements.
It is normal to include a default clause that captures any cases not explicitly stated. This avoids the synthesizer adding extra latches when they are not needed.
So an example could be this:
``` Verilog
reg [1:0] selector;
reg [7:0] output_reg;

always @ (selector) begin
  case (selector)
    2'b00: output_reg = 8'hA1;
    2'b01: output_reg = 8'hB2;
    2'b10: output_reg = 8'hC3;
    2'b11: output_reg = 8'hD4;
    default: output_reg = 8'hFF;
  endcase
end

```

``` Verilog
reg [1:0] selector;
reg [7:0] output_reg;
```
This part declares registers, which can hold and store values, the `[1:0]` and `[7:0]` specifies the register's width. 
`reg [1:0] selector;` - declares a 2-bit wide register named `selector`with the MSB at position 1 and the LSB at position 0
`reg [7:0] output_reg;` - declares an 8-bit wide register named`output_reg`, with the MSB at position 7 and the LSB at position 0.

In this example on how the `case` statement is used, we can see that for the values that selector can have, if it matches the values: `2'b00, 2'b01, 2'b10, 2'b11`, it assigns a corresponding value to `output_reg` and if it there is not a match, then the default value is allocated - `default: output_reg = 8'hFF;` .

## Parallelism
Unlike traditional programming languages where instructions are executed sequentially, Verilog code can execute multiple operations in parallel. This is important in hardware design because digital circuits naturally work in parallel.
![[Pasted image 20241103200130.png#invert|800]]
Looking at this demo above, there are two `always` blocks that are both triggered on the positive edge (`posedge`) of the clock signal (`clk`).
- For the first always block, the block assigns the value of a to b on each rising edge, it uses a non-blocking assignment (`<=`), which is suitable for synchronous operation.
- For the second always block, the block assigns the value of b to c on each rising edge, also using non-blocking assignment (`<=`)
- The catch is the `always` blocks are clocked synchronously: they are triggered by the same clock edge.
From this we can take the fact that since both `always` blocks run in parallel and are triggered by the same clock edge, the order in which they appear in the code does not affect result.
Verilog will therefore execute both results simultaneously when the clock edge occurs.