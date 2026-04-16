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

## Fixed Graphics Pipeline

This is one way that maths gets turned into an image on the screen

![[Pasted image 20260415191327.png]]

The GPU is fed lots of raw data in the form of vertices, they are just independent mathematical points that have no form or structure at the moment.

**[[Transformations]] and [[Year 2/Semester 1/Database Systems/Views|Viewing]]**: it applies the maths we have looked at for **Model Transform**, **View Transform** and **Projection Transform**.

**Lighting** in a *fixed* pipeline, lighting is calculated per-vertex. The GPU takes the light source parameters set in the API, calculates dot products against the surface normals and assigns a colour/brightness value to each individual vertex.

**Primitive Assembly or Clipping**: The GPU here groups isolated dots into 'primitive' structures, usually triangles. 'Clipping' is where the GPU finds out whether an object falls outside the field of view, if it does, it is mathematically clipped.

**Rasterisation:** 3D vector math is stopped and the rasterizer looks at the 2D screen coordinates of a triangle and determines which **dimensionless point samples (pixels)** on your monitor falls inside the triangle's borders. It converts the continuous geometric triangle into a discrete grid of "potential pixels" which are called **Fragments**. 

**Fragment Operations**: Before a fragment is allowed to become an actual pixel colour on your screen, it has to pass some test based on your API parameters.
- **Depth Testing**: checks overlapping triangles and gets rid of the deeper one
- **Alpha Blending**: If the fragment is transparent, the GPU blends its colour with the colour of the pixel sitting behind it.

After this, the fragment reaches the end of the data flow and is output as the final **Pixel Colours** into the memory buffer that the monitor reads to display the frame.

Fixed is easier, but slightly deprecated and isn't as modern.


## Programmable Graphics Pipeline

![[Pasted image 20260415193644.png]]

The **Programmable Graphics Pipeline** showcases a huge shift.

The main difference this and [[Graphics Pipeline and APIs#Fixed Graphics Pipeline|Fixed Graphics Pipelines]] is **control**. In fixed, you pretty much just flick 'switches' that turn on certain features. In the *Programmable* version you *write* custom software called **Shaders** that get compiled and executed on the GPUs cores.

**Vertex Shader Program:** Your custom code is responsible for taking raw local coordinates and doing matrix multiplication $Projection \times View \times Model$ to figure out where it belongs on the screen. Since you have control, you don't just have to do standard transmissions you can just write math to make the vertices wobble to simulate wind etc.

**Geometry Shader / Tessellation**: Whilst the Vertex Shader only *moves* vertices, this stage can create *new* geometry on the fly.
- **Tesselation** takes a low-polygon model and dynamically subdivides it into thousands of tiny triangles right on the GPU.
- **Geometry Shader** takes a primitive and can emit a brand new shape e.g. takes a dimensionless point and generate a 2D square.

**Rasterisation**: This is the same as Fixed Graphics Pipeline. This step is mathematically standardised and requires such extreme hardware optimisation that it remains a fixed hardwired process on the GPU.

**Fragment Shader Program**: This is also known as Pixel Shader, it runs for every single fragment that the Rasterizer spits out.
Instead of the GPU doing basic vertex lighting *your* code dictates exactly what the colour is supposed to be. You can create algorithms that to calculate complex physics-based lighting (PBR), create shiny reflections or use the dot products to generate procedural shadows.
If a triangle covers 1,000 pixels, the Fragment Shader code executes 1,000 separate times.

**Per Sample Operations:** This is the same as **Fixed**.

---

![[Pasted image 20260416114751.png]]

*The image above is what is relevant to the course: Vertex Shader Program, Rasterisation and Fragment Shader Program:*

- The Graphics API is written in JS which receives data from memory that is ran on the CPU.
- The application figures out what we are trying to achieve and sends relevant information to our GPU's memory
- GPU will take relevant scene data and run operations on it.

---

Programmable has a steeper learning curve but allows far more control and is more modern.

### What is Scene Data?

**Scene Data** can be a variety of things. 

![[Pasted image 20260416115227.png]]

The main takeaway is that it contains information **per vertex** to be processed by the **Vertex Shader**.
Vertices are like containers for various attributes: it can talk about things like positions, colours, texture coordinates or even time - you can decide based on your application.

## Coding Shaders

![[Pasted image 20260416161011.png]]

![[Pasted image 20260416161018.png]]

![[Pasted image 20260416161033.png]]

