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

Orthographic projection