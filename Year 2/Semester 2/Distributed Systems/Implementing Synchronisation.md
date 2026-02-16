15-02-2026 21:52

Tags: [[Distributed Systems]]

# Implementing [[Synchronisation]]

If you have multiple distributed systems to achieve one goal, systems need to be **choreographed** in order to be able to avoid situations where possible dilemmas occur i.e. two clients holding on to a finite resource when there's only one left **or** when sending data from one client to another a system crash prevents it from going through.

There are two possible solutions:

1. Centralised Lock Server (and mutual exclusion)
2. Two Phase Commit Algorithm

## Centralised Lock Server and Mutual Exclusion

Here is the mechanism for this technique:

The client does the following:
1. **Request**: It requests the resource.
2. **Wait**: It cannot perform any operation until the resource has been given.
3. **Execute**: Once the client has the resource it performs the operation.
4. **Release**: The data is returned to the server.

The server's job:
1. **Check:** it checks if the resource is available.
2. **Grant or Queue:** If **yes**, the resource is handed over. If **no**, then the client is put on the waiting list (placed in queue).
3. **Handover**: When the resource is returned, if anyone else needs the resource (in the queue) then its handed to them immediately.

### Limitations

1. **Single Point of Failure (SPOF)**
	One single specific server is in charge of *all* permissions, this makes the entire system quite fragile. Makes the system **prone to crashes** and have a **severe bottleneck** (if it has 10,000 clients the system will be overwhelmed).

2. **Isolation vs. Atomicity**
	The server lock guarantees **isolation** but does not guarantee **atomicity**, this means that if the data transfer fails if there will be any rollback.

## Two-Phase Commit Algorithm

The **Two-Phase Commit (2PC)** algorithm is the standard solution for consistency in **distributed systems**.

Here the goal is **atomicity** what this means is that the system can never end up in a half-finished state.
If the a sequence of events fails it returns to the original state as if never happened.

Mechanism:
1. **Request:** The coordinator node tells the participants ($C_1, C_2$) what needs to be done.
2. **Local Check:** Each participant checks if it can do the action
3. **Vote:** if a participant can do it, it logs the action to a secure "undo log" so it can recover later and votes **VOTE_COMMIT**. If it **cannot** do it, it votes **VOTE_ABORT**.

If everyone voted **COMMIT**, then all participants make the changes permanent but if a single node voted **ABORT** then the system rolls back to the exact state it was in before the transaction started.

### Electing a Coordinator Node

The **Bully Algorithm** is a mechanism for choosing a coordinator from a set of coordinate nodes. 
Its called a **Bully Algorithm** because the higher numbered nodes 'bully' lower numbered nodes into submission.

Mechanism:
1. $P$ sends an **ELECTION** message to all modes.
2. If no one responds, $P$ wins the election and becomes the co-ordinator. It informs all the other nodes that it is now the coordinator.
3. If one of the higher-numbered nodes, $Q$, answers then $P$ concedes and $Q$ repeats the election process, until one node eventually wins.

The algorithm relies on the use of timeouts to decide when to 'give up' waiting for responses.
The algorithm **assumes that all the nodes are ordered**.

## Clock Synchronisation

Clock Synchronisation is not completely possible (in Distributed Systems) by the fact that messages are not sent instantly over real networks and there is some degree of variation in the time messages take to arrive at their destination.

As long as some amount of error is acceptable, there are at least two widely acceptable ways for getting clocks in different parts into near synchronisation.

### Cristian's Algorithm

This is when a client is calling the server to ask what the current time is.

You have a machine $P$ that needs the correct time from  a server $S$.

Since network travel takes time, when its 12:00:00 by the time the data get sent to $P$ it will be 12:00:01.

To fix this, you need to account for travel time:
1. $P$ measures the total **Round Trip Time (RTT)** - the time sending the request to getting the reply.
2. $P$ assumes the network is symmetrical (takes the same time to get there and the same back)
3. So $P$ sets its clock to $\text{Server Time} + ({\text{RTT} / 2})$

Remember this assumes that the time for the message to get there is the same as the time to get back, if the assumption is wrong then $RTT$ is inaccurate and the clock will be set incorrectly.

### Berkely Algorithm

This like a conductor leading an orchestra or a teacher synchronising a class.

A group of computers on a LAN need to have the same time but they might not have access to a perfect UTC source.

Mechanism:
1. **Election:** One computer is chosen as the **Master** (using an election method like the Bully Algorithm)
2. **Polling:** The Master asks all other machines (slaves) "What time do you think it is?"
3. **Averaging:** The Master gathers all the times (including its own), it throws out any outliers (clocks that are very wrong) and then calculates an average of the group.
4. **Adjustments:** The Master does **not** send back the absolute time but instead it tells each slave relative offsets to adjust their clocks. This is to prevent further uncertainty due to RTT.