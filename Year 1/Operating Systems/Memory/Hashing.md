12-04-2025 21:47

Tags: [[Operating Systems]]

# Hashing

Hashing is often used in **paging systems** to efficiently map virtual pages to physical frames in memory.

Hashing is a separate techniques to the normal paging memory mapping as it serves different purposes and fits different system requirements.

You have a hash **function** and a hash **tables**.
The **function** maps data (of an arbitrary size) to a fixed size collection of values.
The **tables** are structures for storing key/value pairs. The hash function identifies a slot or bucket for the item.
![[Pasted image 20250412214231.png#invert]]

This is fine until you have keys that hash to the same bucket.
![[Pasted image 20250412214319.png#invert]]
So we have a **linked list** for the keys that hashes to the same bucket.**

![[Pasted image 20250412214915.png]]

