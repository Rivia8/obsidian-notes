21-02-2025 13:56

Tags: [[Operating Systems]]

# Memory Protection

Computer's memory is a resource that is needed by everything that executes, but each process wants its own share that isn't able to be accessed by another process. This is good since it prevents contamination (accidental or malicious) from one process to another.

It is also important to protect the operating system space from being **altered by the user** (apart from **system calls** which are carefully **controlled**).
Which includes:
- Operating System Code
- Operating System Data
- Memory-Mapped Peripheral Devices

[[Memory Mapping]] kind of already establishes a sort of protection where [[Memory Segmentation]] and **Memory Paging** have attributes within it to prevent things like unauthorised access.
If a process has a limited memory map, then it can't 'see' memory which isn't currently mapped for.

But there needs to be something to validate particular access to certain areas, like the Operating system needs to be able to do the mapping, and user applications need to interact with operating system services, so we need some sort of permission levels to be implemented.

## Permissions

The permissions will be specified by the MMU, the exact method may vary but its usually be on a 'per segment' or 'per page' basis.
Page-schemes are probably the most common.

### No Access

May be used to mark a page which is not present. Could be because the process has not been granted access to this part of the address space, in which case it indicates a **segmentation fault**. 

An OS may mark valid pages as 'no access' if it is trying to determine if they are still in use - it is restored if the page is used again, but if it out of use after some waiting time, it may be evicted

### Supervisor Read-Only and Read-Only

Most cases, instruction code is fixed, and should not be written to. Some data structures may also be fixed, like message Strings. 

### Supervisor Read/Write

The operating system's data spaces are sensitive areas. This prevents a user altering anything in there. If something does need to be changed, you have system calls.


### Read/Write any Priv. Level

This is the level which a user's data pages would have. The OS will have access although it won't usually want to.



