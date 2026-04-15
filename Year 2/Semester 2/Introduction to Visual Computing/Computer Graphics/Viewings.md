15-04-2026 15:25

Tags: [[Introduction to Visual Computing]]

Viewing things in the virtual environment can be complicated.

![[Pasted image 20260415152751.png]]

At the top you can see the **Principle of Superposition** this refers to how a **linear transformation** applied to a vector can be applied by a series of multiplications and then summations of the basis vector.
We can define $p$ with one set of basis vectors and $p$ with **another** coordinate system (that uses a different basis vector).

> [!NOTE] Basis Vector
>A Basis Vector, $B$, is called a *Basis* if every element of a vector space $V$ can be written in a unique way as a linear combination of the components of $B$

# Hierarchical Modelling

![[Pasted image 20260415153848.png]]

This is a technique of building complex 3D objects out of simpler, smaller piece by linking them together in a parent-child relationship.

The entire system operates with one fundamental principle:
**Transformations applied to a parent are automatically inherited by its children, but transformations applied to a child do not affect the parent**

# 3D Viewing

![[Pasted image 20260415154548.png]]

When you create a 3D object, it has its own **Local Coordinate System** (that you can see above **Suzanne** and the **Cheese**).
To build a 3D scene, you need shared global environment, which is called **World Space** and to move the objects from their isolated spaces into the shared world space, you **Modelling Transform** which a $4 \times 4$ Scale, Rotate and Translate matrix (SRT hierarchy).

![[Pasted image 20260415155234.png]]

The **View Transform** is how we then *see* the objects.
**The Duality of Modelling and Viewing** is how we can rotate either our *world* or *camera* to achieve the same outcome.
It is convenient for your camera to be at the origin of the world.

To figure out how to move the world, you first have to calculate how the virtual camera is orientated. This is done by calculating three **Orthonormal Basis Vectors**.
- Forward $f$ - the direction the camera lens is pointing
- Right $r$ - the direction point out of the right side of the camera
- Up $u$ - the direction pointing straight out of the top of the camera

If the virtual camera moved 10 units forward and rotated 45 degrees to the right to look at the cheese, you have to do the exact opposite to the world: rotate the world 45 degrees to the left and translate 10 units back.

The **View Transform** is the **Inverse** of the camera's theoretical **Model Transform**:
$$V = M^{-1}_{\textbf{camera}} $$

To build this you break it into two steps, an **Inverse Translation** and an **Inverse Rotation**

1. Inverse Translation, $T^{-1}$:

The camera's position is at $(p_x, p_y, p_z)$ and so we slide the entire world to be the opposite of that:
![[Pasted image 20260415161448.png]]

2. Inverse Rotation, $R^{-1}$

The camera is then shifted to the origin after the translation then we need to twist the world so it aligns with the camera's lens.
Since rotations are orthogonal, to calculate the inverse rotation you just use the **transpose**.

![[Pasted image 20260415161815.png]]

So the the view equation is:

$$\textbf{View} = R^{-1} \times T^{-1} $$
*Note that matrix multiplications are read right to left so the*

## Projection

This is the mathematical process of taking a perfectly aligned 3D world and squashing it so that it fits onto a 2D plane (a monitor screen).

**Perspective Projection:** Mimics how human eyes work, things that are further away from the camera are drawn smaller (**foreshortening**). Parallel lines (like train tracks) appear to converge at a vanishing point.

**Orthographic Projection:** Ignores Distance. An object very far away is drawn at the exact same size as an object 1 inch from the lens and parallel lines remain perfectly parallel.
