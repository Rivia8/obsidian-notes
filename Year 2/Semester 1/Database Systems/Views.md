05-11-2025 16:32

Tags: [[Database Systems]]

# Views

A **View** is a query that pretends to be a table. 
It is a virtual table that's contents are made from the `SELECT` query.

You can add SQL statements and functions to a view and present the data as if the data were coming from one single table.

## Create View Syntax:

```SQL
CREATE VIEW _view_name_ AS  
SELECT _column1_, _column2_, ...  
FROM _table_name_  
WHERE _condition_;
```

Let's look at a more specific example:

```SQL
CREATE VIEW EmployeeLocation AS
SELECT 
    e.employee_id,
    e.first_name,
    e.last_name,
    e.position,
    d.department_name,
    l.location_name,
    l.address AS office_address
FROM 
    Employee AS e
JOIN 
    Department AS d ON e.department_id = d.department_id
JOIN 
    Location AS l ON d.location_id = l.location_id;
```

So now in the database we have a virtual table that is called `EnployeeLocation`.

So now instead of doing a complex 3-table join we can use the virtual table we just created:
*"Show me all employees who work at the 'Kilburnazon Head Office'."*
The query for said  question would be:

```SQL
SELECT first_name, position
FROM EmployeeLocation
WHERE location_name = 'Kilburnazon Head Office';
```

## Why are Views Useful

1. They induce **simplicity:** once you have created the view, it will hide complex joins and calculations, this makes it much easier for analysts to get information.
2. It allows for **security**: views are a powerful security tool, you can give people permission to access views but not the underlying table, to do this you would implement a 'safe' view.

Here is an example of the *safe* view:

```SQL
CREATE VIEW SafeEmployeeDirectory AS
SELECT
	employee_id,
	first_name,
	last_name,
	position,
	department_id,
FROM
	Employee;
```

So here we have selected certain fields from the `Employee` table but some fields have been left out (`salary`, `dob`, `nin` and `home_address`) because they are sensitive and confidential. This allows for maybe someone with a 'lower access level' to be able to still handle the information they need.
