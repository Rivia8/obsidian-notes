27-05-2025 22:11

Tags: [[Java]]

# Threads

## Multithreading Motivation

Multithreading allows a single processor to look like its essentially doing multiple things at once when rather its not - its time slicing.

**Time-Slicing** is a technique that by which the processor's time is distributed across processes.

Although typically this is handled by the operating system,

Java provides built-in support for multithreading through its `java.lang.Thread` class and `java.lang.Runnable` interface, along with a powerful `java.util.concurrent` package (introduced in Java 5).


## Implementing the Runnable interface

1. First you create class that `implements` the `Runnable` interface.
2. Implement the `run()`: Override the `run()` method. This method contains the code that the new thread will execute:

```Java
public void run() {
	// Code to be executed by the thread.
}
```

3. Create a `Thread` **Object**: instantiate a `Thread` object, passing your `Runnable` instance to its constructor.
```Java
Runnable myTask = new MyRunnable();
Thread thread = new Thread(myTask);
```

4. Start the Thread: Call the `start()` method on the `Thread` object, this method tells the JVM to create a new execution thread and call its `run()` method. Do not call `run()` directly as that would simply execute the code in the current thread and not a new thread.

e.g.:

```Java
class MyRunnableTask implements Runnable {
    private String taskName;

    public MyRunnableTask(String name) {
        this.taskName = name;
    }

    @Override
    public void run() {
        for (int i = 0; i < 3; i++) {
            System.out.println(taskName + ": " + i + " - Thread ID: " + Thread.currentThread().getId());
            try {
                Thread.sleep(500); // Pause for 500 milliseconds (simulate work)
            } catch (InterruptedException e) {
                System.out.println(taskName + " was interrupted.");
                Thread.currentThread().interrupt(); // Restore the interrupted status
            }
        }
    }
}

public class RunnableExample {
    public static void main(String[] args) {
        System.out.println("Main thread started. ID: " + Thread.currentThread().getId());

        // Create tasks
        MyRunnableTask task1 = new MyRunnableTask("Task A");
        MyRunnableTask task2 = new MyRunnableTask("Task B");

        // Create threads and start them
        Thread thread1 = new Thread(task1);
        Thread thread2 = new Thread(task2);

        thread1.start();
        thread2.start();

        System.out.println("Main thread finished initiating tasks.");
        // The main thread continues its execution while thread1 and thread2 run concurrently.
    }
}
```

## Extending the Thread Class

This uses the `Thread` class. It's simpler for basic tasks but less flexible as your class cannot extend any other class.

```Java
import java.util.concurrent.TimeUnit;

class MyThread extends Thread {
    private String threadName;

    public MyThread(String name) {
        this.threadName = name;
    }

    @Override
    public void run() {
        // This is the code that this thread object will execute
        System.out.println(threadName + " started in thread: " + Thread.currentThread().getName());
        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            System.out.println(threadName + " was interrupted while sleeping.");
            Thread.currentThread().interrupt();
        }
        System.out.println(threadName + " finished in thread: " + Thread.currentThread().getName());
    }
}
```

Now you can create an instance of your custom thread class:

```Java
// Create an instance of your custom thread class
MyThread thread2 = new MyThread("MySecondThread");

// Start the thread. This tells the JVM to create a new system thread
// and execute the `run()` method of this `thread2` object in that new thread.
thread2.start();
```

