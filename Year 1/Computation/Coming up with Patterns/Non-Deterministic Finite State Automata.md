20-02-2025 16:40

Tags: [[Computation]]

# Non-Deterministic Automata

We have already looked at Deterministic Finite State Automata and we have seen that:
- For each State and Input symbol, there is exactly one next state,
- The automaton can only be in one state at a time,
- Transitions are deterministic - they can be predicted,
- Each state must have exactly one transition for each input symbol,

We have looked at its [[Deterministic Finite-State Automata#Defining Deterministic Finite-State Automata|definition]] and have seen that it has functions that describes its transitions. Each state only has **one** transition, the key **difference** between a **DFA** and an **NFA** is that an NFA allows for **multiple** next states for a state.  

## Why the need for an NFA?

The reason we can/should use them is because it is easier to implement an Automata.

- - - 

Let's say we're considering an automaton that accepts words over the alphabet $\{0,1\}$
that start with a $0$ and have a 1 as the second last character.
The regular expression would be: $0(0|1)^* \,1(0|1)$,

Trying to make a deterministic automata would be quite hard for this, instead we can make something along this nature:

![[Pasted image 20250220195247.png#invert]]

As you can see some of the states have multiple transitions that they could go for.

Lets say we had the word $010$, we have **two possible** paths through the automaton:

1. A to C (0), C to D (1), (D to E) 1 - which would accept the word,

or

2. A to C (0), stay in C (1), stay in C (1) - which would not accept the word.

## Defining Non-Deterministic Finite State Automata

So how would we define it? 

We still have the main things similar to that of a DFA but it is no longer that for every state and every letter from $x$ there is one edge labelled with $x$, there may be several. 
Furthermore, instead of a *transition function* we have a *transition relation*:
Given a state $q$, a letter $x$ and another state $q'$ the relation $\delta$ tells us whether or not there is an edge labelled $x$ from $q$ to $q'$.

![[Pasted image 20250220204435.png#invert]]
When an NFA accepts a word:

![[Pasted image 20250220204505.png#invert]]

For an NFA you do not need an edge for every label: when following a word through an NFA, you might get stuck on a state because there is no edge to get out for the letter you see, for that case we know that word will not be accepted.

Look at this example:

![[Pasted image 20250220210914.png#invert]]

In the initial state we can see that if we had a word beginning with $a$ we would be 'stuck' and so the automata would reject any word beginning with $a$.

This can also be done with DFA's:

![[Pasted image 20250220214059.png#invert]]

In this example, you can see that the first and second state both don't include something that could occur, the first disregards a $1$ and the second a $0$ but if that were to happen then the word would be considered as rejected.

![[Pasted image 20250220214455.png#invert]]
This Automata looks more complicated but describes the exact same DFA, except that it contains the $q_3$ state that is considered a 'dump' state.
