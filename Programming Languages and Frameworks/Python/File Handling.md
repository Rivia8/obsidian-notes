23-01-2025 22:49

Status: #new

Tags: [[Python]]

# File Handling
We have already looked at dictionaries and lists in [[State and Types]] but to also store information we have files.
In order to deal with files we have certain operations we can do.

## Opening and Closing a file
First we have to open the file, in Python we use `open()` function.

```Python
file = open("filename", "mode")
fle_object.close()
```

We have attributed a variable a file that has a name and a certain mode. There are different modes that we can open a file with:

### Modes
- `'r'`: Read (default mode)
- `'w'`: Write (creates a new file or truncates an existing file)
- `'a'`: Append (adds to the end of the file)
- `'b'`: Binary mode (e.g., `'rb'` or `'wb'`)
- `'t'`: Text mode (default, e.g., `'rt'` or `'wt'`)
- `'x'`: Exclusive creation (fails if the file already exists)

```Python 
# Open a file for reading
file = open("example.txt", "r")
file.close()

# Open a file for writing
file = open("example.txt", "w")
file.close()
```

## Reading and Writing from Files
Python provides several methods to read from files:
- `read()`: Reads the entire file or a specified number of characters.
- `readline()`: Reads one line at a time.
- `readlines()`: Reads all lines into a list.

```Python
file = open("example.txt", "r")

# Read the entire file
content = file.read()
print(content)

# Read a specific number of characters
content = file.read(10)
print(content)

# Read one line at a time
line = file.readline()
print(line)

# Read all lines into a list
lines = file.readlines()
print(lines)

file.close()
```

To write to a file, you can use `write()` or `writelines()` methods.

```Python
file = open("example.txt", "w")

# Write a single string to the file
file.write("Hello, world!\n")

# Write multiple lines to the file
lines = ["Line 1\n", "Line 2\n", "Line 3\n"]
file.writelines(lines)

file.close()
```

## Appending to Files
To append content to an existing file without overwriting it, use the `a` mode.

```Python
file = open("example.txt", "a")

# Append a line to the file
file.write("This line is appended.\n")

file.close()
```

## Proper Etiquette for File Handling
When it comes to actually dealing with files, it is best practice to use a `with` statement.
The `with` statement simplifies management resources like files, network connections, or locks by automatically handling the setup and teardown process.

**Example:**
```Python
with open("example.txt", "r") as file:
    content = file.read()
    print(content)
```

- Here `open("example.txt", "r") as file` opens the file in read mode and assigns the variable `file`.
- The block of code inside the `with` statement reads the file's contents and prints it.
- After the block of code is executed, the `__exit__()` method is called, which automatically closes the file even if an exception occurs.

So using `with` statement is beneficial because:
- Cleaner code,
- Automatically handles exceptions,
- Reduces the need for explicit `try` and `finally` blocks to handle clean-up,
- And, avoids resource leaks.