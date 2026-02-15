04-11-2025 16:26

Tags: [[Database Systems]]

# Null

`NULL` is a special marker in SQL that is used to indicate that a value does not exist in the database.

It is not a value, but rather a state of being. It is very important to understand that `NULL` is **not**:
1. `0`,
2. `""`  - an empty string
3. `" "` -  a space.

One thing to note is that Primary Keys can never be `NULL`.

## How to work with `NULL`

When it comes to working with `NULL` you can't use the simple comparison operands. This is because `NULL` just means 'unknown', there are special operators that you use instead:

You **must** use special operators:
- `IS NULL`
- `IS NOT NULL`

**Example:** "Find all employees who are _not_ assigned to a department." (This could be your CEO, Elon Bazos).

```SQL
SELECT first_name, last_name
FROM Employee
WHERE department_id IS NULL;
```

**Example 2:** "Find all employees who _are_ assigned to a department."

```SQL
SELECT first_name, last_name
FROM Employee
WHERE department_id IS NOT NULL;
```

## 3-Valued Logic

In general logic we have `true` and `false`. However, in SQL we also have `UNKNOWN`.

![[Pasted image 20251104163430.png#invert|800]]
