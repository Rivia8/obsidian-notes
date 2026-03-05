28-12-2025 14:15

Tags: [[Algorithms and Data Structures]]

# Reading 8

Reading for week 8 includes:
Pages 68-83, 90-100, and 116-125

# Part I Data Structures

## Chapter 2 Basic Data Structures

### 2.3 Trees

Trees store elements hierarchically. Except the **top** element, each element in a tree has a **parent** and zero or more **children** elements.

A ***tree*** $T$ is a set of nodes storing elements in a parent-child relationship with the following properties:
- $T$ has a special node $r$, called the ***root*** of $T$, with no **parent** node.
- Each node $v$ of $T$ different from $r$ has a unique parent node $u$.

A node is external if it has no children and it is internal if it has one or more children.

**A *binary tree* is an ordered tree in which every node has at most two children.**
A binary tree is **proper** if each internal node has two children. For all internal nodes (in a binary tree) we label them either **left** or **right** children - a left child comes before a right child. The subtree rooted at a left or right child of an internal node $v$ is called a **left subtree** or **right subtree**.

#### Tree Definition

Viewed abstractly, a tree stores elements at positions, which as with positions in a list, are defined relative to neighbouring positions. The terms **positions** and **nodes** can be used interchangeably since the positions *are* nodes. 
Methods:
- `root()`: Returns the root of the tree,
- `parent(v)`: Returns the parent of node *v*,
- `children(v)`: Return a set containing the children of node $v$

If the tree is ordered, then `children(v)` returns an ordered set. 
If $v$ is an external node, then `children(v)` will be an empty set.

We also include the following **query** methods:

- `isInternal(v)`: Test whether node $v$ is internal,
- `isExternal(v):` Test whether node $v$ is external,
- `isRoot(v)`: Test whether node $v$ is the root

There are also a number of generic methods a tree should support:

![[Pasted image 20251228160014.png#invert]]

#### Tree Traversal

There are some assumptions that need to be made for this:

![[Pasted image 20251228160222.png#invert]]
If $v$ is the root, then the depth of $v$ is 0. Otherwise, the depth of $v$ is one plus the depth of the parent of $v$. An algorithm of this can be defined recursively:

![[Pasted image 20251228160601.png#invert]]

The running time of `depth(T, v)` is $O(1 + d_v)$ so in the worst case its $O(n)$ time.

The **height** of a tree $T$ is equal to the maximum depth of an external node of $T$. A better way to do this is doing a recursive method again, where if $v$ is an external node, the height is 0 otherwise the height is the height of the child of $v$ plus 1.

![[Pasted image 20251228161011.png#invert]]

These concepts are needed to understand **traversal**.
A **traversal** of a tree $T$ is a systematic way of accessing or "visiting", all the nodes of $T$. 

##### Preorder Traversal

Here the visit the root first, then the sub-trees are traversed recursively, with the left subtree first and then the right.

![[Pasted image 20251228175534.png#invert]]

The analysis is similar to that of the height algorithm. The overall running time of $T$ is $O(n)$.

![[Pasted image 20251228180040.png#invert]]

##### Postorder Traversal

In this, this is kind of the opposite of preorder, here, the subtrees are visited first then the node:

![[Pasted image 20251228175954.png#invert]]

![[Pasted image 20251228180031.png#invert]]

The running time is similar to that of preorder traversal at $O(n)$ running time.

### Binary Trees

A proper binary tree is an ordered tree in which each internal node has exactly two children .

Abstractly, binary trees have a specialisation where they have three more access methods:
`
`leftChild(v)`: Return the left child of $v$.

`rightChild(v)`: Return the right child of $v$.

`sibling(v)`: Return the sibling of node $v$.

In each level, $d$, of binary tree, we can only have $2^d$ nodes.
![[Pasted image 20251228181242.png#invert]]

![[Pasted image 20251228181145.png#invert]]

In a proper binary tree $T$, the number of external nodes is 1 more than the number of internal nodes.

#### Traversals of a Binary Tree

Here we still have the same categories of traversal that we did for Tree Traversals:

##### Preorder Traversal of a Binary Tree

This is same with the exception of defining which subtree we traverse first:

![[Pasted image 20251228182412.png#invert]]

##### Postorder Traversal of a Binary Tree

![[Pasted image 20251228182444.png#invert]]

##### Inorder Traversal of a Binary Tree

An additional traversal method for a binary tree is the **inorder** traversal. Here we visit a node *between* the recursive traversal of its left and right subtrees shown.

![[Pasted image 20251228182708.png#invert]]

You can think of it as visiting the nodes from left to right.
![[Pasted image 20251228182744.png#invert]]

Each traversal visits the nodes of a tree in a certain order and is guaranteed to visit each node exactly once.

### Unified Tree Traversal Framework

We can unify the tree-traversal algorithms above into a single framework. The resulting method is known as the ***Euler Tour Traversal***.

This can be thought of as a 'walk' around the Binary Tree. You pretty much trace around the Binary Tree left to right:
![[Pasted image 20251228185042.png#invert]]

![[Pasted image 20251228185520.png#invert]]

## Chapter 3 Binary Search Trees

In a 3D game, it is important to be able to find objects relative to other objects in the environment. You could do this by comparing the object $x$ to every object in the environment, *but* this would require $O(n)$ object-object comparisons for $x$ which would in turn be $O(n^2)$ time for every object which is slow.
Because of this, many three-dimensional video games create a partitioning of space using a Binary Tree, by applying a technique called **Binary Space Partitioning**. This uses a **Binary Search Tree** by splitting the area into planes. First splitting it into 2, then splitting those 2 into 2 smaller ones each etc. until there are very small planes that hold a couple of objects. Then we make searches by making left or right decisions.

### Searches and Updates

If you want a system, where if you give a number, you can easily tell a number which sandwiches it. 
The best way to do this is by having an ordered array $A$ of a set $S$. This allows you to access elements by doing $A[i]$. This just lets us jump extremely quickly, $O(1)$, to specific locations.

#### Binary Search Algorithm

This lets us quickly 'home-in' on a search key $k$ using a special algorithm.

- Candidates are the numbers that could still be the answer,
- We have parameters, these are low and high, these are the bookends of the range we are looking at.
- Median candidate is the middle number. This is $\frac{\text{low} + \text{high}}{2}$ and it rounds down to the lower integer (no matter what):
$$ \text{mid} = \lfloor(\text{low} + \text{high}) / 2 \rfloor$$

`elem(i)`: returns the data at that index.
`key(i)`: returns the key at that index.

![[Pasted image 20251229191342.png#invert]]

##### Analysis of Binary Search

We can see that a constant number of operations are executed at each recursive call, so the running time is proportional to the number of recursive calls performed.

If the number of candidates is $n$, after the first call it at most $n/2$ and then $n/4$ and so on. This means that after $m$ steps, the number of items left is roughly $n/2^m$. The worst-case scenario is that the item isn't there, so you stop when there is less than one item to check: $n/2^m < 1$. We can rearrange this formula to get $m > \log_{2}{n}$,

The space requirement is $\Theta(n)$ which is optimal since you can't store $n$ items in less than $n$ space.

A thing to note is that, Binary Search on a sorted array is only great for Static Data (data that doesn't change).

#### Binary Search Tree 

This applies the idea of Binary Search to a Binary Tree.
We define a binary search tree to be a binary tree in which each internal node $v$ stores an element $e$ such that the elements stored in the left subtree of $v$ are less than or equal to $e$ and the elements stored in the left subtree of $v$ are greater than or equal to $e$.

#### Searching in a Binary Search Tree

This is similar to Binary Search in arrays. Just instead, you do the same thing but within a Binary Search Tree and you move left if the value is lower and right if its higher (than the current value).

![[Pasted image 20251229205946.png#invert]]

The run time is dependent on the height of the tree, $h$. Since we spend $O(1)$ time per node encountered, the search method runs in $O(h)$ time.

![[Pasted image 20251229210221.png#invert]]

This means that the Binary Search Tree's performance is dependent on how well *balanced* it is. But even if the tree isn't perfectly balanced, its still fast as long as it isn't too bad. Even a 75/25 split will allow for a logarithmic time complexity and result in a fast-enough time.

#### Insertion in a Binary Search Tree

Binary Search Trees allow the implementations of `insert` and `remove` operations.

![[Pasted image 20251229211704.png#invert]]![[Pasted image 20251229211922.png#invert]]
The speed of insertion is the same as that of searching, since its the same just with an insertion that takes $O(1)$ time.

#### Deletion in a Binary Search Tree

This is a bit more complex than insertion.

## Chapter 4 Balanced Binary Search Trees

**Real-time systems** are computational platforms that have real-time constraints, where computations must complete in a given amount of time.

A Binary Search Tree can to nearest-neighbour queries within these conditions. However, if they reach a certain height, the worst-case running time for performing searches and updates in $T$ can be linear.

We can restructure trees so that they are always "balanced".

### Ranks and Rotations

The worst-case performance of searching in a binary tree can be as bad as linear time, since the time performance can be as bad as linear time.

We can perform restructuring actions on $T$ based on specific rules that maintain some notion of "balance" between sibling subtrees in $T$.

We do this by assigning **ranks**, $r(v)$ for each node, $v$, where $r(v)$ is the height of $v$ or a value related to the height of $v$.

### AVL trees

This is a rank-balanced search tree. Any subtree of an AVL tree is itself an AVL tree.