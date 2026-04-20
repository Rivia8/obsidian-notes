20-04-2026 11:05

Tags: [[Distributed Systems]]

Here are types:
- **Centralised Architectures**: traditional client-server - single server implements most of the software components (and thus functionality)
- **Decentralised Architectures**: peer-to-peer architectures in which all nodes more or less play equal roles
- **Hybrid Architectures**: combining elements from centralised and decentralised architectures.

## Centralised System Architectures

### Simple Client-Server Architecture

![[Pasted image 20260420111054.png#invert|400]]

Processes in a distributed system are divided into two main groups: **Clients** and **Servers**.

A **Server** is a process that implements a specific service. This machine is waiting to be asked, it does not actively send data to the client unless the client asks for it first.
A **Client** is the machine waiting to be asked, it **initiates** the conversation.

The interaction is known as **request-reply** behaviour.

### Multi-Tired Client-Server Architectures

![[Pasted image 20260420111433.png#invert|400]]

This typically presents ***three*** **logical tiers**.
