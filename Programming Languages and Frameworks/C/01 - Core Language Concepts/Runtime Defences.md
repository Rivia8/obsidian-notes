21-11-2025 12:23

Tags: [[C]]

# Runtime Defences

## Non-Executable Memory

This is sometimes also known as **Data Execution Prevention (DEP)**, it is a security feature used to prevent certain types of binary exploitation attacks, particularly **code injection** techniques such as **stack-based buffer overflows.**

It marks certain areas in memory as *not* executable.

This kind of memory protection mechanism can be applied to critical memory areas where user input might be saved, including the **stack** and **heap**.


### Key Memory Regions

Traditionally, a program has the following memory regions:
- **.text** contains the executable code,
- **.data** and **.bss** contain global/static variables,
- **Heap** dynamically allocated memory,
- **Stack** used for function calls and local variables.

What this does here is that regions like the **stack** and **heap** are marked as **non-executable** so the CPU will refuse to execute even if an attacker injects malicious code into these regions.

```C
#include <stdio.h>  
#include <string.h>  
  
void vulnerable_function() {  
    char buffer[64];  // Fixed-size buffer on the stack  
  
    printf("Enter some text:\n");  
    gets(buffer);  // Dangerous: gets() does not perform bounds checking  
  
    printf("You entered: %s\n", buffer);  
}  
  
int main() {  
    vulnerable_function();  
    return 0;  
}
```

Here we can see that `gets()` does not perform bounds checking, this means that if the user were to input a string longer than 64, than those **overflowed** bytes will be injected into the stack.

There are *some* limitations to NX/DEP:
- Return-Orientated Programming (ROP) can be used to reuse existing executable code in memory,
- DEP won't block its use if code already exists in executable memory.

## Address Space Layout Randomisation (ASLR)

This is another defence that is commonly used in most systems and is a security technique that involves randomly arranging the memory locations of key system components, making it much harder for attackers to predict addresses and successfully exploit memory-based vulnerabilities.

If this isn't implemented and an attacker learns the memory layout of a program, it will be easier for them to inject malicious code, redirect program flow and ultimately seize control of endpoints or even escalate privileges across the network.

### ALR Granularity and Entropy

The granularity of ALSR is **coarse-grained**: for performance reasons we cannot really randomise the location of each variable independently. So randomisation is realised at the level of large areas of the virtual address space called program's **segments**. These are realised at the load time for the main program, and for dynamic libraries it's also realised when they are loaded.

When it comes to the **entropy** (the randomness), some Operating Systems or architecture use only a small number of bits for randomisation. This limitation can allow attackers to brute-force possible, the limitation allows some ability of brute-force attacks on smaller systems (32-bit and lower Operating Systems).

### ALSR in the Modern Security Stack

**ALSR** is most powerful when used in combination with other modern memory protections. Modern enterprise operating systems like Windows, Linux and macOS typically enable ASLR by default.

## Stack Canary

This is a run-time protection mechanism for detecting and preventing stack-based buffer overflows. They are **random values** that are placed just before the return addresses on the stack when a function is called.

This is to prevent overflow attacks, since if someone were to overflow they would also have to overwrite the canary value too (the program will detect the tampering).

By default, canaries will be applied only to certain functions but you can use the:
`-fstrack-protector-strong` to apply it to every function in your program.

### Limitations

This however, only protects functions with local buffers. It doesn't stop non-contiguous overflows and can be bypassed using special techniques.
