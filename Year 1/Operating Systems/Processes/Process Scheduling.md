25-04-2025 22:56

Tags: [[Operating Systems]]

# Process Scheduling

**Process Scheduling** determines the execution order of processes in a system. 
When it comes to 'multitasking' this just really means swapping in and out different processes to do (at least for a single core and threaded CPU).

The approach to scheduling varies according to the purpose of the computer system - sometimes referred to as a 'processing mode'.

## Interactive Processing

This is a familiar type where the user constantly interacts with the computer.

A common approach is **"Round Robin"**, this gives all processes equal 'turns' but taking the next process from the front of a FIFO queue whilst appending de-scheduled process to the back.

## Real-time Processing 

This is used in systems where you need **predictability** and **stability.**
This scheduling guarantees response within a certain, maximum **latency**.

Real-time schedulers typically rely heavily on **priority**, where some processes are identified as being more urgent than others, the more urgent ones needing lower latency.

This method sometimes gets two types of constraints:
- A **hard** real-time constraint, where failure to meet a constraint results in a failure.
- A **soft** real-time constraint, where delay leads to annoyance.

## Batch Processing

This picks a particular job and completes it before proceeding to the next - it is not responsive to interactions but is efficient for straight processing.

A common approach is the 'Shortest Job First' or 'Shortest Remaining Time'. This does the job that has the shortest burst time.

