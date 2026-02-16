16-02-2026 12:52

Tags: [[Distributed Systems]]

# Deadlock

Deadlock occurs when 4 conditions hold simultaneously:

1. **Mutual Exclusion**: At least one resource must be non-shareable.
2. **Hold and Wait**: A process is currently holding at least one resource
3. **No Pre-Emption**: Once a process has acquired a resource, nothing can force it to relinquish the resource.
4. **Circular Wait**: A process must be waiting for a resource that is being held by another process and that process is waiting for the resource held by this resource.

## Dealing with a Deadlock

There are three potentially sensible strategies for dealing with a deadlock:

**Prevent:** You prevent the deadlock from occurring in the first place by making sure that it is never possible for all four of the conditions to be true at the same time.




