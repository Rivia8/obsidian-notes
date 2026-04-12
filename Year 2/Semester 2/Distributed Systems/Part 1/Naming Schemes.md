12-04-2026 08:36

Tags: [[Distributed Systems]]

## Identifying Entities

In distributed systems, names are used to **uniquely identify** entities.
An entity can be almost anything, a **process**, a **database table** etc

Because entities are constantly interacting with each other across a network, they need reliable **identifiers**. 

## Name Resolution

*"A name resolution can be resolved to the entity it refers to... the means by which a process is allowed to access a named entity"*

**Name Resolution** is the translation process, it converts human friendly names into something that the network can actually use.

### Centralised Naming Approach

One single central "authority" (usually a server). 
When an entity joins, it must contact the central server and it verifies that the name the entity  wants isn't already taken, or it generates a brand-new unique name and hands it over.

**Advantage:**
- Absolute certain, you are 100% guaranteed that no two entities in your system will ever have the same name

**Disadvantage:**
- If lots of entities try to join, the single server will be overwhelmed and crash. It cannot scale to the size of the something big (like the internet)

### Free-for-All Naming Approach

With this approach, there is no central authority. 
When an entity joins, it generates its own name locally without asking a server for permission.

**Advantage:**
- This is infinitely scalable

**Disadvantage:**
- **No guarantee of uniqueness** and so there will be a massive risk of collision.


### Delegating Naming Responsibilities

 





