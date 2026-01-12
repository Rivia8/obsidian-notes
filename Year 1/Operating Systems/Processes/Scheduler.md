26-04-2025 00:22

Tags: [[Operating Systems]]

# Scheduler

The reason we schedule is that a computer may have multiple processes to run but the choice of how to run them may be influenced by how they are being used.

When it comes to scheduling the scheduler has will have the processes in certain states:

| State                 | Description                                                                        |
| --------------------- | ---------------------------------------------------------------------------------- |
| **Running**           | Process is currently using the CPU.                                                |
| **Ready**             | Process is waiting for CPU time but is otherwise good to go.                       |
| **Blocked (Waiting)** | Process is waiting on something external, like I/O, user input, or a file to load. |
| **Terminated**        | Process has completed or been killed. _(Optional extra state)_                     |

Here's a brief summary of Scheduling algorithms:

| Algorithm                          | Description                                         | Best for                             |
| ---------------------------------- | --------------------------------------------------- | ------------------------------------ |
| **First-Come First-Served (FCFS)** | Runs processes in arrival order                     | Simple batch jobs                    |
| **Round Robin (RR)**               | Each process gets a fixed time slice in a cycle     | Interactive systems                  |
| **Shortest Job First (SJF)**       | Runs shortest estimated job first                   | Efficient batch processing           |
| **Priority Scheduling**            | Higher priority processes run first                 | Real-time / critical tasks           |
| **Multilevel Queue**               | Different queues for different types/priorities     | Complex OS setups                    |
| **Multilevel Feedback Queue**      | Processes can move between queues based on behavior | Balances fairness and responsiveness |

## Process States

When it comes to scheduling, the processes require certain states to be in.


![[Pasted image 20250430145331.png#invert]]

If a process does not block, we can schedule using something called **time-splicing** which allows the process to run for a certain time and then force it to swap for one of the waiting processes.

From the waiting or blocked state, the process must first become ready.

### Why will a Process be Waiting:

A process may wait for the following reasons:

- For input from a file or device,
- For output to a file or device,
- For the right time to run,
- Due to system issues,
- For permissions,
- For a processor to become available.

### How Does a Process Get Out of the Blocked State:

They require some form of external event to elapse before being able to move to the "Ready" state and the scheduler will then need to choose it.
These could be:

- If the current process running terminates or blocks,
- With  cooperative scheduling, when the running process 'yields',
- In a time-sliced system, when it has been running 'long enough' for the OS to 'give someone else a turn' - A **Round Robin** scheduling algorithm.
- - in a pre-emptive system if a process with a higher priority becomes ready.