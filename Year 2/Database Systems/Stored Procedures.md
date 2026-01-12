05-11-2025 18:00

Tags: [[Database Systems]]

# Stored Procedures

A **stored procedure** is very similar to `functions` in programming languages. A procedure is a set of SQL statements that are **stored** and **saved** *inside* the database. The statement gets a name and you then "call" and "execute" it by that name you defined.

Let's look at an example that is quite big but good to know and understand:

```SQL
CREATE PROCEDURE sp_CreateNewOrder (
    IN p_customer_id INT,
    IN p_shipping_address TEXT,
    IN p_billing_address TEXT,
    IN p_product_id INT,
    IN p_quantity INT
)
-- (This is a simplified version that only adds one product)
BEGIN
    
    DECLARE new_order_id INT;
    DECLARE stock_available INT;

    -- Start the "all or nothing" operation
    START TRANSACTION;

    -- 1. Create the Order
    INSERT INTO "Order" (customer_id, order_date, order_status, shipping_address, billing_address)
    VALUES (p_customer_id, NOW(), 'Pending', p_shipping_address, p_billing_address);
    
    -- 2. Get the new order_id
    SET new_order_id = LAST_INSERT_ID(); 

    -- 3. Check if there is enough stock
    SELECT quantity INTO stock_available
    FROM Inventory
    WHERE product_id = p_product_id AND location_id = 1; -- (Assuming we ship from one main location)

    IF stock_available < p_quantity THEN
        -- Not enough stock! Undo everything and stop.
        ROLLBACK;
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Not enough items in stock.';
    ELSE
        -- 4. There is stock, so update the inventory
        UPDATE Inventory
        SET quantity = quantity - p_quantity
        WHERE product_id = p_product_id AND location_id = 1;
        
        -- 5. Add the item to the order
        INSERT INTO OrderItem (order_id, product_id, quantity, price_at_purchase)
        VALUES (new_order_id, p_product_id, p_quantity, (SELECT price FROM Product WHERE product_id = p_product_id));
        
        -- 6. All steps succeeded. Make it permanent.
        COMMIT;
    END IF;

END;
```

So now when it comes to *using* the command, we do:

```SQL
CALL sp_CreateNewOrder(
    1234,                       -- The customer's ID
    '123 Fake St, London',      -- Shipping address
    '123 Fake St, London',      -- Billing address
    5678,                       -- The product ID
    2                           -- The quantity
);
```

So in the example, the checkout button does no complex logic, the database already has it all.

## Syntax

To create a procedure you use the `CREATE PROCEDURE` command.

```SQL
DELIMITER //

CREATE PROCEDURE sp_YourProcedureName(
	--Parameters go here
)
BEGIN
	-- SQL Statements go here

END //

DELIMITER;
```

`DELIMITER //` is a crucial part of MySQL syntax. The `DELIMITER //` specifically denotes where a procedure ends and begins. The reason for this is that SQL contains many semicolons and without it the command would stop at the first semicolon.

### Parameter Types

There are three parameter types  `IN`, `OUT`, `INOUT`.

1. `IN` is the input parameter.

This is the default and here you specify the value that is passed *into* the procedure. The procedure however **cannot change the original value**.

Here is a simple example of getting an employee's detail using their ID:

```SQL
DELIMITER //
CREATE PROCEDURE sp_GetEmployeeDetails(IN p_employee_id INT)
BEGIN
    
    -- This query uses the input parameter in its WHERE clause
    SELECT 
        first_name, 
        last_name, 
        position, 
        email
    FROM 
        Employee
    WHERE 
        employee_id = p_employee_id;
        
END //
DELIMITER ;
```


To call it you do: 

```SQL
CALL sp_GetEmployeeDetails(101);
```

2. `OUT` the output parameter.

The procedure cannot read this variable, but it writes a value to it. The calling program then reads the value after the procedure is finished.

```SQL
DELIMITER //
CREATE PROCEDURE sp_GetEmployeeName(
    IN  p_employee_id INT,
    OUT p_full_name VARCHAR(200)
)
BEGIN

-- This query "selects" the result INTO the output variable
    SELECT 
        CONCAT(first_name, ' ', last_name)
    INTO 
        p_full_name
    FROM 
        Employee
    WHERE 
        employee_id = p_employee_id;

END //
DELIMITER ;
```

**How to call it:** (This is a two-step process in MySQL):

```SQL
-- 1. Call the procedure, passing in a "sessionvariable" (starting with @)

CALL sp_GetEmployeeName(101, @emp_name);   

-- 2. Select the variable to see the result
SELECT @emp_name;
```


3. `INOUT` the input/output parameter

This is a combination, the program passes a value in, the procedure modifies it and the program can read the *new* value.

```SQL
DELIMITER //
CREATE PROCEDURE sp_AddTen(INOUT p_number INT)
BEGIN
    
    -- This procedure modifies the input variable directly
    SET p_number = p_number + 10;
    
END //
DELIMITER ;
```

```SQL
-- 1. Define the variable with a starting value
SET @my_counter = 5;

-- 2. Call the procedure to modify the variable
CALL sp_AddTen(@my_counter);

-- 3. Select the variable to see the new value
SELECT @my_counter; 
-- Result will be 15
```