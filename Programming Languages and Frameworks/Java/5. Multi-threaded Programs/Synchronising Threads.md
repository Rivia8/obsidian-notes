29-05-2025 15:29

Tags: [[Java]]

# Synchronising Threads

When it comes to [[Java Threads]] and multithreading is managing access to shared resources to prevent **race conditions** and ensure data consistency.
A **race condition** occurs when multiple threads try to access and modify shared data concurrently and the final outcome depends on the unpredictable order in which the threads execute.

**Synchronisation** is the mechanism used to control access to shared resources by multiple threads, ensuring that only one thread can access the critical section.

## Synchronised Keyword

One of the basic (and most commonly used form of synchronisation) is using the `synchronized` keyword.

Every Java object has a lock.
And when a `synchronised` instance method is called, the thread acquires the lock of the object on which the method is called.
When a `synchronised` static method is called, the thread acquires the lock of the class object itself.

Only one thread can execute any `synchronized` method (instance or static) of that specific object at a time.

```Java
public class Counter {
    private int count = 0;

    // Synchronized instance method: locks 'this' object
    public synchronized void increment() {
        count++; // Critical section
    }

    public synchronized int getCount() {
        return count; // Critical section
    }
}
```

When you have a `synchronised` block it allows you to specify a particular object whose lock you want to acquire, the `Object` inside the parentheses is the 'monitor' or 'lock' that threads will contend for.

```Java
public class SharedResouces {
	private int value = 0;
	private final Object lock = new Object();

	public void modifyValue() {
		// Only one thread can execute this block at a time, for 'this.lock'
		synchronised (lock) {
			value ++;
		}
	}
	
	public void printValue() {
		synchronised (lock) {
			System.out.println(value);
		}
	}
}
```

## States

When it comes to [[Java Threads]] a way to summarise what is going on, is by looking at a state transition diagram:

![[Pasted image 20250529170344.png#invert]]