26-12-2025 19:44

Tags: [[Database Systems]]

# Couchbase

**Couchbase** is a distributed [[NoSQL]] cloud database designed for modern applications that require high performance, flexibility and scalability. It combines the flexibility of a document database with the power of SQL-like querying, making it easier for developers familiar with relational databases adapt.

You can use it for:
- NoSQL Database, 
- Search Engine, 
- Key-Value,
- Cache

It stores data as **JSON documents** rather than rows and columns, this means you don't need a rigid schema. What this means is that you change the structure of the data on the fly.

The main selling point of Couchbase is that its query language **N1QL** allows you to write complex queries using standard SQL syntax (SELECT, FROM, WHERE)
**N1QL** isn't just SQL like, its **SQL92 Compatible**. What this means that you can have the exact same queries in SQL and N1QL and it work flawlessly.

```SQL
-- 1. Start the transaction
BEGIN TRANSACTION;

-- 2. Perform operations (across different documents/buckets)
UPDATE `orders` SET status = "shipped" WHERE id = 101;
INSERT INTO `logs` (VALUES (UUID(), "Order 101 shipped"));

-- 3. Save changes
COMMIT TRANSACTION;
-- OR, if something goes wrong:
-- ROLLBACK TRANSACTION;
```


Unlike traditional RDBMS that often rely on a central transaction coordinator, Couchbase uses a **decentralised, client-driven** approach. 

## Key Value & Data Services

Key-Value (KV) operations is the method you use within data services.

The Data Service is the most critical component, it is the only service that is strictly mandatory.
Its primary job is to store and retrieve documents in memory and on disk. 
It does not store data in a traditional **Slave** and **Master** relationship like traditional DBMSs, but instead shares evenly across all nodes running the data service using **vBuckets.**
The Data Service manages the "Managed Cache", it keeps active "hot" documents in RAM for instant access and seamlessly ejects older, "cold" data to disk if memory fills up.

While you can use N1QL or SQL to query the database, deep down, Couchbase is a **key-value** store, every single document has a unique ID which is the key.
KV operations allow you to interact directly with the data service using that specific ID.

### Shard Keys

A Shard Key is the specific piece of data used to decide which server a specific document should be stored on. Data can be resharded but its quite expensive. 
But how do you know where the data is clustered?: You can have a Master/Slave architecture of a cluster.
- Master limits scalability,
- There is a single point of failure.
There is a fixed number of shards, **1024**. This limits the maximum number of nodes a cluster can have to 1024.

When you have a document with ID like `user:123`, Couchbase will calculate its location in three steps:
1. Hash the key by running it through CRC32,
2. Map to vbucket - 1024 fixed slots or folders, every document is mathematically guaranteed to belong to exactly one.
3. Map to node - the cluster maintains a map that says "vbucket 1 is on server A".

## Understanding Terminology

A **node** is a simply one physical computer (or one server).
