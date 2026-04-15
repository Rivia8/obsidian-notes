14-04-2026 22:14

Tags: [[Introduction to Visual Computing]]

In a 2D plane you want to:
- Scale (Uniform and Non-uniform), 
- Rotate,
- Reflect
- Sheer
- Translate

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

![[Pasted image 20260414232008.png]]

We use the trigonometric identity as shown above to do this.


![[Pasted image 20260414232132.png]]

Rotation matrices are **orthogonal** which means that the **transpose** equals the **inverse**.
$$R^T = R^{-1} $$
In linear algebra, if you apply a transformation $M$ to a vector, to get the vector back you need to multiply it by the inverse matrix $M^{-1}$.
$$M^{-1} \times M = I$$
Where $I$ is the identity matrix which does nothing and so you get the back the original vector. However, for larger matrices, even a $3 \times 3$ matrix, it involves long and expensive calculations.
***But*** the **Transpose** ($M^T$), which is the vector flipped over its diagonal line causing its rows to become columns and columns to be rows, happen to be the same as the inverse of matrices.

## Reflection

![[Pasted image 20260414233437.png]]

Reflections are also **orthogonal** but they are **not** rotation matrices

## Sheer

A Sheer is **Rotating** the vector *then* **Scaling Non-Uniformly** and *then* **Rotating** back.

However a basic sheer *does* have a single, fundamental operation on its own  dedicated matrix:
![[Pasted image 20260415112500.png]]

Where this is a sheer on the X-axis by a factor of $k$.

![[Pasted image 20260414233730.png]]

**ORDER MATTERS**.

![[Pasted image 20260414234003.png]]

The reason for this is that **matrix multiplication** is *not* **commutative.**

When combining a shear with *other* transformations like rotation, scaling and translation, the order also matters.

In standard notation, the matrix closest to the vector comes first:

$$v_{\textbf{final}} = M_3 \times M_2 \times M_1 \times v_{\textbf{originak}} $$
And the order that you arrange these matrices depends on what you inevitably want to accomplish with the transformation.

# Translation

![[Pasted image 20260415114645.png]]

![[Pasted image 20260415114502.png]]

Translation is **not** a linear transformation. 

In **Linear Algebra** a linear transformation must obey the rule that the origin $(0, 0)$ can never move.

If you take a standard $2 \times 2$ transformation matrix and try to multiply it by the origin coordinate, the math guarantees that the result will always be zero:

![[Pasted image 20260415115329.png]]

This can be applied to scaling, rotating and shearing. Translation however, shifts the entire coordinate system (origin included) so you can't use a $2 \times 2$ matrix to represent it.

An **affine** transformation, is like a linear transformation but *has* the ability to shift the origin, its written algebraically as:

$${\vec{v}}_{final} = (M \times \vec{v}_{original}) + t$$
It guarantees that straight lines remain straight and parallel lines remain parallel, but does not guarantee that the origin stays put.

Technically the formula is correct but doing this is isn't good for graphics pipelines, since tensor cores are optimised for matrix multiplications.
To **force** translation to act as a multiplication, you do something called **Homogeneous Coordinates**. 

How this works is that you add **another dimension**. You pretend the 2D space is actually a flat plane hovering exactly 1 unit high in 3D space by adding a new component, $w$ and setting it to 1, $(x, y, 1)$

Then you perform the multiplication and it works out:
![[Pasted image 20260415120119.png]]
 ![[Pasted image 20260415125948.png]]

You can actually perform all