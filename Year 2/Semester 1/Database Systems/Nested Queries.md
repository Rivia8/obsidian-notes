04-11-2025 16:37

Tags: [[Database Systems]]

# Nested Queries

A nested query is a query within a query, similar to how you have in programming a nested loop (a loop inside a loop).
The database runs the inner query first and then uses its results to run the outer query.
It's like asking a question that requires you to get a piece of information first.

The most common use is using the `WHERE IN` command:

```SQL
SELECT first_name, last_name
FROM Customer
WHERE customer_id IN (
    SELECT DISTINCT customer_id FROM "Order"
);
```

Here you can see that we are getting customer's first and last names where they have placed an order. The `SELECT DISTINCFT customer_id FROM "Order"` part is done first, the inner loop, and then the rest is done.

