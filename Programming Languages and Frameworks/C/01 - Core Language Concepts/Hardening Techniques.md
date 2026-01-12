21-11-2025 13:38

Tags: [[C]]

# Hardening Techniques

We have looked at some mainstream [[Runtime Defences|runtime defences]] that can be employed within C, now we will have a quick glance at some general hardening techniques.


## Stripping Binary

**Stripping Binary** is a common protection technique that includes **stripping** the program from symbols and debug information. 
This makes reverse-engineering a program available in binary form only, a crucial step in many attacks, much more difficult.

### Dead Stripping

Do not confuse **Dead Stripping** with stripping binary, since Dead Stripping is a different process which removes unused function sand data from your code, this happens at the link stage.

## Read-Only Relocations (RELRO)

This makes some binary sections Read-Only, you have to understand how C calls functions work, like `printf` to understand this. The program doesn't actually know where `printf` lives in memory because it is in a separate library `libc`. It uses a lookup table called the **Global Offset Table** to find the address of `printf`.
This means that can go for the middle man, they would perform a GOT Overwrite.
RELRO makes this lookup table **Read-Only** so hackers can't edit it.

## `_FORTIFY_SOURCE` Macro

glibc 2.3.4 introduced `_FORTIFY_SOURCE` in 2004 to catch security errors due to misuse of some C library functions. The initially supported functions were `fprintf, gets, memcpy, memmove, mempcpy, memset, printf, snprintf, sprintf, stpcpy, strcat, strcpy, strncat, strncpy, vfprintf, vprintf, vsnprintf, vsprintf` and focused on buffer overflow detection and dangerous `printf` `%n` uses. The implementation leverages inline functions and `__builtin_object_size`. More functions were added over time and `__builtin_constant_p` was used as well.

`__fortify_function` is a macro which expands to `extern__inline__attribute__ ...`. 