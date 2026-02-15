15-02-2026 21:52

Tags: [[Distributed Systems]]

# Implementing [[Synchronisation]]

If you have multiple distributed systems to achieve one goal, systems need to be **choreographed** in order to be able to avoid situations where possible dilemmas occur i.e. two clients holding on to a finite resource when there's only one left **or** when sending data from one client to another a system crash prevents it from going through.

There are two possible solutions:

1. Centralised Lock Server
2. Two Phase Commit Algorithm

## Centralised Lock Server and Mutual Exclusion







