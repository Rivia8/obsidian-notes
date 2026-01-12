02-02-2025 23:49

Status: #new

Tags: [[Maths]]

# Recursion and Induction
Recursion is a powerful principle. It can be used to:
- Define sets
- Define data types in some programming language such as Java, C, and Haskell,
- Define operations on recursively defined data sets,
- Define operations on recursively defined datatypes and 
- Design recursive algorithms.

## Recursion
Recursion is a method of solving problems where the solution depends on solutions of smaller instances of the same problem.
So a way of thinking of it is you have a big problem and you solve it by solving smaller versions of the same problem. 
	A visual analogy that you can think of it by is like Russian nesting dolls, when you open the big doll you find a smaller doll within which carries on until you have the smallest doll. The smallest doll in this case would be the ***base case*** and you opening a smaller doll would be the ***recursive step.***
## Induction
This is a way of proving that a statement is true for all natural numbers. Its like a row of dominoes: if you can knock over the first domino, and you can show that when any domino falls that it will knock over the next one, then all the dominoes will fall.
# Lists
For recursion we first look at lists. Lists are a standard recursive data type. For a set $S$ we can have:
$$[s_n, s_{n-1},...s_2, s_1]$$
To define a list we can satisfy the following conditions:
- The list is empty if there are no entries.
- If has at least one entry, we can think of it being created from a smaller list $l$, by adding an entry, $s$ to it.

![[Pasted image 20250203010739.png#invert]]
![[Pasted image 20250203010759.png#invert]]

If we were to have a list: $$[4,3,2,1]$$
We could write it in the format
![[Pasted image 20250203012319.png#invert]]

the base and step case together prove that a property holds for all possible lists, which is what we try to prove.
- Base case proves it works for the smallest possible input
- Step case proves that if it works for a list of size $n$, it must also work for a size $n+1$

#### Operations on Lists
Operations that occur on recursive data types are usually also defined recursively.
To understand how to define this we must know what we want for the base case and from there understand what we need for the step case.

**Example:**
![[Pasted image 20250203013334.png#invert]]
![[Pasted image 20250203013346.png#invert]]
![[Pasted image 20250203013630.png#invert]]
This example is quite easy to comprehend as it works quite closely to how lists work recursively, we start off with the base case of an empty list, 0, and add $l$ to it.

We can also have **concatenation** of lists:
![[Pasted image 20250203020017.png#invert]]
*Remember $S$ represents a single element*
![[Pasted image 20250205221213.png#invert]]
![[Pasted image 20250205221537.png#invert]]
Example 6.12: This is proving that the sum of a concatenated list equals the sum of the individual lists added together.
![[Pasted image 20250205224142.png#invert]]

In this specific scenario, we are proving that you can either:
- First concatenate two lists then sum the result, or
- Sum each list separately and add those sums 

# Binary Trees
A binary tree is hierarchal data structure here each node has at most two children, typically called the left and right child.

Here is a basic visual representation:
```
	   A
      / \
     B   C
    /   / \
   D   E   F
```

**Special Terms:**
- **Root**: The topmost node (A in our example),
- **Leaf**: A node with no children (D, E and F in our example),
- **Parent/Child**: The relationship between connected nodes,
- **Depth**: The number of edges from the root to a node,
- **Height**: The number of edges in the longest path from a node to a leaf.

A thing to remember is that in a full binary tree every node has 0 or 2 children so every node is:
- Either a leaf, or
- Has a left and right child, which themselves are the root of a tree.

![[Pasted image 20250209195204.png#invert]]
- There is no such thing as an empty tree, every tree has at least one node.

We use $FBTrees_s$ for the set of all binary trees with the labels from $S$.
Visualisation:
![[Pasted image 20250209195901.png#invert]]
![[Pasted image 20250209195930.png#invert]]

- Two trees are equal if they are created using identical instances of base and step case in the same order - this means that when we draw the trees they look identical.

![[Pasted image 20250210001251.png#invert]]

## Operations on Trees
![[Pasted image 20250210004432.png#invert]]
![[Pasted image 20250210010018.png#invert]]
![[Pasted image 20250210010448.png#invert]]

## Ordered Binary Trees
![[Pasted image 20250210013332.png#invert]]
