25-02-2025 22:53

Tags: [[Computation]]

# Patterns to Automata

We have already looked at [[Automata to Patterns|automata to patterns]] now for the inverse, patterns to automata. It is quite useful to to be bale to derive an automaton from a pattern.
Generally, it is quite difficult to read off an automaton from a pattern, so we introduce an algorithm that works for all regular expressions and is recursive. 
It builds on [[Regular Expressions|definition 1]] making use of recursive structure and patterns.

## Algorithm 3

### $\epsilon$ Transitions
$\epsilon$ transitions are special transitions that allow the automaton to move from one state to another without reading any input symbol. Think of it as 'free' move that doesn't consume any characters from the input string.

### Definition 15
![[Pasted image 20250226140518.png#invert]]

### Definition 16
![[Pasted image 20250226140632.png#invert]]

### General Case

Our regular expressions are defined in a recursive fashion, meaning that we will be defining base cases and then how to apply concatenation, alternative and Kleene star.

#### The Pattern ∅

![[Pasted image 20250226154535.png#invert]]
This automaton is one that accepts no words at all

#### The Pattern $\epsilon$
![[Pasted image 20250226154742.png#invert]]
This automaton only accepts the **empty word,** **$\epsilon$.**

#### The pattern $x$ for $x \in \Sigma$ 

An automaton recognising the language defined by this pattern is given below:

![[Pasted image 20250226155357.png#invert]]
This accepts precisely the word $x$.

#### Concatenation
For both **concatenation** and **alternative** assume that we have patterns $𝑝_1$ and $𝑝_2$ as well as automata $𝐴_1$ and $𝐴_2$ such that $𝐴_𝑖$ recognizes the language defined by $𝑝_𝑖$.

For **concatenation:**
We turn every accepting state $A_1$ into a non-accepting state and draw an $\epsilon$-transition from it to the start $A_2$. This makes that the only accepting states are that of $A_2$. In the end it will give us an automaton that only accepts the concatenation of the patterns - $p_1p_2$.

![[Pasted image 20250226160553.png#invert]]
#### Alternative (OR)

An automaton the language defined by the pattern $p_1 | p_2$ is given below. We add a new start state and connect it to with $\epsilon$-transitions to the start states of $A_1$ and $A_2$ (so these are no longer start states).

![[Pasted image 20250226160809.png#invert]]

#### Kleene Star

We must assume that we have a pattern $p$ as an automaton $A$ that recognises the language defined by $p$.
Given the automaton $A$ we introduce a new start, accepting state. 
We introduce $\epsilon$-transitions from the original start state to the accepting states. 
![[Pasted image 20250226164831.png#invert]]


## Algorithm 4

While we need $\epsilon$ transitions along the way to construct an automaton from a pattern, we do not want to keep them around since they make the automaton confusing, so we have to introduce an algorithm to remove the $\epsilon$-transitions.

![[Pasted image 20250226144042.png#invert]]

The resulting automaton may contain unreachable states that can be removed.

**Example:**
![[Pasted image 20250226145617.png#invert]]
First you copy the states as they are. If you from a non-accepting state you can get to an accepting state only using $\epsilon$-transitions, then you make that state an accepting state.
![[Pasted image 20250226150103.png#invert]]
Here we can see the first and third state have this so we can make them accepting states:
![[Pasted image 20250226150128.png#invert]]
We can then copy all the 'regular' letter labelled transitions other than $\epsilon$ transitions.
![[Pasted image 20250226150146.png#invert]]

You then look at each transition in turn so if we can get to a state with a number of $\epsilon$ transitions followed by that label, we can just join the original state and the next state with the label. 
Let's look at the $a$ transitions first.

- - - 

This:
![[Pasted image 20250226152417.png#invert]]
Will give us:
![[Pasted image 20250226152442.png#invert]]
- - -
This:
![[Pasted image 20250226152512.png#invert]]
Will give us:
![[Pasted image 20250226152532.png#invert]]
- - - 

We combine them to give us:

![[Pasted image 20250226152634.png#invert]]
Now for the $b$ transitions:

- - -

![[Pasted image 20250226152707.png#invert]]
This would give us (in combination with our previous updates):

![[Pasted image 20250226152803.png#invert]]
- - -

We can now remove any redundant states and any transitions involving them:

![[Pasted image 20250226152841.png#invert]]
