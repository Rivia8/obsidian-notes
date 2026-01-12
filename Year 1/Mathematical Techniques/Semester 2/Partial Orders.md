10-03-2025 00:18

Tags: [[Maths]]

# Partial Orders

A **partial order** is a way to organise a set of elements where some elements may be comparable and others not.

A partial order is a specific type of relation that satisfies three properties: **reflexivity**, **antisymmetry** and **transitivity**.
## Anti-Symmetry

This is a new characteristic we will look at.

![[Pasted image 20250310002358.png#invert]]

It explains that it is not possible for two elements to be related both ways unless they are equal.

**Example:**

Set $S = \{1,2,3\}$ 
Relation $R = \{(1,2),(2,1),(1,1),(2,2)\}$ 

Looking at this we can see that we have the pairs $(1,2)$ and $(2,1)$, because $1 \ne 2$, the relation is **not** antisymmetric.

If we have on the other hand:

Relation $R = \{(1,2),(2,3),(1,1),(2,2),(3,3)\}$

In this case, the relation **is** antisymmetric because there are no pairs $(a,b)$ and $(b,a)$ where $a \ne b$.

The antisymmetry condition can be expressed as: 

$$\large R~ \cap R^{op}~ \subseteq I_s$$
## Defining Partial Orders

![[Pasted image 20250310004641.png#invert]]

We often write $(S, \le)$ for the poset of the set $S$ with the partial order.

### Hasse Diagrams

Let's say we have the partial order on the set $\{a,b,c,d,e,f\}$ which is the transitive reflexive closure of: $$\{(𝑎, 𝑏),(𝑏, 𝑐),(𝑎, 𝑒),(𝑒, 𝑓)\}$$
We would usually draw this as:
![[Pasted image 20250310005131.png#invert]]

But for relations that we know are partial orders, we draw this corresponding *Hasse Diagram*.
![[Pasted image 20250310005144.png#invert]]

Here we can see that $a$ is the minimal element, as there are no elements below it. It is 'less than' both $b$ and $e$.
	$a \le e$ and $a \le b$. This is denoted by the positioning of the elements on the diagram and the 'less than' term refers to the hierarchal ordering the element is positioned in.


**Another Example:**
![[Pasted image 20250310011639.png#invert]]

This example is what is known as a total order.
![[Pasted image 20250310011719.png#invert]]

What this means that every element is directly connected to every other element in a sequence/chain-like structure:

```
c
|
b
|
a
```

An example of a **non** total order would be:

```
  c
 / \
a   b
```

Here $a$ and $b$ are not comparable because neither $a \subseteq b$ nor $b \subseteq a$.

