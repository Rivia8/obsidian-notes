15-08-2025 17:47

Tags: [[Java]] [[Java Collections Framework]]

# Queue

The `Queue` interface is designed for holding elements in a collection before they are processed. The defining feature is the **First-In, First-Out (FIFO)** principle.

The easiest way to understand a queue is to think of it as an actual queue at like a supermarket where the first person is the first to get served.

# Priority Queue

`PriorityQueue` is a special type of queue that orders its elements based on their priority, rather than the ordered they were added.

When something like a `LinkedList` implements queue it works on JUST the FIFO principle. The `PriorityQueue` however, is a bit different in the sense it doesn't work on that alone but also based on the fact that some elements just have higher ***priority***. A good analogy would be a hospital room, where patients are treated based on the severity of their condition.

A `PriorityQueue` uses the element's "natural ordering" (if the class implements `Comparable`, like `Integer` or `String`) or a custom `Comparator` to determine priority. By default, the element with the "smallest" value is considered the highest priority.

```Java
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class QueueComparison {
    public static void main(String[] args) {
        // A LinkedList follows FIFO order
        Queue<Integer> fifoQueue = new LinkedList<>();
        fifoQueue.offer(20);
        fifoQueue.offer(5);
        fifoQueue.offer(10);
        System.out.println("LinkedList (FIFO) order:");
        while (!fifoQueue.isEmpty()) {
            System.out.print(fifoQueue.poll() + " "); // Prints in the order they were added
        }

        System.out.println("\n\n---");

        // A PriorityQueue follows priority order (natural order for integers)
        Queue<Integer> priorityQueue = new PriorityQueue<>();
        priorityQueue.offer(20);
        priorityQueue.offer(5);
        priorityQueue.offer(10);
        System.out.println("PriorityQueue order:");
        while (!priorityQueue.isEmpty()) {
            System.out.print(priorityQueue.poll() + " "); // Prints in ascending numerical order
        }
    }
}
```