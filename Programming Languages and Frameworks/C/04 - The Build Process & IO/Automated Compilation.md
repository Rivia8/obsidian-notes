07-11-2025 23:37

Tags: [[C]]

# Automated Compilation

A tool called Make is used that allows the automation of the compilation of programs composed of lots of source files.

When it comes to recompiling for changes we have made, sometimes we don't need to recompile *all* the files for a change that is limited to a single source file. However, we still need to make sure the links for the dependencies are still valid, this is why we use a tool called `make` that does this for us.

# Make

The `make` tool relies on configuration files name 'Makefiles'. They live alongside the sources, describing the build and its dependencies, following a particular format.

The example that we have looked *before* for modular compilation would have this sort of 'dependency tree':

![[deps2.svg#invert|800]]
As you can see from the diagram, if `parser.h` is modified, `parser.o` and `main.o` will need to be rebuilt.

This dependency will need to be explained in a corresponding `Makefile`:

```bash
# The first rule is executed when the
# command make is typed in the local folder:
all: prog

# executable deps and command to build it:
prog: main.o network.o parser.o
    gcc main.o network.o parser.o -o prog

# network.o deps and command to build it:
network.o: network.c network.h
    gcc -c network.c -o network.o

parser.o: parser.c parser.h network.h
    gcc -c parser.c -o parser.o

main.o: main.c network.h parser.h
    gcc -c main.c -o main.o

# Special rule to remove all build files
clean:
    rm -rf *.o prog

```
