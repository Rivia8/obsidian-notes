27-02-2025 11:48

Tags: [[Computation]]

# Equivalence of Automata

Two automata are equivalent if they accept the same language.
If the same automaton is drawn but have different names for the states then that automaton is what we call 'isomorphic'.


## Via Complementation and Intersection

If we have the automatons $A'$ and $A$ that recognise the languages $L$ and $L'$, we are interested in whether $L=L'$. 
This happens **if and only if** $$L \subseteq L'$$**and** $$ L \subseteq L'$$
It also happens **if and only if**. $$L ~\cap~(\Sigma^*-L') = \varnothing $$
	*(This is saying that the intersection of the language, $L$, with the complement of $L'$ will have to be equal to the **empty set**. This means that the set of strings/words in $L$ that are **not** in the complement of $L'$( $\overline{L'}$ ), has to be empty. If this is the case then $L$ does not contain any words that are not in $L'$ implying that $L \subseteq L'$. A way to think of it is that if $L$ shares any word that is **NOT** in $L'$ then this would be false, since this would not equal the empty set. )*

![[Pasted image 20250227123212.png#invert]]



**and** $$L'~\cap~(\Sigma^*-L) = \varnothing$$
	This is the same as the previous explanation but $L$ and $L'$ switching sides, if this is true then it would equate to $L' \subseteq L$.

The reason for why **both** the conditions need to be true is because just because $L$ can be a subset to $L'$ doesn't mean that $L'$ is also the subset of $L$ (making them equal to each other). Take this for example:

![[Pasted image 20250227124329.png#invert]]

Of course doing this with simple alphabets is easy and takes little time, but doing it with more complex alphabets and languages will take more time since you would have to:
1. Construct the complement automata,
2. Construct the automata for the intersections,
3. Verify that the intersection automata accepts no words at all.

This makes the procedure impractical and computationally intensive.

## Via Simulations

It is much more of a challenge deciding if two NFA's recognise the same language than DFA's.

A simulation is a relation that helps us compare states between two NFAs.

### Definition 26:

Assume we have two NFA's, $A = (Q,~q_.,~F,~\delta)$ and $B = (P,~p_.,~E,~\gamma)$.
If we can show that for each state of $q$ of $A$ there is an 'analogous' state $p$ of $B$, then every word accepted by the first automaton should be accepted by the second one.

![[Pasted image 20250227131332.png#invert]]

- $q_. \sim p_.$ , means that the start of automata $A$ is related to the start of automata $B$.
- If we have two states, $p$ and $q$, $q$ from $A$ and $p$ from $B$ then they must have the same transition via the same input $x$. 

![[Pasted image 20250227134236.png#invert]]

A key point to know is that a non-existence of a simulation between two automata doesn't mean that the two automata are not equivalent:

![[Pasted image 20250227134102.png]]

These two accept the same language, but do not have a bi-simulation between them.

![[Pasted image 20250227134414.png#invert]]

## Via Minimisation
Consider the two automaton:

![[Pasted image 20250227151603.png#invert]]

These two automaton are equivalent.

![[Pasted image 20250227151955.png#invert]]

This automaton is the same but larger but its the same once again.

This prompts the question as to having a DFA with the most minimal number of states.

![[Pasted image 20250227152152.png#invert]]

This gives us the idea that **two DFAs are equivalent if they result in the same minimisation.**

There are several algorithms for calculating the minimal automaton, the one we will consider is the table filling algorithm.

### Definition 32:

![[Pasted image 20250227153800.png#invert]]

What this means in simple terms is that two states are distinguishable if there is a word that will lead to different outcomes when starting at that state. 
- If one state is an acceptance state and the other is not then they are immediately distinguishable. 

### Table Filling Algorithm

This is quite an easy algorithm to understand and execute.
Example:

![[Pasted image 20250227161227.png#invert]]
With this automaton make a table for each (non-equal) pair of states.
![[Pasted image 20250227161325.png#invert]]
Mark the pairs that have one of them being an accepting state and the other not accepting i.e. (0,1) will be a distinguishable pair straight away since 1 is an accepting state and 0 is not.

![[Pasted image 20250227161443.png#invert]]
Now iterate through the rest of the pairs, marking those that are distinguishable. You should end up with:
![[Pasted image 20250227161532.png#invert]]
From this we can see that the states (1,3) can be collapsed to give us:

![[Pasted image 20250227162150.png#invert]]

### Minimisation with DFAs

![[Pasted image 20250227162436.png#]]

These two DFAs showcase regular expressions that are equivalent and they are fully minimised since their states are distinguishable but they are not *isomorphic*.


This shows that unique minimisation is only *guaranteed* for DFAs.
