20-11-2025 11:01

Tags: [[C]]

# Detecting Bugs

We are going to look at techniques that are slow or make applications slow.
As a result, they cannot run in production and are rather used during development. These techniques will fall into two categories:
1. **Static Analysis:** this scans program's source code or binary for bugs without executing it.
2. **Dynamic Analysis:** checking for the presence of bugs by running the program


## Static Analysis

Static analysis tools scan the source code of the program for any possible bugs without actually running the program.

Static analysis generally suffers from false positives - it identifies issues with the code that does not represent programming mistakes or security vulnerabilities (logic errors). This is because it doesn't run the program so things that are dependent on context like memory content during runtime will not be highlighted. Static analysis are quite slow and do not scale well to the large code bases.

Many static analysis approaches are implemented at the level of the compiler.
You can enable high degrees of compiler warnings. 
You can increase the order of 'pickiness', `-Wall` to get additional warnings and then `-Wextra` to get even more warnings and `-pedantic` to add even more warnings.

### Clang Static Analyser

This is one of the forms of static analyser:

```C
// includes omitted

int c;

int main() {

    int a = INT_MAX;
    int b = 1;
    c = a + b; // Integer overflow!

    char buffer[8];
    char str[] = "this string is too long";
    strcpy(buffer, str); // Buffer overflow!


    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 42;
    free(ptr);
    *ptr = 99; // Use-after-free!

    return 0;
}
```

There are three bugs here:

- The first bug is an integer overflow, we add in `c` 1 to the largest integer that can be stored on an int `INT_MAX`.
- The second bug is a buffer overflow, we copy in `buffer`, which size is 8 bytes, a string that is larger than 8 bytes.
- And the last bug is a use after free, where we dereference the pointer `ptr` after having freed the buffer it points to.

With the default level of warnings, the program compiles fine, it also runs without any visible errors. If we run the Clan static analyser over our program, we get the following output:

```Bash
$ clang --analyze faulty.c
faulty.c:22:10: warning: Use of memory after it is freed [unix.Malloc]
    *ptr = 99; // Use-after-free!
    ~~~~ ^
1 warning generated.
```

## Dynamic Analysis

This tries to detect errors while running the program, doing so it gets access to more information than static analysis.
A popular type is called **compiler based instrumentation**. These are called sanitisers. The most widespread is **Address Sanitisation (ASan)** that will detect a wide range of memory errors that would not be caught at compile time or at runtime without instrumentation. 
You also have **Undefined Behaviour Sanitisation (UBSan)** that detects things like integer overflows, invalid casts and so on.

### Using Sanitisers

We can enable address sanitiser instrumentation at compile time on our faulty program as:

```Bash
$ clang -fsanitize=address faulty.c -o faulty
```

If we launch the program, we can see that ASan catches the buffer overflow:

```Bash
$ ./faulty
=================================================================
==21543==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffcc881f268 # ...
```

Once that is done, overflow we can recompile the program and then use the address sanitiser, and launch it again. Here we can see that it detects the *'user after free*:

```Bash
clang -fsanitize=address faulty.c -o faulty
$ ./faulty
./faulty                                   
=================================================================
==22504==ERROR: AddressSanitizer: heap-use-after-free on address 0x602000000010 # ...
```

When we enable **UBSan** and launch the program, the interger overflow is detected:

```bash
$ clang -fsanitize=undefined faulty.c -o faulty
$ ./faulty
faulty.c:12:11: runtime error: signed integer overflow:
    2147483647 + 1 cannot be represented in type 'int'
```

### Valgrind

There are other dynamic tools but the ones that came before sanitisers have been rendered obsolete.

## Fuzz Testing

Fuzzing consists in blasting a trust boundary with malformed inputs with the hope to trigger bugs. 