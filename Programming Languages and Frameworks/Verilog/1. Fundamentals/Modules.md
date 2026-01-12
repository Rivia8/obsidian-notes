14-10-2025 14:48

Tags: [[Verilog]]

# Modules

The module is the basic building block for describing digital systems, it is the equivalent of a schematic (or a symbol representing a design).
It takes input signals and depending on these (and for sequential circuits), the prior state of input signals, and and we generate some output signals.
There can be any number of input and output signals, single wires or buses it just depends on the design.

![[Pasted image 20251014145415.png#invert|800]]

![[Pasted image 20251014145446.png#invert|800]]

So above we have a general look at a module, where we have three inputs: a, b, c and the outputs d and e.

In Verilog one thing to remember is that in Verilog you are describing physical hardware that exists and runs concurrently all the time.
So once the Verilog code that you have created is synthesised its technically **always *on***.
Instead of thinking of modules as like a function or a class in regular programming, think of it as an Integrated Circuit (IC):
- The `module` declaration is the plastic casing of the chip,
- The `input` and the `output` ports are the **metal pins** sticking out of the chip,
- The logic inside the module (`assign`, `always` blocks) represents the transistors and wires inside the chip.

Here is an example.
**Verilog Module Hardware:**

```Verilog
// This is the "chip casing" and "pins"
module adder (
  input  [7:0] a,
  input  [7:0] b,
  output [7:0] sum
);

  // This is the "internal wiring"
  // It describes a permanent connection
  assign sum = a + b;

endmodule
```

So once this circuit is described and synthesised, anything that changes with `a` or `b`, `sum` will update automatically.

## Partitioning

A single module can have numerous `assign` and `always` blocks.
But you should only assign a variable in one block and not mix blocking.
![[Pasted image 20241103195731.png#invert]]