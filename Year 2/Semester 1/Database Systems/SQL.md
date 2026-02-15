06-10-2025 15:36

Tags: [[Database Systems]]

# SQL

SQL comes from the "Sequel" (Structured English QUEry Language) 
This is a standard programming language for storing and processing information in a relational [[Databases|database]].
It lets your access and manipulate databases.

What can SQL Do?
- Execute queries against a database,
- Can retrieve data from a database, 
- Insert, update, delete, and create new records in a database,

## Using SQL

In order to use SQL to show data from a database in a web-app, you will need:
- An RDBMS database program,
- Use a server-side scripting language, like PHP or ASP, 
- To use SQL to get the data you want, 
- To use HTML/CSS to style the page.

*RDBMS stands for Relational Database Managment Systems.*


# Basic SQL Usage

## 1. DDL (Data Definition Language)

**Purpose:** To build and define the database structure (your "schema").

This is what you use to translate your PDM diagram into actual database tables.

### `CREATE TABLE`

This is the most important DDL command. It builds a new table.

**Example:**

```SQL
CREATE TABLE Employee (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    nin VARCHAR(9) NOT NULL UNIQUE,
    department_id INT,
    
    -- This line creates the relationship (the line on your diagram)
    FOREIGN KEY (department_id) REFERENCES Department(department_id)
);
```

**What this does:**

- `employee_id INT PRIMARY KEY`: Creates an integer column named `employee_id` and makes it the primary key.
    
- `first_name VARCHAR(100) NOT NULL`: Creates a text column that cannot be empty.
    
- `email VARCHAR(255) NOT NULL UNIQUE`: Creates a text column that cannot be empty _and_ ensures no two employees can have the same email.
    
- `FOREIGN KEY (department_id) REFERENCES Department(department_id)`: This is the magic. It creates the link to the `Department` table. The database will now reject any `employee` if their `department_id` doesn't already exist in the `Department` table.

### `ALTER TABLE`

**Purpose:** To modify an existing table (e.g., add or remove a column).

**Example:** You forgot to add the `salary` column to your `Employee` table.

```SQL
ALTER TABLE Employee
ADD COLUMN salary DECIMAL(10, 2);
```

### `DROP TABLE`

**Purpose:** To completely delete a table and all its data.

**Example:**

```SQL
DROP TABLE LeaveRequest;
```

## 2. DML (Data Manipulation Language)

**Purpose:** To manage the data _inside_ the tables. This is how you create, update, and delete rows.

### `INSERT INTO`

**Purpose:** To add a new row of data.

**Example:** Let's add a new department to your `Department` table.

```SQL
INSERT INTO Department (department_id, department_name, location_id, manager_id)
VALUES (1, 'Technology', 4, 15309112);
```

_(This assumes a location with `location_id` 4 and an employee with `manager_id` 15309112 already exist)_

### `UPDATE`

**Purpose:** To modify data that is already in a table.

**Example:** Your `Product` with ID `eac7efa5` has a new price.

```SQL
UPDATE Product
SET price = 17.99
WHERE product_id = 'eac7efa5';
```

- `SET price = 17.99`: This is the new value.
    
- `WHERE product_id = 'eac7efa5'`: This is the _most important part_. It specifies _which row(s)_ to update. If you forget the `WHERE` clause, you will change the price of **every single product in your database**.
    

### `DELETE FROM`

**Purpose:** To remove a row of data.

**Example:** A customer with ID `b17540ef` has cancelled their account.

```SQL
DELETE FROM Customer
WHERE customer_id = 'b17540ef';
```

- Just like `UPDATE`, the `WHERE` clause is critical. If you forget it, you will delete **all customers**.

## 3. DQL (Data Query Language)

**Purpose:** To get data _out_ of the database. This is the `SELECT` statement, which you will use the most.

### `SELECT` (The basic query)

**Purpose:** To retrieve columns from a table.

**Example 1: Get specific columns** "I need the names and prices of all products."

```SQL
SELECT product_name, price
FROM Product;
```

**Example 2: Get all columns** "Show me everything you know about employees."

```SQL
SELECT *
FROM Employee;
```

### `WHERE` (Filtering data)

**Purpose:** To specify _which rows_ you want.

**Example:** "Get the names of all employees in the 'Operations' department (let's assume its ID is 2)."

```SQL
SELECT first_name, last_name
FROM Employee
WHERE department_id = 2;
```

### `JOIN` (The power of the Relational Model)

**Purpose:** To combine data from two or more tables based on their relationship. This is where your `FK` and `PK` links become powerful.

**Example:** "I want to see the `first_name` of each employee _and_ their `department_name`." (The name is in `Employee`, the department name is in `Department`).

```SQL
SELECT 
    Employee.first_name,
    Department.department_name
FROM 
    Employee
JOIN 
    Department ON Employee.department_id = Department.department_id;
```

- `JOIN Department`: Tells SQL which table to connect.
    
- `ON Employee.department_id = Department.department_id`: This is the "bridge". It tells SQL _how_ the tables are related, using the exact PK-FK link you defined in your PDM.

## Other

There are other things that you need to know to fully get by with SQL and just databases in general:
1. [[Null]]
2. [[Nested Queries]]
3. [[Views]]
4. [[Stored Procedures]]