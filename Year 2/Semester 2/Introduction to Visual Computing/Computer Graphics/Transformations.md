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

Non-Uniform scale is quite similar to uniform scale, the main difference being is that instead both axes being multiplied by the same constant scalar, it the axes have different values.

## Rotation

When rotating an object, you will end up with different values for the axes.
![[Pasted image 20260414225840.png]]

You **can** use trigonometry like the above to work these values out, but it can be tedious so we use a different method.

![[Pasted image 20260414231348.png]]
Its kind of similar to how you do Scale transformations but instead of a simple scalar number, you use trigonometry. You use the above matrix.

Whenever you multiply the above with your vector you'll get something like this:

![[Pasted image 20260414231450.png]]

![[Pasted image 20260414231740.png]]

We use the trigonometric identity as shown above to do this.

