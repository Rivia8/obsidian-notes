28-02-2025 12:18

Tags: [[Computation]]

# Generating Words

Instead of thinking of patterns that may be matched by strings, you could *generate* all the words in our language following some rules, the 'rules' are given by what we call a *[[Context-Free Grammars|grammar]].* We can also use this as a test for membership.

Let's look at this following example:

![[Pasted image 20250228132941.png#invert]]
We have to have a place to start, and we always use $S$ as the only symbol we may create from nothing. Once we have $S$ we can use any of the rules on the right hand side to replace it by a more complicated string:

![[Pasted image 20250228133611.png#invert]]

We call this a **derivation** from the grammar.

When it comes to grammars we can see that it allows us to build expressions in a mechanical manner. Usually we are only interested in derivations that end up that consisting only of digits and arithmetic operations - don't have $S$ or $B$. These letters can be seen as placeholders for expressions that have not been built yet. 

- We call the letters we want our final strings to be built of **terminal symbols** (the final symbols hence terminal), as soon as these are introduced they can no longer be replaced.

- The other symbols are called **non-terminal** symbols.

We usually write these symbols in an abbreviated form of giving rules:

![[Pasted image 20250228134703.png#invert]]

