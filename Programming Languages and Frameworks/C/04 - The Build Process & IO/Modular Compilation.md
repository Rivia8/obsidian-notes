01-11-2025 16:09

Tags: [[C]]

# Modular Compilation

**Modular compilation** is the standard practice for building any C program that isn't trivially small. It's the process of splitting a large project into multiple, logical `.c` files that are compiled independently and then linked together into a final executable.

The main purpose is to improve the organisation of the project and speed up the build time.

So let's say you had a program that was 5,000 lines long and it is one main file, `main.c`. This would occur lots of problems for the nearly every programmer: it's unmanageable, it's slow and it's not reusable.

The modular solution is to break your code into pairs of files, typically by "subject". For example, you'd have:

- `player.c` & `player.h`
- `enemy.c` & `enemy.h`
- `main.c`

## The Compilation Phase

We might think that (outside of the preprocessor phase) the compilation process includes the compiler directly transforming the source code into an executable, however that is not the case.
The compilation process actually has a more complicated process.
The way it *actually* goes about is that we have an intermediate format called the **object files** and we have a tool called the **linker** which transforms object files into executables.

![[phase2.svg#invert|800]]
We can do the process manually ourselves using commands:

```bash
gcc -c src.c -o src.o
gcc src.o -o executable
ls
executable src.c src.o
```

1. `gcc -c src.c -o src.o` - we call the compiler, with `-c`, to produce an object file. Object files are denoted with the `.o` extension.
2. `gcc src.o -o executable` - the object file is then linked to an executable.


## How Modulation Works

So how do we break down the source files we have into many modular files? Firstly, it is good practice to regroup code into source files (these are called **modules** in C) by functionality.
We can look at a simple example to understand this, let's look at a hypothetical server:

![[server.svg#invert|800]]
Let's say this server is built from 3 source files:
- `network.c` containing the code related to networking operations
- `parser.c` contains the code to parse the requests received by the server
- `main.c` contains the `main` function, initialisation/exit code and the main server loop

Now how do we go about combining these three C files into one executable?

We do the following:

```Bash
$ gcc -c main.c -o main.o                   # build main.o
$ gcc -c parser.c -o parser.o               # build parser.o
$ gcc -c network.c -o network.o             # build network.o
$ gcc main.o network.o parser.o -o prog     # link executable
```

Visually this looks like the following:

![[modular1.svg#invert|800]]


Each source file exposes a set of functions that can eb called from other files - an [[API|Application Programming Interface]] (API).
