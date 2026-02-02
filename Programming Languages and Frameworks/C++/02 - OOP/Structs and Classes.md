02-02-2026 20:56

Tags: [[Structs and Classes]]

# Structs and Classes

C++ class are almost identical to C++ structs.

Both have:

- member variable definition,
- `.` and `->` operators,
- member functions

What they differ in is:

1. **Default Visibility:**

`class` members are `private` by default. You have to explicitly type `public` to share them.
`struct` members are `public` by default.

2. **Default Inheritance:**

`class` inherits from parents **privately** by default and `structs` inherits from parents **publicly** by default.


3. **Culture**

They are technically the same but they offer different **conventions** (coding styles). This is how we signal intent to other programmers.

We use `struct` when the object is **POD** (plain old data).

