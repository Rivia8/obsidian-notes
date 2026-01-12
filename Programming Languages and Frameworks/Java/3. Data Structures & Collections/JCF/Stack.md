28-05-2025 21:57

Tags: [[Java]]

# Stack

The stack uses the core principle of LIFO (like a stack of plates).
There are common operations that it has:

- `push(item)`: Adds an item to the top of the stack.
- `pop()`: Removes and returns the item from the top of the stack.
- `peek()`: Returns the item from the top of the stack **without** removing it.
- `isEmpty()`: Checks if the stack contains no items.
- `size()`: Returns the number of items in the stack.
- `clear()`: Removes all elements.

Both [[List - ArrayList#ArrayList|ArrayList]] and Stack implement the `List` interface, this means that we can declare both of them using their common ancestor:

```Java
List<String> shoppingList = new ArrayList<String>();
List<String> readingPile = new Stack<String>();
```



