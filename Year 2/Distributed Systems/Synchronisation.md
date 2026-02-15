15-02-2026 12:48

Tags: [[Distributed Systems]]

# Synchronisation

Synchronisation relates to both:
1. **Data Synchronisation**: keeping multiple copies of a dataset in coherence with one another, given that the various copies are located in different nodes (same data in different nodes)
2. **Process Synchronisation:** multiple processes needing to act together to achieve a certain overall purpose.

Synchronisation requires **fast** and **reliable** communication between processes.

Synchronisation is needed when you need to agree on the order of events (if a message came before or after a process) **and** when multiple processes try to simultaneously access a shared resource (such as a printer) and should instead cooperate in granting each other temporary exclusive access.

**Deadlock** can result when multiple processes are sharing the same resources.








