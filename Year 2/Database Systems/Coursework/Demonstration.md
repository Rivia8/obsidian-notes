02-12-2025 12:33

Tags: [[Database Systems]]

# Demonstration

Hello I'm Armaan and this is my database implementation and design
## Back End

First we will look at the back-end.

- The database schema that I have created and implemented is designed to model the complete Kilburnazon ecosystem, everything from employees to customer facing logistics. It consists of 15 interconnected tables, ensuring that all data is stored efficiently and **with minimal** redundancy whilst still adhering to relational database principles. Looking specifically at tables that revolve around employee management, I've split the data into 3 entities, `Employee`, `Department` and `Location` tables. This structure adheres to 3NF by removing any transitive dependencies. For an example, an employee's office location is determined by their `department_id`, not the employee record itself. This prevents any update anomalies if a department moves and creates a single source of truth for location data..

Here is the full DDL code I used to create and implement the entire database.

- I’ve used features such as relationships, constraints, and indexing throughout the schema to enforce the various types of **data integrity**:
	- Foreign keys for **Relational Integrity**.
	- `CHECK` constraints on data for **Domain Integrity**.
	- `UNIQUE` constraints for **entity integrity.**

- Here is a deeper dive at some of the SQL statements.

Here you can see various constraints and checks that are used heavily in my database, `NOT NULL` deals with having no garbage data and`UNIQUE` enforces **entity integrity**, it does this by guaranteeing that no two employees can share the same identity documents or contact info, preventing duplicate records from sneaking in and therefore prevents logical errors. `Check` enforces **domain integrity** by restricting the allowed values for a column to a logical range.

Here you can see my circular dependency solution, it handles a problem where I couldn't create one of the tables without the other existing first, so I correctly decoupled the creation process, creating the tables without a strict link and *then* using `ALTER TABLE` to "snap" the constraint into place.

Here is another example: You can see the use of `DECIMAL` types for financial accuracy (`FLOAT` can have rounding errors) and `ON DELETE CASCADE` rules to handle data clean-up automatically.

Finally, to enforce dynamic business rules that standard constraints cannot handle, I implemented SQL Triggers. For example, I created a `BEFORE INSERT` trigger on the Employee table. This trigger automatically checks the `hired_date` against the server's current date (`CURDATE()`). If an attempt is made to hire an employee in the future, the trigger intercepts the transaction and throws a custom SQL error signal. This ensures data validity at the database level, acting as a final fail-safe regardless of front-end validation

## Front End

- The front end provides a comprehensive interface for HR and management. The central hub is the **Employee Directory**, which features a dynamic search and filtering system. This acts as the entry point for detailed profile views, promotion management, staff onboarding, and the contract termination workflow.
- The application is built using a **LAMP stack approach** (Linux/Windows, Apache, MySQL, PHP). The critical technical decision here was how the front end communicates with the back end. I utilized **PDO (PHP Data Objects)** rather than the older `mysqli` extension. I chose PDO specifically because it supports **Named Parameters and Prepared Statements**. This is an essential security feature. By separating the SQL code from the data, the application is protected against **SQL Injection attacks**. The database treats user input strictly as data, never as executable code.
- To further enhance data integrity, I implemented **Client-Side Logic using JavaScript**. I moved beyond static forms by using event listeners to make the 'Add Employee' workflow dynamic. For example, selecting a specific 'Department' instantly updates the 'Position' dropdown to show only relevant roles. This ensures a user cannot logically assign a 'CEO' role to the 'Operations' department or a 'Factory Worker' to 'Finance'. **The system auto-generates a compliant Employee ID.** It applies a specific semantic prefix—like '15' for Technology or '12' for Operations—ensuring that the ID structure adheres to the company's internal numbering schema before the form is even submitted. This reduces human error before the data even reaches the server validation layer.
- In terms of UX, I designed the interface with usability in mind, opting for a dark theme and clear visual feedback. The directory uses colour-coded badges for contract types—green for full-time, yellow for part-time, and blue for freelancers—allowing managers to assess team composition at a quick glance. I also focused on **Intuitive Navigation**; critical functions like employee termination are placed in deliberate positions that add a bit of **positive friction** to prevent accidental deletions. Furthermore, I implemented comprehensive feedback loops: every action, whether adding a user or updating a salary, returns a clear success or error message. Finally, using **CSS Grid** for the directory cards allows the layout to adapt gracefully to different screen sizes, ensuring usability across monitors and tablets.
## Task 1

I will now be demonstrating the search and filter functionalities of the directory, by default the values are set to 'All' with nothing at the search.
First let's look at the search functionality, its highly versatile as Instead of forcing users to navigate multiple search boxes, this 'smart search' automatically queries across several key attributes.
Of course, standard searches by **Name** are supported. The system checks both the `first_name` and `last_name` columns simultaneously.
A user can also search by **Job Title**. Typing 'Front End' instantly retrieves all developers with that role. The backend query uses `OR` logic to scan the `position` column, ensuring that job-specific searches are seamless.
Crucially, the search also extends to **Location**. By typing 'London' or 'Head Office', the query joins the `Employee` table with the `Location` table to find matches. This allows managers to quickly pull up a list of all staff at a specific site without needing a separate filter.
Finally, for precise lookups, the system supports searching by **Employee ID**. This is vital for HR tasks where unique identification is required. By simply entering the ID, the system bypasses the broader text matches and homes in on the exact record needed.

I am now going to demonstrate the filter functionality.
When a user selects any combination of these filters, the PHP backend dynamically constructs an SQL statement. It appends the necessary `WHERE` clauses for each active filter, joining relevant tables like `Department` and `Location` as needed. This ensures that the search results are always precise and relevant to the user's specific query.
The interface provides immediate visual feedback. Notice how the employee cards update instantly to reflect the filtered dataset. The color-coded contract badges—green for Full-Time, yellow for Part-Time, and blue for Freelance—offer a quick visual confirmation that the filters are working correctly and effectively narrowing down the team view. This flexible, multi-criteria filtering system significantly enhances the usability of the directory, allowing HR and management to quickly locate staff members based on their specific operational needs.

## Task 2

I am now going to demonstrate the Employee Data management and Promotion Updates by onboarding a new staff member, Malissia Jonsson. As I input her details, I want to highlight the validation strategy.
On the **client-side** I utilise HTML5 attributes like `required` and `type='email'` to ensure fields aren't left blank and data formats are correct before submission.
However, for critical data like the National Insurance Number, I rely on Server-Side validation. The UK standard dictates the last character must be A, B, C or D. The data provided for Malissia ends in 'R', which is technically invalid.
If i attempt to submit this \[pause] the server rejects it, this is caught by the regular expression in my php script which enforces the correct schema, ensuring database integrity.
Here you can see the `preg_match` function blocking the invalid pattern. I will correct the suffix to 'A' to comply with the standard and the record is now successfully corrected.

Next, I will process a promotion for employee 14316158, I'll navigate to their profile and access the promotion interface.
The system abstracts the math from the user, I simply enter the required 3.4% increase and the backend calculates the new decimal value and performs SQL `UPDATE`, as you can see the new salary is immediately reflected in the record.

## Task 3

Moving to Task 3, I've implemented the 'Birthday Card' initiative. By clicking 'View Birthdays', the system retrieves all employees whose birth month matches the current calendar month.
To implement this efficiently, I utilized a **Stored Procedure** named `sp_GetBirthdaysByMonth`. Instead of writing raw SQL in the PHP file, the application simply calls this procedure and passes the current month as a parameter. This encapsulates the logic within the database, making it reusable and secure.
The procedure is designed to return not just names, but essential contact details like home addresses and emails. This allows the CEO to immediately verify where to send a physical card or digital greeting without needing to cross-reference the main directory. The results are also sorted by day, helping the executive team plan their schedule to ensure no employee is missed.
## Task 4

For the final task, I will process a contract termination. I’m entering the specific ID for an employee 15210392 and I’ll record the specific reason - in this case, 'Left for a different job - and input my own ID to log who is authorizing this deletion. When I click process, the system performs a database transaction: creating the log entry first, and then removing the user from the active `Employee` table. You can see the new entry in the Audit Log here. It captures the essential details required for accountability: the name of the employee who left, the reason, the exact date and time of the event, and the ID of the user who processed the termination.
Finally, to handle GDPR compliance regarding data retention, I’ve implemented this cleanup function. This executes a SQL command that checks the `deleted_at` timestamp. It automatically removes any audit records older than three years, ensuring we adhere to data minimization principles by not holding onto historical data longer than necessary.

## Conclusion

To conclude, this implementation of the Kilburnazon Directory successfully meets all functional requirements while prioritizing **Security** and **Data Integrity**.

By strictly adhering to **3rd Normal Form**, I ensured the database structure is scalable and free of redundancy. The use of **PDO Prepared Statements** and **Stored Procedures** secures the application logic, while the **Automated Audit Log** ensures the system remains compliant with GDPR regulations.

On the front end, the combination of **Dynamic JavaScript validation** and a responsive **CSS Grid** layout ensures a seamless, error-resistant experience for HR staff.

If I were to develop this further, the next logical step would be to implement a granular **Role-Based Access Control (RBAC)** system. This would allow us to restrict sensitive views—like Salaries and National Insurance numbers—so that they are only visible to specific 'Manager' or 'HR' accounts, further hardening the system's privacy.

Thank you for your time.