22-04-2026 16:10

Tags: [[Distributed Systems]]

Inter-process communication is the way that processes on **different machines** can exchange information. Normally when two processes want to speak to each other they utilise **shared memory** but since the machines are *different* and are in different places, it can be a problem.

Traditional inter-process communication has always been based on **low-level message passing** done by the underlying network and so is harder to *realise* than communication based on shared **memory**. 
As modern distributing systems often consist of thousands or even millions of processes scattered across a network with unreliable communication such as the internet. Development of large-scale distributed applications such as is difficult.

There are **two** widely used models for communcation:

1. Remote Procedure Call (RPC)
2. Message-Orientated Middleware (MOM)

## Remote Procedure Call (RPC)

This utilises **abstraction** heavily: the programmer will use a function like any other function but the function hides all the messy networking. This is ideal for **client-server applications**.

--- 

**How it works:**
![[Pasted image 20260422163646.png#invert|400]]

Using the `append(data, dblist)` example

1. The main program calls `append()` (it thinks its working on the database locally),
2. It isn't the real function, its actually calling a fake, stand-in version of the function called a **Client Stub**
3. **Packing or Marshalling** is then done which is translating the parameters, `data` and `dblist`, into a format the network can understand,
4. The client stub sends the message across the network to the server, after sending, the stub **suspends** the main program, the applications literally pauses and waits (kind of what happens for a heavy calculation).
5. The remote server receives the message, unpacks it and runs the *real* `append` function on its database and sends the resulting `newlist` back *over* the internet.
6. The Client Stub receives the reply, unpacks it and and hands it back to the main program.

After all this, the main program wakes back up and continues executing, unaware that its data just travelled a large distance and back, it just thinks that `append()` took a couple extra milliseconds.

What actually happens at the server though?
When the message arrives at the server, the server's OS passes it to a **Server Stub**, this acts as the **server's** translator.
- It **unpacks** the parameters from the message,
- It turns to the actual, real application code on the server and calls the function exactly as if it were a local program.
- Once the real function is done, the Server Stub takes the results, pack it back into a network message and fires it back to the client.

**Phase 1: The Outbound Trip (Client to Network)**

- **Step 1:** Your main program calls the _Client Stub_ (thinking it's the real function).
- **Step 2:** The Client Stub packs the data into a message and hands it to the local OS.
- **Step 3:** The Client's OS physically transmits the data across the internet to the Remote OS.

**Phase 2: The Execution (Network to Server)**

- **Step 4:** The Remote OS receives the data and hands it to the _Server Stub_.
- **Step 5:** The Server Stub unpacks the data and calls the actual, real Server program.
- **Step 6:** The Server runs the calculation/database lookup and gives the result back to the Server Stub.

**Phase 3: The Return Trip (Server back to Client)**

- **Step 7:** The Server Stub packs the result into a new message and hands it to the Remote OS.
- **Step 8:** The Remote OS transmits it back across the internet to the Client's OS.
- **Step 9:** The Client's OS hands the incoming message to the Client Stub.
- **Step 10:** The Client Stub unpacks the result and hands it to your main program. Your program wakes up and continues.

---

A well-known example of this technology being used and fully embedded is Java: **Java RMI (Remote Method Invocation)**.
Java is an Object-Orientated Language, they don't use the term "Remote Procedure Call" (RPC), they call it **Remote Method Invocation (RMI)**.

It's the exact same concept, instead of calling a standalone *procedure* on a remote machine, you are invoking a method on an object that physically exists in RAM of a different server. Java RMI automatically handles creating the client and server stubs for you, so you can write code that seamlessly interacts with objects across a network.

## Parameter Passing in RPCs

Like we said the the function of the client stub is to take its parameters, pack them into a message and send them to the server stub.
**Packing parameters** into a message is called **Parameter Marshalling**.

Network cables just pass strings of 1s and 0s there is nothing more to bridge context. To further add on to the complexity, different computers read binary differently: A Windows machine with an Intel processor might read binary number from left-to-right, while a Sun SPARC server might read the other way around ([[RISC-V with Memory#Endianness|Endianness]]). The solution is ***Parameter Marshalling***

**Parameter Marshalling** is *NOT* straightforward. The server just sees a series of bytes coming which make up the original message sent by the client, there is no additional information on how those bytes should be interpreted is provided with the message. 
In Parameter Marshalling, we take the local data out of the machine specific memory structure, and convert it to a strictly agree-upon, machine and network-independent format

For this to work properly, both the client and the server must be programmed to expect the same data type - if the client is sending an integer, the server's function must be expecting an integer too.

So essentially, the Client Stub sends its machine dependent routines that are translated into a **neutral format** and then the **Server Stub** translates the *neutral* format into something *it* can understand.

## Passing References to Objects in RPCs

![[Pasted image 20260424130123.png#invert]]

We need to look at how pointers (or in general, references) are passed.
A [[Pointers|pointer]] is a physical address in a machines RAM. 