16-10-2025 15:01

Tags: [[Verilog]]

# Testing

When designing hardware we start by providing a block diagram overview - it is the role of the designer to produce this design.
In Verilog, the designer then works at producing a Verilog description of the design, compiling it using CAD software and then fixing any compile errors.
![[Pasted image 20251016150431.png#invert|800]]

If the design compiles, then we use a **simulator** (and an accompanying testbench design) to test the functionality of the design. Some errors may appear here and so the designer will have to go back and fix it.

## Hierarchical Approach

We use a **Hierarchical Approach** in testing where we split the complex design into multiple pieces that are easier to handle and test. Once the individual units have been tested we can 'put them together' and perform **integration testing** to ensure that the components now work together.

![[Pasted image 20251016151134.png#invert|800]]

## Regression Testing

Regression testing is very important, not only in software design but also in the design of hardware systems.

**Regression tests** are tests that attempt to ensure that a developing design stays working, so when changes are made the tests can be run again to demonstrate something that had previously passed will continue to do so (and haven't been affected by more recent modifications).
![[Pasted image 20251016151202.png#invert|800]]

Regressions tests are important since when you fix one bug or modify a design you are likely to introduce newer bugs.