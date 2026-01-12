01-11-2025 14:28

Tags: [[C]]

# The Preprocessor

The **Preprocessor** is a particular tool that is executed by the compiler during the build process of a C or C++ program.

The C Preprocessor is a separate program that runs before the code is ever compiled.

![[preprocessor2.svg#invert|800]]

It performs **textual transformations** on the sources, so it takes as input the C source file and produces as output a modified version of these sources, i.e. something that is still C source code.  
After that step the compiler translates it into machine code.

To understand what's going on a brief look at the C translation pipeline:


⚙️ The Compilation Pipeline (When does it run?)

To understand this, you need to see the full process of building a C program:

1. **Source Code (`.c`)**: Your human-readable code.
2. **➡️ Preprocessor**: Reads your `.c` file, processes all lines starting with `#`, and produces a new, temporary file (let's call it `temp.c`).
3. **➡️ Compiler**: Reads `temp.c` (which has no `#` lines left) and turns it into assembly language.
4. **➡️ Assembler**: Reads the assembly code and turns it into machine code (an object file, `.o`).
5. **➡️ Linker**: Reads your `.o` file and any other libraries (like the Standard Library) and bundles them all into the final `.exe` file.


Looking at the steps above you can see that the pre processor is step 2. 
But what does the Preprocessor actually do?

The preprocessor's main job is to manipulate the text of the source code and produce an output that is still C source code but in a more 'ready' state.

## Header Inclusion

**Header files** are these files ending with the `.h` extension. What the preprocessor does with these is that it literally **copy-pastes** the entire of another file into your code.

There are two ways to include a header in your .c file:
```C
// In the .c source file, include headers like that:
#include <stdio.h>            // Use <> to include a file from the default include path
#include "my-custom-header.h" // Use "" for the local and user-supplied include directories
```


Here is a quick look at what it was meant by the entire code is copied:

![[include 1.svg#invert|800]]

## Macro Expansion

Macros are textual substitutions based on tokens. They are very useful for defining things like compile-time constants.
Lets look at an example:

```C
#include <stdio.h>

// If we want to change the array size,
// we only need to update this:
*#define ARRAY_SIZE  10

int main(int argc, char **argv) {
* int array[ARRAY_SIZE];

* for(int i=0; i<ARRAY_SIZE; i++) {
    array[i] = i;
    printf("array[%d] = %d\n", i, array[i]);
  }

  return 0;
}
```

Here we have a macro named `ARRAY_SIZE` (the convention is to have it in all caps). The macro is used both in the array definition to set its size and in the loop header iterating over the array to the set the number of iterations.
The nice thing about these are that they are "find-and-replace" functions, meaning it doesn't operate like a variable in the sense that multiple updates will be needed to change the the constant or the function of something - everything will be updated at once.

Some things to note, because its 'dumb text replacement', when it comes to things like arithmetic operations, orders of precedence matters and the preprocessor doesn't look at these things, so its recommended to always use parentheses.

## Conditional Compilation

The preprocessor allows the conditional inclusion of code:

```C
#define DEBUG_MODE             // controls the activation/deactivation of debug mode
#define VERBOSITY_LEVEL 4      // controls the debug verbosity level

#ifdef DEBUG_MODE
int debug_function();
#endif

int main(int argc, char **argv) {
    printf("hello, world\n");

#ifdef DEBUG_MODE
    debug_function();
#endif
    return 0;
}

#ifdef DEBUG_MODE
int debug_function() {
    printf("This is printed only if the macro DEBUG_MODE is defined\n");

#if VERBOSITY_LEVEL > 3
    printf("Additional debug because the verbosity level is high\n");
#endif /* VERBOSITY_LEVEL */

    return 42;
}
#endif /* DEBUG_MODE */
```

If you look we have some [[The Preprocessor#Macro Expansion|macro functions]] defined. Specifically in the example above we define two macros, `DEBUG_MODE` and `VERBOSITY_LEVEL`. `DEBUG_MODE` is defined without a particular value but if you look at further in the code we can see some **directives**, these directives are made so that they become defined and will be **compiled** *only* when `DEBUG_MODE` has a value.
This is also the case for the other macro, `VERBOSITY_LEVEL`, which will have extra 'debug' cases if it has a certain value (>4).

