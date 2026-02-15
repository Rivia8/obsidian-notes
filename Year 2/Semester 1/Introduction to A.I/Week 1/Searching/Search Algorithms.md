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

![[Pasted image 20251002103750.png#invert|800]]

![[Pasted image 20251002104445.png#invert]]
The figure directly above shows how we have expanded every node on the frontier, extending every path with all applicable actions that don't result in a state that hasn't been reached.


## Best-First Search

But how do we decide which node from the frontier to expand next?

A very general approach is called best-first approach, in which we choose a node, *n*, with minimum value of some **evaluation function, $f(n)$.

![[Pasted image 20251002152759.png#invert|600]]

## Search Data Structure

Search algorithms require a data structure to keep track of the data structure,  a node in the tree is represented by a data structure with four components:
- **node.STATE**: the state to which the node corresponds,
- **node.PARENT:** the node in the tree that generated this node,
- **node.ACTION:** the action that was applied to the parent's state to generate this node,
- **node.PATH-COST:** the total cost of the path from the initial state to this node. In mathematical formula, we use $g(node)$ as a synonym for PATH-COST

Three kind of queues are used in search algorithms:
- A priority queue, first pops the node with the minimum cost according to some evaluation function, $f$. Used in [[Search Algorithms#Best-First Search|best-fit search]] algorithms,
- A LIFO queue, this first pops the node that was added to the queue first,
- A LIFO queue, this pops the first most recently added node, 

## Redundant Paths

Since there are a lot of ways to get to get from 'A to B' an algorithm that explores all these paths will be incredibly slow.

**Cycle (or 'Loopy Paths')**: This is when a pat loops back on itself, e.g. `Arad → Sibiu → Arad → Sibiu → Arad...`

**Redundant Paths**: A path is redundant if you find a way to get to a state, (longer, more expensive) than a path you've *already* found to the same state.

## Measuring Problem-Solving Performance

We can evaluate the performance of algorithm's in four ways:
- **Completeness:** Is it guaranteed to find the solution when there is one,
- **Cost optimality:** does it find a solution with the lowest path cost of all solution?
- **Time complexity:** How long does it take to find a solution? This can be measured in either seconds or by the number of states and actions considered,
- **Space Complexity:** How much memory is needed to perform the search?

To be complete a search algorithm must be **systematic** in the way it explores an infinite state space, making sure it can eventually reach any state that is connected to the initail sate.