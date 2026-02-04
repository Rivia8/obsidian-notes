04-02-2026 12:32

Tags: [[C++]]

# Special Functions

These are functions that are 'special' because if you **don't write them yourself** the compiler will automatically write them for you.


- **Default Constructor**

`Circle()`
This creates an object with no arguments
If another constructor is defined, it is not auto-generated.

- **Destructor**

`~Class()`
This cleans up when the object dies.

- **Copy Constructor**

`Class(const Class&)` 
This creates a new object as a clone of an existing one.

- **Copy Assignment**

`operator=(const Class&)`
This updates an already alive object to look like another.

- **Move Constructor**

`Class(Class&&)`
This 'steals' resources from a dying object to build a new one.

- **Move Assignment**

`operator=(Class&&)`
This steals resources from a dying object to update an alive one.

---

The compiler produces default versions of these and they are:
- Recursive
- Apply special functions on every member variable,
- Work most of the time
- Faster, smaller, safer code.