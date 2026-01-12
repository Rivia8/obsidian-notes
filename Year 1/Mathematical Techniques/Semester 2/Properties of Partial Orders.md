16-03-2025 21:36

Tags: [[Maths]]

# Properties of Partial Orders

## Maximal/Minimal

![[Pasted image 20250316214844.png#invert]]

**Maximal:**

$p$ is maximal if no other element in the poset is 'greater than' $p$ in the partial order, except for $p$ itself.
Something to remember is that a maximal element does not mean it is the 'largest' in terms of order, rather it simply means that there is no element above it in the poset.

**Minimal:**

$p$ is minimal if no other element in the poset is 'smaller than' $p$ in the partial order, except for $p$ itself.
Similarly for maximal elements, minimal elements do not have to be the absolute smallest element, they just can't have anything strictly below them.

![[Pasted image 20250316220106.png#invert]]

At most there is at least one greatest element and one minimal element.

## Greatest/Least

![[Pasted image 20250316224843.png#invert]]

**Greatest:**

An element $g$ in a poset, is called the greatest element if it is greater than or equal to every other element in the set $P$.

- There can be at most one **greatest** element in a poset, if there were two, they'd have to be comparable.
- The greatest element is like the 'peak' of the poset.

**Least:**

An element $l$ in a poset, is called the **least** element if it less than or equal to every other element in the set $P$.

- Like the greatest element, there can be at most one least element in a poset.
- The least element is like 'base' or 'foundation' of the poset.

![[Pasted image 20250316225928.png#invert]]

In the example above, we can see there is a **least element** but no **greatest element**, this is because $c$ and $f$ are both at the same 'position' but are not comparable.

## Upper/Lower Bounds

We often would like to wage whether a collection of elements can be safely 'overestimated' or 'underestimated'.

![[Pasted image 20250317001156.png#invert]]

An upper bound for a set is greater than or equal to every element of that set.

- An **upper/lower bound** is not necessarily am element of $S$, it just needs to be in $P$.
- There can be multiple upper/lower bounds for $S$.


![[Pasted image 20250317003846.png#invert]]

The reason why $f$ isn't part for the upper bound is because it is not comparable to $e$.


### Least Upper / Greatest Lower Bound

![[Pasted image 20250317005200.png#invert]]

A least upper bound for a set is greater than or equal to every element of that set, and it is the least element of with that property.

![[Pasted image 20250317005418.png#invert]]

If we change the poset slightly we get:
![[Pasted image 20250317005752.png#invert]]

Then $c$, $f$ and $g$ are all upper bounds of $\{b,e\}$, but none of them is the least upper bound since the set $\{c,f,g\}$ has no least element.

