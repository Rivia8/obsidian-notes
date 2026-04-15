15-04-2026 16:57

Tags: [[Introduction to Visual Computing]]

![[Pasted image 20260415165843.png]]

This is the entire rendering pipeline
![[Pasted image 20260415165902.png]]

Will be focusing on this part.

# Graphics APIs

![[Pasted image 20260415170028.png]]

In order to speak to hardware you need a Graphic API, an example is **OpenGL** which is free and open source.
Its quite old but is still quite powerful.

![[Pasted image 20260415170331.png]]

You also have **WebGL** which is a continuation of **OpenGL** but for browsers. 

**WebGL** is still powerful and the browser can still talk to hardware and since it used in browsers, it utilises JavaScript and wrappers were made utilising **three.js**.

![[Pasted image 20260415171157.png]]

The **Khronos Group** are the ones who support these APIs and companies like Intel and Nvidia.
They also contributed to the creation of Vulkan.

Their APIs are cross-platform.

Another example is Microsoft's **DirectX**.

Apple has their own called **Metal.**

## How Graphics APIs Work

![[Pasted image 20260415171548.png]]

Above is the high level view of how graphics APIs work.

We go from input device where the user with some sort of input (keyboard most likely) interacts with the Graphics API (usually through some programming language) where the Application Program deals with those to implement it into the Application Model that presents a fancy scene, this goes back down where Graphics API will decide how to render it on the screen.

# GPUs

Graphical Processing Units are multi-core processing units that are optimised for parallel operations.

![[Pasted image 20260415190859.png]]

What is this data?
The main 'data' or input that the graphics card takes is **vertices** which are used to create shapes, specifically triangles which are used to compose other shapes.




