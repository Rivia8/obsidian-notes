14-12-2025 17:08

Tags: [[Database Systems]]

# MongoDB

**MongoDB** is a general purpose, document-based, distributed database built for modern application developers and for the cloud era.

**MongoDB** is developed by **MongoDB Inc** and licensed under the Server Side Public License (SSPL).

**MongoDB** is very popular.

## Terms and Concepts

When it comes to the key concepts from regular SQL and MongoDB some are the same but other things are different:

![[Pasted image 20251214171431.png#invert]]

In MongoDB, **database** holds **collection** of documents which are in **JSON-style** (JavaScript Object Notation Style) format.

![[Pasted image 20251214171549.png#invert]]
In the image above, you can see a table represented in regular SQL and then the same table but as a **collection** in MongoDB.

## Use and Creation

MongoDB is a lot different than say MySQL. In MySQL, you essentially write a string of text (SQL) that describes what you want. MongoDB is different, it doesn't use a string-based language, instead, it uses an **API-Based** approach often called **MQL (MongoDB 
Query Language).**

In MySQL, you use the DDL, to create tables and the structure ***beforehand***, in MongoDB, you do **not** need to do the same thing. If the collection doesn't exist, MongoDB creates it for you **instantly** - this is called **implicit creation**.

```SQL
-- Step 1: Define the table (Required)
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    role VARCHAR(50),
    age INT
);

-- Step 2: Insert data
INSERT INTO users (name, role, age) 
VALUES ('Alice', 'Admin', 29);
```

This is how it is for MongoDB:

```JavaScript
// Step 1: There is no Step 1.

// Step 2: Insert data into a collection named 'users'
// If 'users' doesn't exist, Mongo creates it now.
db.users.insertOne({
    name: "Alice",
    role: "Admin",
    age: 29
});
```

MongoDB uses a Binary-encoded serialisation of JSON-**like** documents, it actually stores data in a format called [[MongoDB Document|BSON]].

## MongoDB CRUD Operations

*Remember: **CRUD** is a fundamental acronym that stands for Create, Read, Update and Delete. These are the four basic functions needed to manage persist data in any system.*

| **Operation** | **SQL Command** | **MongoDB Method**                           |
| ------------- | --------------- | -------------------------------------------- |
| **C**reate    | `INSERT`        | `db.collection.insertOne()` / `insertMany()` |
| **R**ead      | `SELECT`        | `db.collection.find()` / `findOne()`         |
| **U**pdate    | `UPDATE`        | `db.collection.updateOne()` / `updateMany()` |
| **D**elete    | `DELETE`        | `db.collection.deleteOne()` / `deleteMany()` |
### Create (Insert)

You don't need to "create" table first, inserting data automatically creates the collection.

```JavaScript
// Inserting a single user
db.users.insertOne({ 
    name: "John Doe", 
    age: 30, 
    status: "active" 
});
```

`insertMany([{...}, {...}])` adds an array of multiple documents.

### Read (Find)

Read operations allow you to retrieve documents from a collection:
- `find(filter)`: returns all documents that match the filter. Using `find({})` to get everything.
- `FindOne(filter)`: returns only the first document that matches the criteria.

```JavaScript
// SQL: SELECT * FROM users WHERE age > 25;
db.users.find({ 
    age: { $gt: 25 } 
});
```

### Update (Modify)

Updating in MongoDB usually requires an "Update [[MongoDB#Query Operators|Operator]]" like `$set` to tell the database exactly what to change without overwriting the entire document. 
- `updateOne(filter, update)`: Modifies the first document that matches
- `updateMnay(filter, update)`: Modifies all documents that matches

```JavaScript
// SQL: UPDATE users SET status = 'pending' WHERE name = 'John Doe';
db.users.updateOne(
    { name: "John Doe" },      // The filter (Who to find)
    { $set: { status: "pending" } } // The update (What to change)
);
```

### Delete (Remove)

These methods remove documents permanently.
- `deleteOne(filter)`: Removes the first document that matches.
- `deleteMany(filter)`: Removes all documents matching the filter.

```JavaScript
// SQL: DELETE FROM users WHERE status = 'inactive';
db.users.deleteMany({ status: "inactive" });
```


## Query Operators:

![[Pasted image 20251214210519.png#invert]]