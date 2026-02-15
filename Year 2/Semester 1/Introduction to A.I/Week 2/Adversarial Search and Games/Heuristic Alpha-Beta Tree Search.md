30-12-2025 17:54

Tags: [[Introduction to A.I]]

# Heuristic Alpha-Beta Tree Search

We have limited computation time, we can cut off the search early and apply a heuristic **evaluation function** to states.

![[Pasted image 20251230175629.png#invert]]


## Evaluation Functions

EVAL($s, p$) returns an *estimate* of the expected utility of state $s$ to player $p$, just as the heuristic functions of chapter 3 return an estimate of the distance to the goal.
If the AI is winning the number is high, if its losing it should be low.

Games like Chess are not random, if you freeze a Chess game, the winner is mathematically determined (assuming perfect play). There is no "luck".

Because the AI is cutting of the search early its ignorant of the future we have to treat the ignorance as a probability. 
It does this through "guessing" and it guesses by looking for "features", these features are taken together to define various categories or *equivalence **classes***.
In practice this kind of analysis requires too many categories and hence too much experience to estimate all the probabilities. Instead, move evaluation functions compute separate numerical contributions from each feature and combine them to find the total value.
Mathematically this kind of evaluation function is called a weighted liner function, because it can be expressed as:
![[Pasted image 20251230181751.png#invert]]
Where each $f_i$ is a feature of the position and each $w_i$ is a weight.
![[Pasted image 20251230181851.png#invert]]

Adding up the values like this involves a **strong assumption** that the contribution of each feature is independent of the values of other features.

## Cutting Off Search

We also have to modify `ALPHA-BETA-SEARCH` so that it will call the heuristic EVAL function when it is appropriate to cut off the search.

We have to also keep track of the current depth and increment it on each recursive call. The most straightforward approach is to control the amount of search to a fixed depth limit. But if you set a hard limit, you might finish in 2 seconds and waste the remaining time, or take 20 minutes and lose on time.
Instead we use **Iterative Deepening**, this is where we have a set time allocated for searching at deeper and deeper depths, then we return the result from the deepest completed depth..

The problem that we have is that we can evaluate a position but it can be immediately changed **after** a ply i.e. white captures your queen. 

> [!Quiescent]
> **"The evaluation function should be applied only to positions that are quiescent—that is, positions in which there is no pending move (such as a capturing the queen) that would wildly swing the evaluation."**

For non-quiescent positions the `IS-CUTOFF` returns false, and the search continues.

The **horizon effect** is more difficult to eliminate. It arises when the program is facing an opponent's move that causes serious damage and is ultimately unavoidable but can be avoided by the use of delaying tactics.
We can us e**Singular Extensions** To fix the Horizon Effect, we use **Singular Extensions**. If the AI sees a move that is "clearly better" or "forced" (like the opponent capturing that trapped Bishop), it is allowed to break the depth limit and keep searching that _specific_ chain of moves. This allows the AI to see over the "horizon" and realize the piece is doomed regardless of the delay tactics.

## Forward Pruning

**Forward Pruning** prunes moves that appear to be poor moves.

One approach is **Beam Search**, where on each ply you consider only a "beam" of the $n$ best moves.

## Search Versus Lookup

Its overkill for a chess program to start a game by considering a tree of a billion game states.
Instead of thinking the computer could memorise the best positions and use a table lookup.

1. The Opening: "Don't Reinvent the Wheel"
The text argues that it is a waste of electricity for a supercomputer to spend 10 minutes analysing the starting board only to play **Pawn to e4**.
- **Why?** Humans have played Chess for centuries. We already _know_ the best starting moves.
- **The Solution (Opening Book):** The computer is given a database of the first 10-15 moves of standard chess games.
    - If the board matches an entry in the database, the computer plays the stored move instantly (0 seconds).
    - It relies on **Human Expertise** (and statistics from millions of past games).
    - It only switches to "Thinking" (Search) once the players deviate into a "rarely seen position" that isn't in the book.


2. The Endgame: "Solved by Computers"
At the end of the game, there are very few pieces left (e.g., Kings, a Rook, and a Knight).
- **The Difference:** While Openings rely on human history, Endgames rely on **Computer Perfection**.
- **The Concept:** Because there are so few pieces (e.g., 7 or fewer), a computer can solve the _entire_ state space. It doesn't need to "guess" or "prune." It knows the absolute truth.
- **The Solution (Endgame Tablebase):** The computer looks up the current board in a massive table. The table tells it: _"In this position, if you move the Knight to F3, you will force a checkmate in exactly 14 moves."_
    - This is a **Policy**: A direct mapping of `State -> Best Action`.


2. Retrograde Minimax Search (How the Table is built)
The text explains how these "Endgame Tables" are created. They don't search forward from the start; they search **backward from the end**.

3. **Place the pieces:** Set up a board with just a few pieces (e.g., King + Rook vs. King).
4. **Find the Ends:** Identify every position that is an immediate Checkmate. Mark those as "Win in 0".
5. **Reverse Move:** Work backward. What move could White make to _result_ in those Checkmate positions? Mark those as "Win in 1".
6. **Repeat:** Keep working backward until every possible arrangement of those pieces is labeled as a Win, Loss, or Draw.