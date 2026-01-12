13-10-2025 18:48

Tags: [[Database Systems]]

# Database Languages

Database languages are specialised programming languages used to interact with and manage databases. They are the communication bridge between the developer and the database, allowing the developer to define the database, manipulate the data it holds and control who has access to it.

There are three different kinds of DB languages.

1. **DDL: Data definition language.**

This language is used to create the database, tables and alter them, etc. It specifies the database *schema*, meaning it is used to create, modify and delete database objects like tables, indexes and schemas (the DDL builds the blueprint of your database).

The DDL statements include:
- **CREATE:** Crate new database, table, etc.
- **ALTER:** Alter existing database, table,
- **DROP:** Drop the database,
- **RENAME:** Set a new name for the table.

2. **DML: Data Manipulation Language.**

This is used to interact with the data, within the database. Once you have your database structure defined with the DDL you use DML to add, update and delete actual information.

The DML statements include:
- **INSERT:** Insert data,
- **UPDATE**: Update all the data,
- **DELETE:** Delete all records.

3. **(D)QL:  Data Query Language**

This returns the results without altering the database.

In practice this distinction is not often enforced:
![[Pasted image 20251013185811.png#invert|800]]





