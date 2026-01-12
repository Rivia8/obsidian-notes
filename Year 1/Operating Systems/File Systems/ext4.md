18-05-2025 22:01

Tags: [[Operating Systems]]

# ext4

**ext4** stands for "Fourth extended file system", its the default file system for many Linux distros. 
Here is a diagram of the *ext4* file system:

![[Ext2.png#invert]]
- The superblock and group descriptor specify details
- Bitmaps are a convenient way of indicating whether a data block/i-node is used or not.
- The I-node table is an array of records which defines both the file (data blocks) and its attributes.
- The disk is divided into **block groups**.

## I-node system

An **I-node** is a data structure on disk that stores metadata about a file or directory, excluding the name.
Think of an I-node as a file's identity card - it contains **all** the important details except the filename itself, which is stored separately in the directory structure. 

Each I-node contains:

|Metadata|Description|
|---|---|
|**File type**|Regular file, directory, symbolic link, etc.|
|**Permissions**|e.g. `rw-r--r--`|
|**Owner UID**|User ID of the owner|
|**Group GID**|Group ID of the owner|
|**File size**|In bytes|
|**Timestamps**|Last access (`atime`), modification (`mtime`), and status change (`ctime`)|
|**Link count**|Number of directory entries (hard links) that point to the inode|
|**Pointers to data**|Addresses of the blocks on disk where the file's actual data is stored|
|**Flags**|For file behaviour, e.g. "immutable", "append-only"|
|**Extended attributes**|Extra metadata (ACLs, SELinux labels, etc.)|

The I-node points to data blocks but since it is quite small it can only point towards a small amount of data blocks, which could limit the amount of storage ext4 could support. However, an I-node's **pointer** could **point** to a data block that points to another **data block** which holds a pointer:

![[Inodes.png#invert]]

