
25-10-2025 14:03

Tags: [[C]]

# Dynamic Memory Allocation

There are technically two types of memory location, static and dynamic. 
Static memory location is what you're most likely familiar with, this means that the memory space reserved for variables we used is determined at compile time.
But there are some scenarios in which the amount of space needed is only known at runtime.

To understand the difference between static and dynamic memory allocation, you also need to understand the difference between the [[Stack vs Heap|stack and heap]]

Here is an example:

```C
int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <array size>\n", argv[0]);
        return -1;
    }

    int size = atoi(argv[1]);
    int array[size]; // variable-sized array
    
    for(int i=0; i<size; i++) {
        array[i] = i;
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
```

Here the `size` is only known at runtime and this this is a variable-sized array.
Variable sized arrays are rarely used in C because they have many downsides.

So in memory there are 4 parts:
1. The Stack
2. The Heap
3. The Static/Data Segment
4. Text Segment

The static memory is for things that are allocated once and that do not change once within the program, things like global variables. These last for the entire program's execution.
Static variables and or functions are those that are **not** placed on the stack, this means that they do not get freed once they have been done with like things on the stack do.

## Allocating on the Heap

When it comes to allocating memory yourself on the heap, you only need a few functions from `<stdlib.h>` to manage the heap.

1. `malloc` (Memory Allocation)

This is the 'ask' function, it stands for 'memory allocation'. It asks the OS for a number of bytes on the heap and you **must** tell it exactly how many bytes you want. You should use `sizeof()` call to be safe.
When this is called it returns a `void*` (a generic pointer), to the start of that new memory block and it must be cast to type you want.

```C
// How to ask for memory for a single integer:
int *ptr_to_int = (int*)malloc(sizeof(int));

// How to ask for memory for an array of 50 floats:
float *ptr_to_floats = (float*)malloc(50 * sizeof(float));
```

2. `free` (Returning the Memory)

This is freeing the memory space. You pass it to the exact same pointer you got from the `malloc` call.

```C
// Give back the memory we borrowed
free(ptr_to_int);
free(ptr_to_floats);
```

3. `calloc` (The 'clean' Allocator)

This is a variation of `malloc`, it's similar in the sense that it takes two arguments, the number of items and the size of each item. The difference is that it initialises the memory to all zeroes. On the other hand, `malloc` just gives you raw uninitialized memory - it give's you garbage data.

```C
int *ptr = (int*)calloc(100, sizeof(int));
```

4. `realloc` (The 'Resizer')

If you asked for 50 floats, but you need 100 - to overcome this you can try to resize a block of memory you've already allocated. You use it like this:

```C
int *new_ptr = (int*)realloc(old_ptr, new_size);
```


### The Dangers of this:

1. Memory Leaks

- **What it is:** Forgetting to `free()` memory.
- **Analogy:** You keep renting storage units and throwing away the keys.
- **The Result:** Your program's memory usage grows and grows. A small program might be fine, but a web server that does this will eventually consume all the server's RAM and crash. This is a **memory leak**.

There is a useful program called 'Valgrind' that checks for memory leaks.

1. Dangling Pointers

- **What it is:** Using a pointer _after_ you have `free()`d it.
- **Analogy:** You check out of a hotel room, but you keep a copy of the key. You sneak back in, but the hotel has already rented the room to someone else.
- **The Result:** You are now writing data into memory that you no longer own. This is **undefined behavior**. You might corrupt another part of your program, or you might crash immediately.
- **Best Practice:** After you `free(ptr)`, immediately set `ptr = NULL;`. This "defuses" the pointer.

3. Double Free

- **What it is:** Calling `free(ptr)` twice on the same pointer.
- **The Result:** This corrupts the Heap's internal bookkeeping. It will almost certainly crash your program in a very confusing way.

