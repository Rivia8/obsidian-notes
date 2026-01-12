24-02-2025 20:31

Tags: [[Operating Systems]]

# Virtual Memory

One of the most critical functions of any OS is to provide a virtual environment for application's code. 
An application has an idealised view of the machine it is running on:
Virtual Memory is a memory management technique that creates an abstraction layer between the physical memory (RAM) and the memory that applications perceive they have. This abstraction allows a system to give the illusion of having more memory than is physically installed.

When it comes to memory, different machines have varying amounts of physical memory installed. We've already discussed the **Virtual Memory** solution when looking at [[Memory Mapping# Virtual Memory Solution|memory mapping]]. We looked at **virtual addresses** used by the application, that are converted into physical addresses which solves any potential address conflicts.

So in summary, virtual memory works by utilising **address translation**, **paging** (and page tables) and **swapping**.

## Swapping

Mapping the memory works well **IF** the sum of the memory used by all current applications does not exceed the size of the installed physical memory. If we run out of physical memory, the OS can move inactive pages from RAM to a designated space on a secondary storage device, a HDD or an SSD. When those pages are needed again, they can be swapped back into RAM replacing other pages in their place, essentially swapping them in and out of disk and RAM.

![[Pasted image 20250224211802.png#invert]]

Swapping makes sure everything continues to run but secondary storage is much more **slower** than RAM and it also takes time for pages to be moved back and forth.

