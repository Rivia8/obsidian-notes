09-03-2026 15:01

Tags: [[Introduction to Visual Computing]]

# Maths for Graphics

Points that are discussed:

- Geometric Entities:
	- Points
	- Vectors

- Matrices
- Coordinates

In graphics vectors are denoted by $v$ and not $\vec{v}$.
Vectors use the matrix notation to be represented in a column:

![[Pasted image 20260309154245.png|300]]


The little $t$ on the top right means transposed and that means the column because horizontal rather than vertical.

**Points vs Vectors:**
Points are a specific *point* meaning a specific place.
Vectors are represent the displacement of an object.

We use perpendicular vectors, they are *orthonormal* which means orthogonal and along the normal:

![[Pasted image 20260313154707.png]]

**Orthagonal**: The axes are mutually perpendicular. Every axis is at exactly 90° to the others.
**Normalised:** Each axis is a "unit vector", so it has strict length (or magnitude) of exactly 1.

A vector is a geometric quantity that has direction and size and roughly represents position, but it is better to refer it to as **displacement**.
A vector requires to exist in a vector space equipped with addition and scalar multiplication.

In order to represent 0 displacement we have a zero vector.
$$ V + 0 = V$$
$$ V * 0  = 0$$ Where $0$ is the zero vector. 

## Dot Product

This is an operation that takes two vectors and returns a single, standard number (a scalar). It measures how much two vectors point in the same direction:

$$a + b = a_xb_x + a_yb_y + a_zb_z$$

We can also use the angle between the vectors to calculate the dot product:

![[Pasted image 20260313162116.png]]

If $a$ and $b$ are unit vectors:
$$\hat{a}~ \cdot~ \hat{b} = \cos{\theta} $$
If the values are perpendicular, then the dot product is 0 since $\cos{90}$ is 0:
![[Pasted image 20260313162347.png]]

## Cross Product

The cross product gives us a Vector (rather than a scalar like the dot product above).

![[Pasted image 20260313163136.png]]

## Matrices

These are useful mathematical tools.

![[Pasted image 20260313163229.png]]

Matrix addition doesn't work unless the matrix is the size

Matrix multiplication can happen as long as the number of columns in the first matrix is the same as the number of rows in the second matrix.

![[Pasted image 20260313163431.png]]

This means that matrix multiplication is **not** commutative.