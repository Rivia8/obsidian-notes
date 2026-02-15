20-10-2025 11:14

Tags: [[Database Systems]]

# Keys

A key is an attribute used to:
1. Uniquely identify a row in a table,
2. Create relationships between tables,

There are three (main) types of key:
- Primary Key
- Candidate Key
- Foreign Key

We have seen keys before when looking at [[EER Modelling]], the way they link is that from an EER model you then create  a relational model, which is the technical implementation based on the blueprint (the EER model).

## Primary Key

**This uniquely identifies a row in a table**, usually within a table the primary key is underlined
![[Pasted image 20251020112316.png#invert|600]]


### Choosing a Primary Key

When you have to choose a PK, there are often some 'guidelines' that you should take but firstly the PK **must** have unique values and can **never** have a null value. 
It should be simple, if possible for it not to be a set and is best for it to be numbers and not a string.


## Candidate Key

This is a set of attributes that can **uniquely identify a row**.

![[Pasted image 20251020112451.png#invert]]

So the candidate key are attributes (one or more) that can be the primary key.

## Foreign Keys

Foreign keys (FKs) are the most important part, This describes the **relationship** between two entities like Student and Tutor:

![[Pasted image 20251020113114.png#invert|800]]

**The foreign key of a table is the PK of another table.**

