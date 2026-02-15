01-10-2025 22:15

Tags: [[Introduction to A.I]]

# Uninformed Search Strategies

An uninformed search algorithm is given no clue about how close a state is to the goal.

## Breadth-First Search

When all actions have the same cost, an appropriate strategy is the **breadth-first** search, in which the root node is expanded first, then all the successors of the root node are expended next, then their successors and so on:
![[Pasted image 20251002165121.png#invert]]
A FIFO queue will be faster than a priority queue and will give us the correct order of nodes.

When the search commences, all the nodes remain in memory, so both time and space complexity are $O(b^d)$, in general exponential-complexity search problems cannot be solved by uninformed search for any but the smallest instances.

## Dijkstra's Algorithm or Uniform Cost Search

When actions have different costs, we can implement a uniform-cost search that to spread out in waves of uniform path-cost, the algorithm, the algorithm can be implemented as a call to BEST-FIRST-SEARCH with PATH-COST as the evaluation function.

The complexity of uniform-cost search is characterised in terms of $C^*$, the cost of the optimal solution, and $\epsilon$, a lower bound on the cost of each action (where it is greater than 0).
This means that the algorithm's worst-case time and space complexity is $$O(b^{1 + [C^*/ \epsilon ]})$$
which can be much greater than $b^d$ since it can explore large trees of actions with low costs before exploring paths involving a high-cost and perhaps useful action.
When all action costs are equal the complexity becomes just: $$b^{d+1}$$
and uniform-cost search is similar to breadth-first search.

Uniform-cost search is complete and is cost-optimal, because the first solution it finds will have a cost that is cost of any other node in the frontier, it also considers all paths systematically in order of increasing cost, never getting caught going down a single infinite path.

**TL;DR UCS is guaranteed to find a solution if one exists and is cost-optimal**

## Depth-first Search

In this type of search, it always expands the deepest node in the frontier first.

![[Pasted image 20251002201941.png#invert|700]]

The search proceeds immediately to the deepest level of the search tree, where the nodes have no successors. The search then 'backs up' to the next deepest node that still has unexpanded successors. Depth-first search is **not** cost-optimal as it returns the first solution it finds, even if it is not the cheapest.

For finite state spaces that are trees it is efficient and **complete** but for acyclic state spaces it may end up expanding the same state many times via different paths, but will eventually systematically explore the entire space.

In cyclic state spaces it can get stuck in an infinite loop so some implementations of depth-first search check each new node for cycles, finally, in infinite state spaces, depth-first isn't systematic, it can get stuck on an infinite path even if there are no cycles, making the search algorithm **incomplete**.

The positives for Depth-first search are that when a tree-like search is feasible, depth-first search requires less memory - a reached table isn't needed at all and the frontier is very small: think of the frontier of Depth-first as the radius of a circle and for Breadth-first as an expanding circle.

For a tree like above, a depth-first tree-like search takes time proportional to the number of states, and has a memory complexity of $O(bm)$, where $b$ is the branching factor and $m$ is the maximum depth of the tree.

A variant of depth-first search called **backtracking search** uses even less memory - only one successor is generated at a time rather than all successors.

## Depth-Limited and Iterative Deepening Search

To keep depth-first from going infinitely we can use a **depth-limited** search where we give the algorithm a depth limit, $l$, treating all nodes at depth $l$ as if they have no successor.
This gives a time complexity of $O(b^l)$ and the space complexity is $O(bl)$,
An appropriate choice for $l$ will be needed, if not then we may not reach a solution.

We sort of need to estimate a good $l$ value based on the knowledge of the problem, i.e. above the Romania example, we can figure out that any city can be reached in at most 9 actions, this number is known as the **diameter** of the state-space graph, this *diameter* will lead to a more efficient depth-limited search, unfortunately, for most problems we can only reach this value **after** the problem has been solved.

**Iterative Deepening Search** kind of solves this by trying **all** values: first -, then 1, then 2, and so on (until a solution has found or a failure is returned).
This type of search combines many of the benefits of depth-first and breadth-first search.
Like depth-first search, its memory requirements are modest: $O(bd)$ when there is a solution or $O(bm)$ on finite state spaces with no solution. Iterative deepening 

![[Pasted image 20251002210311.png#invert|900]]

Above you can see that iterative deepening returns either a solution node, failure (when exhausted all nodes) or cutoff (there may be a solution at a deeper level than $l$). It does not keep track of reached states, so uses much less memory than best first search. 

![[Pasted image 20251002210625.png#invert|800]]

Here we have four iterations of deepening search with the depth limit varying from 0 to 3. 

This algorithm can be seen as wasteful because states near the top of the search tree are re-generated multiple times, but for many state spaces most of the nodes are in the bottom level, so it doesn't matter that the upper levels are repeated.
If the repetition is a concern you can use a hybrid approach where one runs breadth-first search until almost all the available memory is consumed and then runs iterative deepening from all the nodes in the frontier.

