15-02-2026 12:48

Tags: [[Distributed Systems]]

# Synchronisation

Synchronisation relates to both:
1. **Data Synchronisation**: keeping multiple copies of a dataset in coherence with one another, given that the various copies are located in different nodes (same data in different nodes)
2. **Process Synchronisation:** multiple processes needing to act together to achieve a certain overall purpose.

Synchronisation requires **fast** and **reliable** communication between processes.

Synchronisation is needed when you need to agree on the order of events (if a message came before or after a process) **and** when multiple processes try to simultaneously access a shared resource (such as a printer) and should instead cooperate in granting each other temporary exclusive access.

**Deadlock** can result when multiple processes are sharing the same resources.

Nodes in a distributed system are connected via a network, networks are not always reliable and so coordination of actions that require communication can be quite difficult.

You *could* timestamp a message as its sent out, but you don't know how long the message would have taken to be sent unless the two nodes have the same clock **or**
the two clocks are in sync.
(The only thing that is certain when you have two independent clocks is that a message will not arrive at its destination before its sent which is self-explanatory and obvious).

---
Example:

You have P and Q which are two distinct processes and they execute a sequence of instructions:

![[Pasted image 20260215131243.png#invert|300]]
Although vertically p4 is lower than q3, if you look at the arrows, we can see that a message was sent **from** q3 **to** p4, this means that p4 happens **after** q3 and so p5 is the last thing to execute.

---

The sending and receiving of messag





