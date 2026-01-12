06-11-2025 16:54

Tags: [[C]]

# Application Programming Interface

In our program files, each source file exposes a set of functions that can be called from other files.
The interface should be as small as possible to hide internal module code and data.

*To understand this we will look at the example established in [[Modular Compilation]]*.

Let's say we have the methods: `rcv_request()`, `init_network()` and `parse_req()` that follow the command flow:


![[interractions.svg#invert|400]]

- When the program starts, in order to initialise networking, `main.c` calls `init_network()` which is implemented in `network.c`.
- `main.c` then runs the main sever loop:
    - `main.c` calls `rcv_request()` implemented in `network.c` to wait for the next request.
    - When a request is received, `main.c` calls `parse_req()` which is implemented by `parser.c` to process the request.
    - Rinse and repeat.


## Defining APIs with Header Files

To define an API you create a header file (a .`h` file). This file is the public menu for the module. It only contains declarations that you want other people to see. These files are usually tell the programmer **what** is happening and not **how** you have implemented the solution to something.

What needs to be included in the `.h` file:
- **Function Prototypes** - this is the most important part, this is the function signature and its ended with a semicolon.
- `struct` Definitions - if the function uses a custom `struct`, the definition must be in the header.
- `#define` Constants - any public constants others might need.

You **must not** put these things in the `.h` file:
1. **Function Definitions:** The actual code (the `{ ... }` block). This belongs in the `.c` file.
2. **Private Variables:** Any global variables used _only_ by your module.

So how would the above file system be implemented now?:
![[modular3.svg#invert|400]]
`network.h` would like the following:

```C
#ifndef NETWORK_H // include guard
#define NETWORK_H

typedef struct {
    int id;
    char content[128];
} request;

void init_network();
int rcv_request(request *r);

#endif /* NETWORK_H */
```

…and this would be the `network.c` implementation:

```C
/* std includes here */
#include "network.h"

// this function and variable are internal
// so they are not declared in network.h
// the keyword static force their use
// to be only within the network.c file
static void generate_request(request *r);
static int request_counter = 0;

void init_network() {
    /* init code here ... */
}

int rcv_request(request *r) {
    generate_request(r);
    /* ... */
}

static void generate_request(request *r) {
    /* ... */
}
```

Same for `parser.h`:

```C
/* parser.h */

#ifndef PARSER_H
#define PARSER_H

/* needed for the definition of request: */
#include "network.h"

void parse_req(request *r);

#endif
```

and `parser.c`

```C
/* parser .c */
#include "parser.h"

static void internal1(request *r);
static void internal2(request *r);

void parse_req(request *r) {
    internal1(r);
    internal2(r);
}

static void internal1(request *r) {
    /* ... */
}

static void internal2(request *r) {
    /* ... */
}
```

`main.c` would look like the following:

```C
/* main.c */

#include "network.h"
#include "parser.h"

int main(int argc, char **argv) {
    request req;

    /* call functions from network module */
    init_network();
    rcv_request(&req);

    /* call function from parser module */
    parse_req(&req);
    /* ... */
}
```

You might have noticed that in the `.h` files there is a 'Header Guard'. This is a special preprocessor 'trick'. This because there can be a convoluted dependency with the inclusion of certain libraries, let's say `main.c` includes `lib1.h` and `lib2.h` but `lib1.h` *also* includes `lib2.h`. This will cause the preprocessor to copy `lib2.h` twice.
In order to prevent this problem and make it 'safe', a header guard is used which is wrapper that is put around the entire contents of the header file.

Three processor directives are used:
- `#ifndef` - if not defined
- `#define` - then define
- `#endif` - end of the block


