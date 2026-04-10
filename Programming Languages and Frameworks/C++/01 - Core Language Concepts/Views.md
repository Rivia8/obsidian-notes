09-04-2026 09:51

Tags: [[C++]]

A view is a specific type of [[Ranges|Range]]. 

Views have three properties:

- Non-owning
- Non-mutating
- Cheap to copy (creating, copying, or passing a view takes $O(1)$ time

 Views use lazy evaluation. So when you attach a view to a container, no calculation happens. The view simply remembers the instruction.



