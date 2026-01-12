01-10-2025 22:12

Tags: [[Introduction to A.I]]

# Search Algorithms

A **search algorithm** takes a search problem as input and returns a solution, or an indication of failure. We consider algorithms that superimpose a **search tree** over the state-space graph, forming various paths from the initial state, trying to find a path that reaches a goal state.
Each **node** in the search tree corresponds to actions, the root of the tree corresponds to the initial state of the problem.

*One thing to note is the distinction between the **state space** and the **search tree**, where the state space describes the possibly infinite set of states in the world, whereas the the search tree describes the paths between these states*

*The search tree may have multiple paths to any given state but each node in the tree has a unique path back to the root.*

The example below shows the first few steps in finding a path from Arad to Bucharest.

![[Pasted image 20251002102955.png#invert]]

If you look at the example above we can see that if we choose Sibiu first after the **initial state** Arad, a set of 6 unexpanded nodes are given as a result (those in bold).

**Expanding** a node is considering the available *actions* for that state, using the *result* function to see where those actions lead to and then **generating** a new node (called a **child node** or successor node)

![[Pasted image 20251002103750.png#invert]]

![[Pasted image 20251002104445.png#invert]]
