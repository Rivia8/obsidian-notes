12-01-2026 19:14

Tags: [[Introduction to A.I]]

# The Structure of Problems

Normally, CSPs are NP-Hard (this means that they take exponential time, $O(d^n)$. However, if the graph representing the problem has a specific shape, we can solve it in **Linear Time.**

We can use **Independent Subproblems** **(Divide and Conquer)** approach to reduce load.
*The text uses the Tasmania example to do illustrate this. - Solving the whole map at once: Exponential time ($d^n$). Solving mainland + Tasmania separately: Linear time ($n×d^c$). *

**Tree-Structured CSPs:**
Most problems aren't fully disconnected, but they often lack loops (cycles). If a constraint graph is a **Tree** (where any two nodes are connected by only one path), we can cheat. We can solve *any* tree-structured CSP in linear time without any backtracking at all.

We can solve any tree-structured CSP in linear time without any backtracking at all.
The process uses a concept called **Direct Arc Consistency (DAC)**.

![[Pasted image 20260112193217.png#invert]]
*^The TREE-CSP-SOLVER algorithm for solving tree-structured CSPs. If the CSP has a solution, we will find it in linear time; if not, we will detect a contradiction.*

## Cutset Conditioning

This is a clever hybrid algorithm that allows the use of the fast tree solver on graphs that aren't actually trees.
It identifies problems that create loops in the graph and fixes them first.


Having a loop is hard to solve:
![[Pasted image 20260112193559.png#invert]]
But how do we get rid of SA?:
- We don't actually delete the country. Instead, we **fix its value** (e.g., assume `SA = Red`).
- Once SA is fixed, it acts like a constant, not a variable. We update its neighbours' domains (delete 'Red' from WA, NT, Q, NSW, V).
- Now, the rest of the problem is just a simple Tree CSP, which we can solve in linear time.

How the Algorithm works:
1. We find the cutset ($S$), this is the smallest group of variables that, if removed, turns the graph into a tree.
2. We then **brute force the cutset** - looping through every possible assignment for the variable in $S$.

Standard Search: $O(d^n)$
**Cutset Conditioning:** $O(d^c \cdot (n-c))$
- $d^c$ is the brute-force guessing,
- $n-c$ is the linear time to solve the rest.

If your graph is nearly tree, its fast (small $c$). If its a large $c$, then its just as slow as standard search.

**Cutset Conditioning is a way to isolate complexity. You accept a slow, brute-force search on a tiny part of the graph (the Cutset) so that you can enjoy a super-fast, linear search on the massive remainder of the graph.**

## Tree Decomposition

Second method for reducing a complex graph into a simple tree. 
Instead of treating every individual variable as a node, we group variables into "clusters", **Mega Nodes** and if we organise these clusters correctly, they form a tree structure that is easy to solve.
There are three rules:
- **Every Variable** must appear in at least one cluster.
- **Every Constraint** (connected pair) must appear together in at least one cluster.
- **Connectedness:** If a variable appears in two different clusters, it must also appear in every cluster along the path connecting them. (This ensures that if "South Australia" is Red in cluster A, it stays Red all the way to cluster B).

![[Pasted image 20260112200605.png#invert]]
- In the original map, **SA, WA, NT** form a triangle (a loop).
- In the decomposition, we group them into one single node: `{SA, WA, NT}`.
- **The Constraint:** Inside this node, the "variable" is no longer a single state, but a **Tuple** of three colors. The domain is the list of all valid combinations for that triangle (e.g., `(Red, Green, Blue)`).

The efficiency depends on the **Tree Width** ($w$) which is determined by the size of the largest cluster.
Time Complexity $O(n \cdot d^{w+1})$. If $w$ is small, the problem is solved instantly. If $w$ is large (giant clusters) it takes forever.

**Trade off:**

| **Feature**  | **Cutset Conditioning**             | **Tree Decomposition**                              |
| ------------ | ----------------------------------- | --------------------------------------------------- |
| **Strategy** | Fix a few variables to break loops. | Group variables into tree clusters.                 |
| **Time**     | Slower ($O(d^c)$).                  | Faster ($O(d^{w+1})$).                              |
| **Memory**   | **Linear** (Good for low RAM).      | **Exponential** (Needs massive RAM for the tuples). |

## Value Symmetry

In **Map Colouring** the names of the colours don't matter:
- _Solution A:_ WA=Red, NT=Blue, SA=Green.
- _Solution B:_ WA=Blue, NT=Red, SA=Green.
- Mathematically, these are distinct solutions. Practically, they are identical. If you have d colors, there are d! (factorial) variations of the _same_ solution. Searching for all of them is a waste of time.

To fix this we have Symmetry-Breaking Constraints:
We introduce an artificial rule to force the AI to find only **one** version of the solution. 
Example: "We require that the colours be in alphabetical order: NT<SA<WA." What this does is that it forces the AI to assign Blue to NT, Green to SA, and Red to WA, eliminating the other 5 variations instantly.

- **Tree Decomposition** turns a "loop" problem into a "tree" problem by solving small chunks (clusters) first.
- **Symmetry Breaking** stops the AI from wasting time finding the same solution 6 different times just because the colours are swapped