30-12-2025 12:19

Tags: [[Introduction to A.I]]

# Optimal Decisions in Games

MAX wants to find a sequence of actions leading to a win. MIN wants the opposite. MAX's strategy must be conditional, what this means is that it needs to take MIN's possible moves into consideration when it, itself moves. 

We could use AND-OR search but that is only for games that are simple when it comes to winning or losing - you just find one path.

In the image below we can see possible replies to the action $a_1$ for MIN which are $b_1$, $b_2$,. $b_3$ and so on. In some games, the word "move" means that both players have taken an action, therefore the word **ply** is used to unambiguously mean one move by one player.
![[Pasted image 20251230124451.png#invert]]
![[Pasted image 20251230133009.png#invert]]

## The minimax Search Algorithm


![[Pasted image 20251230133205.png#invert]]

The minimax algorithm performs a complete depth-first exploration of the game tree. If the maximum depth of the tree is $m$ and there ae $b$ legal moves at each point, then the time complexity of the minimax algorithm is $O(b^m)$.
The space complexity is $O(bm)$ for an algorithm that generates all actions at once, or $O(m)$ for an algorithm that generates actions at one at a time.

## Optimal Decisions in Multiplayer Games

Many popular games allow more than two players. For minmax it is straightforward technically.
Here instead of a single number, every node on the game tree holds a **Vector**.

When a computer looks at a node to decide which path it takes, it checks whose turn it takes and looks at the corresponding node:

![[Pasted image 20251230143403.png#invert]]

When AI plays multiplayer games, it forms **Alliances**, but the AI is not programmed to "be friends", it is programmed to be selfish. 

If the game isn't "Zero Sum", cooperation becomes the permanent best strategy.

## Alpha-Beta Pruning

No algorithm can completely eliminate the exponent but we can cut it in half. We do this by computing the correct minimax decision without examining every state by **pruning**. Specifically **alpha-beta pruning**.


The square brackets hold the values for $\alpha$ and $\beta$.

![[Pasted image 20251230150824.png#invert]]
![[Pasted image 20251230151221.png#invert]]
Alpha and Beta are values that are used to keep track of guarantees. 
Alpha is the best option for MAX so far, think of alpha as the floor or as "**at least**".
Beta is the best option for MIN so far. This is the lowest value MIN ha already found, think of it as "Better Not Exceed".

Pruning occurs when beta is less than alpha in that position.
If $\alpha \ge \beta$, stop searching. If MAX finds a move that is better than or equal to what MIN has already guaranteed elsewhere ($\beta$), MIN will simply never let the game reach that state.

## Move Ordering

Effectiveness of alpha-beta pruning is dependent on the order in which the states are examined: If you check the best moves first, the algorithm runs drastically faster. If you check the worst moves first, the algorithm runs at the same slow speed as standard Minimax.
Alpha-beta with perfect move ordering can solve a tree almost twice as deep as minimax in the same amount of time.

Standard Minimax takes $O(b^m)$ time, Perfect Ordering reduces this to $O(b^{m/2})$ - which is $O(\sqrt{b^m})$. 