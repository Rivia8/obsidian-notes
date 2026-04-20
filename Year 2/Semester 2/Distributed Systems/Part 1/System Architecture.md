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
- The networks nodes are formed by the processes and its links represents communication channels with other nodes.

Two types of overlay networks exist, characterising peer-to-peer systems as: 
- Structured
- Unstructured

### Structured P2P Systems

Nodes are organised in an overlay that adheres to a **specific**, **deterministic** **topology**: a ring, a binary tree, a grid etc.
The topology is used to efficiently look up data that is maintained by the system.

When an item (a file) is added to the system, the data is ran through a mathematical formula called a **hash function** which outputs a unique ID number (a key). The key is then used as an **index** since it identifies a node in the system.

Because the network is arranged in a strict manner, it allows for **Deterministic Routing**. Every node is assigned a range of keys to look after, if you are searching for a file with the key `14` the network's geometry allows your request to take the most direct, efficient path straight to the exact node holding `14`.

### Unstructured P2P Systems

![[Pasted image 20260420124322.png#invert]]

In an unstructured system, there is no mathematical shape. Nodes are just connected to whichever other nodes they happen to find. Each node maintains an **ad hoc list of neighbours**. When a node joins it will contact a well-known node to get a starting list of other peers in the system and this list can be used to find more peers and ignore others etc - a node generally changes its **local list almost continuously**.

Looking up data cannot follow a pre-determined route, so instead searching for data is necessary.

#### Searching Method: Flooding

An issuing node $u$ will pass a request of data to its list of neighbours, if *they* don't have the file, the original nodes neighbours will pass the request to their neighbours etc.

It is fast and guarantees you will find the file if it exists. However, it is **disastrous** and **overwhelming** for the network since it creates a tsunami of duplicate messages that can crash the system.

As a fix, you can implement **TTL** (**Time to Live**), what this does is is stops a request from bouncing around the network for a long and sets a limit to the number of bounces e.g. 5 so after 5 bounces, the 5th node will just delete it instead of passing it on, killing the flood.

#### Searching Method: Random Walks

An issuer $u$ will pass the request to *one* of its neighbours $v$ who then passes it to *one* of **its** neighbours etc. until the file is found.

This generates very little network traffic but is very slow because the "walker" might wander in the completely wrong direction.

To fix it, you can have 3 or 4 separate 'walks' that each go in different directions to speed it up, this in turn increases traffic and will need a **TTL** so they expire.

### Making Data Search More Scalable in Unstructured P2P Systems

We can make use of **Hybrid Architectures** in order to fix the problems that Client-Server and P2P networks face:
- Scalability problems of unstructured P2P systems,
- Workload balancing in traditional client-server architectures

#### Abandoning Symmetry

You can make use of special nodes that maintain and index of data items which abandons the **symmetric nature**.
The **special nodes** often called **super nodes** are connected to normal nodes of whom want to find out where exactly is the file they want.

#### Collaborative Distributed Systems

![[Pasted image 20260420143009.png#invert]]

*BitTorrent* is the ultimate example of Hybrid Architecture because it splits the process into two distinct phases, one centralised and the other decentralised.

1. You first download a small `.torrent` file that holds the list of IP addresses of all the other active users currently download or uploading that specific file.
2. Once the tracker gives you a list of peers, the centralised part is over, your computer establishes direct TCP connection with those other users, you begin downloading different "chunks" of the file from them whilst simultaneously uploading the chunks you already have to others.

With this method, the central tracker never gets overwhelmed.

#### Edge-Server Systems

![[Pasted image 20260420143418.png#invert|400]]

These have the following properties:
- Are deployed on the internet,
- Their servers are placed "at the edge" of the network

If an **Origin Server** of a website is very far away, it will use its **Edge Servers** that are placed all over the world where the high-demand content are replicated on these servers to mitigate latency from the **Origin Server**.

If you are accessing content from **California** it may have an edge server in **London** that you will be redirected for the in high demand content.

**Fog Computing:** This is where even the end-user devices from part of the system and are used as a miniature, decentralised extension of the cloud.




