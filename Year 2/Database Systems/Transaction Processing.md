21-11-2025 20:11

Tags: [[Database Systems]]

# Transaction Processing

A **transaction** is a mechanism for describing logical units of database processing. It is a single logical unit of work that might involve one or more steps, (like reading, writing, updating or deleting data).

They can be embedded within the application program or within the SQL server.

Transaction processing is a way of managing data operations to ensure that a database remains consistent, accurate and reliable especially when multiple operations happen at the same time.

## Interleaving 

This is assuming we have a CPU with only one core to make it simpler.

![[Pasted image 20251121202718.png#invert|800]]
Transaction states and additional operations:

![[Pasted image 20251126142740.png#invert|800]]
We start at **Active** here the transaction is currently running and executing operations, then we have **Partially Committed** where the transaction has finished its final statement but hasn't been safely saved yet.
The transaction can **Fail** at any of the two points above, this is a check that discovers that normal execution cannot continue.
**Aborted** is the one place a failed transaction can go, this is where it is rolled back and the database restored it to its start state.

### What Causes it to Fail or Abort

There are several reasons why a transaction can might enter a 'failed' or 'aborted' state:
- **System Crash:** Hardware, software, or power failure.
- **Transaction Error:** Integer overflow or division by zero.
- **Logical Error:** The transaction detects a bad condition and chooses to abort itself.
- **Physical Problems:** Disk failure or IRL disaster (fire, earthquake etc.)

## Database Model and Buffers

The database model that is used to represent transaction processing is very simple, a database is seen as a collection of named data items and there are various levels of granularity that could be represented.

*The University curriculum uses a simplified abstract model to teach Transaction Processing.*

When we have the DBMS we have two specific areas of memory:
- **RAM:** This is the local memory for the running application/transaction. It holds variables.
- **DBMS Buffer:** This is the shared memory area managed by the database system. It holds the "official" cached copies of data items (like `X` and `Y`) that have been fetched from the **disk**.

![[Pasted image 20251126121326.png#invert|1000]]
When we have operations like 'read' and 'write' they are strictly about moving data between these two memory areas.
When we have something like `read_item(X)`, the operation causes the value of item `X` from the DBMS buffer into a program variable. If `X` is *not* in the buffer, the system must first fetch the block containing `X` from the disk into the buffer and *then* copy it into the program variable.
When we have `write_item(X)` it causes it to write that value into the DBMS buffer, it doesn't necessarily mean that the value is put straight into disk, but it the value overwrites the one that is in the buffer.

### Concurrency Control

This also links to [[Transaction Processing#Interleaving|interleaving]] as because these are steps and not atomic operations, it can cause errors. If we have a lots of steps one after another, the operating system might pause at one.
Because of this you can sometimes have **'lost' updates**, in the sense that the scheduler might stop a step and resume another causing the original step to not do what was *intended*.
Step-by-step:
1. $T_1$ reads $X$ (e.g., value 80) into its local program memory.
2. **Interruption:** The scheduler pauses $T_1$ and starts $T_2$.
3. $T_2$ reads $X$ (still 80, because $T_1$ hasn't written back yet).
4. $T_2$ updates $X$ to 84 ($80+4$) and does `write_item(X)`.
5. **Resumption:** $T_1$ wakes up. It calculates $75$ ($80-5$) based on its _old_ local memory value.
6. $T_1$ does `write_item(X)`, overwriting the buffer with $75$.
7. **Result:** The update from $T_2$ is "Lost".

What we just discussed is known as **Concurrency Control** this is because its the transactional model dealing with multiple operations at the same time.
Above we discussed **lost** updates but you can also have a **temporary** **update**:
Scenario:
- $T_1$ updates $X$, from 80 to 75.
- $T_2$ reads that new value.
- $T_1$ fails before it finishes, 
- Because $T_1$ failed, its changed must be rolled back, $X$ goes **back** to 80.
- But $T_2$ is still working with 75 that doesn't exist.

### Why Even Enable Interleaving

We have looked at 2 possible problems that interleaving can cause and the question remains as to why even enable it?

**Throughput and Scale:** Look at Lloyd's Banking Group, they have 27 million customers, if it could **only** do serial processing then everyone would have to wait, it would be practically unusable.

## How do we Prove a Transaction is Safe

There are some desirable properties that come from the acronym **ACID:**

- A: Atomicity,
- C: Consistency - The data must make sense,
- I: Isolation - Transactions should not mess with each other when running,
- D: Durability - Once saved, it stays saved.

There is a strict checklist that decides if two operations 'conflict':
Two operations conflict **only** if **all three** are true:
1. **Different Transactions:** they belong to different transactions,
2. **Same Item:** they access the same data item
3. **One is a Write:** At least one of the operations is a `write_item`.

This matters because conflicting operations are the only places where interleaving can cause data corruption.

## Modes of Schedule and Equivalence

When it comes to the schedule we can have different 'modes' per say:
- **Serial Schedule**: $T_1$ runs completely then $T_2$ runs completely, very safe but very slow,
A schedule S of n transactions is serializable if it is equivalent to some serial schedule of the same 𝑛 transactions, there are $n!$ possible schedules of serial transactions.
- **Non-Serialised Schedule:** the operation are interleaved (mixed together), it is very fast but extremely dangerous.
- **Serializable Schedule:** this is 'sweet spot', it has the benefit of a serial schedule's safeness and the speed of a non-serialised schedule.

What does 'equivalent' mean, in the simplest terms it is comparing the results of a serial schedule to that of a non-serial schedule but we need a safe and general approach to equivalence, the safe approach is to focus only on the read and write operations of the transactions (don't make assumptions about the other internal operations).
**Two schedules are equivalent if the operations applied to each data item affected by the schedules should be applied to that item in both schedules in the same order (they both do the same in the same order)**.

### Conflict of Equivalence

Two schedules are said to be **conflict equivalence** if the relative order of any two operations is the same in both schedules.
So if they are different transactions and they **both** access the **same** item and **one** or **both** is a write operation.
(It isn't conflicting when operations are applied in different orders in two schedules).

### Serialisable Schedules

If we have a schedule S, it can be serialisable if it is (conflict) equivalent to some serial schedule, so by reordering the operations you can create a serialisable schedule.

![[Pasted image 20251126153353.png#invert|800]]


### Testing the Serialisability of a Schedule

We can use graph theory to test if a schedule is serializable or not (we only look at read and write operations):

![[Pasted image 20251126153828.png#invert|800]]


