14-04-2026 22:14

Tags: [[Introduction to Visual Computing]]

In a 2D plane you want to:
- Scale (Uniform and Non-uniform), 
- Rotate,
- Reflect
- Translate
- Sheer

To do this, we use Linear Algebra, specifically, **Linear Transformations**.

**Linear Transformations**a are the process of applying a function to a vector to get a new vector.

There are some rules that need to be upheld for linear transformations:

![[Pasted image 20260414222220.png]]

Matrix vector multiplication can be used to describe linear transformations since the rules uphold when using them. 

Remember that the last point shows that any change to the origin/zero vector ($\vec{0}$) results in itself.

## Scale

There are two forms of Scale, **Uniform** and **Non-Uniform** as we have said.

### Uniform Scale


![[Pasted image 20260414222841.png]]

If you have a vector $\vec{v}$ and apply a scalar to it:

![[Pasted image 20260414222920.png]]

The operation *can* indeed be represented as a matrix multiplication.

### Non-Uniform Scale

![[Pasted image 20260414223109.png]]

Non-Uniform scale is quite similar to unifrom scale, the main difference being is that the 

## Rotation

