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




