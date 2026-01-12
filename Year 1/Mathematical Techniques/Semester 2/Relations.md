23-02-2025 22:06

Tags: [[Maths]]

# Relations

When trying to connect two sets, we have only looked at functions which assumes that we have a mechanism for turning elements from the source set into elements of the target set. However, there are other ways of making connections.

In a database you typically want to think of tables, and people often talk about 'relational databases' which can be viewed as relations of a general kind.

Lets look at an example:

Let's say we have a library which has a table of members that are uniquely assigned identifiers ($M$), a table of books ($B$) and a table that tracks which book is currently on loan to which member. We can think of this as connecting the set of all members $M$ to the set of all books $B$.
The connection cannot be thought of a function since a member can have no or several books on loan (many-to-many), so we cannot produce a unique output for each input. Instead, we can think of this table as a subset $L$ of the product, $M \times B$ with the property that $(m,b) \, \in \, L$ if and only if member $m$ currently has book $b$ on loan.

In terms of a database this would be described as a relation schema and would give a type for it along the following lines:
`OnLoan(member:int, book:int),`


## My Definition

A Relation $R$ between two sets $A$ and $B$ is as subset of the Cartesian product $A \times B$. This means $R$ is a set of ordered pairs where the first element of each pair comes from $A$ and the second element comes from $B$:$$(a,b) \, \in R$$

Looking at the library example one more time:

**Members** ($M$): e.g. $\{1,2,3\}$ 
**Books** ($B$): e.g. $\{101, 102, 103\}$

The relation $L$ might represent which members have which books on loan and $L$ is a subset of $M \times B$. If $(m,b) \, \in \, L$, it means that $m$ has book $b$ on loan.

So we could have: $$L \,\,= \,\, \{(1,101), \, (2,102) \, (3,103) \, (1,103)\}$$
Which would translate to:
- **(1, 101)**: Member 1 has book 101 on loan.
- **(2, 102)**: Member 2 has book 102 on loan.
- **(3, 103)**: Member 3 has book 103 on loan.
- **(1, 103)**: Member 1 also has book 103 on loan.


## Relation Notation

It is convenient to think of relations as generalisations of functions and sometimes a similar notation is used.
A **relation** $R$ from a set $S$ to a set $T$ is given by a subset $S \times T$. Which is sometimes written as: $$ R: S \rightarrow T $$
We say: $$ (s,t) \in R $$
Sometimes infix notation is preferred, and instead of $(s,t) \, \in \, R$ , you can write: $$s\,\,R\,\,t $$
It is also not unusual to see symbols, rather than letters to denote relation: $$ s \sim t$$
- - - 

$S \times T$ means all possible pairs of elements from sets $S$ and $T$, and a relation $R$ is a subset of these pairs that describes how elements from $S$ are associated with elements of $T$.

**Example:**

![[Pasted image 20250223225925.png#invert]]

This example above is not a function due to the fact that not every element in the **source** set, has a relation with something in the **target** set. Furthermore, an element of the source set needs to have a **unique** relation into the target set (both W and X relate to 10).


## Identity Relation

Given a set $S$ the identity relation $I_s$ on $S$ is given by : $$\{(s,s)~\in~S \times S \,\, | \,\, s \, \in S\}$$This means that every element $s$ in $S$ is related to itself and only to itself.

For example:
If $S = \{a,b,c\}$, the identity relation $I_s$ would be: $$I_s = \{(a,a),(b,b),(c,c)\}$$
![[Pasted image 20250224003426.png]]

## The Opposite Relation

If you have been given a relation $R$ from $S$ to $T$, there is an easy way of turning it into a relation from $T$ to $S$: 
The opposite relation $R^{op}$ of $R$ is given by: $$ 𝑅^{op} = {(𝑡, 𝑠) ∈ 𝑇 × 𝑆 ~|~(𝑠, 𝑡) \in 𝑅}.$$
The sets are swapped in the Cartesian product, making $R^{op}$ a subset of $T \times S$.

Example:
- Sets $S$ and $T$
	- $S = \{a,b\}$
	- $T = \{1,2\}$

The original relation would be: $R = \{(a,1),(b,2)\}$ 

The opposite relation would be: $R^{op} = \{(1,a),(2,b)\}$

- - - 

This relation:
![[Pasted image 20250224004413.png#invert]]

Has the opposite:

![[Pasted image 20250224004358.png#invert]]

## Composite of Relations

Given a relation of $R$ from $S$ to $T$, its complement is the set of pairs in $S \times T$ that are not in $R$. 
Formally, the complement of $R$ is $(S \times T) ~~ \backslash ~~ R$, and given two relations $R$ and $R'$ from $S$ to $T$ we may form, their union $R \cup R'$ and their intersection $R\cap R'$.

Let $R$ be a relation from $S$ to $S'$, and let $R'$ be a relation from $S'$ to $S''$.
The **relational composite** $R$; $R'$ is given by:
$$𝑅~ ; 𝑅' = {(𝑠, 𝑠'') ∈ 𝑆 × 𝑆''~~ |~~ ∃𝑠' ∈ 𝑆' .((𝑠, 𝑠') ∈ 𝑅 ~~~and~~~ (𝑠 ′ , 𝑠′′) ∈ 𝑅 ′ )}$$

So in essence its combining two relations to form a new relation based on their connectivity.
