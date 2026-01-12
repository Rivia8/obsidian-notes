13-10-2025 16:21

Tags: [[Database Systems]] 

# NoSQL

NoSQL, which stands for **"Not Only SQL"**, encompasses a wide variety of database technologies that were developed in response to the demands of modern web-scale applications. 
They are designed to handle large volumes of unstructured and semi-structured data.

It does not follow all of the rules of a relational database, typically very large databases which are prone to performance issues use this format and because of this many see this as the 'modern' database of choice.

Implementations include:
- [[MongoDB]]
- Facebook's Cassandra,
- Google's BigTable

NoSQL has different functions and different ways they are implemented. **MongoDB** is Document-based, Google's **BigTable** is column based and Amazon's **DynamoDB** is Key-value and column based as a few examples.

## Characteristics:

In terms of the characteristics related to the Distributed Database and Distributed Systems:

- Highly scalable,
- Available, replicable and has eventual consistency,
- High-performance data access.

Characteristics related to Data Models and Query Language:

- Doesn't require a schema (schemeless),
- Less powerful query language.

**Categories of NoSQL Systems:**

![[Pasted image 20251213205306.png#invert]]

## CAP Theorem

**Consistency:** implies all nodes should contain the same copies of replicated data item visible for various transactions.

**Availability:** implies that the system should be consistently available for read and write operations.

**Partition Tolerance:** implies that the system should be continually available in situations where the system is partitioned by network faults.

The CAP theorem states that is is not possible to guarantee all the desirable properties.

## NoSQL Database Design

When it comes to the database design there is a bit of a 'balancing act' that needs to happen:

![[Pasted image 20251214214251.png#invert]]

Collections in NoSQL (MongoDB) do not require document schema by default (SQL databases require a schema before data insertion). Data types for each field in a collection may differ across documents within the same collection.
Changing documents structure is as simple as updating the document directly.
*We **can** enforce a schema but isn't a necessity*.

NoSQL databases allow for both a normalised schema and **denormalised** schema.

![[Pasted image 20251214221505.png#invert]]
**Embedding** would be denormalisation, you add a document within a field.
**Referencing** is keeping a normalised structure, its like the SQL approach, you store the data in separate collisions and link them using an `_id`. 


![[Pasted image 20251214221546.png#invert]]

If you look at the example above, you can see that you can identify whether something is either one-to-many or one-to-one based on the brackets. 
If you look at `products` you can see that its a one-to-many just based on the fact that it holds an array of documents.
If you look at `contact` you can just see that it *doesn't* have any square brackets, highlighting that it just contains the one its own, making it a one-to-one relationship.

**Embedding** is advisable when:
- Related items are frequently used or fetched together,
- There is a one-to-one relationship between two documents,
- The document, that will be embedded, is not a key document
- Data does not change or does not grow much,
- Related documents have similar volatility.

**Referencing** is advisable when:
- Embedding would result in substantial data duplication,
- When embedded documents grow - it will be easier to manipulate a single document rather than going through a nested document,
- To present more complex 'many-to-many' relationships,
- The document will be embedded, is a key document
- Requirements for fast writes.


