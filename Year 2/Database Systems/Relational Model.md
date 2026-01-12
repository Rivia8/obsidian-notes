20-10-2025 11:01

Tags: [[Database Systems]]

# Relational Model

This is one of the models used by a type of [[Database Management Systems|DBMS]] whereby a relational model is a way of logically organising data in a database.

The main idea is to store data in simple two-dimensional tables called **relations.**

![[Pasted image 20251020110513.png#invert|800]]

The part that makes it relational is the use of [[Keys|keys]] to create logical relationships.
For example in the table above, the primary key would be the `stuid`.

## Database Schema

The Database Schema is **the formal definition that describes the entire structure of the database.**

![[Pasted image 20251020114303.png#invert|800]]

The Relational Model that we have been describing here is the *theory* or *method* of organising data into tables with keys, where the **Schema** is the *specific* application of that theory for one particular database.
In order to implement a schema with a [[Database Management Systems|DBMS]] you use a [[Database Languages|DDL]] usually [[SQL]].

For example this SQL code defines a piece of Schema:

```SQL
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    FirstName VARCHAR(100) NOT NULL,
    Email VARCHAR(100) UNIQUE
);
```

This code is the "blueprint" (schema) that tells the DBMS to build a table named `Student` with three columns, each having specific data types and constraints (a `PRIMARY KEY`, a `NOT NULL` rule, and a `UNIQUE` rule).

The [[Database Management Systems|DBMS]] will automatically employ integrity constraints:
- Prevent you from setting a PK to NULL,
- Prevent you from trying to having two PKs with the same value in the same table,
- Prevent a parent's FK having a value which does not occur in the child table,


