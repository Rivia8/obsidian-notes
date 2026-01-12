18-05-2025 17:46

Tags: [[Operating Systems]]

# Deadlock

This describes a situation where progress cannot be made.

Usually a process can deadlock if they are competing for resources with each other:

![[Pasted image 20250518181343.png#invert]]

Each is waiting for the other to release what they need and so neither proceeds.
This causes a **circular wait** and so leads to deadlock.

There are some necessary conditions for deadlock:

1. **Mutual Exclusion** - At least one resource is held in a non-shareable mode,
2. **Hold and Wait** - A process holding one resource is waiting to acquire additional resources,
3. **No Pre-emption** - Resources cannot be forcibly taken from a process; they must be released voluntarily,
4. **Circular wait** -  A closed chain of processes exists where each process holds at least one resource the next process needs.

## Preventing Deadlock

When it comes to preventing deadlocks there are solutions but they almost always come at a cost.

### Ordering Claims

If all processes makes claims in the same order, the one which has progressed 'furthest' will not be blocked, will continue to completion and will release the resources for others to use.

```C
X: get A → get B
Y: get A → get B
```

And so whoever wants 'A' and has gone furthest will do so.
The issues with this is that it requires coordination, which might not be possible.
### Back Off

"If a request is denied, give up and start again."
Pretty much if a process cannot get all the resources it needs, it releases everything it has and tries again later.

```C
// Process X
lock(A);
if (!trylock(B)) {
    unlock(A);
    sleep_and_retry();
}

// Process Y
lock(B);
if (!trylock(A)) {
    unlock(B);
    sleep_and_retry();
}

```

If one tries to A tries to grab B and B tries to grab A, one of them will fail, back off and retry.

The issue with this is that you could have **Live lock**:
- Whereby processes might keep releasing and retrying at the same time.

### Central Arbiter

Instead of a process claiming a resource directly, you ask a 'servant' for it. This centralised arbiter can decide if a deadlock might occur and avoid the situation.

A **central controller**, an arbiter, gets what they need, the arbiter in this case:
- Knows what resources everyone has,
- Can refuse requests,
- Can ensure safe sequences of resource grants,

In the scenario:

- X requests A, then B.
- Y requests B, then A.

Processes go:

```C
Jeeves.request(A);
Jeeves.request(B);
```

Here `jeeves` prevents circular wait from every forming.


## Summary:

|Strategy|How It Works|Strengths|Weaknesses|
|---|---|---|---|
|Ordering Claims|All processes request resources in same order|Simple in theory|Hard to enforce in complex systems|
|Back Off!|Release resources and retry if blocked|Simple to implement|Risk of livelock, retry overhead|
|Central Arbiter|Use a “servant” to manage all resource access|Very safe, avoids circular wait|Bottleneck and centralised control|