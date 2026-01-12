18-05-2025 23:03

Tags: [[Operating Systems]]

# File Attributes

File contains data but also has something called metadata, this is information about the data.

It is normal to include the **permissions** of the files, this includes what can be done to the file.

It is also very useful to know who 'owns' which file. An associated identifier can provide this information usually.

## File Types

- **l** – a symbolic [link](https://wiki.cs.manchester.ac.uk/COMP15212/index.php/Links "Links")
- **p** – a named [pipe](https://wiki.cs.manchester.ac.uk/COMP15212/index.php/Pipes "Pipes")
- **s** – a [socket](https://wiki.cs.manchester.ac.uk/COMP15212/index.php/Sockets "Sockets")
- **c** – a character [device](https://wiki.cs.manchester.ac.uk/COMP15212/index.php/Device_Drivers "Device Drivers")
- **b** – a block [device](https://wiki.cs.manchester.ac.uk/COMP15212/index.php/Device_Drivers "Device Drivers")


## File Permissions

Most file systems include some form of access control, which could support multiple users of a system so that each user's files were private.

These are the basic file permissions:
- File's **owner** - UID
- File's **group** - GUID

## File Access
Users usually identify files with their filenames and path to that file.

**Open**: This is to obtain a file handle,
**Close:** When a file is finished it should be 'closed', this may be needed before another process writes to that file.
**Reading and Writing:** It is usual to read and or write **blocks** of data.

## File Descriptor
The descriptor will be created when a file is opened and is associated with a particular file within a particular process. It is used for immediate file access and will info like:

- Access permissions,
- Index of the file,
- Error status,
- Control flags.