09-03-2025 21:55

Tags: [[Maths]]

# Equivalence Classes

An **equivalence class** is a subset of a set formed by grouping elements that are equivalent to each other with respect to a given equivalence relation.

	An equivalence relation on a set S is a relation that is Reflexive, Symmetric and Transitive.

**Example** of equivalent classes:

$S = \{1,2,3,4,5,6\}$,     
The relation, $\sim$, where $a \sim b$ if $a$ and $b$ have the same parity (i.e. both are odd or even).

The equivalence class for odd numbers: $[1] = \{1,3,5\}$
The equivalence class for even numbers: $[2] = \{2,4,6\}$

- - - 

A **quotient set** is the set of all equivalence classes of a set $S$ under an equivalence relation $\sim$, the notion is often denoted as $S/\sim$ .    

![[Pasted image 20250309222812.png#invert]]

Looking at the example above, we would apply this to produce: $$S/\sim ~=~~ \{\{1,3,5\},\{2,4,6\}\}$$
The quotient set, is the set of all the equivalent classes. It represents the original set $S$, divided into mutually exclusive and collectively exhaustive equivalence classes.

**Visualisation:**

Imagine you have a set of coloured balls:

- **Set** $S$: Contains all the balls.
- **Equivalence Relation** $\sim$: Groups balls by colour.
- **Equivalence Classes**: Each group of balls of the same colour.
- **Quotient Set**: The set containing each group of balls (one group for each colour).

We can define binary relations and equivalence using [[Recursion and Induction|recursion and induction]]. 

Check out [[Maths Notes 2.pdf#page=115|this part of the notes]] to see how to recursively define binary relations and prove their equivalence properties.

