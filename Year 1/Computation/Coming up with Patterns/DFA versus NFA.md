20-02-2025 21:47

Tags: [[Computation]] [[Deterministic Finite-State Automata]] [[Non-Deterministic Finite State Automata]]

# DFA versus NFA

- For the same problem it is usually easier to design a non-deterministic automaton, and the resulting automata are often smaller 
- But, following a word through a deterministic automaton is straightforward and so deciding whether the word is accepted is easy, for an NFA we have to find all the possible paths a word might move along and decide whether any of them leads to an accepting state.

A key point to know about their relationship is that:

	For every non-deterministic automaton there is a deterministic one that recognises precisely the same words.


We can easily produce NFA's from DFA's since usually DFA's are usually harder to produce but what about the other way around?

## Producing DFA's from NFA's

![[Pasted image 20250220225559.png#invert]]

The states of the DFA are the subsets of the states of the NFA, so if $Q$ is the set of states of the NFA, the states of the DFA will be $P(Q)$, the powerset of $Q$.
This means that every possible combination of states from the the NFA is considered a state in the DFA.

So if we had: 
- States: $\{0, 1, 2\}$, 
- Start State: $0$
- Accepting State: $2$

When converting this NFA to a DFA, we would have the states: {}, {0}, {1}, {2}, {0, 1}, {0, 2}, {1, 2}, {0, 1, 2}.

When producing the DFA, the accepting states would be the states that is the subset of an accepting state.

