19-11-2025 14:16

Tags: [[C]]

# Memory Safety

C is inherently **not memory-safe** this is one of the big things when it comes to C.
What this means is that there is no protection against a range of bugs when dealing with memory accesses. These bugs can relate to spatial safety.

**Spatial Safety:** the C programmer is free to read or write anywhere they want in memory. These include things like 'out of bound array accesses' and bad pointer dereference etc.

**Temporal Safety:** the compiler cannot check things like accessing a dynamically-allocated buffer after it has been freed, these can lead to undefined behaviour.

Adding memory checks to make it memory safe hurts performance. All the issues related to memory unsafety are quite hard to debug and they can be hard to reproduce.

'The lack of memory safety in C/C++ is very problematic: recent numbers by [Google](https://www.zdnet.com/article/chrome-70-of-all-security-bugs-are-memory-safety-issues/) and [Microsoft](https://www.zdnet.com/article/microsoft-70-percent-of-all-security-bugs-are-memory-safety-issues/) show that about 70% of the security vulnerabilities found stem from memory safety-related bugs. The NSA [reports](https://media.defense.gov/2023/Dec/06/2003352724/-1/-1/0/THE-CASE-FOR-MEMORY-SAFE-ROADMAPS-TLP-CLEAR.PDF) that the most prevalent type of disclosed software vulnerabilities are memory safety ones, and encourage, among [others](https://www.whitehouse.gov/wp-content/uploads/2024/02/Final-ONCD-Technical-Report.pdf), the transition to memory safe languages. That transition is however not going to happen overnight given the huge amount of legacy/existing software written in memory unsafe languages.'

## Examples of Memory Leaks

### Infoleak

This example has the following assumptions, a security-sensitive program is distributed in binary-only form. It contains a password. An attacker has access to the binary but not the source code.

```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *welcome_message = "Hi there! How is it going?\n"; // 27 char
char *password = "secret";
char entered_password[128];

int main(int argc, char **argv) {
    // Print welcome message character by character
    for(int i=0; i<27; i++) {
        printf("%c", welcome_message[i]);
    }

    printf("Please input the password:\n");
    scanf("%s", entered_password);

    if(!strcmp(entered_password, password)) {
        printf("Passowrd ok!\n");
    /* ... */
    } else {
        printf("Wrong password! aborting\n");
    }

    return 0;
}

```

If the programmer reduces the size of the welcome message, it would cause an overflow for the pointer - it starts pointing to the next thing in memory, in this case it is the password that we allocated at the beginning.

### Sensitive Data Tampering

```C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char user_input[32] = "00000000000";
char password[32] = "secret";

int main(int argc, char **argv) {

    if(argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 0;
    }

    strcpy(user_input, argv[1]); // oopsie!

    if(!strncmp(password, user_input, strlen(password))) {
        printf("login success!\n");
        /* do important stuff  ... */
    } else {
        printf("wrong password!\n");
        exit(-1);
    }

    return 0;
}
```

The attacker will not try to leak the password but rather to bypass the password check.

This can be done if the programmer does **not** include a size checker for the input, this leads to the hacker being able to input a string of characters that exceeds the `user_input` array which overflows into the `password` array, this allows the hacker to put their own password in by having the first 32 characters be the `user_input` and the last 32 bits be the `password`. This is due to the fact that the two arrays are most likely stored contiguously in memory.

### Stack Smashing

This is an old attack, where a buffer overflow can be exploited on the stack to take over the control flow of an application.

The main idea is to overwrite the return address of a function `f` with the address of the code the attacker wishes to execute: when `f` returns, rather than returning to `f`'s caller, the program jumps to the target code.

```C
char *password = "super-secret";

void caesar_encrypt(char* text) { /* ... */ }

void security_critical_function() {
    printf("launching nukes!!\n");
}

void preprocess_input(char *string) {
    char local_buffer[16];
    strcpy(local_buffer, string); // Oopsie!

    /* work on local buffer ... */
    return;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s <password>\n", argv[0]);
        return -1;
    }

    preprocess_input(argv[1]);

    if(!strncmp(password, argv[1], strlen(password)))
        security_critical_function();
    else
        printf("Unauthorized user!\n");

    return 0;
}
```

If you look at the program, it takes a password attempt as a command line parameter, it is passed through a function `preprocess_input` that copies the parameter value in a local buffer with `strcpy`, and performs some processing on that copy. The password attempt is then checked against the correct password with `strncmp`.
The bug here is that `strcpy` does not check for the size of `string` prior to copying it in `local_buffer`, letting the attacker overflow that buffer if data passed on the command line is larger than 16 bytes.
The attacker simply uses the overflow to overwrite the return address of `preprocess_input` with the address of `security_critical_function` in order to bypass the password check

### Use-After-Free

A use-after-free happens when the programmer mistakenly uses an object after it has been freed.

```C
typedef struct {
    double member1;
    double member2;
    void (*member3)(int);
} my_struct;

void print_hello(int x) {
    printf("Hello, parameter: %d\n", x);
}

void security_critical_function() {
    printf("Launching nukes!\n");
    /* ... */
}

int main(int argc, char **argv) {

    /* allocate and init ms */
    my_struct *ms = malloc(sizeof(my_struct));
    ms->member1 = 42.0; ms->member2 = 42.0;
    ms->member3 = &print_hello;

    /* call the function pointer */
    ms->member3(12);

    free(ms);

    char *buffer = malloc(12);
    strcpy(buffer, argv[1]);

    ms->member3(12); // Oopsie!
    exit(0);
}
```

`ms` is allocated with `malloc`, then freed, then mistakenly used right before the call to `exit(0)`. The issue is not caught by the compiler and may not be caught during run time.

There is once again a lack of check on the size of the command line argument, and once again the attacker can overflow the memory pointed by the buffer.
The main way to explain this type of vulnerability, is to replace the data structure being used after free with a payload that will corrupt the behaviour of the program once the use-after-free happens.

`buffer` and `ms` are allocated on the heap.
`ms` is then freed.

`malloc` manages allocations on the heap, and to avoid memory waste `malloc` will reuse freed memory to serve new allocation requests, the pointed area `ms` will be reused for `buffer`. Through buffer overflow, the attacker will have control over the content of  `buffer`, the attacker is going to write inside `buffer` the address of the `security_critical_function`.

![[use-after-free-3.svg#invert|800]]
## Conclusion

C is not memory safe, the memory safety bugs introduced by programming mistakes lead to not only crashes but more importantly to security vulnerabilities that can have serious consequences.