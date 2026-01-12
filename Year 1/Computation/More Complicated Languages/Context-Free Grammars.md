28-02-2025 13:47

Tags: [[Computation]]

# Context-Free Grammars

We need to formally define **context-free grammars**:

## Definition 33:
![[Pasted image 20250228134904.png#invert]]

We call these grammars '**context-free**' because the rules tell us that we can replace a non-terminal symbol no matter where it appears in the string, this rule applies universally and is not dependent on the surrounding context
e.g. $$ A \rightarrow (A)$$ This rule shows that whenever you encounter the non-terminal $A$, you can replace it with the string $A$, it does not matter what symbols come before or after $A$, it will always be replaced the same way.

**'Context-Sensitive'** grammars on the other hand, are grammars of which allow production rules to depend on the context of non-terminal symbols. This means that the rule for replacing non-terminal $A$ might depend on what symbols appear to the left or right of $A$.
e.g. $$ SA \rightarrow S(A) $$ This says that you can replace $A$ with $(A)$ **only if** $A$ is immediately preceded by $S$.


## Definition 34:

![[Pasted image 20250228140809.png#invert]]


## Definition 35:

Name for languages that can be described by a context-free grammar:

![[Pasted image 20250228141633.png#invert]]

## Grammars with Non-Regular Languages

Our solution for some problems that came with the [[Limitations of Regular Languages|limitations of regular languages]] can be helped with grammars.
Many non-regular languages that are needed to be expressed for application can be done with grammars:

![[Pasted image 20250228142254.png]]

This is an example of palindromes, which is a non-regular language.

## Regular Languages to CFGs

We have seen that we can capture non-regular languages using CFGs but can we express **every** regular language using CFGs?

Let's look at a procedure to convert a regular language (express by a DFA) to a CFG.

![[Pasted image 20250228143129.png#invert]]
First Label the states as non-terminals:
![[Pasted image 20250228143155.png#invert]]
Then for every edge the state has, express it as a terminal.
Looking at the first state we can see that it has a $1$ edge that leads back to itself, $S \rightarrow 1S$, a $0$ edge that goes to the second state we have labelled as $A$, $S \rightarrow 0A$ and the first state we have started at is an accepting state so we can have, $S \rightarrow \epsilon$. 
This gives us for the $S$ non-terminal: $$ S \rightarrow 1S ~|~ 0A ~|~ \epsilon$$
For the $A$ terminal repeat the same steps, we have a $1$ edge that goes back to itself, $A \rightarrow 1A$, and we have a $0$ edge that goes to the $S$ state, $A \rightarrow 0S$, so for the $A$ terminal we have: $$A \rightarrow 1A~|~0S$$
Here we have expressed the grammar that will generate the language of those words consisting of $0$s and $1$s which contain an even number of $0$s.

