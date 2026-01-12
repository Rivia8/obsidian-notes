18-10-2025 14:31

Tags:

# ER Modelling

**Entity-Relationship modelling** is a graphical approach to database design.
It is a conceptual blueprint that shows how different pieces of information are related to each other.

Its kind of like an architectural design plan for a database, before you build a house, you draw the blueprint showing the room (entities), the features of the rooms (attributes) and the hallways/doors that connect them (relationships).

 **Phases of Database Design:**

![[Pasted image 20251018165401.png#invert|800]]


We have to create a conceptual model and the requirements for the conceptual to create a logical model.
A **conceptual model** is the main outcome of the conceptual design phase.
Our end goal is what to have a well-defined ER model that can be directly translated into the actual database structure.

![[Pasted image 20251018143821.png#invert|800]]
This is an example of a conceptual model , from here we go to a logical model:

![[Pasted image 20251018143911.png#invert|600]]

An ER model has 3 main concepts:

1. **Entities**,
These are the things you want to store data about, typically they are nouns.

2. **Attributes**,
These are the properties or characteries of an entity, they are specific details you want to save.

![[Pasted image 20251018144337.png#invert|400]]


3. **Relationships**.
These how two or more entities are connected or associated with each other, relationships are typically verbs.
An example of this would be: A `Student` **enrols** in `Course`,  An `Employee` **works** in a `Department`

![[Pasted image 20251018165629.png#invert|800]]
The asterisk here in this example highlights the fact that the 'alias' is used as the unique identifier.

### Cardinality Constraints and Notations

When we have relationships, we may need to have some sort of **constraints**, an example could be in 'Customer' -> 'Order' relationship: A customer can have many or zero orders, but an order can only belong to **one** customer.

When we have tables for these entities the best thing to do to indicate cardinality is to annotate the relationship line:

![[Pasted image 20251018170422.png#invert|800]]

The image above we have is known as **Crow's foot diagram** (there are different types of ER diagram like the Chen diagram).

![[Pasted image 20251018170547.png#invert|800]]



## Keys

In ER modelling, a **key constraint** holds, this refers to an attribute used to **uniquely identify** a specific entity instance. It can be thought similarly to an ID number.

There are different types of keys, but the main ones are the:

1. Primary Key
This is the most important key, this is usually the main unique identifier of a key.

2. Foreign Key
This is the key that builds the relationship, this is the attribute in one entity that is the **primary** of another.

3. Candidate Key
A candidate key is any attribute that _could_ be used as the primary key. An entity might have several candidate keys.
4. Composite Key
This is a primary key that is **made up of two or more attributes** combined. This is used when one attribute alone isn't enough to uniquely identify a record.
5. Super Key
This is a more technical term. A super key is any set of attributes that can uniquely identify a record. A super key might contain _extra, unnecessary_ attributes.


### Weak Entity

This is an entity that cannot be uniquely identified by its own attributes alone, it *depends* on a relationship with another entity (called the **strong/owner** entity) to get its full identity.

think of it this way:
- A **strong entity** is like a `Building`. It has its own unique primary key (like `Building_Address` or `Building_ID`) and can exist on its own.
- A **weak entity** is like an `Apartment`. An `Apartment` is identified by its `Apt_Number` (e.g., "3B"), but this number is only unique _within_ its building. There are thousands of "3B" apartments in the world.

![[Pasted image 20251018194402.png#invert|800]]

