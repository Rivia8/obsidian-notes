11-10-2024 23:01

Status: #new

Tags: [[Computer Engineering]]  [[Year 1/Computer Engineering/Sequential Systems]]

# Delays in Circuits

One may assume that the D-type flip-flop stores the value on the D input immediately on seeing a rising edge on the clock input, but that isn't the case.
Remember that nothing acts immediately in a digital circuit, signals take a finite time to change state and there is always a delay before an input change causes the output of a circuit to change.

Each logic gate will this have a delay associated with it and so more logic gates means the signal must propagate further and therefor a longer delay. Such delays are inherent to the circuit.

# Timing Diagrams
Truth tables depict all the possible outcomes of a logic function, but they are static, i.e., they do not demonstrate dynamic behaviour.

![[Pasted image 20241012174233.png#invert]]
![[Pasted image 20241012174423.png#invert]]
![[Pasted image 20241012175439.png#invert]]

![[Pasted image 20241012174627.png#invert]]
