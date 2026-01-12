18-10-2025 22:39

Tags: [[Verilog]]

# Verilog Synthesis

Not everything in Verilog can be synthesised into hardware.
For an example: `#100`
- There is no reliable, technology-independent temperature-stable way of making a 100ns delay on a chip
- If a delay is necessary it is done by counting clock pulses from a stable, external clock.


![[Pasted image 20241103204340.png#invert|800]]

For Verilog structure:
- Use meaningful names for signals and variables,
- Comment code, in a sensible way to make it readable,
- Do not mix level and edge sensitive elements in the same always block,
- Avoid mixing positive and negative edge-triggered flip-flops,
- Use parentheses to optimise logic structure,
- Use continuous assign statements for simple combinatorial logic,
- Use non-blocking (<=) for sequential and blocking (=) for combinatorial logic,
- Do not mix blocking and non-blocking assignments in the same always block,
- All non-blocking assignments in the same always block are evaluated at the same time.



