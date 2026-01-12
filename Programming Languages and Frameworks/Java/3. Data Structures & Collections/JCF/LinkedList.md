28-05-2025 22:09

Tags: [[Java]]

# LinkedList

The linked list implements both the Queue and List interfaces.
Here we will be talking about it using the Queue interface.

It follows the **FIFO** principle, first-in first-out.

Common operations include:

- `add(item)` or `offer(item)`: Adds an item to the back (or "tail") of the queue, `add` throws an exception if full, `offer` returns `false`.
- `remove()` or `poll()`: Removes and returns the item from the front (or "head") of the queue, `remove` throws an exception if empty, `poll` returns `null`.. 
- `element()` or `peek()`: Returns the item from the front of the queue **without** removing it. `element` throws an exception if empty, `peek` returns `null`.
- `isEmpty()`: Checks if the queue contains no items.
- `size()`: Returns the number of items in the queue.

Here is an example of it being used:

```Java
import java.util.LinkedList;
import java.util.Queue;

public class SupermarketQueue {

    public static void main(String[] args) {
        // 1. Create a Queue using a LinkedList
        Queue<String> customerQueue = new LinkedList<>();

        // 2. Add customers to the back of the queue using offer()
        customerQueue.offer("Alice");
        customerQueue.offer("Bob");
        customer.offer("Charlie");

        System.out.println("Customers in line: " + customerQueue); // [Alice, Bob, Charlie]

        // 3. Peek to see who is at the front of the line
        String nextCustomer = customerQueue.peek();
        System.out.println("Next to be served: " + nextCustomer); // Alice

        // 4. Process the queue until it is empty
        while (!customerQueue.isEmpty()) {
            // Remove the customer from the front using poll()
            String servedCustomer = customerQueue.poll();
            System.out.println("Serving: " + servedCustomer);
            System.out.println("Remaining in line: " + customerQueue);
        }
    }
}
```