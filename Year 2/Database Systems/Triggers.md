05-11-2025 17:06

Tags: [[Database Systems]]

# Triggers

A trigger is a stored program that is invoked automatically in response to an event.
Triggers are similar to `if-else` statements in other programming languages - **if** a certain condition is fulfilled **then** the trigger automatically fires and runs code to `UPDATE` the `AVG_REVIEW_RATING` in the `Product` table.

Triggers are the "automation" layer of a database, they are "event-driven" meaning they don't run until you do something to "trigger" them.

## Components of a Trigger

A trigger is defined by three main things:
1. **Event**: The DML action
	- `INSERT`
	- `UPDATE`
	- `DELETE`
2. **Timing:** When the trigger should fire.
	- `BEFORE` the event happens
	- `AFTER` the event has completed
3. **Target**: The table the trigger is 'listening' to.

When it comes to whether to use `BEFORE` or `AFTER` triggers, this entirely depends on what you want to do:
`BEFORE` triggers are useful to update or validate record values before they're saved to the database. 

`AFTER` triggers are use to access field values that are set by the system and to affect changes in other records.

You can also call multiple triggers by using the keywords `FOLLOWS` or `PRECEDES`. 
- `FOLLOWS`: allows the new trigger to activate after an existing trigger,
- `PRECEDES`: allows the new trigger to activate before an existing trigger.
## Why Use Triggers

Triggers are used to enforce complex business logic and automation that a simple `CHECK` or `NOT NULL` constraint can't handle.

An example could be as follows:
- **Problem:** Your `Product` table has `NUM_REVIEWS` and `AVG_REVIEW_RATING`. This is derived data. How do you keep it up-to-date?
- **Solution:** A trigger.
- **The Trigger:**
    - **Name:** `trg_update_product_rating`
    - **Event:** `AFTER INSERT`
    - **Target:** `ON "Review"`
    - **Action (What it does):** When a new review is inserted, this trigger fires. It gets the `product_id` from the newly inserted review. It then runs a query like `SELECT COUNT(*), AVG(rating) FROM Review WHERE product_id = ...` and immediately `UPDATE`s the correct row in the `Product` table with these new values.

This way, your product ratings are _always_ in sync, automatically.

## Pros V Cons

Some Pros are as follows:
- **Automation**
- **Data Integrity**
- **Consistency**

Some Cons are as follows:
- '**Invisible logic**': A developer might run a simple `INSERT` and have no idea a complex trigger is running in the background.
- **Performance**: A trigger adds work to the DML statements, this can slow down the database if the triggers are written poorly
- **Complexity:** One trigger can fire another and another... and so on - this is called a "cascading trigger" and is extremely difficult to manage.



