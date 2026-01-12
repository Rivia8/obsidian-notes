17-05-2025 22:10

Tags: [[Operating Systems]]

# Parent Processes

Processes can create other processes. The process that creates another process is termed the parent in this situation and the newly created process is the child. Whereby the relationship is established using the `fork()` system call.

# Child Process

This is a duplicate of the parent process created via `fork()`.  It inherits most attributes from the parent but operates concurrently.
