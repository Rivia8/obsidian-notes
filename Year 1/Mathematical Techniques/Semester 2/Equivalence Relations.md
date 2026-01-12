06-03-2025 22:16

Tags: [[Maths]]

# Equivalence Relations

In order for relations to be classified as equivalent, we need to look at their properties.

## Reflexivity

![[Pasted image 20250306222028.png#invert]]

This just means that every element is related to itself.

Reflexivity can be expressed as: $I_s \subseteq R$. So this means for a relation to be classed as reflexive, it must have the criteria of containing at least the [[Relations#Identity Relation#|identity relation]].

Example:

Say we have the set $S = \{a,b,c\}$, $I_s = \{(a,a), (b,b), (c,c)\}$.
Then lets say we have the relation $R = \{(a,a),(b,b), (c,c), (a,b), (b,c)\}$.

We can see that the $R$ includes all pairs in $I_S$ and some additional pairs.
 
Visually to check if a relation is reflexive, look and see if every element has a loop.

- - - 

You can make a relation reflexive easily, the *reflexive closure* of $R$ is given by: $$𝑅 ∪ I_S = 𝑅 ∪ {(𝑠, 𝑠) ~|~ 𝑠 ∈ 𝑆}.$$

## Symmetry

Another important property is **symmetry**, this refers to the directedness: if we can go from one element to another, can we always go back?

![[Pasted image 20250307141201.png#invert]]

A way to make something symmetric is quite simple: $$𝑅 ∪ 𝑅^{op}$$
![[Pasted image 20250307141331.png#invert]]

## Transitivity

![[Pasted image 20250307141957.png#invert]]

This is saying that if an element $x$ is related to $y$ and $y$ is related to $z$, then $x$ will be related to $z$.

![[Pasted image 20250307142148.png#invert]]
![[Pasted image 20250307162229.png#invert]]

![[Pasted image 20250307162246.png#invert]]
![[Pasted image 20250307162301.png#invert]]
Look at [[Maths Notes 2.pdf#page=91|here]] to see an example of the transitive closure. 
## Equivalence Relations

![[Pasted image 20250307220410.png#invert]]

So if we have a relation $R$ the equivalence relation generated is the relation obtained from the **transitive** closure of the **symmetric** closure of the **reflexive** closure of $R$.

## Equivalence Classes - Modular Arithmetic

An **equivalence class** consists of all elements that are related to each other.
For an example: $[0] =$ all even numbers and $[1] =$ all odd numbers, so every integer belongs to exactly one of the two classes.

We can use the idea of equivalent classes to compute addition/multiplication rather than dealing with individual numbers, so where we would normally have a table like this:

![[Pasted image 20250307233900.png#invert]]

we could have as:

![[Pasted image 20250307233920.png#invert]]

Where $[0]$ and $[1]$ are sets: $$ \mathbb{N}/∼ ~ = ~\{[0],~[1]\}  $$
Whereby $i ∼ j$ if and only if $i$ mod $2 = j$ mod $2$.

![[Pasted image 20250307234951.png#invert]]

We look at this further in [[Equivalence Classes|equivalent classes]]. 