23-03-2025 21:41

Tags: [[Maths]]

# Vector Spaces

A **vector space** is essentially a set of objects called vectors that can be:

1. Added together,
2. Can be multiplied by numbers,
3. Follow specific rules about how these operations behave.

We use $\underline{underlines}$ to denote vectors.

![[Pasted image 20250323214231.png#invert]]

The definition above can be daunting to understand.

The first 3 points:

1. **Vector addition**
- You can combine two vectors to get another vector (the sum).
- For example, if you have the vectors $\underline{v}$ and $\underline{w}$, $\underline{v} + \underline{w}$ is also a vector in the space.

2. **Zero Vector** ($\underline{0}$)
- There is a special vector called the zero vector, this acts as an additive identity.
- Adding a zero vector to any vector does not change the vector: $v + \underline{0} = v$.

3. **Scalar Multiplication**
- You can multiply vectors by scalars (real numbers), this results in another vector in the same space.
- For example, $rv$ scales the vector $v$ by the real number $r$.

The definition defines some properties that are self-explanatory.

## Fields and General Vector Spaces.

![[Pasted image 20250331001848.png#invert]]

A **field** is an algebraic structure that provides the necessary arithmetic operations (addition, subtraction, multiplication and division) for defining vector spaces, matrices and other key concepts.

This means that given any field, the definition of a vector space is almost identical to that for the reals (the definition above).

![[Pasted image 20250331002254.png#invert]]
![[Pasted image 20250331002321.png#invert]]

![[Pasted image 20250331002935.png#invert]]

The **direct sum of vector spaces** is a way of combining two vector spaces, $V$ and $W$, over the same field, $K$, into a new larger vector space.

## Subspaces, Linear Independence and bases.

![[Pasted image 20250331022404.png#invert]]

Given the vectors $v_1~ ... ~v_n$ in a vector space, a **linear combination** is any vector you can create by: 
1. **Scaling** each $v_i$ by a number - the scalar. $r_i$.
2. **Adding** of the scaled vectors together.

- - -

Example of Linear Combination (of $\mathbb{R}^2$):

$$ 3v_1 + 2v_2= 3\begin{pmatrix} 1 \\ 0 \end{pmatrix} ~+~2\begin{pmatrix} 0 \\ 1 \end{pmatrix} = \begin{pmatrix} 3 \\ 2 \end{pmatrix}$$

- - -

This can be defined by a recursion definition:

- Base Case, $n = \underline{0}$, if there are no vectors the linear combination is the zero vector.

- Step Case, $n + 1$, first combine the first $n$ vectors, then add the scaled $v_{n+1}$

![[Pasted image 20250331024159.png]]

![[Pasted image 20250331024330.png#invert]]

 1. $\underline{0} \in W$

- The **zero vector** of the big space $V$ must also be in the small space $W$.
- This ensures there’s a “nothingness” vector in the subspace too (very important for solving equations, etc.).

 2. **Closure under scalar multiplication**:

- If you pick any vector $w$ in $W$, and any scalar $r$ from the field $K$,
- Then $rw$ (i.e., scale $w$ by $r$) must also still be in $W$.
- **You can’t leave** $W$ by scaling!

 3. **Closure under addition**:

- If you pick any two vectors $w,w′w, w'w,w′$ from $W$,
- Then their sum $w+w′$  must also stay inside $W$.
- **You can’t leave** $W$ by adding