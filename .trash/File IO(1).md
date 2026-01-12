06-05-2025 21:24

Tags: [[Java]]

# File IO

## IO Streams

This is where java views each file as a sequential stream of bytes. The stream is a mechanism from getting data from source to destination.

We have **input streams** that get input to a program like from files or a keyboard and we have **output streams** that accept output from a program and deliver it to an external source, like a screen or file.

Every 'file' that we're reading or writing will have two identifiers:
1. The name used by the operating system,
2. The name of the **stream object**

e.g.:
```Java
FileReader inputStream = new FileReader("in.txt")
FileWriter outputStream = new FileWriter("out.txt")
```

Important classes for text file output:
- `java.io.FileWriter`
- `java.io.PrintWriter`

Important classes for text file input:
- `java.io.FileReader`
- `java.io.BufferedReader`

The thing is to remember some of these stream 'tools' don't all necessarily use the raw encoded message of bytes as some will use a **Character** stream.

## Serializable Interface

Any class that you intend to write out to a file using object encoding must implement the `Serializable` interface. - pretty much the `Serializable` interface is a permission slip. This is the reason why its a special type of interface known as a **marker interface** where it has **no methods** you need to implement as its only purpose is to "mark" your class and tell the JVM that it can be used to be saved and sent to a file.

The reason why classes aren't `Serializable` by default is because serialisation allows access to data irrespective to modifiers (less security).