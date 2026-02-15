11-01-2026 17:35

Tags: [[Introduction to A.I]]

# Constraint Propagation: Interference in CSPs

CSPs are solved much more efficiently than standard logic puzzles. They have the concept of "thinking before you move".

**Atomic State Searching:** This is essentially guessing, the algorithm picks a variable, assigns a random value and moves to the next. If it hits a dead end it backtracks. It "makes progress" only by blindly moving forward.

**CSP Algorithm:** This algorithm has a superpower called **Constraint Propagation**, before picking a value, it looks at the rules (Constraints) to see if it can cross off impossible options.

So it has almost of a Ripple effect where if one variable has to uphold one constraint and another that depends on that has to hold another constraint which impacts that variable... it ends up narrowing that variable to a single state.
This is called **pruning**, by crossing off options early, you can dramatically shrink the search space (the haystack) before you even start looking for the needle.

**Node Consistency:**
This deals with **Unary Constraints**.
A node is "Node-Consistent" if every option in its domain satisfies its own internal rules.

- **Variable:** South Australia (SA).
- **Original Domain:** `{Red, Green, Blue}`.
- **Unary Constraint:** "South Australians dislike Green" (SA=Green).
- **The Fix:** The computer deletes 'Green' from the domain.
- **New Domain:** `{Red, Blue}`.

**Arc Consistency:**
This is checking if a value is valid by looking at its neighbours.
The formal rule is as follows:
$X_i$ is arc-consistent with respect to $X_j$ if, for every value in $X_i$'s domain, there is some value $y$ in $X_j$'s domain that satisfies the constraint.

Here is an algorithm that is used to enforce Arc Consistency throughout an entire graph.
![[Pasted image 20260111220808.png#invert]]

By running AC-3 *before* you start a heavy search, like backtracking, you drastically reduce the search space.

However,  you can have failure with arc consistency. To fix this, you can have **Path Consistency**, this looks at **three variables** at once.

**In General,** 'Consistency' is just a measure of how many variables you check at once.

- **1-Consistency (Node Consistency):**
    - "Given 0 variables fixed, can I find a valid value for 1 variable?"
    - _Simple Check:_ Does the value satisfy the unary constraints.
- **2-Consistency (Arc Consistency):**
    - "Given 1 variable fixed, can I find a valid value for a 2nd variable?"
- **3-Consistency (Path Consistency):**
    - "Given 2 variables fixed, can I find a valid value for a 3rd variable?"
- **K-Consistency:**
    - "Given k−1 variables fixed, can I always find a valid value for the k-th variable?"

A graph with $n$ variables is **Strongly K-Consistent**, if it is $1,2,3$... and $k$-consistent all at the same time.
With a graph like this, you don't need to search or backtrack anymore.

If strong-N consistency makes solving puzzles instant, why isn't it always implemented? The reason is because converting a messy graph into a strongly N-Consistent graph is incredibly expensive. It takes exponential time and exponential space to enforce this level of consistency.
In the real world, AI engineers usually settle for Arc Consistency (2-Consistency). It catches 90% of the errors and is cheap to compute.

**Global Constraints:**
A **Global Constraints** is a rule that applies to an arbitrary number of variables, not just two. These are essential because handling one big rule is often much faster for computing than checking a web of dozens of small separate rules.
**The Aldiff Constraint**: This is the most common example, it just states that every variable in this group must have different values.

For problems involving numbers (like scheduling or logistics), constraints often limit the **sum** of values.
**Atmost Constraint**: This limits the total resources used: `Atmost(10, P1, P2, P3, P4)` means the sum of personnel assigned to four tasks cannot exceed 10. When it comes to the **inference,** if the sum of the minimums is already > 10, the path is invalid. It can also delete maximum values that would force the sum over the limit.
**Bounds Propagation:** In large problems (e.g. moving 1,000 people), variable domains are too huge to list every integer so instead the computer just tracks the **lower bound** and **upper bound**. This saves massive amounts of time.
