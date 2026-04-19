19-04-2026 16:51

Tags: [[Distributed Systems]]

One way to distinguish between distributed systems in on the organisation of their **software components** and how they interact. This refers to their software architecture.

Here are types:
- **Centralised Architectures**: traditional client-server - single server implements most of the software components (and thus functionality)
- **Decentralised Architectures**: peer-to-peer architectures in which all nodes more or less play equal roles
- **Hybrid Architectures**: combining elements from centralised and decentralised architectures.

*"The final instantiation of the software components of a distributed system is what we call **system architecture***"

## Software Architectural Styles

A software architectural style is formulated in terms of **components**: how the components are connected to each other, the data exchanged between components and how these elements are configured *jointly* within a system.

***Component**: A modular unit, with well-required and provided interfaces that is replaceable within its environment*

A **connector** is a mechanism that mediates communication or cooperation amongst components - it allows for the flow of control and data between components.

### Layered Architectural Style

![[Pasted image 20260419172051.png#invert|400]]

Components are organised in a layered fashion, where components at the level $L_j$ request downwards to components $L_i$ where $i \lt j$. Requests go downwards and responses go upwards.
This is similar to a corporate hierarchy.

An example of this is **networking**, the web browser doesn't know how to send electrical signals over Wi-Fi, it just hands requests down to the Operating System layer which then hands it over to the physical hardware.
### Object-Based Architectural Style

![[Pasted image 20260419175829.png#invert|400]]


> [!Note] Object
>  **Object**: An object is a self-contained unit that holds both its own data (state) and the functions needed to manipulate that data (methods).

***Object:** An object is a self-contained unit that holds both its own data (state) and the functions needed to manipulate that data (methods).*

This provides a way of **encapsulating** data and the operations that can be performed on that data into a **single entity**.

Objects communicate by calling each other's methods. If object A needs data from Object B, it just calls `ObjectB.getData()`.

A normal program will have all the objects in memory but  in a **Distributed System** these objects may be split over a network on different 


### Resource-Centred Architectural Style


### Event-Based Architectural Style





