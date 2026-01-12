11-01-2026 12:56

Tags: [[Introduction to A.I]]

# Defining Constraint Satisfaction Problems

A **Constraint Satisfaction Problem** is a formal way of describing problems where you need to find a state that satisfies a specific set of rules.

A Constraint Satisfaction  problem consists of 3 components, $X$, $D$ and $C$:

- $X$ (Variables) these are the questions:
These are the things you need to find values for.

- $D$ (Domains) these are the options:
For every variable, what are the possible answers.
An example is for Sudoku, for every square we have the domain of the set of numbers: $\{1,2,3,4,5,6,7,8,9\}$ 

- $C$ (Constraints) these are the rules:
This specifies which combinations are allowed.

"Each constraint $C_j$ consists of a pair $<\text{scope}, \text{rel}>$"

There are two ways to write a rule:
1. **Explicit Set:** Listing every single allowed pair: "Allowed pairs for A and B are (1,2), (1,3) etc.."
2. **Function:** Can also be a math formula.


Assignments are you playing the game:

- **Assignment:** Giving a value to a variable (e.g., "I'll put a 5 in the top-left corner").
- **Consistent / Legal Assignment:** You put a number down, and it **didn't break any rules** immediately.
- **Partial Assignment:** You have filled in some of the grid, but not all of it.
- **Complete Assignment:** Every single square has a number in it.
- **Solution:** A **Complete** assignment where **Zero** constraints are violated. (You filled the whole Sudoku grid, and the numbers are correct).

CPSs are NP-Complete, what this means is that in the worst case scenario, these problems are extremely difficult to solve. As the puzzle gets bigger, the time it takes to solve it explodes exponentially. There is no known "magic math formula" to instantly solve every CSP, usually, you have to use search algorithms, but specific types of CSPs (those with very structured constraints can be solved quickly).

## Variations in CSP Formalism

There can be different variations with the problems you can encounter based on what kind of data you are working with (variables) and how complex the rules are.

1. Types of Domain (Answers)

	- Discrete Finite Domains (limited list of options)
	- Discrete Infinite Domains (options are countable integers or strings, but they go on forever)
	- Continuous Domains (real numbers, decimals)

2. Types of Constraints (This talks about how many variables can be involved in a single rule)

	- **Unary (1 Variable):** A rule involving one person.
		e.g. "South Australia cannot be Green"
	- **Binary (2 Variables):** A rule relating two people.
	- **Global / N-ary (3+ Variables):** A rule involving a group,
		This doesn't mean every variable, just an arbitrary number of variables.


3. Reducing Complexities (Dual Graphs)

	This asks the questions that: "What if we have a complex Global Constraint but out AI only knows how to solve simple Binary Constraints?"


	We have a trick called **Dual Graph Transformation:** 
	This is where we turn the Constraints into the variables. An example is this: $X + Y = Z$, A 3-variable constraint. We create a new variable $C_1$ and make the Domain (answers) the valid combinations, like $(1,2,3)$ or $(2,3,5)$.

4. **Preference Constraints**

	In real life, we don't just have "Allowed" or "Forbidden":
- **Absolute Constraint:** The Professor **cannot** be in two places at once. (Hard rule).
- **Preference Constraint:** The Professor **prefers** teaching in the morning. (Soft rule).
- **COP (Constrained Optimization Problem):** This is a CSP where we assign "points" or "costs."
    - Morning class = Cost 1.
    - Afternoon class = Cost 2.
    - _Goal:_ Find a valid schedule (Absolute) with the lowest cost (Preference).


