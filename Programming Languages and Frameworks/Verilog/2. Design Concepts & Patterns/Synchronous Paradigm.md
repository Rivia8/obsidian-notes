18-10-2025 23:49

Tags: [[Verilog]]

# Synchronous Paradigm

This is a design methodology for digital circuits where all-state changing elements are coordinated to update at the same time using the [[Year 1/Computer Engineering/Sequential Systems#The Clock|the clock]].

## Moore and Mealy Machine

**Moore Machine:**
![[Pasted image 20251019000005.png#invert|800]]

**Mealy Machine**
![[Pasted image 20251019000017.png#invert|800]]

In a **Moore Machine**, the output signal only depends on the current state. As such they will change synchronously at the same time as the current FSM changes.
In the **Mealy Machine**,, the outputs depend on the current state and the state of any input signals. This means that the output signals can change asynchronously whenever the inputs change or the current state changes.
