19-11-2025 16:14

Tags: [[C]]

# Secure Coding Practices

Since the language is not [[Memory Safety|memory safe]] we need to be able to incorporate practices that make sure that we can actually produce secure code.

We have seen that memory safety and undefined behaviour issues are common in software written in C and that can lead to issues that lead to security vulnerabilities that can be exploited by attackers to do various forms of bad things.

What can we do?

1. Adhere to good coding practices, 
2. Techniques that can help analyse our code during development and detect some bugs,
3. Techniques to help protect our program during production


## Preventing Overflows

Overflows occur with arrays, buffers and integers.

To prevent array buffer overflows, in C remember that the sizes of the arrays are not embedded so **you** need to keep track of the size of each array/buffer you use - this is important because you need to know the size of an array to know when to **stop** iterating.

For integers, its important to remember how much size the compiler holds for that data type and architecture you are programming for, one thing you can use is the `sizeof()` command to determine these sizes.
The compiler has some built in functions that can tell you if an integer operation overflows:

```C
bool __builtin_add_overflow (type1 a, type2 b, type3 *res)
```

## Unsafe LibC functions

Here are some unsafe lib functions:

|Unsafe Function|Why It Is Unsafe|Safe Alternative(s)|
|---|---|---|
|`gets()`|No bounds checking; allows buffer overflows|`fgets()`|
|`strcpy()`|No bounds checking; can overflow destination buffer|`strncpy()`, `strlcpy()` (if available)|
|`sprintf()`|No bounds checking; leads to buffer overflows|`snprintf()`|
|`scanf()`|No bounds checking e.g., `%s` with no width|`fgets()` + `sscanf()` with width specifiers|
|`memcpy()`|No bounds checking; can cause overflows|Use with care; consider `memmove()` for overlapping memory|
|`bcopy()`|Obsolete; unsafe due to no bounds checking|`memmove()`|
|`strlen()`|Not inherently unsafe, but must not be used on untrusted or unterminated buffers|Ensure string is null-terminated before use|
The safe version should be used when possible for these functions.
[Here are some more functions avoid](https://docs.fedoraproject.org/en-US/defensive-coding/programming-languages/C/#sect-Defensive_Coding-C-Avoid)

When it comes to libc string manipulation functions, you should make sure to use the `n` versions that force you to indicate a maximum number of characters to process. This is not perfect though.

If you look at the following example:

```C
char string1[] = "hello, world";
char string2[32] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
strncpy(string2, string1, strlen(string1));
printf("%s\n", string2); // prints "hello, worldxxxxxxxxxxxxxxxxxxx"
```

You might thing all is good, but what happens is that since you have asked to copy *exactly* 12 bytes, it does in fact **not** count the null terminator. So what has happened here is that the 12 first bytes of `string1` are copied over to the first 12 bytes of `string2` (the first 12 bytes of `string1` excludes the null terminator), this leads to `string2` having the 'Hello, World' but then the rest being all the x's. 
`String2` hasn't changed the amount of characters it contains.

## Dynamic Memory Allocation

When using dynamic memory allocation, make sure to check `malloc`'s return value.

Always be wary with `realloc` since it will return `null` upon failure, so make sure it does not overwrite the original pointer to the buffer you want to increase the size, otherwise you will get a leak.

```C
ptr = realloc(ptr, new_size)
```

So if `ptr` pointed to a valid address `0x100`, you then call `realloc` but the system fails since it is out of memory, so it returns `null`. The memory at `0x100` is still allocated but the `ptr` which is the only thing that was pointing to `0x100` is now `null`, now you can no longer `free` it, this causes a memory leak.

Another point to remember is the difference between `malloc` and `calloc` - `calloc` scrubs the appointed memory block clean whilst `malloc` just retrieves it as is, `calloc` is therefore a bit *slower* but is much more safer: if sending the data to an 'untrusted context' the receiver might be able to analyse that garbage data and find sensitive information leaking from the RAM.

## Dead Pointers

If a `ptr` is freed the best thing to do with that `ptr` is then set it as `null` this is because the variable will still hold the address to that piece of memory, its just that there isn't anything there anymore. 
So if you were to still use `ptr`, it would result you in corrupting other pieces of memory or a SegFault.