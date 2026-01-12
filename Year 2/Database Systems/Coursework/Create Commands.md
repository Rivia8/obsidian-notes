[[Database Systems]]

```SQL
SET FOREIGN_KEY_CHECKS = 0;

DROP TABLE IF EXISTS AuditLog;
DROP TABLE IF EXISTS Shipment;
DROP TABLE IF EXISTS OrderItem;
DROP TABLE IF EXISTS `Order`;
DROP TABLE IF EXISTS Review;
DROP TABLE IF EXISTS Customer;
DROP TABLE IF EXISTS LeaveRequest;
DROP TABLE IF EXISTS Department; 
DROP TABLE IF EXISTS Employee;
DROP TABLE IF EXISTS Inventory;
DROP TABLE IF EXISTS Product;
DROP TABLE IF EXISTS SubCategory;
DROP TABLE IF EXISTS Category;
DROP TABLE IF EXISTS Manufacturer;
DROP TABLE IF EXISTS Location;

SET FOREIGN_KEY_CHECKS = 1;

CREATE TABLE Location (
    location_id INT AUTO_INCREMENT PRIMARY KEY,
    location_name VARCHAR(100) NOT NULL,
    address TEXT NOT NULL,
    location_type VARCHAR(50)
) ENGINE=InnoDB;

CREATE TABLE Manufacturer (
    manufacturer_id INT AUTO_INCREMENT PRIMARY KEY,
    manufacturer_name VARCHAR(100) NOT NULL UNIQUE
) ENGINE=InnoDB;

CREATE TABLE Category (
    category_id INT AUTO_INCREMENT PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL UNIQUE
) ENGINE=InnoDB;

CREATE TABLE Customer (
    customer_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB;

CREATE TABLE AuditLog (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    employee_id_deleted INT,
    employee_name VARCHAR(200),
    termination_reason TEXT,
    deleted_by_id INT,
    deleted_at DATETIME DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB;

CREATE TABLE SubCategory (
    subcategory_id INT AUTO_INCREMENT PRIMARY KEY,
    subcategory_name VARCHAR(100) NOT NULL,
    category_id INT,
    INDEX (category_id),
    FOREIGN KEY (category_id) REFERENCES Category(category_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE Product (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(255) NOT NULL,
    manufacturer_id INT,
    subcategory_id INT,
    price DECIMAL(10, 2) NOT NULL CHECK (price >= 0),
    num_reviews INT DEFAULT 0,
    num_answered_questions INT DEFAULT 0,
    avg_review_rating DECIMAL(3, 2) DEFAULT 0.00,
    description TEXT,
    INDEX (manufacturer_id),
    INDEX (subcategory_id),
    FOREIGN KEY (manufacturer_id) REFERENCES Manufacturer(manufacturer_id) ON DELETE SET NULL,
    FOREIGN KEY (subcategory_id) REFERENCES SubCategory(subcategory_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE Inventory (
    product_id INT,
    location_id INT,
    quantity INT NOT NULL DEFAULT 0 CHECK (quantity >= 0),
    PRIMARY KEY (product_id, location_id),
    FOREIGN KEY (product_id) REFERENCES Product(product_id) ON DELETE CASCADE,
    FOREIGN KEY (location_id) REFERENCES Location(location_id) ON DELETE CASCADE
) ENGINE=InnoDB;

CREATE TABLE Department (
    department_id INT AUTO_INCREMENT PRIMARY KEY,
    department_name VARCHAR(100) NOT NULL UNIQUE,
    location_id INT,
    manager_id INT UNIQUE, 
    INDEX (location_id),
    INDEX (manager_id),
    FOREIGN KEY (location_id) REFERENCES Location(location_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE Employee (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    position VARCHAR(100),
    department_id INT,
    salary DECIMAL(10, 2) CHECK (salary >= 0),
    email VARCHAR(255) NOT NULL UNIQUE,
    dob DATE,
    home_address TEXT,
    hired_date DATE NOT NULL,
    contract_type VARCHAR(50),
    nin VARCHAR(20) NOT NULL UNIQUE,
    emergency_name VARCHAR(100),
    emergency_relationship VARCHAR(50),
    emergency_phone VARCHAR(20),
    FOREIGN KEY (department_id) REFERENCES Department(department_id) ON DELETE SET NULL
) ENGINE=InnoDB;

ALTER TABLE Department
ADD CONSTRAINT fk_dept_manager
FOREIGN KEY (manager_id) REFERENCES Employee(employee_id) ON DELETE SET NULL;

CREATE TABLE LeaveRequest (
    request_id INT AUTO_INCREMENT PRIMARY KEY,
    employee_id INT,
    start_date DATE NOT NULL,
    end_date DATE NOT NULL,
    status VARCHAR(20) NOT NULL DEFAULT 'Pending',
    approver_id INT,
    INDEX (employee_id),
    INDEX (approver_id),
    FOREIGN KEY (employee_id) REFERENCES Employee(employee_id) ON DELETE CASCADE,
    FOREIGN KEY (approver_id) REFERENCES Employee(employee_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE Review (
    review_id INT AUTO_INCREMENT PRIMARY KEY,
    product_id INT,
    customer_id INT,
    rating INT NOT NULL CHECK (rating >= 0 AND rating <= 5),
    comment TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX (product_id),
    INDEX (customer_id),
    FOREIGN KEY (product_id) REFERENCES Product(product_id) ON DELETE CASCADE,
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE `Order` (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    order_status VARCHAR(50) DEFAULT 'Pending',
    shipping_address TEXT NOT NULL,
    billing_address TEXT NOT NULL,
    INDEX (customer_id),
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id) ON DELETE SET NULL
) ENGINE=InnoDB;

CREATE TABLE OrderItem (
    order_id INT,
    product_id INT,
    quantity INT NOT NULL CHECK (quantity > 0),
    price_at_purchase DECIMAL(10, 2) NOT NULL,
    PRIMARY KEY (order_id, product_id),
    FOREIGN KEY (order_id) REFERENCES `Order`(order_id) ON DELETE CASCADE,
    FOREIGN KEY (product_id) REFERENCES Product(product_id) ON DELETE NO ACTION
) ENGINE=InnoDB;

CREATE TABLE Shipment (
    shipment_id INT AUTO_INCREMENT PRIMARY KEY,
    order_id INT,
    driver_id INT,
    status VARCHAR(50) NOT NULL DEFAULT 'Processing',
    dispatched_at TIMESTAMP NULL,
    INDEX (order_id),
    INDEX (driver_id),
    FOREIGN KEY (order_id) REFERENCES `Order`(order_id) ON DELETE CASCADE,
    FOREIGN KEY (driver_id) REFERENCES Employee(employee_id) ON DELETE SET NULL
) ENGINE=InnoDB;
```


Creating employee DDL:
```SQL

INSERT INTO Location (location_id, location_name, address, location_type) VALUES 
(1, 'Scotland Distribution Centre', 'Scotland', 'Distribution Centre'),
(2, 'Northern Ireland Distribution Centre', 'Northern Ireland', 'Distribution Centre'),
(3, 'England North Distribution Centre', 'England North', 'Distribution Centre'),
(4, 'Kilburnazon Head Office', 'Kilburn Building, London', 'Head Office'),
(5, 'England Central Distribution Centre', 'England Central', 'Distribution Centre'),
(6, 'Birmingham Office', 'Lewis Building, Birmingham', 'Office'),
(7, 'Wales Distribution Centre', 'Wales', 'Distribution Centre'),
(8, 'London Office', 'Broadgate Tower, London', 'Office'),
(9, 'England South Distribution Centre', 'England South', 'Distribution Centre');

-- We map these to their primary "Headquarters" location ID
INSERT INTO Department (department_id, department_name, location_id) VALUES 
(1, 'Executive', 4),   -- Kilburn Head Office
(2, 'Operations', 5),  -- England Central Hub
(3, 'Finance', 6),     -- Birmingham Office
(4, 'Marketing', 8),   -- London Office
(5, 'Technology', 4);  -- Kilburn Head Office

-- Chiefs (Executive Team)
INSERT INTO Employee (employee_id, first_name, last_name, position, department_id, salary, email, dob, home_address, hired_date, contract_type, nin, emergency_name, emergency_relationship, emergency_phone) VALUES 
(11123211, 'Elon', 'Bazos', 'CEO', 1, 150000, 'Elon.Bazos@kilburnazon.com', '1974-04-12', '534 Moulton Avenue', '2014-02-15', 'Full-Time', 'RE885173B', 'Stanislas Tunnow', 'Wife', '07208 300969'),
(11214682, 'Jarvis', 'Kare', 'PA', 1, 75000, 'Jarvis.Kare@kilburnazon.com', '1981-03-06', '75631 Hazelcrest Court', '2015-11-16', 'Full-Time', 'DF625255C', 'Pittem Kare', 'Wife', NULL),
(11229804, 'Tracey', 'Gates', 'COO', 1, 150000, 'Tracey.Gates@kilburnazon.com', '1977-10-26', '29916 Elmside Center', '2017-07-26', 'Full-Time', 'AN593683D', 'Karlens Kilfether', NULL, '07770 850 516'),
(11226496, 'Jeff', 'Lovelace', 'CFO', 1, 150000, 'Jeff.Lovelace@kilburnazon.com', '1976-12-15', '2 Waubesa Terrace', '2016-07-16', 'Full-Time', 'SY194109A', NULL, 'Boyfriend', '07786 830672'),
(11224403, 'Steve', 'Hopper', 'CMO', 1, 150000, 'Steve.Hopper@kilburnazon.com', '1986-08-27', '21917 Forest Place', '2015-11-11', 'Full-Time', 'BG154525C', NULL, 'Civil Partner', '07279 090043'),
(11223214, 'Sarah', 'Turing', 'CTO', 1, 150000, 'Sarah.Turing@kilburnazon.com', '1977-08-23', '462 Westerfield Road', '2017-12-02', 'Full-Time', 'LQ649084C', 'Agosto Hoggan', 'Boyfriend', '07760 801643');

-- Operations Team (Factory Workers, Drivers, Safety)
INSERT INTO Employee (employee_id, first_name, last_name, position, department_id, salary, email, dob, home_address, hired_date, contract_type, nin, emergency_name, emergency_relationship, emergency_phone) VALUES 
(12116288, 'Deeanne', 'Westoll', 'Health & Safety Officer', 2, 34693, 'Deeanne.Westoll@kilburnazon.com', '1977-12-06', '412 North Street', '2016-09-21', 'Full-Time', 'XR656206B', 'Zeke Vennings', 'Wife', '07647 152752'),
(12111088, 'Tierney', 'Saura', 'Health & Safety Officer', 2, 33774, 'Tierney.Saura@kilburnazon.com', '2003-08-20', '36 Fordem Way', '2023-02-16', 'Full-Time', 'IB336855D', NULL, NULL, '07776 617476'),
(1221452, 'Harriott', 'Pinn', 'Factory Worker', 2, 29230, 'Harriott.Pinn@kilburnazon.com', '2009-05-28', '94695 Oak Valley Drive', '2015-05-04', 'Full-Time', 'SB900295A', 'Ella Huygen', NULL, '07527 612710'),
(12217466, 'Joelynn', 'Dorgan', 'Factory Worker', 2, 22660, 'Joelynn.Dorgan@kilburnazon.com', '1989-08-08', '556 Merchant Drive', '2016-01-02', 'Full-Time', 'QQ562762D', 'Rog Redman', 'Wife', '07596 559644'),
(12316237, 'Bald', 'Spindler', 'Delivery Driver', 2, 28972, 'Bald.Spindler@kilburnazon.com', '1977-11-12', '894 Stoughton Way', '2018-08-29', 'Full-Time', 'KY965343C', 'Isidor Hillan', NULL, '07722 676666'),
(12315752, 'Evvie', 'Chesters', 'Delivery Driver', 2, 26877, 'Evvie.Chesters@kilburnazon.com', '1997-09-04', '84068 Sycamore Trail', '2015-07-14', 'Freelance', 'AN202720C', 'Natasha Santoro', NULL, '07084 119115');

-- Finance Team (Accountants, Analysts)
INSERT INTO Employee (employee_id, first_name, last_name, position, department_id, salary, email, dob, home_address, hired_date, contract_type, nin, emergency_name, emergency_relationship, emergency_phone) VALUES 
(13110482, 'Jayme', 'Greiswood', 'Accountant', 3, 33681, 'Jayme.Greiswood@kilburnazon.com', '1991-11-11', '70 Farragut Lane', '2018-08-16', 'Full-Time', 'PH455369B', 'Hayward Norley', 'Mother', '07832 036596'),
(13111738, 'Mirabella', 'Gullane', 'Accountant', 3, 38988, 'Mirabella.Gullane@kilburnazon.com', '1996-05-20', '3 Beilfuss Trail', '2020-12-28', 'Part-Time', 'KF883937B', NULL, 'Boyfriend', '07862 622159'),
(13211973, 'Elden', 'Toy', 'Financial Analyst', 3, 39153, 'Elden.Toy@kilburnazon.com', '2004-06-04', '2816 Florence Crossing', '2023-01-02', 'Full-Time', 'NL822476D', 'Kienan Killeley', 'Father', NULL),
(13212738, 'Paolo', 'Lewin', 'Financial Analyst', 3, 32254, 'Paolo.Lewin@kilburnazon.com', '1995-07-27', '84332 Oak Plaza', '2020-08-13', 'Full-Time', 'RI019366A', 'Jenica McGrudder', 'Girlfriend', '07963 860510');

-- Marketing Team (Brand, Researchers, Designers)
INSERT INTO Employee (employee_id, first_name, last_name, position, department_id, salary, email, dob, home_address, hired_date, contract_type, nin, emergency_name, emergency_relationship, emergency_phone) VALUES 
(14119372, 'Peirce', 'Stoyell', 'Brand Developer', 4, 22515, 'Peirce.Stoyell@kilburnazon.com', '1982-10-03', '903 Claremont Street', '2020-10-13', 'Freelance', 'VQ308399D', 'Doria Johanchon', 'Civil Partner', '07036 960338'),
(14118236, 'Emogene', 'Burchard', 'Brand Developer', 4, 25249, 'Emogene.Burchard@kilburnazon.com', '1988-07-19', '25 Arkansas Trail', '2022-09-29', 'Part-Time', 'UZ112160A', NULL, 'Boyfriend', NULL),
(14218309, 'Colette', 'McChruiter', 'Industry Researcher', 4, 28946, 'Colette.McChruiter@kilburnazon.com', '1996-09-27', '227 Green Ridge Junction', '2023-05-01', 'Freelance', 'YK615192A', 'Brianna Harlock', 'Husband', '07181 235352'),
(14212158, 'Zacharias', 'Tomlett', 'Industry Researcher', 4, 28703, 'Zacharias.Tomlett@kilburnazon.com', '1986-08-20', '679 Brown Hill', '2018-05-01', 'Full-Time', 'TK940382B', 'Minda Ferrillo', 'Mother', '07056 710360'),
(14319953, 'Cornelle', 'Plowright', 'Product Designer', 4, 28686, 'Cornelle.Plowright@kilburnazon.com', '1993-03-15', '8902 Eastlawn Court', '2015-03-22', 'Full-Time', 'UG075011C', 'Calypso Mapston', NULL, '07608 461696'),
(14316158, 'Janessa', 'Hilldrup', 'Product Designer', 4, 24021, 'Janessa.Hilldrup@kilburnazon.com', '2008-07-12', '7 Dorton Way', '2016-08-21', 'Full-Time', 'JO147528A', 'Denny Nicolson', 'Wife', '07123 801554');

-- Technology Team (Devs, Cyber Security)
INSERT INTO Employee (employee_id, first_name, last_name, position, department_id, salary, email, dob, home_address, hired_date, contract_type, nin, emergency_name, emergency_relationship, emergency_phone) VALUES 
(15118902, 'Torrey', 'Lidgertwood', 'Front End Developer', 5, 37008, 'Torrey.Lidgertwood@kilburnazon.com', '2006-02-12', '366 Eagle Crest Park', '2023-05-07', 'Full-Time', 'MB541802C', 'Tull North', NULL, '07082 174879'),
(15112846, 'Quintina', 'Stannard', 'Front End Developer', 5, 48586, 'Quintina.Stannard@kilburnazon.com', '2002-10-24', '695 Mariners Cove Court', '2018-04-30', 'Part-Time', 'OS711286D', 'Livvy Shingles', 'Wife', NULL),
(15210392, 'Gert', 'Romagnosi', 'Back End Developer', 5, 37617, 'Gert.Romagnosi@kilburnazon.com', '1995-04-29', '81 Mallard Alley', '2016-08-21', 'Full-Time', 'TG492624A', 'Jilly Fullbrook', 'Girlfriend', '07405 079997'),
(15218274, 'Brooke', 'Bevir', 'Back End Developer', 5, 41271, 'Brooke.Bevir@kilburnazon.com', '1992-12-08', '9456 Charing Cross Parkway', '2020-04-15', 'Full-Time', 'SJ671620A', 'Tremayne Mumford', 'Girlfriend', '07070 829323'),
(15310538, 'Barnie', 'Howsden', 'Full Stack Developer', 5, 78124, 'Barnie.Howsden@kilburnazon.com', '2004-05-28', '940 Green Ridge Crossing', '2017-04-26', 'Part-Time', 'QW437381C', NULL, 'Mother', '07654 711451'),
(15314926, 'Brunhilde', 'Doring', 'Full Stack Developer', 5, 82064, 'Brunhilde.Doring@kilburnazon.com', '1989-03-04', '8 Canary Terrace', '2023-06-05', 'Full-Time', 'DY737542D', 'Marlin Knight', 'Civil Partner', '07326 647976'),
(15413482, 'Brande', 'Setch', 'Junior Developer', 5, 53173, 'Brande.Setch@kilburnazon.com', '2000-06-01', '2 Columbus Terrace', '2020-09-11', 'Full-Time', 'CM199844A', 'Nerissa Maisey', 'Wife', '07740 330980'),
(15419183, 'Bevvy', 'Counihan', 'Junior Developer', 5, 95590, 'Bevvy.Counihan@kilburnazon.com', '1992-04-05', '20943 Everett Park', '2023-07-04', 'Part-Time', 'CU409429A', 'Fayth Bazylets', 'Girlfriend', NULL),
(15512916, 'Sherye', 'Larrat', 'Cyber Security', 5, 63743, 'Sherye.Larrat@kilburnazon.com', '1993-12-23', '700 Harper Alley', '2018-03-08', 'Part-Time', 'ZK749313A', 'Isidora Hanster', NULL, '07736 429556'),
(15518273, 'Julissa', 'Pedrocchi', 'Cyber Security', 5, 62946, 'Julissa.Pedrocchi@kilburnazon.com', '1989-02-28', '23483 Clove Circle', '2022-02-21', 'Part-Time', 'XA340620B', NULL, 'Wife', '07043 095609');

-- 4. Assign Managers to Departments (Resolving Circular Dependency)
UPDATE Department SET manager_id = 11123211 WHERE department_name = 'Executive';
UPDATE Department SET manager_id = 11229804 WHERE department_name = 'Operations';
UPDATE Department SET manager_id = 11226496 WHERE department_name = 'Finance';
UPDATE Department SET manager_id = 11224403 WHERE department_name = 'Marketing';
UPDATE Department SET manager_id = 11223214 WHERE department_name = 'Technology';
```


Creating Stored Procedure:
```SQL
DELIMITER //

CREATE PROCEDURE sp_GetBirthdaysByMonth(
    IN target_month INT
)
BEGIN
    SELECT 
        employee_id, 
        first_name, 
        last_name, 
        dob, 
        email, 
        home_address, 
        emergency_phone,
        DATE_FORMAT(dob, '%M %D') as birthday_display 
    FROM Employee 
    WHERE MONTH(dob) = target_month
    ORDER BY DAY(dob);
END //

DELIMITER;
```

Trigger implementation for data integrity.
```SQL
DELIMITER //

CREATE TRIGGER trg_check_dob_before_insert
BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
    IF NEW.dob > CURDATE() THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Error: Date of Birth cannot be in the future.';
    END IF;
END //

DELIMITER ;
```

```SQL
DELIMITER //

CREATE TRIGGER trg_check_hired_date
BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
    IF NEW.hired_date > CURDATE() THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Error: Hired Date cannot be in the future.';
    END IF;
END //

DELIMITER ;
```