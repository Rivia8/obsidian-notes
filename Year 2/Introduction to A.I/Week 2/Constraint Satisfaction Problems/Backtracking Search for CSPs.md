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

	**Degree Heuristics:** You pick the variable connected to the most other unassigned variables. **This is the TIE breaker for MRV that we mentioned above**. Let's say at the very start of the map colouring everyone has 3 colours (MRV) is tied. Who do you then pick? You pick the most connected variable, the one that "touches the most states". With this you impose constraints on the rest of the board early, reducing the branching factor for future steps.

2. **Which option do I try?** (**Value Selection**):

	Once you have picked a variable you then need to choose a colour.

	**Least Constraining Value (LCV):**
	Here you pick the value that leaves the most options open for your neighbours. You are being considerate by choosing choices that are considerate for your neighbours, you are maximising the chances that you won't need to backtrack later.

## Interleaving Search and Interference

You can have **inference during search**: instead of blindly guessing values and waiting until you hit a wall (dead end), these algorithms "look ahead" after every single move to see if the puzzle is still solvable.

1. Level 1: Forward Checking (The Immediate Neighbour Check)

	Forward Checking is the simplest form of inference. How this works is that whenever you assign a value to a variable $X$ (e.g. $WA = \text{Red}$) you immediately look at all **unassigned neighbours** of $X$.
	You then delete any options from the neighbour's domain that conflicts with your choice.
	- **Action:** You assign **WA = Red**.
	- **Forward Check:** You look at WA's neighbours (NT and SA). You delete "Red" from their lists.
	- **Action:** You assign **Q = Green**.
	- **Forward Check:** You look at Q's neighbours (NT, SA, NSW). You delete "Green" from their lists.
	- **The Result:** NT and SA are now reduced to a single possible value: **Blue**.
	- **The Catch (Inconsistency):** Forward Checking stops here. It says, "I successfully removed the bad values from the neighbours. Good job!" It **fails to notice** that NT and SA (who are neighbours) are now forced to be the _same_ colour (Blue), which is impossible.

2. Level 2: **MAC (Maintaining Arc Consistency)**

	This is stronger and the "recursive" version of inference. It detects the error that Forward Checking Missed. Whenever you assign a variable, you don't just check neighbours once. You run the full **AC-3** algorithm. If a neighbour's domain shrinks, MAC checks *that* neighbour's neighbour and so on. It propagates the change through the whole graph.

| **Feature** | **Forward Checking**                                             | **MAC (Maintaining Arc Consistency)**                                            |
| ----------- | ---------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| **Scope**   | Checks only immediate neighbors of the current variable.         | Checks neighbors, then neighbors of neighbors (recursive).                       |
| **Power**   | Weak. Misses "secondary" conflicts (like the NT vs SA triangle). | Strong. Detects almost all conflicts early.                                      |
| **Speed**   | Fast execution per step.                                         | Slower execution per step (runs AC-3), but drastically reduces search tree size. |

## Intelligent Backtracking

Standard backtracking is "dumb". So we use **Backjumping**: Instead of going back to the most *recent* variable, the AI should jump back to the source of the problem.

**Conflict Set:** The AI keeps a list of exactly which variables caused the current failure. The AI will look at its conflict set and jump back to the most recent variable in the set, skipping over anything that isn't needed.

But if you are using **Forward Checking**, simple backjumping becomes redundant because forward checking usually prevents you from reaching these empty-domain states in the first-place. 
But we can go deeper, so when a branch is doomed not when a domain is empty right now but because the combination of variables makes a solution impossible down the road. When a variable fails, it passes its "conflict set" backwards to the variable responsible. The previous variable will "absorb" the blame. This allows the AI to trace a chain of failures all the way back to the root cause.

## Constraint Learning

This is advanced. Even with backjumping, the AI might run into the same bad combinations of assignments later in the search tree. When the AI hits a dead end, it writes the "minimum set" of variables that caused the crash. The benefit of this is that if the AI every tries to recreate this specific combination again in the future, the new rule blocks it immediately, pruning that entire branch before the search even starts.