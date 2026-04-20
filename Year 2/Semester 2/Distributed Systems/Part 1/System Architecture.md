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


This distinction of having *tiers* makes it so that there can be numerous possibilities for physically distributing a client-server application. 

Many distributed applications are divided into the three layers:
- User Interface Layer
- Processing Layer
- Data Layer

The main challenge to clients and servers is to distribute these layers across different machines which is called the **Vertical Distribution**.

The simplest way to do so is to have only two-types of machines (2-Tiered "Dumb Terminal"):
- A client machine (this contains only the user-interface level)
- A server machine

You can also have a similar setup (2-Tiered "Fat client"):
- A client machine (runs the the user interface *and* the Processing logic only contacts the server when it needs to retrieve or save something to the Data Layer.)

![[Pasted image 20260420114717.png#invert|400]]

A server may sometimes need to act as a client, typically leading to a physically three-tiered architecture.
The most famous setup is the three-tiered architecture, the code is split across three entirely separate machines:
- **Tier 1:** The user's laptop (runs the User Interface).
- **Tier 2:** An application server (runs the Processing logic). It acts as a server to the user, but acts as a _client_ to the database.
- **Tier 3:** A dedicated database server (runs the Data layer)

## Decentralised System Architecture

![[Pasted image 20260420121751.png#invert]]
In Decentralised Architectures, there is a bigger shift towards distributing client and server functionality **more evenly** across machines to achieve better workload balance.
To achieve this we utilise **Horizontal Distribution** (as opposed to **Vertical Distribution)**: You split up the workload/data and each machine has the exact same capabilities.

In a **Centralised Architecture** a Client asks and a Server replies, in a P2P system, that is removed.
- **Classic Example (BitTorrent):** When you download a file via BitTorrent, your computer asks other peers for pieces of the file (acting as a **client**). At the exact same time, your computer is uploading the pieces you already have to other people who are asking for them (acting as a **server**).
This behaviour can be defined as **Symmetric Behaviour (Everyone is equal)**.

Due to the **Symmetric Behaviour** of processes in peer-to-peer architectures, processes are organised in **Overlay Networks**:
- A virtual network is placed on top of the physical one, 
- 
