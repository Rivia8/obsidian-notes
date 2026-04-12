12-04-2026 17:53

Tags: [[Distributed Systems]]

## A Simple Machine

![[Pasted image 20260412175903.png#invert|500]]

A machine boils down to two resources
- CPU (CPU time)
- Storage - Primary Storage which is RAM

An application lives within secondary storage, but once you click on it, its contents are opened within primary storage and it becomes a [[Processes|process]].

![[Pasted image 20260412180341.png#invert]]


The Operating System manages multiple processes in order to make sure they are executed.
The OS will assign each process with an ID and then it controls how a process is granted access to computing resources.
The OS will also control its **storage resources** by assigning it an **address space**.

When the OS ensures that each process **P** has a single address space **A** that is exclusive to **P**, it allows for **sequential reading** of the steps that comprise the **process**.

```Python
def foobar(a, b):
	x = a + 1
	y = b + 3
	print("x = ' + x)
	print("y = ' + y)
```

This provides **strict isolation**, what this means is that the process will know with 100% certainty that it will execute in that order and no other will change the values of `x` and `y`.

