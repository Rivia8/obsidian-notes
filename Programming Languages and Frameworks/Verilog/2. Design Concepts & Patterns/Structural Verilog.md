16-10-2025 14:36

Tags: [[Verilog]]

# Structural Verilog

Structural Verilog allows you to define the structure of a design.
Previously we have looked at just the **behaviour** of the circuits we have been designing while **Structural Verilog** describes *how* it's built by connecting smaller components together.

Lets look at the following circuits:

![[Pasted image 20251016144707.png#invert]]

We can describe this circuit structurally in two ways:

1. Explicitly:

Assuming we have a 2-input AND gate already defined as:
```Verilog
module AND2 (C, A, B); // C = A & B
```

```Verilog
module top (output z,
input W, X, Y);
wire int;
AND2 I1(.A(W), .B(X), .C(int)); //I1 & I2 are unique names
AND2 I2(.A(int), .B(Y), .C(Z)); //signals can be in any order
//because they are explicitly
//assigned to pins of AND2
endmodule
```

2. Implicitly:

```Verilog
module top (output z,
input W, X, Y);
wire int;
AND2 I1(int, W, X);
AND2 I2(Z, int, Y); //signals are in the same order as in the
//AND2 module
endmodule
```

