20-04-2026 11:02

Tags: [[Distributed Systems]]

A **software architectural style** is formulated in terms of **components**: how the components are connected to each other, the data exchanged between components and how these elements are configured *jointly* within a system.

***Component**: A modular unit, with well-required and provided interfaces that is replaceable within its environment*

A **connector** is a mechanism that mediates communication or cooperation amongst components - it allows for the flow of control and data between components.

## Layered Architectural Style

![[Pasted image 20260419172051.png#invert|400]]

Components are organised in a layered fashion, where components at the level $L_j$ request downwards to components $L_i$ where $i \lt j$. Requests go downwards and responses go upwards.
This is similar to a corporate hierarchy.

An example of this is **networking**, the web browser doesn't know how to send electrical signals over Wi-Fi, it just hands requests down to the Operating System layer which then hands it over to the physical hardware.
## Object-Based Architectural Style

![[Pasted image 20260419175829.png#invert|400]]


> [!Note] Object
>  **Object**: An object is a self-contained unit that holds both its own data (state) and the functions needed to manipulate that data (methods).


This way provides a way of **encapsulating** data and the operations that can be performed on that data into a **single entity**.
Objects communicate by calling each other's methods. If object A needs data from Object B, it just calls `ObjectB.getData()`.

A normal program will have all the objects in memory but  in a **Distributed System** these objects may be split over a network on different  devices.
This is where **Remote Procedure Calls** **(RPC)**  comes into place. RPC is the *connector* (type of middleware) that makes calling a method on a computer 200 miles away look and act like calling a method on your machine.

## Resource-Centred Architectural Style

![[Pasted image 20260420103805.png#invert|500]]

Instead of viewing a **distributed** **system** as a collection of functions or objects, this style views the system as a giant warehouse of **data resources** (like user profiles, images, or documents). Everything is treated as a resource.

*This is widely adopted for the internet and websites, specifically how the HTTP protocol functions.*

The advantage of this is that it is simple and standardised. Any application can interact with the system as long as it knows how to request or modify the central resources.

## Event-Based Architectural Style

![[Pasted image 20260420104531.png#invert|400]]


This style abandons point-to-point communication.
Instead of **System A** directly calling **System B** they communicate through a **Publish/Subscribe** **(Pub/Sub)** model where **publishing**  is describing the occurrence of an event.

Processes running on the various components are both **Referentially Decoupled** and **Temporally Coupled**.

**Referentially Decoupled**: This means that "System A does not know System B exists".
**Temporally Coupled**: Since components are "shouting into the void", they both must be active and running at the exact same time, or else the service may miss a message.

The advantage is that you can easily add or remove components without breaking the system.
-  If you want to add a brand-new analytics service to track video uploads, you don't  have to rewrite the upload service's code, you can just tell the new analytics service to **subscribe** to existing events.