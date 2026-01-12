20-02-2025 15:25

Tags: [[Computation]]

# Defining Deterministic Finite-State Automata

We have seen how these have looked, but haven't properly given a definition and showcased the criteria of an DFA:

![[Pasted image 20250220152817.png#invert]]

- - - 
- We can also say that all the states of the automaton belong to the set $Q$ and that of these states the accepting states that belong to the criteria could form the subset $F$ so $F$ of $Q$.

- We need a function that takes as its input a state and a letter from $\Sigma$  and then returns a state, the function is what we call a **Transition Function**, $\delta$. 

The definition by the notes:

## Definition 6:

![[Pasted image 20250220152652.png#invert]]

Deterministic Finite-State Automata are also referred to as **finite state machines**.

## Definition 7:

![[Pasted image 20250220155534.png#invert]]
So **definition 7** states that a word $s$ is comprised of a series of letters (or the empty letter, $\epsilon$) that belongs to an alphabet $\Sigma$. 

## Definition 8:

![[Pasted image 20250220155924.png#invert]]


