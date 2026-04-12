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

This is a **hierarchy** of trust.
The authority to delegate names is delegated to **smaller parts of the system**.

This approach better balances the conflicting issues associated with single points of **failure** and **scalability**. 

Blocks of names are handed out down the hierarchy of trust.
Certain rules are applied that are appropriate for each system:
- A rule could state that every device in an organisation has to have a name that includes the name of the organisation,
- Every device in a particular country has to have a name that includes the name of the country 

#### MAC Addresses

The Media Access Control address is a unique identifier that is given to each *network* device in a system.
The MAC address is a 48-bit number that is assigned to every wifi-enabled device.

The way the delegation works for this is that the IEEE (a global org) sell 24-bit blocks (this is called the **OUI**) to a manufacturer (e.g. Apple) and then Apple has sole authority over their 24-bit block. Apple then has to make sure that they don't print the exact same second half on two different Wi-Fi chips.

#### IP Addresses

The **IANA** delegates ranges of IP addresses to five **Regional Internet Registries** which in turn delegate sub ranges of their space to internet service providers.

#### Domain Names

Domain names were created since its hard for humans to read and remember IP addresses.
The Domain Name System (DNS) is itself a distribute system built on top of the Internet, used to create associations between human-readable names and IP addresses.




