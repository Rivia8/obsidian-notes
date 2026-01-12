31-12-2025 16:22

Tags: [[Introduction to A.I]]

# Monte Carlo Tree Search

The game of Go illustrates two major weaknesses of heuristic alpha-beta search.
1. Go has a branching factor that starts at 361, so alpha-beta search would be limited to only 4 or 5 ply.
2. Second it is difficult to define a good evaluation function for go since material value is not a strong indicator and most positions are in flux until the end game.
Go programs have abandoned alpha-beta search and instead use a strategy called **Monte Carlo Tree Search (MCTS).**

The basic MCTS strategy does not use a heuristic evaluation function. Instead it uses **Simulations**, also called Playouts or Rollouts. 
How it works is that a move is chosen first for one player, then for the other repeating until the end, then we find who wins at the end. We know exactly who wins in that scenario. If you run 1,000 of these fast-forward simulations for Move A and win 800 of them, the "value" of Move A is simply **80%**.

But how to choose what moves to make during the playout? To get useful information a playout policy is needed that **biases the moves towards good ones.** 

We need to decide two things, what positions do we start the playouts and also how many playouts do we allocate to each position? Simplest answer is called **pure Monte Carlo search**, is to do $N$ simulations starting from the current state of the game and track which of the possible moves from the current position has the highest win percentage.
For some stochastic games this is fie but for most games its not sufficient and we need a **selection policy** that focuses resources on two factors:

1. **Exploration**, Greed

2. **Exploitation**, Curiosity

The MCTS loop:

1. **Selection**: AI starts at the root and moves down the existing tree, at every split, it uses a math formula called **UCT** to decide which branch to take,
2. **Expansion:** Once it hits the bottom of its known tree, a leaf, it creates a one new node.
3. **Simulation:** From this node, the AI plays a fast-forward game all the way to the end.
4. **Back-propagation:** The AI walks back up the path it took and updates the number on every node it touched.

![[Pasted image 20251231181229.png#invert]]

These 4 steps are repeated for a set number of iterations or until the allotted time has expired and then return the move with the highest number of playouts.

An effective selection policy is ***upper confidence bounds applied to trees*** or **UCT**, the policy ranks each possible move based on an upper confidence bound formula called **UCB1**.

![[Pasted image 20251231173956.png#invert]]

In Alpha-Beta, it tries to look at every possible move, but because of the branching factor it hits a wall quickly.
MCTS is narrow and deep, a simulation is a single line $O(depth)$ it ignores the vast majority of the tree to rush to the end.
	With the same power, MCTS can simulate **10 million full games**, whereas Alpha-Beta can only see **12 moves ahead**

**Alpha-Beta** is fragile, it relies entirely on on the **Heuristic Evaluation Function** (if your heuristic is wrong about a single node Alpha-Beta will walk right into the trap). **MCTS is Robust**, it relies on averages. If a heuristic is wrong, MCTS will likely correct it. If the board _looks_ pretty (Heuristic says +10), but MCTS plays it out 1,000 times and loses 900 times, MCTS ignores the pretty board and trusts the win rate. It is harder to fool.

 Versatility: The "New Game" Problem
- **Alpha-Beta:** Requires a human expert to teach it strategy. You cannot use a Chess Alpha-Beta bot to play Go unless you rewrite the Evaluation Function (e.g., define "What is a good Go board?").
- **MCTS:** Is "Plug and Play." As long as you tell it the rules (legal moves and who wins), it can play _anything_. It doesn't need to know strategy; it learns what works by trial and error (Reinforcement Learning).

There are two major weaknesses of MCTS where Alpha-Beta is superior?:

**A. The "One-Move" Trap (Type B Pruning Risk)** MCTS is stochastic (random). It might simulate 99% of moves, but miss the _one_ specific move that causes you to lose instantly.
- **Alpha-Beta:** Guarantees it will see the trap (if it's within the depth limit) because it checks _everything_.
- **MCTS:** Might accidentally "prune" (ignore) the vital line of play because the random dice rolls just didn't land on it often enough.

**B. The "Obvious Win" Drag**
- **Scenario:** You have a King and Queen vs. a lone King. It is an obvious win.
- **Alpha-Beta:** Sees "Material +9" immediately and plays the win.
- **MCTS:** Doesn't "know" it's a win. It has to simulate the game for 50 more moves just to prove it. It can be inefficient in "solved" situations.