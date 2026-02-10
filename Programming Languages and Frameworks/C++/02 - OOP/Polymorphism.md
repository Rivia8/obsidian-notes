10-02-2026 15:27

Tags: [[C++]]

# Polymorphism

Polymorphism is the ability to treat different objects (like a `dog` or a `cat`) as if they were the same general type (an `animal`) while still getting the specific behaviour of the actual object.

There are 2 distinct types of **polymorphism**:

1. **Compile-Time Polymorphism** **(Static Binding)**

This happens **before** the program runs. The compiler knows exactly which function to call based on the arguments.

**Function Overloading:** `print(in)` vs `print(string)`

**Templates**: `vector<int>` vs `vector<float>`

2. **Runtime Polymorphism (Dynamic Binding)**

This is considered the 'true' OOP polymorphism. What this means is that the program decides while it is running which function to call, this is achieved using **inheritance** and **Virtual Functions**.




