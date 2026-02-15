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

The sending and receiving of messages gives us an implicit partial ordering of events whether we intend to or not (a message never arrives before being sent).


Some true statements:

1. if $a$ and $b$ are events in the same process, and $a$ occurs before $b$ then $a \rightarrow b$ is true.
2. If $a$ is the event of a message being sent by one process and $b$ is the event of the message being received by another process then $a \rightarrow b$ is true.
3. $\rightarrow$ is a transitive relation, so if $a \rightarrow b$ and $b \rightarrow c$ then $a \rightarrow c$ is true.
4. If two events $x$ and $y$ are events that happen in different processes that do not exchange messages (not even indirectly), then $x \rightarrow y$ is not true and not even directly. These events are said to be **concurrent** which means nothing can be said about either of them.

## Logical Clocks

Since there is no **global** clock, you cannot use something like `System.currentTimeMillis()` since one node might be ahead/behind another.

**Logical clocks** take advantage of the fact that an **implicit partial ordering of events can be obtained from the simple sending and receiving of messages between processes** 
So we track events and not time.

### Lamport's Logical Clock

This is a simple example of a logical clock.
It assumes that each processor $i$ has a Logical Clock $LC_i$. 

When an event occurs on processor $i$, $LC_i$ is incremented by 1 and when a processor sends a message to another process it also sends its logical clock.

If the receiving process' logical clock is less than the logical clock sent by the process, the receiving process **updates** its logical clock.
If the receiving process' logical clock is **greater** than the logical clock sent by the process, the receiving **does not** update its logical clock.

For an example:

We have $X$ and $Y$
$X$ sends a message to $Y$.

*Scenario 1*
$Y$'s clock, $LC_Y$ is **behind** $LC_X$ (the sender).
Since $LC_Y < LC_X$, $LC_Y = LC_X + 1$, Process $Y$'s logical clock gets updated.

*Scenario 2:*
$X$ clock, $LC_X$ is less than $LC_Y$
Since $LC_Y > LC_X$, $LC_Y = LC_Y$, nothing happens


Another Example:

|**Step**|**Process**|**Action**|**Local Clock**|**Explanation**|
|---|---|---|---|---|
|1|**P1**|Internal Event|**1**|P1 starts working.|
|2|**P1**|**Sends Message**|**2**|P1 ticks to 2 and sends message `(Msg, Time=2)` to P2.|
|3|**P2**|Internal Event|**1**|P2 is working independently.|
|4|**P2**|**Receives Message**|**3**|P2 receives `(Msg, Time=2)`.<br><br>  <br><br>P2's clock is currently 1.<br><br>  <br><br>Comparison: Is $1 < (2 + 1)$? Yes.<br><br>  <br><br>Update: Set P2's clock to $2 + 1 = \mathbf{3}$.|
One thing to note is that we cannot infer a causal relationship just by looking at timestamps: just because $LC_A \lt LC_B$ then $a \rightarrow b$.






