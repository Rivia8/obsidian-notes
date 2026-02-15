13-10-2025 19:01

Tags: [[Database Systems]]

# Database Management Systems

A **Database Management System (DBMS)** is a software that allows you to create, manage, and interact with databases.

It's like an intermediary or an operating system for your data, it's pretty much something like Microsoft Excel but for Databases instead of spreadsheets.

**(In the course-unit we use MySQL as our database and the DBMS is MySQL Workbench).**

How it all fits:
'**SQL** is a programming language used to manipulate data. You use it to talk to a **DBMS** (like **MySQL**). Different **DBMSs** implement different data models; for instance, **MySQL** uses a relational model with a strict **schema**, while **MongoDB** uses a non-relational model with a flexible **schema** and requires a different language'

## Types of DBMSs

The types are categorised based on how they structure data, the main types include:

1. **Relational DBMS:** 

This is the most popular type of DBMS, it stores data in tables with rows and columns, similar to spreadsheets. The relationships between tables are clearly defined.
Examples: MySQL, PostgreSQL, Oracle Database etc.

2. **NoSQL DBMS**

These are non-relational databases that offer more flexibility in how databases are stored, they are great at handling large volumes of unstructured or semi-structured data. There are different types:
- **Document types:** Store data in JSON-like documents (e.g. MongoDB),
- **Key-Value Stores:** Store data as simple key-value pairs (e.g. Redis),
- **Column-Family Stores**,
- **Graph Databases**.

3. **Object-Orientated DBMS:**

This type stores the data in the form of objects, as used in OOP, less common overall, but useful for complex data types.

4. **Hierarchical DBMS:**

This model organises data in a tree-like structure with parent-child relationships, its an older model but still used in some legacy systems.

## Why do we need DBMS

- Its an extension of human logic,
- Computer can quickly answer a lot of questions of quickly, 
- Some questions can be really complicated, 
- People can be easily overwhelmed with information,
- Automation is the key of efficiency,
- A DBMS is better than manual processes in so many ways.

- Its hard and costly to engineer a new piece of software for a bespoke task.

A DBMS has at least the following functionality **CRUD** - Create, Read, Update and Delete.


![[Pasted image 20251013200932.png#invert|800]]

But *why* databases and not straight up just using files? One of the key points is that with an integrated database, a workforce that has many departments can access a unified and integrated database whilst still keeping security measures upheld. This means that if one of the departments want to access the same data that can happen whilst still having permissions upheld.

## Single User vs Multiuser Systems

One criteria of classifying a database system is the number of users that can access the database concurrently, 
- A DBMS is 'single user' if only one user at a time can use the system.
- A DBMS is multiuser if the system is accessed by multiple users at the same time (concurrently).

We mention the idea of **concurrency**, this is achieved through the concept of multiprogramming. Remember that a CPU can only process one process at a single time so how does *that* do multiple operations at the same time?: **time-slicing**, **context switching** etc. In Database Systems a similar approach is used called [[Transaction Processing#Interleaving|interleaving]].


