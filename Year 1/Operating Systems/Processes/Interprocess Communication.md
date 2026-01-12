17-05-2025 00:15

Tags: [[Operating Systems]]

# Interprocess Communication

Sometimes processes do 'their own thing', each process has its own [[Processes#Context|context]] that is protected from other processes, **Interprocess communication** requires some form of operating system intervention.
What Interprocess communication (IPC) refers to are the mechanisms provided by the operating system that allows processes to exchange data and coordinate their actions with each other.

If processes (or threads) share some RAM they can communicate using that:

![[Comms_shared_mem.png#invert]]

Why is an IPC needed?
- Enable resource sharing,
- To coordinate actions, e.g. waiting for another process to finish before commencing its own operations,
- Allowing modular applications to be broken into cooperating processes.

---

**Understanding Producer & Consumer:**

- Producer: The process that creates or sends data,
- Consume: The process that uses or receives data,

Think of the producer as someone placing parcels of (data) on a conveyor belt (pip, message queue, etc.), and the consumer picks them up and opens them.


## Simple Flag Protocol

We can have a simple **producer-consumer** model for a protocol whereby one protocol is the **consumer** and the other the **producer**:

Process A (Producer):
- Waits for flag to be `FALSE`.
- Writes data to shared array.
- Sets flag to `TRUE`.

Process B (Consumer):
- Waits for flag to be `TRUE`.
- Reads the data.
- Sets flag back to `FALSE`.

However, in most scenarios this case isn't enough:

1. Non-atomic operations (i.e.`i++`, which may seem atomic isn't) 
2. Instruction reordering - modern CPUs and compilers often reorder instructions for optimisation which will break this protocol:

```C
flag = true;
buffer[0] = 42;
```

this could be reordered to write to `buffer` first, which can break the protocol.

## Files

Processes can also communicate through files, whereby they save to file and the files contents can be visible to all processes on the system which have the permission to read them.
- This is good for large quantities of data.

## Messages

These are data blocks that are sent from process to process. There is no storage of any data.
This method can be seen with web browsers (browser to server).
And also with packets (the internet).

When passing messages it is typical that the producer and consumer setup a *one-to-one basis*: one message sent, one received.

### Synchronous
Message passing can be **synchronised**. In synchronous messaging the '**output**' and '**input**'
are compelled to 'meet' at the **'rendezvous'**. Whoever reaches this point first is blocked until the other arrives.

### Asynchronous
Asynchronous here means non-blocking whereby the producer send the message to a queue and moves on.
With asynchronous message passing, there is a concept of **elasticity**, where a message queue is maintained so the producer may get some 'distance' ahead of the consumer. 

## Pipes

A pipe is a unidirectional communication channel that allows one process to send data to another, kind of like a straw: from the **producer** to the **consumer.**


```C
#include <stdio.h>
#include <unistd.h>   // for pipe(), fork(), read(), write()
#include <string.h>   // for strlen()
#include <stdlib.h>   // for exit()

int main() {
    int pipefd[2]; // [0] = read end, [1] = write end
    pid_t pid;
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork(); // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // --- Child Process ---
        close(pipefd[1]); // Close unused write end

        // Read from pipe
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(pipefd[0]); // Close read end
    } else {
        // --- Parent Process ---
        close(pipefd[0]); // Close unused read end

        const char *msg = "Hello from parent!";
        write(pipefd[1], msg, strlen(msg) + 1); // include null terminator

        close(pipefd[1]); // Close write end
    }

    return 0;
}

```

## Signals

The term 'signal' is used in different ways.

- *Wait and Signal*: a means of synchronisation, where processes (or threads) block and unblock each other.
- In Unix 'Signal' is used as a term for synchronous events. These events are similar in principle to interrupts although they are software generated, mediated by the OS. 