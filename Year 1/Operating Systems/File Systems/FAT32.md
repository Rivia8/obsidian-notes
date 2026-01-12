19-05-2025 00:22

Tags: [[Operating Systems]]

# FAT

FAT are used in legacy Windows systems and embedded systems.
FAT (Fat Allocation Table) is an array of cluster pointers, one pointer corresponding to one cluster on the disk.
***A cluster is one is set of one or more of the disk's data blocks***

The FAT pointers are then used to define linked lists - one list per file. A reserve value acts as a `NULL` end of file marker. This means that files can occupy any number of clusters on the disk and can grow in length as long as there are some free clusters left somewhere.

![[FAT.png#invert]]




