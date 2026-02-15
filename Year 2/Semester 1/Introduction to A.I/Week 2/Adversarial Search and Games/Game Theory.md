30-12-2025 11:54

Tags: [[Introduction to A.I]]

# Game Theory

There are three different ways an AI can view other participants in an environment.

1. When you have lots of agents (millions of people), it is impossible to predict what one specific person will do. Instead, you treat them like on single mass or force. E.g. if demand goes up, prices rise, and you don't look at one individual.
2. We can consider adversarial agents as just the environment, like the weather. This isn't great since your opponent in chess isn't the weather, it doesn't happen randomly. You'd use this in single-agent environments, where obstacles move randomly.
3. This is the game-theory stance, you explicitly model the other agent as an intelligent **adversary** who is trying to beat you.

**Pruning:** This is where in complex games, the tree of possibilities is too big to check every branch, so you "prune" (cut off) branches of the search tree that are obviously bad.

**Minimax**: This is the standard algorithm for 1v1, it assumes you are trying to **Maximise** your score, and **they** are trying to minimise your score.

For complex games like chess, the tree is too deep to see to the end, you have to stop searching eventually (looking 10 moves ahead and then stop), but how do you know who is winning 10 moves in?

1. Heuristic Evaluation (looking at features in the board to make an educated guess)
2. Fast Simulations (**Monte Carlo** simulation)

## Two-player Zero-sum Games

Chess and Go are deterministic, two-player, turn-taking, perfect information, zero-sum games.

"Perfect Information" is a synonym for "Fully Observable" and "Zero-Sum" means what is good for one player is just as bad for the other, there is no "win-win" outcome.
- Move = Action
- Position = State

The two players will be called MAX and MIN, MAX moves first. Points will be awarded to  the winning player and penalties given to the loser:

•$S_0$: The initial state, which specifies how the game is set up at the start.
•TO-MOVE($s$): The player whose turn it is to move in state s.
•ACTIONS($s$): The set of legal moves in state s.
•RESULT($s, a$): The transition model, which defines the state resulting from taking action a in state s.
•IS-TERMINAL($s$): A terminal test, which is true when the game is over and false otherwise. states where the game has ended are called terminal states.
•UTILITY($s, p$): A utility function (also called an objective function or payoff function), which defines the final numeric value to player p when the game ends in terminal state s. In chess, the outcome is a win, loss, or draw, with values 1, 0, or 1/2.2 Some games have a wider range of possible outcomes—for example, the payoffs in backgammon range from 0 to 192

ACTIONS and RESULT function define a state space graph. This represents every possible state of the game and how they connect, it's a graph because you can loop back to the same position.