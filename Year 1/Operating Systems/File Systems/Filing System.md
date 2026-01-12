
18-05-2025 20:42

Tags: [[Operating Systems]]

# Filing System

The filing system lives between the user applications - which want to handle files and the disk. 
All processes should see the same files so this is common software that is clearly party of the operating system.

![[File_system.png]]

The OS provides system calls for access to files.


## Types of File Systems

The simplest file stores are 'flat' i.e. there is one place where all the files are kept (this becomes crowded fast).

A modern file-store is most likely to be **hierarchal** with a tree-like structure. Each tree has a single 'root' which branches repeatedly.

![[File_tree_Windows.png#invert]]

![[File_tree_Unix.png#invert]]
As you can see Unix file-store has all the devices under a single 'tree', where the branching points are directories and terminal points on the trees are files.

Then we also have the actual different file system **formats** whereby it dictates how files are kept:

| File System   | Used By       | Features                              |
| ------------- | ------------- | ------------------------------------- |
| **[[FAT32]]** | Windows, USBs | Simple, old, limited to 4GB files.    |
| **NTFS**      | Windows       | Journaling, compression, permissions. |
| **[[ext4]]**  | Linux         | Journaling, performance, stability.   |
| **APFS**      | macOS         | Snapshots, encryption, cloning.       |

## Links

**Links** refer to special directory entries that allow multiple names or paths to refer to the same directory.
A **hard link** is essentially a name for an existing file, it points to the same I-node.
A **Symbolic link** is a shortcut or a pointer to another file or directory. It stores the path of the original file, not the file's data itself.