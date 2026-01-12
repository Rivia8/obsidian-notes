19-02-2025 11:51

Tags: [[Operating Systems]]

# Memory Segmentation

The Von Neumann architecture has a **single memory address space**. This means that that both data and instructions share the same memory.

The memory is logically divided into a number of regions in any given application. Each segment is a contiguous block of memory represents a logical unit, such as a function, data array or stack. **Unlike paging**, (which divides memory in fixed-sized pages), segments can vary in size based on their purpose.

Memory is divided into **logical divisions** (segments), each representing a logical part of the program.
The operating system maintains a segment table for each process, the segment table contains entries with information about each segment, like its base address and **limit** (length).

| Segment Number | Base Address | Limit |
| -------------- | ------------ | ----- |
| 0              | 1000         | 4000  |
| 1              | 5000         | 1500  |
| 2              | 7000         | 1000  |

The segments will have other attributes and properties like whether they are able to be read/written to or from and execute permissions. This provides protection and isolation.

