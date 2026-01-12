18-02-2025 12:56

Tags: [[Operating Systems]]
 
# Memory Management

There is limited memory resources in a computer. In a simple system, virtual memory is used to prevent any problems if we were to run out of RAM.

With **[[Virtual Memory]]** and **[[Paging]]** some of the restrictions can be bypassed (up to a point) but the problems still arise.

Any process will require on ore more logical memory segments which are contiguous parts of the address space  - a sequence of addresses next to each other.

When a process starts some of the memory can be allocated because *sometimes* the program code is a known length and so there could be some **static** data - the variable's data is constant. This is only for some cases though, in others memory is allocated dynamically, which means that the instead of during compile time the memory is allocated in run-time so the exact amount of memory required can be determined on the fly based on the program's current needs.

Let's look at an example in C:

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int)); // dynamic allocation
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    // Use the array
    free(arr); // deallocate memory
    return 0;

```

In the example we can see that the array's memory is allocated based on the user's input, and it is freed after use to avoid memory leaks. 

The pattern of segments may vary, there are some typical examples:

![[Pasted image 20250218131626.png#invert]]


![[Pasted image 20250218131409.png#invert]]

Both applications and the O.S can perform memory management.

Applications can request 'large' blocks of memory and then allocate from them, which saves them from using system calls.

The OS can keep records of the memory in use and in a virtual memory environment and which physical pages are in use and for what they are used by.

The OS may need to::

- Allocate spaces when a process is loaded
	- Set up pages in a virtual memory system
- Manage access permissions
- Allocate additional space if the **stack** or **heap** overflow
- Keep track of a process’ use and recover the resource when the process terminates

