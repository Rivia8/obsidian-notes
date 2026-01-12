12-01-2026 14:56

Tags: [[Introduction to A.I]]

# Backtracking Search for CSPs

Logic alone leaves you with a few options, so you have to start guessing to find the final solution.

if you were to use a standard search algorithm on a CSP, it would be very slow.
If you have $n$ variables and $d$ options for each, a standard search has $n! \cdot d^n$ leaves.

The solution to this is **Backtracking** search. By recognising that order doesn't matter, you can restrict the search. You do this by **picking one variable, assigning a value and moving to the next**. We never backtrack over the choice of variable, only the assignment of a value. This reduces the search space drastically to just $d^n$.

![[Pasted image 20260112151301.png#invert]]

How the Algorithm Works (Figure 5.5):
- **Select Unassigned Variable:** Pick a region that needs a colour (e.g., WA).
- **Order Domain Values:** Look at the options (Red, Green, Blue).
- **Check Consistency:** Pick "Red." Does it conflict with neighbours?
    - **If Yes:** Skip it.
    - **If No:** Add `{WA = Red}` to the assignment.
- **Recurse:** Now call the function again for the _next_ variable.
- **Backtrack:** If the recursive call returns "Failure" (meaning you hit a dead end down that path), **remove** `{WA = Red}` and try "Green" instead.

## Variable and Value Ordering:

How to make the Backtracking Search Algorithm efficient:
If you pick variables and values randomly, the computer spends ages exploring dead ends. By using smart heuristics, you can guide the search to find the solution thousands of times faster.

1. **Who Goes first (Variable Selection)**:

	When the algorithm performs `SELECT-UNASSIGNED-VARIABLE`, who should it pick? The text argues for a "Fail-First" strategy.

	**Minimum Remaining Value:** Here it picks the variable with the fewest legal moves left. Pretty much if a variable only has one legal move left and you go to the next neighbouring variables, you could make it so that first variable can no longer use that colour and so causing a dead-end further down the line. By picking it now you save 10 steps.

	**Degree Heuristics:** You pick the variable connected to the most other unassigned variables. **This is the TIE breaker for MRV that we mentioned above**. Let's say at the very start of the map colouu