[[Database Systems]]
# Interview

General goal of kilburnazon:
- Revolutionise operational efficiency of speed and accuracy of delivering products.

How is the business structured?:
- There are a team of executives (hierarchy)
- Each are in charge of their own department e.g. Tracy in charge of delivery drivers

How does Kilburnazon manage their rota of staff:
- Nearly a couple hundred employees, each have their own unique id for the monitoring system.
- The ID is categorised by their department and then some random digits
- Its useful to know things like location and emergency data of their employees.

Is Kilburnazon national and not only manchester located?:
- Distribution centers are scattered across the UK

What about their customers:?
- Customers are very important, their details are collected: where they live, email (needs to be properly locked down), how many ordered they've made, 

Delivering many items is a big feat how do they manage everything?:
- A long products list and products are stored in various distribution centers, once orders come in clear orders in similar orders who are passed to delivery drivers and this is optimised to reduce carbon footprint.

Customers can be fickle, what steps are taken so customers are satisfied?:
- Customers are asked to fill reviews on a scale of 0 to 5 stars via email and then the PA looks at lowly rated products to see whats gone wrong.

What does kilburnazon do to ensure staff satisfaction?:
- UK laws are abided of 28 days a year and every year that an employee stays they get an additional of 2 days. 
- In order to prevent all drivers in one area to go on leave at once, a rigorous system is needed to prevent this occuring.


# Information
## Hierarchy:

CEO: Elon Bazos ---> PA: Jarvis Kare
- COO: Tracy Gates
	- Health and Safety officer
	- Factory Worker
	- Delivery Driver
- CFO: Jeff Lovelace
	- Accountant
	- Financial Analyst
- CMO: Staff Hopper
	- Brand Developer
	- Industry Researcher
	- Product Designer
- CTO: Sarah Turing
	- Front-end developer
	- Back-end developer
	- Full-stack deverloper
	- Junior developer 
	- CyberSecurity
## Locations:

There are 9 locations
1. Scotland Distribution Centre
2. Northern Ireland Distribution Centre
3. England North Distribution Centre
4. **Kilburnazon Head Office**
5. England Central Distribution Centre
6. Birmingham Office for Kilburnazon
7. Wales Distribution Centre
8. The London Office for Kilburnazon
9. England South Distribution Centre


# Entity Breakdown
## Employees

- ID
- NAME
	- FIRST_NAME
	- SECOND_NAME 
- POSITION
- DEPARTMENT
- SALARY
- EMAIL
- DOB
- ~~OFFICE~~ to remove transitive dependency
- HOME_ADDRESSS
- HIRED_DATE
- CONTRACT
- NIN
- EMERGENCY_NAME
- EMERGENCY_RELATIONSHIP
- EMERGENCY_PHONE


## Products

- UNIQ_ID
- PRODUCT_NAME
- MANUFACTURER
- PRICE
- NUMBER_AVAILABLE_IN_STOCK
- NUMBER_OF_REVIEWS
- NUMBER_OF_ANSWERED_QUESTIONS
- AVERAGE_REVIEW_RATING
- KILBURNAZON_CATEGORY_AND_SUB_CATERGORY
- DESCRIPTION



# My Own Entities

This is for simplicity and to make sure that the information is atomic to comply with 1NF and for other discrepancies with other normal forms: 

## Customer

(Based on the words said by Elon Bazos himself we need these too although not explicitly mentioned in the other material):
- CUSTOMER_ID
- FIRST_NAME
- LAST_NAME
- EMAIL
- PASSWORD_HASH
- CREATED_AT

## Department
(A good chain would be: `EmployeeID` -> `Department` -> `Office`)

## Location
- LOCATION_ID
- LOCATION_NAME
- ADDRESS
- LOCATION_TYPE

## Categories
- CATEGORY_ID
- CATEGORY_NAME

## SubCategory
- SUBCATEGORY_ID
- SUBCATEGORY_NAME
- CATEGORY_ID

## Order 
- ORDER_ID
- CUSTOMER_ID
- ORDER_DATE
- ORDER_STATUS
- SHIPPING_ADDRESS
- BILLING_ADDRESS

## OrderItem

Why do we need this? Because an order can have many Order items.
Junction table

- ORDER_ID
- PRODUCT_ID
- QUANTITY
- PRICE_AT_PURCHASE

# Relationship Explanation

### `OrderItem` (linking `Order` and `Product`)

- **`Order` to `OrderItem`:**
    
    - **Logic:** Can an `Order` exist without any `OrderItems`? No, an empty order is pointless. It _must_ have at least one item.
        
    - **Symbols:** `||` (one and only one) at the `Order` end, and **`|<` (one or many)** at the `OrderItem` end.
        
    - _This is the **mandatory many** you were asking about._
        
- **`Product` to `OrderItem`:**
    
    - **Logic:** Can a `Product` exist without being in any `OrderItem`? Yes, a new product.
        
    - **Symbols:** `|O` (one or zero) at the `Product` end, and **`O<` (zero or many)** at the `OrderItem` end.
        

### `Inventory` (linking `Product` and `Location`)

This one is slightly different from `OrderItem`.

- **`Product` to `Inventory`:**
    
    - **Logic:** Can a `Product` exist before it's in any `Inventory`? Yes, you can add it to the system first.
        
    - **Symbols:** `|O` (one or zero) at the `Product` end, and **`O<` (zero or many)** at the `Inventory` end.
        
- **`Location` to `Inventory`:**
    
    - **Logic:** Can a `Location` exist (like the Head Office) that holds _zero_ stock? Yes.
        
    - **Symbols:** `|O` (one or zero) at the `Location` end, and **`O<` (zero or many)** at the `Inventory` end.
        

The reason both `Inventory` and `OrderItem` use **optional** "many" sides (`O<`) is because a parent (`Product`, `Location`, `Customer`) can exist _without_ any children.

The only "mandatory many" (`|<`) you have is **`Order` → `OrderItem`**, because an order, by definition, _must_ have at least one item. Your original diagram _correctly_ showed this relationship between `Order` and `OrderItem`.

### `Employee` and `Department` (works in)

- **Relationship:** `Department.department_id` (PK) $\to$ `Employee.department_id` (FK)
    
- **Logic (Dept $\to$ Emp):** Can a `Department` exist with zero `Employees`? Yes, a brand new department might be empty.
    
- **Logic (Emp $\to$ Dept):** Can an `Employee` exist without a `Department`? **Yes.** Think about the CEO, Elon Bazos. He isn't _in_ the Finance department or the Tech department; he manages the executives who run them. So, the `department_id` for an `Employee` should be **optional (nullable)**.
    
- **Symbols:**
    
    - At the `Department` end (the "one" side): **`|O` (one or zero)**
        
    - At the `Employee` end (the "many" side): **`O<` (zero or many)**
        

---

### `Employee` and `Department` (manages)

- **Relationship:** `Employee.employee_id` (PK) $\to$ `Department.manager_id` (FK)
    
- **Logic (Emp $\to$ Dept):** Can an `Employee` exist who manages _zero_ departments? Yes, 99% of them. Can they manage more than one? No, your hierarchy implies one manager per department.
    
- **Logic (Dept $\to$ Emp):** Can a `Department` exist without a `Manager`? Let's assume no. A department _must_ have a leader.
    
- **Symbols:**
    
    - At the `Employee` end (the "one" side): **`|O` (one or zero)**
        
    - At the `Department` end (the other "one" side): **`||` (one and only one)**
        

---

### `Department` and `Location`

- **Relationship:** `Location.location_id` (PK) $\to$ `Department.location_id` (FK)
    
- **Logic (Loc $\to$ Dept):** Can a `Location` exist (like the "London Office") that has _zero_ `Departments`? Plausible, but unlikely for a distribution centre. Let's say a location _must_ have at least one department, even if it's just "Warehouse".
    
- **Logic (Dept $\to$ Loc):** Can a `Department` exist _without_ a `Location`? Maybe a "Remote" department. This is a design choice. Let's assume for simplicity that a department _must_ be assigned to a location.
    
- **Symbols:**
    
    - At the `Location` end (the "one" side): **`||` (one and only one)**
        
    - At the `Department` end (the "many" side): **`|<` (one or many)**
        

---

### `Product` and `Manufacturer`

- **Relationship:** `Manufacturer.manufacturer_id` (PK) $\to$ `Product.manufacturer_id` (FK)
    
- **Logic (Man $\to$ Pro):** Can a `Manufacturer` exist in your system that you _don't_ currently stock any products for? Yes, you might be in negotiations with them.
    
- **Logic (Pro $\to$ Man):** Can a `Product` exist without a `Manufacturer`? No, it has to be made by someone. The `manufacturer_id` should be **mandatory (NOT NULL)**.
    
- **Symbols:**
    
    - At the `Manufacturer` end (the "one" side): **`||` (one and only one)**
        
    - At the `Product` end (the "many" side): **`O<` (zero or many)**
        

---

### `Category` and `SubCategory`

- **Relationship:** `Category.category_id` (PK) $\to$ `SubCategory.category_id` (FK)
    
- **Logic (Cat $\to$ Sub):** Can a `Category` (like "Electronics") exist without any `SubCategories`? No, that wouldn't make sense. It must have at least one (e.g., "Phones").
    
- **Logic (Sub $\to$ Cat):** Can a `SubCategory` (like "Phones") exist without a `Category`? No. It _must_ belong to one.
    
- **Symbols:**
    
    - At the `Category` end (the "one" side): **`||` (one and only one)**
        
    - At the `SubCategory` end (the "many" side): **`|<` (one or many)**
        

---

### `Product` and `SubCategory`

- **Relationship:** `SubCategory.subcategory_id` (PK) $\to$ `Product.subcategory_id` (FK)
    
- **Logic (Sub $\to$ Pro):** Can a `SubCategory` (like "Smart Watches") exist even if you don't stock any products for it yet? Yes.
    
- **Logic (Pro $\to$ Sub):** Can a `Product` exist without a `SubCategory`? No, it must be listed somewhere for customers to find it.
    
- **Symbols:**
    
    - At the `SubCategory` end (the "one" side): **`||` (one and only one)**
        
    - At the `Product` end (the "many" side): **`O<` (zero or many)**
        

---

### `Customer` and `Order`

- **Relationship:** `Customer.customer_id` (PK) $\to$ `Order.customer_id` (FK)
    
- **Logic (Cust $\to$ Ord):** Can a `Customer` exist who has made _zero_ `Orders`? Yes, a brand new customer.
    
- **Logic (Ord $\to$ Cust):** Can an `Order` exist without a `Customer`? No. The `customer_id` must be **mandatory (NOT NULL)**.
    
- **Symbols:**
    
    - At the `Customer` end (the "one" side): **`||` (one and only one)**
        
    - At the `Order` end (the "many" side): **`O<` (zero or many)**