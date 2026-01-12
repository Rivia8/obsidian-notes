16-02-2025 20:02

Tags: \[\[Maths]]

# Recursion Natural Numbers

!\[\[Pasted image 20250216200321.png#invert]]

This definition uses recursion to describe the set of of natural numbers $\\mathbb{N}$  
It is usually written $n+1$ for $S\_n$ but we use $S\_n$ for the time being.

!\[\[Pasted image 20250216205320.png#invert]]

The standard structure for an inductive proof over the natural numbers is the following.
Assume we have a statement given in terms of the variable $n$ denoting an element $\\mathbb{N}$.

**Base Case:** We show the statement for some number $𝑏$. The base case is the case of the smallest number $𝑏$ for which the given statement holds, and it is obtained by replacing every occurrence of $𝑛$ by that smallest number.

**Inductive Hypothesis:** We assume that the statement holds for 𝑛 (in which case it coincides with the given statement), or possibly all numbers that are less than or equal to 𝑛, and greater than or equal to the number 𝑏 from the base case.

**Step Case:** We show the statement for 𝑆𝑛 by proving the statement where every occurrence of 𝑛 has been replaced by 𝑆𝑛.

!\[\[Pasted image 20250216201216.png#invert]]
!\[\[Pasted image 20250216211027.png#invert]]
!\[\[Pasted image 20250216210442.png#invert]]

