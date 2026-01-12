14-10-2025 14:43

Tags: [[2 - Tags/Verilog|Verilog]]

# Introduction 

Verilog is a hardware design language (HDL), it allows you to define hardware in a textual form. Verilog is not the only HDL but is what we will be using.
They way we define the behaviour of hardware in Verilog is very to different to how we describe an algorithm.

Advantages of using HDLs:
- Easy to express logic functions
- Suited to RTL (Register Transfer Level)
- Allows synthesis of designs into hardware
- Code may be easier to follow and is portable

Disadvantages of using HDLs:
- Code may not synthesise into hardware 
- Easy to write inefficient code
- parallelism is difficult to visualise/"see"

Verilog was originally intended as a description language for *modelling systems*. It was extended to enable it to be used to synthesise logic circuits. It is particularly suited for RTL descriptions.

We will be using Verilog for:
- Stimulus files, for testing designs with a simulator (Not synthesisable)
- Hardware descriptions, for building into running chips (Synthesisable)

## Folder Layout:
![[Pasted image 20251014164857.png#left|600]]



