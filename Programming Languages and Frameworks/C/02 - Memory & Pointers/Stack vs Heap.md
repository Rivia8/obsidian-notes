25-10-2025 14:21

Tags: [[C]]

# Stack vs Heap

An understanding of the Stack and Heap in memory is good in order for a complete understand as to where things are being allocated in your program.

## Stack

To understand the stack, you first need to understand the stack data structure:
- Its like a stack of plates, 
- You can add plates (functions, variables, etc.) to the top of the stack of plates but can't add things in the middle nor the bottom,
- This means you can only access things at the top of the stack and have to 'pop' everything above to get to things at the bottom.

The Stack is also responsible for **local** variables, these are variables that have limited scope i.e. they are limited to functions. 
Its quite fast and is 'automatic' and therefore is usually used for 'temporary' calls.

## Heap

Functions and variables can be accessed from anywhere, so it's unorganised and bigger. Because its an unorganised pool of memory, there is a much larger overhead - it's bigger but much slower. This means that it is usually used for things that will outlive things that are on the Stack.
When it comes to dealing with the heap, everything is manual - the memory stays allocated until you explicitly free it with `free()`, no matter what function created it.
