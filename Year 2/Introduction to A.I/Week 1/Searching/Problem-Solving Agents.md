01-10-2025 20:32

Tags: [[Introduction to A.I]]

# Problem-Solving Agents

When the action to take is not obvious, an agent may need to *plan ahead* (this means to consider a sequence of actions that form a path to a goal state).
Such an agent is called a **problem-solving** agent.

The computational process that an agent undertakes is called **search**.
Problem-solving agents use **atomic** representation.

The agent will perform some steps:
1. **Goal Formation** - it adopts the goal it wants to complete,
2. **Problem Formulation** - it devises a description of the states and actions necessary to reach the goal - an abstract model of the relevant situation,
3. **Search** - Before taking any action in the real world, the agent simulates sequences of actions in its model, searching until it finds a sequence of actions that reaches the goal. Such a sequence is called a solution.
4. **Execution:** The agent can now execute the actions in the solution one at a time.

It is extremely important that in a fully observable, deterministic, known environment, *the solution* to any problem is a fixed sequence of actions (For example the Romania travelling example in the book would have the actions of driving to *Sibiu*, then *Fagaras*, then *Bucharest*, Bucharest being the solution)

A search problem can be defined formally as:
- A set of all possible states that the environment can be in (state space),
- The initial state,
- A set of one or more **goal states**, there can be alternative goal states and sometimes the goal is defined by a property that applies to many states,
- Actions available to the agent,
- An action cost function,

A sequence of actions form a path, and a solution is a path from the initial to the goal state, and the optimum solution has the lowest path cost among all solutions.

When we **model** out formulation of a problem we usually abstract things away that are not necessary to reach the goal but in the real it would be there. But then we need to ensure a correct level of abstraction, this is done by removing as much detail as possible whilst retaining validity and ensuring that the abstract actions are easy to carry out - were it not for the ability to construct useful abstractions, intelligent agents would be completely swamped by the real world.