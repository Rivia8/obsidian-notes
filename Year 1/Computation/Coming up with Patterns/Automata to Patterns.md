24-02-2025 22:01

Tags: [[Computation]]

# Automata to Patterns

We need to understand how to produce a pattern from a DFA.
To do this we can use an algorithm. Why an algorithm?, since sometimes we can just read the pattern off the automaton using intuition. The problem comes when the automaton starts to get complex that an algorithm may need to be used. Also if the automaton is non-deterministic it becomes even harder to comprehend so it might be a good idea to convert [[DFA versus NFA# Producing DFA's from NFA's|NFA's to DFA's]] using Algorithm 1,.

In order to show that it is possible to construct a regular expression for *every* automaton we have to give an algorithm that works for all automata.

## Algorithm 2
Consider the following DFA:

![[Pasted image 20250225112615.png#invert]]
In order to apply the algorithm, we have to name the states, and the algorithm assumes that the states are numbered. The **order** that the states are numbered can make a difference in how **complex** the algorithm is to carry out.

**Labelling States:**

1. Count the number of states, $n$. Number them from $n-1$ to $0$. *So if we have $n=3$ the states will be labelled from $0$ to $2$. 
2. Set $m = n - 1$
3. Label the state that **has the most loops** (transitions back to itself) that hasn't already been numbered with $m$.
4. Update $m$ by decreasing it by $1$, $m = m-1$
5. Remove the loops considered that involve the newly named state,
6. Repeat steps 3, 5 until all states have been labelled.

*Or*, you could number the states in order of complexity:

- The state with the most paths going through it gets the highest number, the next highest goes to the next 'complicated' state etc.

So from the starting point that we had earlier we would get:

![[Pasted image 20250225115050.png#invert]]
In this automata there are two accepting states, $0$ and $2$, this means that the language $L$ accepted by this automaton is the union of two languages which we can write as:
$$L=L_{0\rightarrow0}~~ \cup~~L_{0\rightarrow2}$$
So when we have ${0\rightarrow0}$, the first numbered state shows what we start in and the second is the state we end in.
We now break this first part (the first accepted language) down.

- - - 

**Going from State $0$ to State $0$, $L_{0\rightarrow0}$**

To do this we can either:
- Not use state $2$ at all,
- Go to state $2$, return to it many times as we like (go to $1$ then $2$ and repeat), then go to state $0$ right at the end.

We can display this as the following equality:

$$L_{0→0} = L^{≤2}_{0→0} = L^{≤1}_{0→0} ~~ ∪ ~~ L^{≤1}_{0→2} ~\cdot ~ (L{^≤1}_{2→2})^∗ ~\cdot ~L^{≤1}_{2→0}$$ 
The notation $L^{≤2}_{0→0}$ means that we go from state $0$ to $0$ while using only states from $0$ to $2$ in between, we can't pass through .

We can simplify each of the following languages we have defined by looking at them as they are now comprehendible. 

![[Pasted image 20250225121941.png#invert]]

Putting these together we get the following:

![[Pasted image 20250225122056.png#invert]]

![[Pasted image 20250225122217.png#invert]]

Now we have the second part, 
**Going from State $0$ to State $2$, $L_{0\rightarrow2}$**

To do this we can:
- Go to state 2 and return to it as many times as we like.

This gives us:
$$L_{0→2} = L^{≤2}_{0→2} = L^{≤1}_{0→2} ~⋅~ (L^{≤1}_{2→2})^∗$$

![[Pasted image 20250225122804.png#invert]]

We can simply this to:
![[Pasted image 20250225122918.png#invert]]

## Generalising Algorithm 2

The states in the automaton are given by $\{0,~1,~...,~n\}$ and that $j$ is the start state, where $0 \le j \le n$ and $i$ is the end state.

![[Pasted image 20250225175821.png#invert]]
We do this repeatedly until we get down to a sub-language that passes through no states at all.

Once we have reached the point that we have paths which are not allowed to use any other states, we have the following:

![[Pasted image 20250225211022.png#invert]]
![[Pasted image 20250225211106.png#invert]]

