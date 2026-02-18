18-02-2026 13:55

Tags: [[Distributed Systems]]

# Introduction to Distributed Systems

A **Distributed System** has nodes and it relies on a **network**.
The network can be something like the internet or a proprietary system
*Relying on a network isn't a good thing,* 

Textbook definition of a **Distributed System:** 
"A Distributed System is a collection of autonomous computing elements that appears to its users as a single coherent system"

A computing element can be either a hardware or software process.

In Distributed Systems, nodes are programmed to achieve common goals and they do this by exchanging messages with each other. 
To appear to users as a single coherent system, **distribution transparency** is an important goal of distributed systems.

Examples of a Distributed System:
- Web over the internet,
- Mobile telecommunications,
- Banking

With Distributed Systems you can:
- Share Resources
- Bind customers and suppliers
- Allow us to things we could not normally do
	- We can employ the use of lots of machines to speed up processes and so reliability

This gives us:
- Higher reliability
- Scalability
- Faster cooperation
- Better performance

Distributed Systems vary in size and the way which nodes are connected (the topology).
Although nodes can act independently from one another, they cannot ignore one another.

Computation is **concurrent**, there is **no shared state** (no single global clock) and failures can occur which we may not be aware of.

Not taking the fact that components are distributed into account during design time is what makes many systems flawed.

[[1- Introduction to Distributed Systems.pdf#page=3|Look here for the rest of the content]]