17-05-2025 22:48

Tags: [[Operating Systems]]

# Zombie Process

A Zombie process is a process that has completed it execution but still remains in the **process table** because its parent process has not yet read its exit status.

It might be implied that they use system resources like CPU usage and memory but they do not, but rather clutter the process table and might make it so new processes cannot be created.

- Child process finished executing ---> parent process has not called `wait()` yet ---> 

Example of Zombie Process:

```C
// A C program to demonstrate working of
// fork() and process table entries.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    int i;
    int pid = fork();

    if (pid == 0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
    }
    else
    {
        printf("I am Parent\n");
        while(1);
    }
}
```

Here it outputs "I am a child" for PID = 0, but after the child process finishes executing there is a zombie process created.

The reason why the process becomes a zombie process is that once the child process finishes executing it usually calls `exit()` but this does not immediately update the process table but rather then requires the **parent** process to check and update the state of the child process.

- Child finished executing - PID stored, exit code stored, other info stored
- Parent needs to call `wait()` or `waitpid()` to check and update the process table.